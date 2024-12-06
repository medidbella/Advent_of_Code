file_name = "input_Historian_Hysteria_P2.txt"

try:
    with open(file_name, "r") as file:
        first_column = []
        second_column = {}
        while True:
            line = file.readline()
            if not line:
                break
            x, y = map(int, line.split())
            first_column.append(x)
            if (not y in second_column):
                second_column[y] = 0
            second_column[y] += 1
        
        Sum = 0
        for x in first_column:
            if x in second_column:
                Sum += x * second_column[x]

        print(Sum)

except:
    print("Error")