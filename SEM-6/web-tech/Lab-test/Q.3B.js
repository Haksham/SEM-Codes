const express = require('express');
const app = express();
const { MongoClient } = require('mongodb');
const path = require('path');

const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'employee.html'));
});

app.get('/add-employee', async (req, res) => {
  const { emp_name, email, phone, hire_date, job_title, salary } = req.query;
  const parsedSalary = parseFloat(salary);

  if (!emp_name || !email || !phone || !hire_date || !job_title || isNaN(parsedSalary)) {
    return res.send('Invalid input');
  }

  let client;
  try {
    client = await MongoClient.connect(uri, { useUnifiedTopology: true });
    const db = client.db('HR');
    const collection = db.collection('employees');

    await collection.insertOne({
      emp_name,
      email,
      phone,
      hire_date,
      job_title,
      salary: parsedSalary
    });

    const highEarners = await collection.find({ salary: { $gt: 50000 } }).toArray();

    let responseHTML = `<h2>Employees with Salary > 50000</h2><ul>`;
    highEarners.forEach(emp => {
      responseHTML += `<li>${emp.emp_name} - ${emp.email} - ₹${emp.salary}</li>`;
    });
    responseHTML += `</ul>`;

    res.send(responseHTML);

  } catch (err) {
    console.error('Error:', err);
    res.status(500).send('Internal server error');
  } finally {
    if (client) await client.close();
  }
});

app.listen(5009, () => {
  console.log('Server running on http://localhost:5009');
});
