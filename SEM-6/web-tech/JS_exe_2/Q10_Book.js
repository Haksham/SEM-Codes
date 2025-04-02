const books = [
  { title: 'a', author: 'x', read: true },
  { title: 'b', author: 'y', read: false },
  { title: 'c', author: 'z', read: true },
  { title: 'd', author: 'w', read: false }
];
books.forEach(book => {
  if (book.read) {
    console.log(`You already read "${book.title}" by ${book.author}`);
  } else {
    console.log(`You still need to read "${book.title}" by ${book.author}.`);
  }
});
