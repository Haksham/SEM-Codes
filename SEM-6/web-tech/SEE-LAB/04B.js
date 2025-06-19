
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit intern.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('intern')

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
  res.sendFile(path.join(__dirname, 'intern.html'));
});

app.get('/insert', async (req, res) => {
  const { Sid,name,company,duration,status } = req.query; 
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('intern');
  
  await collection.insertOne({ Sid,name,company,duration, status: 'pending' });
  const result = await collection.find({company:"infosys"}).toArray();
  await client.close()
  res.send(result)
})

app.post('/update', async (req, res) => {
  const { Sid, status } = req.body;  
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('intern');
  
  const result = await collection.findOneAndUpdate({ Sid: Sid },{ $set: { status } },{ returnDocument: 'after' })
  await client.close()
  res.send(result)
})

app.listen(3000)

//---------------------------------------
// intern.html
<html>
<body>
  <h2>Add Internship</h2>
  <form action="/insert" method="get">
    <input type="text" name="Sid" placeholder="Student ID" required><br>
    <input type="text" name="name" placeholder="Name" required><br>
    <input type="text" name="company" placeholder="Company" required><br>
    <input type="text" name="duration" placeholder="Duration" required><br>
    <input type="text" name="status" placeholder="Status" value="pending" readonly><br>
    <button type="submit">Add Internship</button>
  </form>

  <h2>Update Internship Status</h2>
  <form action="/update" method="post">
    <input type="text" name="Sid" placeholder="Student ID" required><br>
    <select name="status" required>
      <option value="pending">Pending</option>
      <option value="inprogress">In Progress</option>
      <option value="completed">Completed</option>
    </select><br>
    <button type="submit">Update Status</button>
  </form>
</body>
</html>