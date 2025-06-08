
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit mks.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('mks')

// no need to insert any data manually, the server will handle it

// ----------------------------------------------
// server.js

const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'mks.html'));
});

app.get('/submit', async (req, res) => {
  const { name, usn, mks } = req.query;
  const mksNum = parseFloat(mks);
  const client = await MongoClient.connect(uri);
  const db = client.db("mydb");
  const collection = db.collection("mks");

  await collection.insertOne({ name, usn, mks: mksNum });
  const lowMks = await collection.find({ mks: { $lt: 20 } }).toArray();
  await client.close();

  let html = '<h2>Students with mks below 20</h2><ul>';
    lowMks.forEach(s => {
      html += `<li>Name: ${s.name}, USN: ${s.usn}, mks: ${s.mks}%</li>`;
    });
  html += '</ul><a href="/">Go back</a>';
  res.send(html);
});

app.listen(3000);


// ----------------------------------------------
// mks.html

<html>
<body>
	<form action="/submit" method="get">
	Name:<input type="text" name="name"/>
	USn:<input type="text" name="usn"/>
	mks:<input type="number" name="mks"/>
	<button type="submit">Enter</button>
	</form>
</body>
</html>