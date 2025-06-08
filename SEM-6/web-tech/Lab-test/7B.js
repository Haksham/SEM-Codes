
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit form.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('grade')

// no need to insert any data manually, the server will handle it

// ------------------------------------------------------------------------
// server.js

const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'form.html'));
});

app.get('/add', async (req, res) => {
  const { name, usn, branch, sem, grade } = req.query;
  const client = await MongoClient.connect(uri);
  const db = client.db('mydb');
  const collection = db.collection('grade');
  
  await collection.insertOne({name,usn,branch,sem: parseInt(sem),grade,});
  const students = await collection.find({ grade: 'S' }).toArray();
  await client.close();

  let output = "<h2>Students with 'S' Grade</h2><ul>";
  students.forEach(s => {
    output += `<li>${s.name} - ${s.usn} - ${s.branch} - Semester ${s.sem}</li>`;
  });
  output += '</ul><a href="/">Go Back</a>';

  res.send(output);
});

app.listen(3000);

// ------------------------------------------------------
// form.html

<html>
<body>
  <h1>Add Student</h1>
  <form action="/add" method="get">
    Name: <input type="text" name="name"><br/>
    USN: <input type="text" name="usn"><br/>
    Branch: <input type="text" name="branch"><br/>
    Semester: <input type="number" name="sem"><br/>
    Grade: <input type="text" name="grade"><br/>
    <button type="submit">Add Student</button>
  </form>
</body>
</html>

