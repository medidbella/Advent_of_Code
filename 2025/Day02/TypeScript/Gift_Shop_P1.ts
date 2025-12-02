import { readFileSync } from "node:fs";

function Solver(input: string):number
{
	let counter:number = 0
	let num1 = parseInt(input.split('-')[0]!)
	let num2 = parseInt(input.split('-')[1]!)
	let asciiNum:string
	while (num1 <= num2)
	{
		asciiNum = String(num1)
		if (asciiNum.length % 2){
			num1++;
			continue;
		}
		if (asciiNum.slice(0, asciiNum.length/2) == asciiNum.slice(asciiNum.length/2)){
			counter += num1;
		}
		num1++
	}
	return counter;
}

let input: string[] = readFileSync("input.txt", "ascii").split(',')
let result:number = 0

input.forEach(element => {
	result += Solver(element)
});

console.log(result)