function recipe(){
  const rec={
    "title":"Mole",
    "servings":5,
    "ingredients":["a","b","c","d"]
  }

  for (let key in rec) {
    if(Array.isArray(rec[key])){
      console.log(key+":");
      for(let i=0;i<rec[key].length;i++){

        console.log(rec[key][i]);
      }
    }else{
      console.log(`${key}:${rec[key]}`);
    }
  }
}

recipe();