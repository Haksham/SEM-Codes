const convert = () => {
  const list = [
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  ];
  return function(month) {
    const res = Math.floor(month);
    if (isNaN(res) || res < 1 || res > 12) return "Bad Number";
    return list[res - 1];
  };
};

const convertMonth = convert();

console.log(convertMonth("3"));
console.log(convertMonth("7.9"));
console.log(convertMonth("0")); 
console.log(convertMonth("13")); 
console.log(convertMonth("abc"));

// node Q.2A.js