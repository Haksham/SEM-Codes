function createTaxCalculator(taxRate) {
  return function(price) {
    return price + (price * taxRate);
  };
}

const gstCalculator = createTaxCalculator(0.18); 
console.log(gstCalculator(1000)); 

// createTaxCalculator is a closure that takes a tax rate (like 0.18 for 18%).

// It returns another function that, when called with a price, calculates the net price including tax.