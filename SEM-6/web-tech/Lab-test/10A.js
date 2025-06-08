
// install node_modules (folder)
// gedit server.js (add given content)
// node server.js
// visit localhost:3000 (on any browser)
// also check the console for logs

//-----------------------------------------------------

// server.js
const express = require('express');
const app = express();

const visits = {};

app.use((req, res, next) => {
  const now = new Date();
  console.log(`[${now.toISOString()}] ${req.method} ${req.url}`);
  next();
});

app.use((req, res, next) => {
  const ip = req.ip;
  visits[ip] = (visits[ip] || 0) + 1;
  req.visitCount = visits[ip];
  next();
});

app.get('/', (req, res) => {res.send(`Welcome! You have visited ${req.visitCount} times.`);});

app.listen(3000);