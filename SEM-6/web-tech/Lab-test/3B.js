
// install the node_modules + node_mongo_2025 folder from server
// gedit server.js
// gedit employee.html
// node server.js
// Open browser and go to http://localhost:3000

// for mongodb>>

// sudo systemctl start mongod
// sudo systemctl enable mongod
// mongosh
// use HR
// db.createCollection('employees')

// no need to insert data manually, it will be done through the form

//-------------------------------------------------------------
// server.js
const express = require('express');
const { MongoClient } = require('mongodb');
const path = require('path');
const app = express();
const uri = 'mongodb://127.0.0.1:27017';

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'employee.html'));
});

app.get('/add-employee', async (req, res) => {
  const { emp_name, email, phone, hire_date, job_title, salary } = req.query;
  const parsedSalary = parseFloat(salary);

  const client = await MongoClient.connect(uri);
  const db = client.db('HR');
  const employees = db.collection('employees');
  await employees.insertOne({emp_name, email, phone, hire_date, job_title,salary: parsedSalary});
  const results = await employees.find({ salary: { $gt: 50000 } }).toArray();

  let html = `<h2>Employees with Salary > 50000</h2><ul>`;
  for (const emp of results) {
    html += `<li>${emp.emp_name} - ${emp.email} - ₹${emp.salary}</li>`;
  }
  html += `</ul>`;

  res.send(html);
  await client.close();
});

app.listen(3000);

//-------------------------------------------------------------
// employee.html

<html>
<body>
  <h1>Add Employee</h1>
  <form action="/add-employee" method="get">
    <label>Name: <input type="text" name="emp_name" required></label><br>
    <label>Email: <input type="email" name="email" required></label><br>
    <label>Phone: <input type="text" name="phone" required></label><br>
    <label>Hire Date: <input type="date" name="hire_date" required></label><br>
    <label>Job Title: <input type="text" name="job_title" required></label><br>
    <label>Salary: <input type="number" name="salary" required></label><br><br>
    <button type="submit">Submit</button>
  </form>
</body>
</html>
