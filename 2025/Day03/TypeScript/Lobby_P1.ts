import { readFileSync } from "fs";

let input:string[] = readFileSync("input.txt", "ascii").split('\n')
type digit = {num:string; index:number}


function Solver()
{
	let result:number = 0
	let largest:digit = { num: '0', index: 0 }
	let secLargest:digit = { num: '0', index: 0 }

	for (let j = 0; j < input.length;j++)
	{
		if (!input[j])
			continue
		largest = { num: '0', index: 0 }
		secLargest = { num: '0', index: 0 }
		for (let i = 0; i < input[j]!.length; i++)
		{
			if (input[j]![i]! > largest.num){
				secLargest.num = largest.num
				secLargest.index = largest.index
				largest.index = i
				largest.num = input[j]![i]!
			}
			else if (input[j]![i]! > secLargest.num){
				secLargest.num = input[j]![i]!
				secLargest.index = i
			}
		}
		if (largest.index < secLargest.index || largest.num == secLargest.num)
			result += parseInt(largest.num + secLargest.num)
		else if (largest.index == input[j]!.length - 1)
			result += parseInt(secLargest.num + largest.num)
		else {
			secLargest.num = input[j]![largest.index + 1]!
			for (let k=largest.index + 1; k < input[j]!.length; k++)
				if (secLargest.num < input[j]![k]!)
					secLargest.num = input[j]![k]!
			result += parseInt(largest.num + secLargest.num)
		}
	}
	console.log(result)
}

Solver()
