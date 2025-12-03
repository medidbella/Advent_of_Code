import { readFileSync } from "fs";

let input:string[] = readFileSync("input.txt", "ascii").split('\n')

let lineLength= input[0]!.length

function checkDept(digitCount:number, index:number):boolean{
	return (lineLength - index >= 12 - digitCount)
}

function Solver()
{
	let result:number = 0
	let index:number = 0
	let largest:string = ""
	let digit:string = '0'

	for (let j = 0; j < input.length;j++)
	{
		if (!input[j])
			continue
		index = -1
		largest = ""
		while (largest.length != 12)
		{
			digit = '0'
			for (let i = index+1;i < input[j]!.length && checkDept(largest.length, i); i++)
			{
				if (digit < input[j]![i]!){
					digit = input[j]![i]!
					index = i
				}
				if (input[j]![i]! == '9'){
					index = i
					break
				}
			}
			largest += digit
		}
		result += parseInt(largest)
	}
	console.log(result)
}
 
Solver()
