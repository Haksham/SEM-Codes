// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit 1b.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('student')
// db.student.insertMany([
//   { usn: '1CS21IS001', name: 'Alice', scode: 'CS101', marks: 15 },
//   { usn: '1CS21IS002', name: 'Bob', scode: 'CS102', marks: 25 }
// ])

//------------------------------------------------------

// server.js
const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const url = 'mongodb://127.0.0.1:27017';

app.use(express.static(__dirname));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '1b.html'));
});

app.get('/insert', async (req, res) => {

	const { name, usn, scode, marks } = req.query;
	const parsedMarks = parseInt(marks, 10);
	const client = await MongoClient.connect(url);
	const db =client.db('mydb');
	const collection = db.collection('student');

	await collection.insertOne({ usn, name, scode, marks: parsedMarks });
	const lowScorers = await collection.find({ marks: { $lt: 20 } }).toArray();
	await client.close();  
	res.json(lowScorers);
});

app.listen(3000);

// -------------------------------------------------------
// 1b.html

<html>
<body>
  <h1>Insert Student Record</h1>
  <form action="/insert" method="get">
    USN: <input type="text" name="usn" required><br>
    Name: <input type="text" name="name" required><br>
    Subject Code: <input type="text" name="scode" required><br>
    Marks: <input type="number" name="marks" required><br>
    <button type="submit">Insert</button>
  </form>
</body>
</html>
