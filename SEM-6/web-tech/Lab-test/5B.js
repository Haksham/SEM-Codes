
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit index.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('students')

// no need to insert any data manually, the server will handle it

// ----------------------------------------------------------

// server.js

const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.use(express.urlencoded({ extended: true }));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

app.post('/submit', async (req, res) => {
  const { name, usn, dept, grade, action } = req.body;
  const client = await MongoClient.connect(uri);
  const db = client.db("mydb");
  const collection = db.collection('students');

  if (action === 'add' && name && usn && dept && grade) {
    await collection.insertOne({ name, usn, dept, grade });
  } else if (action === 'update' && name && grade) {
    await collection.updateOne({ name }, { $set: { grade } });
  }

  const students = await collection.find().toArray();
  await client.close();

  res.json(students);
});

app.listen(3000);

//---------------------------------------------------------------------
// index.html

<html>
<body>
  <h2>Add Student</h2>
  <form action="/submit" method="POST">
    <input type="hidden" name="action" value="add">
    Name: <input type="text" name="name" required><br>
    USN: <input type="text" name="usn" required><br>
    Dept: <input type="text" name="dept" required><br>
    Grade: <input type="text" name="grade" required><br>
    <button type="submit">Add Student</button>
  </form>

  <hr>

  <h2>Update Grade</h2>
  <form action="/submit" method="POST">
    <input type="hidden" name="action" value="update">
    Name: <input type="text" name="name" required><br>
    New Grade: <input type="text" name="grade" required><br>
    <button type="submit">Update Grade</button>
  </form>
</body>
</html>
