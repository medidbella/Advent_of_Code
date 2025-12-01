import { readFileSync } from "node:fs";

class CircularBuffer
{
	#num: number;
	#limit: number;
	
	constructor(limit:number = 100, start_with:number = 50)
	{
		this.#limit = limit
		this.#num = start_with
	}

	RotateLeft(distance:number): void{
		this.#num = (this.#num - distance + this.#limit) % this.#limit;
	}
	RotateRight(distance: number): void
	{
		this.#num += distance
		if (this.#num >= this.#limit)
			this.#num %= this.#limit
	}
	
	get value(): number
	{
		return this.#num;
	}
}

function ApplyRotation(direction:string | undefined, distance:string | undefined , safeDial:CircularBuffer):number
{
	console.log(`d: ${direction}, dist:${distance}`)
	if (!direction || !distance)
	{
		console.log("unexpected: "+ `d: ${direction}, dist:${distance}`);
		return 0
	}
	if (direction == "L")
		safeDial.RotateLeft(parseInt(distance))
	else if (direction == "R")
		safeDial.RotateRight(parseInt(distance))
	console.log("dial value:", safeDial.value)
	return +(safeDial.value == 0)
}

function Solver(input:string[], safeDial:CircularBuffer):number
{
	let result = 0
	for (let i:number = 0; i < input.length; i++)
	{
		if (!input.at(i))
			continue ;
		result += ApplyRotation(input[i]?.at(0), input[i]?.slice(1), safeDial)
	}
	return result
}

let safeDial = new CircularBuffer
const puzzle_input:string[] = readFileSync("input.txt", "ascii").split('\n');
console.log(Solver(puzzle_input, safeDial))