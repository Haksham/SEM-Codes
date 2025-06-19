
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit hospital.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('hospital')

//--------------------------------------
// server.js
const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.use(express.urlencoded({ extended: true }));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'hospital.html'));
});

app.post('/admit', async (req, res) => {
  const { Hospital_ID, Name, Location, Total_Beds, Occupied_Beds } = req.body;
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('hospitals');

  if (Name) {
    await collection.insertOne({ Hospital_ID, Name, Location, Total_Beds: parseInt(Total_Beds), Occupied_Beds: parseInt(Occupied_Beds),});
    res.send('Hospital data added');
  } else {
    await collection.updateOne({ Hospital_ID }, { $inc: { Occupied_Beds: 1 }});
    res.send('Patient admitted');
  }

  await client.close();
});

app.get('/critical', async (req, res) => {
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('hospitals');
  const result = await collection.find({ $expr: { $lt: [{ $subtract: ['$Total_Beds', '$Occupied_Beds'] }, 10] }}).toArray();
  await client.close();
  res.send(result);
});

app.listen(3000);

//-------------------------------------------
// hospital.html

<html>
<body>
  <h3>Add Hospital</h3>
  <form action="/admit" method="post">
    <input name="Hospital_ID" placeholder="Hospital ID" required><br>
    <input name="Name" placeholder="Name" required><br>
    <input name="Location" placeholder="Location" required><br>
    <input name="Total_Beds" placeholder="Total Beds" type="number" required><br>
    <input name="Occupied_Beds" placeholder="Occupied Beds" type="number" required><br>
    <button type="submit">Add Hospital</button>
  </form>

  <h3>Admit Patient</h3>
  <form action="/admit" method="post">
    <input name="Hospital_ID" placeholder="Hospital ID" required><br>
    <button type="submit">Admit</button>
  </form>

  <h3>Show Hospitals with less than 10 Beds</h3>
  <form action="/critical" method="get">
    <button type="submit">View</button>
  </form>
</body>
</html>