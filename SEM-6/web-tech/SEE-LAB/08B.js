
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit product.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use mydb
// db.createCollection('product')

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
  res.sendFile(path.join(__dirname, 'product.html'));
});

app.get('/insert', async (req, res) => {
  const { id,name,price,discount,stock } = req.query; 
  const client = await MongoClient.connect(uri);
  const collection = client.db('mydb').collection('product');
  
  const parsedPrice = parseFloat(price);
  const parsedDiscount = parseFloat(discount);
  const finalPrice = parsedPrice - (parsedPrice * parsedDiscount / 100);
  
  await collection.insertOne({ id,name,price: parsedPrice, discount: parsedDiscount, stock, final:finalPrice });
  const result = await collection.find({final: {$lte: 1000}}).toArray();
  await client.close()
  res.send(result)
})

app.listen(3000)

//---------------------
// product.html
<html>
<body>
  <h2>Insert Product</h2>
  <form action="/insert" method="get">
    <input type="text" name="id" placeholder="Product ID" required><br>
    <input type="text" name="name" placeholder="Product Name" required><br>
    <input type="number" name="price" placeholder="Price" required><br>
    <input type="number" name="discount" placeholder="Discount (%)" required><br>
    <input type="number" name="stock" placeholder="Stock Quantity" required><br>
    <button type="submit">Add Product</button>
  </form>
</body>
</html>