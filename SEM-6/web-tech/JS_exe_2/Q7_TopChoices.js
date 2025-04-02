function topChoices(){
  const choice=["a","b","c","d"];
  const suffix=["st","nd","rd"];
  for(let i=0;i<choice.length;i++){
    if(i<3){console.log(`My ${i+1}${suffix[i]} choice is ${choice[i]}`);}
    else{console.log(`My ${i+1}th choice is ${choice[i]}`);}
  }
}
topChoices();