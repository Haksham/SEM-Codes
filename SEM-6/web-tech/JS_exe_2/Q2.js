function mixUp(str1,str2){
  let str3=str1.slice(0,2)+str2.slice(2,str2.length)+" "+str2.slice(0,2)+str1.slice(2,str1.length);
  console.log(str3);
}

mixUp("hell","bepp");