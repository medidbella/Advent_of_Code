import { accessSync, readFileSync } from "node:fs";

function SetDivisors(size:number, divisors: number[]):void
{
	divisors.length = 0
	divisors.push(1);
	for (let i = 2; i <= Math.floor(size / 2); i++){
		if (size % i === 0)
			divisors.push(i);
	}
}

function CheckSequence(sequence:string, divisors:number[]):boolean
{
	let first:number = 0, second:number = 0

	for (let i:number = 0; i < divisors.length; i++)
	{
		first = 0
		second = divisors[i]!
		while (second < sequence.length)
		{
			if (sequence[first] != sequence[second])
					break;
			first++;
			second++;
			if (second == sequence.length)
				return true
		}
	}
	return false;
}

function Solver(input: string):number
{
	let counter:number = 0
	let num1 = parseInt(input.split('-')[0]!)
	let num2 = parseInt(input.split('-')[1]!)
	let asciiNum:string
	let divisors:number[] = []
	let currentLen:number = 0

	while (num1 <= num2)
	{
		asciiNum = String(num1)
		if (currentLen != asciiNum.length){
			SetDivisors(asciiNum.length, divisors)
			currentLen = asciiNum.length
		}
		if (CheckSequence(asciiNum, divisors))
			counter += num1
		num1++
	}
	return counter
}
let input: string[] = readFileSync("input.txt", "ascii").split(',')
let result:number = 0

input.forEach(element => {
	result += Solver(element)
});

console.log(result)
