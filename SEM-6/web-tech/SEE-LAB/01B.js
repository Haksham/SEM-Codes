
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit complaint.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('complaints')

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
  res.sendFile(path.join(__dirname, 'complaint.html'));
});

app.post('/insert', async (req, res) => {
  const { user_name, issue } = req.body; 
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('complaints');
  
  await collection.insertOne({ user_name, issue, status: 'pending' });
  await client.close()
  res.send("insert successful")
})

app.post('/update', async (req, res) => {
  const { user_name, status } = req.body;  
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('complaints');
  
  const result = await collection.findOneAndUpdate({ user_name: user_name },{ $set: { status } },{ returnDocument: 'after' })
  await client.close()
  res.send(result)
})

app.get('/pending', async (req, res) => {  
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('complaints');
  
  const result = await collection.find({ status: 'pending' }).toArray()
  await client.close()
  res.send(result)
})

app.listen(3000)

//--------------------------------------------
// complaint.html

<html>
<body>
  <h2>Submit a Complaint</h2>
  <form action="/insert" method="post">
    <input type="text" name="user_name" required placeholder="Your Name">
    <input type="text" name="issue" required placeholder="Issue"></input>
    <button type="submit">Submit</button>
  </form>

  <h2>Update Complaint Status</h2>
  <form action="/update" method="post">
    <input type="text" name="user_name" required placeholder="Complaint user">
    <select name="status">
      <option value="inprogress">In Progress</option>
      <option value="resolved">Resolved</option>
    </select>
    <button type="submit">Update</button>
  </form>

  <h2>View Pending Complaints</h2>
  <form action="/pending" method="get">
    <button type="submit">Load Pending</button>
  </form>
</body>
</html>