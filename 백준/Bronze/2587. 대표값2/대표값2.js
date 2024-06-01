let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let numbers = [];
let average = 0;

for (let i = 0; i < input.length; i++) {
  if (input[i] !== '') {
    numbers.push(Number(input[i]));
    average += Number(input[i]);
  }
}

average /= 5;
numbers = numbers.sort();

console.log(average);
console.log(numbers[2]);