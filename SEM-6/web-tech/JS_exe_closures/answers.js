// Harshvardhan Mehta
// 1MS22CS062 , 6th B

// QP1

/* 
1. A closure in JavaScript is a function that “remembers” the environment in which it was created. In other words, a closure gives you access to variables from an outer (enclosing) function’s scope, even after that outer function has finished running.
2. Closures are possible because of JavaScript’s lexical scope. Lexical scope means that the way code is written (its location in the source) determines which variables are visible. When a function is defined inside another function, it lexically “closes over” the surrounding variables. Even if the outer function returns and its local variables would normally disappear, any inner function that forms a closure still holds references to those variables.
3. Real-world example: Data privacy. Suppose we want a counter that can only be changed by calling specific methods. You can write a function createCounter that defines a private variable count and returns two inner functions: increment and getCount. These inner functions form closures over count. Because they hold the reference, you can call increment() to change it and getCount() to read it, but no code outside can directly alter count. This pattern keeps count private and prevents unwanted modification.
By using closures, we encapsulate data and control how it is accessed or modified. This is especially useful in event handlers, modular code, and anywhere we need to maintain state without exposing it globally.
*/

function makeCounter() {
    let count = 0;

    return function () { // returned function forms a closure over the count variable
        count++;
        return count;
    };
}
const counter = makeCounter();  // defining the counter
console.log(counter());
console.log(counter());
console.log(counter());

// Q.2

function createGreeter(name){  // name is used by the inner function
    return function(){
        return `Welcome ${name}, as a user.`;
    };
}
const greet1=createGreeter('Harsh');  // examples cases
const greet2=createGreeter('Joy');
console.log(greet1());
console.log(greet2());

// Q.3

function multiplierFactory(factor){// creat different functions using closure 
    return function(num){
        return factor*num;
    };
}

const a=multiplierFactory(2); // examples cases, defining factors
const b=multiplierFactory(3);
const c= multiplierFactory(4);

console.log(a(10)); // defining numbers
console.log(b(20));
console.log(c(30));


// QP2
/*
A. 
> Closures differ from plain global or local variables because they bundle a function together with its surrounding lexical environment. A local variable in a function normally disappears when the function returns, and a global variable is accessible everywhere (risking unwanted modifications). A closure, by contrast, “remembers” the local variables of its outer function even after that function has finished executing, while keeping those variables hidden from the rest of the program.
> In the counter example, using a closure means the internal count variable is private: only the returned increment() and getCount() functions can access or modify it. If you had used a global variable, any code anywhere could change count, leading to bugs or security issues. The closure ensures controlled access, encapsulation, and avoids polluting the global namespace.
B.
> In Exercise 3, each call to multiplierFactory(factor) creates a new execution context with its own factor variable. The returned inner function forms a closure over that specific factor, so each multiplier function retains its unique value even after the factory call ends. Internally, JavaScript preserves the environment where the function was defined, binding factor into the function instance.
> If factor were a global variable instead, every multiplier function would reference the same shared variable. Changing the global factor would affect all multiplier functions, and they would no longer behave independently. You’d lose the ability to have separate “double,” “triple,” or “half” behaviors—each function would always use whatever the current global factor happens to be.
*/

// Q.4

function makeFibonacci() {
    const cache={0:0,1:1}; // cache initialize as obj.
  
    return function fib(n) {
      if(n<0){throw new Error('negative integer !!!');}

      if (cache[n]!==undefined) {
        return cache[n]; // check if present in cache
      }
      cache[n]=fib(n-1)+fib(n-2); // calc and storing in cache
      return cache[n];
    };
  }
  const fibonacci=makeFibonacci();
  console.log(fibonacci(6));
  console.log(fibonacci(6)); // cached
  console.log(fibonacci(7)); // cached till f(6)

// Q.5

function createTodoModule(){
    let task=[];
    return{
        add(item){task.push(item);},  // add a item
        remove(i){task.splice(i,1);}, // remove from index
        clear(){task=[];},  // clear list which is not const
        show(){console.log(task);} // display list
    };
}

const m1=createTodoModule();
m1.add("one");
m1.add("two");
m1.add("three");
m1.show();
m1.remove(0);
m1.show();
m1.clear();
m1.show();
console.log(m1.task); // hidden task array