const express=require('express');
const app=express();
const { MongoClient }=require('mongodb');
const path=require('path');

const uri = 'mongodb://127.0.0.1:27017';

app.get('/',(req,res)=>{
	res.sendFile(path.join(__dirname,'1b.html'));
});

app.get('/insert', async (req, res) => {
  const { name, usn, scode, marks } = req.query;
  const parsedMarks = parseInt(marks);

  if (!usn || !name || !scode || isNaN(parsedMarks)) {
    return res.send('Invalid input');
  }

  let client;
  try{
  	client = await MongoClient.connect(uri, { useUnifiedTopology: true });
    	const db = client.db('mydb');
    	const collection = db.collection('student');
    	
    	await collection.insertOne({ usn, name, scode, marks: parsedMarks });
    	
    	const lowScorers = await collection.find({ marks: { $lt: 20 } }).toArray();
    	
    	console.log('Students with marks < 20:', lowScorers);
    	res.json(lowScorers);

  } catch (err) {
    	console.error('Error:', err);
    	res.status(500).send('Internal server error');
  } finally {
    	if (client) {
      	await client.close();
    	}
  }
});

app.listen(5000, () => {
  console.log('Listening on port 5000');
});

// p1.html (make a "hello world" file)
// Node (current js)
// Mongo Node (file)