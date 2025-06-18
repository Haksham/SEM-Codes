function pluralize(noun,num){
  if(num==1){console.log(num+" : "+noun);}
  else{
    if(noun=="sheep"){
      console.log(num+" : "+noun);
    }
    else if(noun=="geese"){
      console.log(num+" : "+"goose");
    }else{
      console.log(num+" : "+noun+"s");}
    }
}

pluralize("cat", 1);
pluralize("dog", 5);
pluralize("car", 0);
pluralize("geese",4);
pluralize("sheep",3);