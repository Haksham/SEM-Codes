
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit faculty.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('faculty')

// no need to insert any data manually, the server will handle it

// --------------------------------------------------------

// server.js

const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'faculty.html'));
});

app.get('/submit', async (req, res) => {
  const { ID, Title, Name, branch } = req.query;
  const client = await MongoClient.connect(uri);
  const db = client.db("mydb");
  const collection = db.collection("faculty");

  await collection.insertOne({ ID, Title, Name, branch });
  const professors = await collection.find({ branch: /cse/i, Title: /professor/i }).toArray();
  await client.close();

  let html = `<h2>CSE Professors</h2><ul>`;
  professors.forEach(faculty => {
      html += `<li>ID: ${faculty.ID}, Name: ${faculty.Name}, Title: ${faculty.Title}, Branch: ${faculty.branch}</li>`;
    });
  html += `</ul><a href="/">Go back</a>`;
  res.send(html);
});

app.listen(3000);

// -------------------------------------------------------------

// faculty.html

<html>
<body>
  <h1>Enter Faculty Details</h1>
  <form action="/submit" method="get">
    ID: <input type="text" name="ID"><br>
    Title: <input type="text" name="Title" ><br>
    Name: <input type="text" name="Name" ><br>
    Branch: <input type="text" name="branch" ><br>
    <button type="submit">Submit</button>
  </form>
</body>
</html>