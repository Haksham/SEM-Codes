const getMonthNameConverter = () => {
  const monthNames = [
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  ];
  return function(monthInput) {
    const parsedNumber = parseFloat(monthInput);
    if (isNaN(parsedNumber)) return "Bad Number";
    const monthNumber = Math.floor(parsedNumber);
    if (monthNumber < 1 || monthNumber > 12) return "Bad Number";
    return monthNames[monthNumber - 1];
  };
};

const convertMonth = getMonthNameConverter();

console.log(convertMonth("3"));
console.log(convertMonth("7.9"));
console.log(convertMonth("0")); 
console.log(convertMonth("13")); 
console.log(convertMonth("abc"));

// node Q.2A.js