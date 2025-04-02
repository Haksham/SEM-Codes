const cart={
  a:1,
  b:2,
  c:3,
  d:4
}

function cashRegister(cart){
  let total=0;
  for(i in cart){
    total+=cart[i];
  }
  console.log("Sum: "+total);
}

cashRegister(cart);