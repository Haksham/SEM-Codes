function FixStart(str){
  let ch=str[0];
  let res = ch + str.slice(1).split(ch).join("*");
  console.log(res);
}

FixStart("haphuih");