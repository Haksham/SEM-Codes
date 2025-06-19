
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit records.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('records')

//--------------------------------------
// server.js
const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'records.html'));
});

app.get('/insert', async (req, res) => {
  const { name,usn,dept,grade } = req.query; 
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('records');
  
  await collection.insertOne({ name,usn,dept,grade });
  const result = await collection.find().toArray();
  await client.close()
  res.send(result)
})

app.post('/update', async (req, res) => {
  const { name, grade } = req.body;  
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('records');
  
  const result = await collection.findOneAndUpdate({ name: name },{ $set: { grade } },{ returnDocument: 'after' })
  await client.close()
  res.send(result)
})

app.listen(3000)

//--------------------------------------
// records.html
<html>
<body>
  <h2>Add Student Record</h2>
  <form action="/insert" method="get">
    <input type="text" name="name" placeholder="Name" required><br>
    <input type="text" name="usn" placeholder="USN" required><br>
    <input type="text" name="dept" placeholder="Department" required><br>
    <input type="text" name="grade" placeholder="Grade" required><br>
    <button type="submit">Insert Record</button>
  </form>

  <h2>Update Grade by Name</h2>
  <form action="/update" method="post">
    <input type="text" name="name" placeholder="Name" required><br>
    <input type="text" name="grade" placeholder="New Grade" required><br>
    <button type="submit">Update Grade</button>
  </form>
</body>
</html>