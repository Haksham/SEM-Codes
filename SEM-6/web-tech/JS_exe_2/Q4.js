function verbing(str){
  let res=""

  if(str.length<=2){res=str;}
  else if(str.slice(str.length-3,str.length)==="ing"){
    res=str.slice(0,str.length-3)+"ly";
  }
  else{res=str+"ing";}

  console.log(res);
}

verbing('good');
verbing("making");
verbing("lo");