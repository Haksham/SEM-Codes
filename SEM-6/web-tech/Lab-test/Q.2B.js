const express = require('express');
const app = express();
const { MongoClient } = require('mongodb');
const path = require('path');

const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'examfee.html'));
});

app.get('/submit', async (req, res) => {
  const { student_name, usn, semester, exam_fee } = req.query;
  const parsedFee = parseInt(exam_fee);

  if (!student_name || !usn || !semester || isNaN(parsedFee)) {
    return res.send('Invalid input');
  }

  let client;
  try {
    client = await MongoClient.connect(uri, { useUnifiedTopology: true });
    const db = client.db('mydb');
    const collection = db.collection('exam_fee');

    await collection.insertOne({ student_name, usn, semester, exam_fee: parsedFee });

    const deleteResult = await collection.deleteMany({ exam_fee: { $lte: 0 } });

    const remainingStudents = await collection.find().toArray();

    res.send({
      message: `Deleted ${deleteResult.deletedCount} students who did not pay the exam fee.`,
      remaining: remainingStudents
    });

  } catch (err) {
    console.error('Error:', err);
    res.status(500).send('Internal server error');
  } finally {
    if (client) await client.close();
  }
});

app.listen(5008, () => {
  console.log('Listening on port 5008');
});
