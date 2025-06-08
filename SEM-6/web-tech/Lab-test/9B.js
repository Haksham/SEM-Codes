
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit sem.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('sem')

// no need to insert any data manually, the server will handle it

// ------------------------------------------------------

// server.js

const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'sem.html'));
});

app.get('/submit', async (req, res) => {
  const { name, branch, semester } = req.query;
  const sem = parseInt(semester);
  const client = await MongoClient.connect(uri);
  const db = client.db('mydb');
  const collection = db.collection('sem');

  await collection.insertOne({ name, branch, semester: sem });
  const students = await collection.find({ branch: /cse/i, semester: 6 }).toArray();
  await client.close();

  let html = `<h2>CSE Branch - 6th Semester Students</h2><ul>`;
  students.forEach(s => {
    html += `<li>${s.name} - ${s.branch} - Semester ${s.semester}</li>`;
  });
  html += `</ul><a href="/">Back</a>`;
  res.send(html);
});

app.listen(3000);

// ------------------------------------------------

// sem.html

<html>
<body>
  <h1>Enter Student Details</h1>
  <form action="/submit" method="get">
    Name: <input type="text" name="name"><br>
    Branch: <input type="text" name="branch" ><br>
    Semester: <input type="number" name="semester"><br>
    <button type="submit">Submit</button>
  </form>
</body>
</html>