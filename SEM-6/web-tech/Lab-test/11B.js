
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit attendance.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('attendance')

// no need to insert any data manually, the server will handle it

// ------------------------------------------------------

// server.js

const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'attendance.html'));
});

app.get('/submit', async (req, res) => {
  const { name, usn, dept, attendance } = req.query;
  const attendanceNum = parseFloat(attendance);
  const client = await MongoClient.connect(uri);
  const db = client.db("mydb");
  const collection = db.collection("attendance");

  await collection.insertOne({ name, usn, dept, attendance: attendanceNum });
  const lowAttendanceStudents = await collection.find({ attendance: { $lt: 75 } }).toArray();
  await client.close();

  let html = '<h2>Students with Attendance below 75%</h2><ul>';
    lowAttendanceStudents.forEach(s => {
      html += `<li>Name: ${s.name}, USN: ${s.usn}, Dept: ${s.dept}, Attendance: ${s.attendance}%</li>`;
    });
  html += '</ul><a href="/">Go back</a>';
  res.send(html);
});

app.listen(3000);

//----------------------------------------------------

// attendance.html

<html>
<body>
  <h1>Enter Student Attendance</h1>
  <form action="/submit" method="get">
    Name: <input type="text" name="name" ><br>
    USN: <input type="text" name="usn" ><br>
    Department: <input type="text" name="dept" ><br>
    Attendance (%): <input type="number" name="attendance"><br>
    <button type="submit">Submit</button>
  </form>
</body>
</html>