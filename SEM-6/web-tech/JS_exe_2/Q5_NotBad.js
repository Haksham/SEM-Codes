function notBad(str) {
  let not = str.indexOf("not");
  let bad = str.indexOf("bad");

  if (not !== -1 && bad !== -1 && bad > not) {
    console.log(str.slice(0, not) + "good" + str.slice(bad + 3));
  }else{console.log(str);}
}

notBad('This dinner is not that bad!');
notBad('This movie is not so bad!');
notBad('This dinner is bad!');
