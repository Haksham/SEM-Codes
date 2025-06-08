
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit company.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('company')

// no need to insert data manually, it will be done through the form

// --------------------------------------------------------
// server.js

const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'company.html'));
});

app.get('/submit', async (req, res) => {
  const { usn, name, company } = req.query;
  const client = await MongoClient.connect(uri);
  const db = client.db('mydb');
  const collection = db.collection('company');
  
  await collection.insertOne({ usn, name, company });
  const infosysStudents = await collection.find({ company: /infosys/i }).toArray();
  await client.close();

  let output = `<h2>Infosys Selected Students</h2><ul>`;
  infosysStudents.forEach(s => {
    output += `<li>${s.name} (${s.usn})</li>`;
  });
  output += `</ul><a href="/">Go Back</a>`;

  res.send(output);
});

app.listen(3000);

//------------------------------------------------------
// company.html

<html>
  <h1>Submit Student Details</h1>
  <form action="/submit" method="get">
    USN: <input type="text" name="usn"><br>
    Name: <input type="text" name="name" ><br>
    Company: <input type="text" name="company" ><br>
    <button type="submit">Submit</button>
  </form>
</body>
</html>