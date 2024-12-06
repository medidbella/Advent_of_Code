file_name = "input_Historian_Hysteria_P1.txt"

try:
    with open(file_name, "r") as file:
        first_column = []
        second_column = []
        while True:
            line = file.readline()
            if not line:
                break
            x, y = map(int, line.split())
            first_column.append(x)
            second_column.append(y)
        
        first_column.sort()
        second_column.sort()

        Sum = 0
        for i in range(len(first_column)):
            Sum += abs(first_column[i] - second_column[i])
        
        print(Sum)

except:
    print("Error")