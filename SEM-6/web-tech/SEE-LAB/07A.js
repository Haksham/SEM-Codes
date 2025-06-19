
// install node_modules (folder)
// gedit server.js (add given content)
// mkdir views(folder)
// cd views
// gedit cse.html ece.html me.html (add the respective given code below) 
// cd ..
// node server.js
// visit localhost:3000 (on any browser)

// ------------------------------------------------------------------------------------
// server.js

const express = require('express');
const path = require('path');
const app = express();

app.get('/', (req, res) => {
  res.send(`
    <h1>Engineering Branches</h1>
    <ul>
      <li><a href="/cse">(CSE)</a></li>
      <li><a href="/ece">(ECE)</a></li>
      <li><a href="/me">(ME)</a></li>
    </ul>
  `);
});

app.get('/cse', (req, res) => {
  res.sendFile(path.join(__dirname, 'views', 'cse.html'));
});

app.get('/ece', (req, res) => {
  res.sendFile(path.join(__dirname, 'views', 'ece.html'));
});

app.get('/me', (req, res) => {
  res.sendFile(path.join(__dirname, 'views', 'me.html'));
});

app.listen(3000);

// ------------------------------------------------------------------

// cse.html + ece.html + me.html
<html>
<head>
  <style>
    body {
      background-color: #cce6ff;
      font-family: 'Courier New', Courier, monospace;
      color: #003366;
      padding: 20px;
    }
  </style>
</head>
<body>
  <h1>Computer Science and Engineering (CSE)</h1>
  <a href="/">Home</a>
</body>
</html>

// make similar files for me.html , ece.html 
