function validateCreditCard(num) {
  let n = num.replaceAll("-", "").split("");
  let errors = [];
  let flag = n[0];
  let sum = 0;

  for (let i = 0; i < n.length; i++) {
    if (!(/\d/.test(n[i]))) {
      errors.push("Not completely digits.");
      break;
    }
    if (flag != n[i]) {
      flag = 1;
    }
    sum += parseInt(n[i]);
  }

  if (n.length !== 16) {errors.push("Not 16 digits.");}
  if (flag != 1) {errors.push("All digits are the same.");}
  if (n[n.length - 1] % 2 !== 0) {errors.push("Last digit is odd.");}
  if (sum <= 16) {errors.push("Invalid sum.");}

  if (errors.length === 0) {
    return { valid: true, message: "Valid credit card." };
  } else {
    return { valid: false, errors: errors };
  }
}

console.log(validateCreditCard("9999-9999-8888-0000")); 
console.log(validateCreditCard("1111-1111-1111-0110")); 
console.log(validateCreditCard("4444-4444-4444-4444")); 
console.log(validateCreditCard("1111-1111-1111-1113")); 
console.log(validateCreditCard("a923-3211-9c01-1112")); 