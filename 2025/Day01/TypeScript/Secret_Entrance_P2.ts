import { readFileSync } from "node:fs";

class CircularBuffer
{
	#num: number;
	#limit: number;
	#loop_counter:number;

	constructor(limit:number = 100, start_with:number = 50)
	{
		this.#loop_counter = 0
		this.#limit = limit
		this.#num = start_with
	}

	RotateLeft(distance:number): void
	{
		let tmp:number = this.#num - distance 
		if (tmp <= 0)
			this.#loop_counter = this.#loop_counter + Math.floor(tmp * -1 / this.#limit) + +(this.#num != 0)
		this.#num = (this.#num - distance % this.#limit + this.#limit) % this.#limit;
	}

	RotateRight(distance: number): void
	{
		this.#num += distance
		this.#loop_counter = this.#loop_counter + Math.floor(this.#num / this.#limit);
		if (this.#num >= this.#limit)
			this.#num %= this.#limit
	}
	
	get value(): number{
		return this.#num;
	}

	get counter():number{
		return this.#loop_counter;
	}
}

function Solver(input:string[], safeDial:CircularBuffer):void
{
	for (let i:number = 0; i < input.length; i++)
	{
		if (!input[i]?.at(0))
			continue
		if (input[i]?.at(0) == 'R')
			safeDial.RotateRight(parseInt(input[i]!.slice(1)))
		else if (input[i]?.at(0) == 'L')
			safeDial.RotateLeft(parseInt(input[i]!.slice(1)))
	}
}

let safeDial = new CircularBuffer()

const puzzle_input:string[] = readFileSync("input.txt", "ascii").split('\n');

Solver(puzzle_input, safeDial)

console.log(safeDial.counter)
