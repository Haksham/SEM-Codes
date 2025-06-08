
// install node_modules (folder)
// gedit server.js (add given content)
// mkdir views(folder)
// cd views
// gedit home.html registration.html contact.html announcements.html (add the respective given code below) 
// cd ..
// node server.js
// visit localhost:3000 (on any browser)


// ------------------------------------------------------

// server.js (content)

const express = require('express');
const app = express();
const path = require('path');
const PORT = 3000;

app.use(express.static(path.join(__dirname, 'views')));

app.get('/', (req, res) => { res.sendFile(path.join(__dirname, 'views', 'home.html'));});

app.get('/registration', (req, res) => {res.sendFile(path.join(__dirname, 'views', 'registration.html'));});

app.get('/announcements', (req, res) => {res.sendFile(path.join(__dirname, 'views', 'announcements.html'));});

app.get('/contact', (req, res) => {res.sendFile(path.join(__dirname, 'views', 'contact.html'));});

app.listen(PORT, () => {console.log(`Server running at http://localhost:${PORT}`);});

// ---------------------------------------------------------

// home.html

<html>
<body>
    <a href="/">Home</a>
    <a href="/registration">Register</a>
    <a href="/announcements">Announcements</a>
    <a href="/contact">Contact</a>
  <p>This is the home page.</p>
</body>
</html>

//------------------------------------------------------------
// announcements.html

<html>
<body>
    <a href="/">Home</a>
    <a href="/registration">Register</a>
    <a href="/announcements">Announcements</a>
    <a href="/contact">Contact</a>
  <p>This is the announcement page.</p>
</body>
</html>

// make similar contact.html and registration.html