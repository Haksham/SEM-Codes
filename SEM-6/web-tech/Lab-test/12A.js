
// install node_modules (folder)
// gedit stack.js queue.js server.js (add the below provided content)
// node server.js

// ----------------------------------------------------
// stack.js

export class Stack {
    constructor() { this.items = [];}

  push(element) {this.items.push(element);}
  pop() {
    if (this.isEmpty()) {return null;}
    return this.items.pop();
  }
  peek() {
    if (this.isEmpty()) {return null;}
    return this.items[this.items.length - 1];
  }
  isEmpty() {return this.items.length === 0;}
  size() {return this.items.length;}
}

// ----------------------------------------------------------
// queue.js

export class Queue {
  constructor() { this.items = [];}

  enqueue(element) {this.items.push(element);}

  dequeue() {
    if (this.isEmpty()) {return null;}
    return this.items.shift();
  }
  front() {
    if (this.isEmpty()) {return null;}
    return this.items[0];
  }
  isEmpty() { return this.items.length === 0;}
  size() {return this.items.length;}
}

// -------------------------------------------------------------
// server.js

import { Stack } from './stack.js';
import { Queue } from './queue.js';

const stack = new Stack();
stack.push(10);
stack.push(20);
stack.push(30);
console.log('Stack size:', stack.size());
console.log('Stack peek:', stack.peek());
console.log('Stack pop:', stack.pop());
console.log('Stack after pop:', stack.items);

const queue = new Queue();
queue.enqueue('a');
queue.enqueue('b');
queue.enqueue('c');
console.log('Queue size:', queue.size());
console.log('Queue front:', queue.front());
console.log('Queue dequeue:', queue.dequeue());
console.log('Queue after dequeue:', queue.items);