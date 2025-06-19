
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit enroll.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('enroll')

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
  res.sendFile(path.join(__dirname, 'enroll.html'));
});

app.get('/insert', async (req, res) => {
  const { id,name,course,duration,status } = req.query; 
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('enroll');
  
  await collection.insertOne({ id,name,course,duration, status: 'active' });
  const result = await collection.find({status:"active"}).toArray();
  await client.close()
  res.send(result)
})

app.post('/update', async (req, res) => {
  const { id, name } = req.body;  
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('enroll');
  
  const result = await collection.findOneAndUpdate({ id: id , name: name },{ $set: {status :"completed"}},{ returnDocument: 'after' })
  await client.close()
  res.send(result)
})

app.listen(3000)

//-------------------------------------------
// enroll.html

<html>
<body>
  <h2>Insert Intern Enrollment</h2>
  <form action="/insert" method="get">
    <input type="text" name="id" placeholder="ID" required><br>
    <input type="text" name="name" placeholder="Name" required><br>
    <input type="text" name="course" placeholder="Course" required><br>
    <input type="text" name="duration" placeholder="Duration" required><br>
    <input type="hidden" name="status" value="pending">
    <button type="submit">Insert</button>
  </form>

  <h2>Update Intern Status</h2>
  <form action="/update" method="post">
    <input type="text" name="id" placeholder="Intern ID" required><br>
    <input type="text" name="name" placeholder="Updated Name" required><br>
    <button type="submit">Mark as Completed</button>
  </form>
</body>
</html>