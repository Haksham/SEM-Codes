
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit startup.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('startup')

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
  res.sendFile(path.join(__dirname, 'a1.html'));
});

app.get('/insert', async (req, res) => {
  const { id,team,title,domain,funding } = req.query; 
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('startup');
  const parsedFund = parseFloat(funding);
  
  await collection.insertOne({ id,team,title,domain,funding: parsedFund });
  const result = await collection.find({domain:"edtech" , funding: {$gte: 500000}}).toArray();
  await client.close()
  res.send(result)
})

app.listen(3000)

//----------------------------------------
// startup.html
<html>
<body>
  <h2>Submit a Startup</h2>
  <form action="/insert" method="get">
    <input type="text" name="id" placeholder="Startup ID" required><br>
    <input type="text" name="team" placeholder="Team Name" required><br>
    <input type="text" name="title" placeholder="Startup Title" required><br>
    <input type="text" name="domain" placeholder="Domain" required><br>
    <input type="number" name="funding" placeholder="Funding Amount (INR)" required><br>
    <button type="submit">Submit</button>
  </form>
</body>
</html>