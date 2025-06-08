
// install node_modules (folder)
// gedit server.js (add given content)
// mkdir views(folder)
// cd views
// gedit home.html Registration.html contact.html (add the respective given code below) 
// cd ..
// node server.js
// visit localhost:3000 (on any browser)

// ---------------------------------------------------
// server.js

const express = require('express');
const path = require('path');
const app = express();

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'views', 'home.html'));
});

app.get('/register', (req, res) => {
  res.sendFile(path.join(__dirname, 'views', 'register.html'));
});

app.get('/contact', (req, res) => {
  res.sendFile(path.join(__dirname, 'views', 'contact.html'));
});

app.listen(3000);


// ----------------------------------------------------

// home.html

<html>
<body>
  <h1>Welcome to Online Training Home page</h1>
  <a href="/register">Go to Registration</a><br />
  <a href="/contact">Go to Announcements & Contact</a>
</body>
</html>

// -------------------------------------------------------

// Registration.html

<html>
<body>
  <h1>Registration Page</h1>
  <a href="/">Back to Home</a>
</body>
</html>

// -----------------------------------------------------

// contact.html

<html>
<body>
  <h3>Contact Us</h3>
  <a href="/">Back to Home</a>
</body>
</html>