const movie = {
  title: 'pol',
  duration: 3,
  stars: ['p', 'j', 't']
};
function printMovieInfo(movie) {
  const ls = movie.stars.join(', ');
  console.log(`${movie.title} lasts for ${movie.duration} minutes. Stars: ${ls}.`);
}

printMovieInfo(movie);