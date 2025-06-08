
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit examfee.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('exam_fee')
// db.exam_fee.insertMany([
//   {
//     student_name: 'Alice',
//     usn: '1AB21CS001',
//     semester: '5',
//     exam_fee: 2000
//   },
//   {
//     student_name: 'Bob',
//     usn: '1AB21CS002',
//     semester: '6',
//     exam_fee: -100
//   },
//   {
//     student_name: 'Charlie',
//     usn: '1AB21CS003',
//     semester: '5',
//     exam_fee: 1500
//   }
// ])

//--------------------------------------------------
// server.js
const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'examfee.html'));
});

app.get('/submit', async (req, res) => {
  const { student_name, usn, semester, exam_fee } = req.query;
  const parsedFee = parseInt(exam_fee);

  const client = await MongoClient.connect(uri);
  const db = client.db('mydb');
  const collection = db.collection('exam_fee');

  await collection.insertOne({ student_name, usn, semester, exam_fee: parsedFee });
  const deleteResult = await collection.deleteMany({ exam_fee: { $lte: 0 } });
  const remainingStudents = await collection.find().toArray();
  await client.close();

  res.send(`
    <h2>Deleted ${deleteResult.deletedCount} students with fee ≤ 0</h2>
    <h3>Remaining Students:</h3>
    <ul>
      ${remainingStudents.map(s => `<li>${s.student_name} - ${s.usn} - ₹${s.exam_fee}</li>`).join('')}
    </ul>
  `);
});

app.listen(3000);

//------------------------------------------------

// examfee.html

<html>
<body>
  <h2>Exam Fee Submission</h2>
  <form action="/submit" method="get">
    <label>Student Name: <input type="text" name="student_name" required></label><br><br>
    <label>USN: <input type="text" name="usn" required></label><br><br>
    <label>Semester: <input type="text" name="semester" required></label><br><br>
    <label>Exam Fee: <input type="number" name="exam_fee" required></label><br><br>
    <button type="submit">Submit</button>
  </form>
</body>
</html>