file_name = "input_Red-Nosed_Reports_P1.txt"

try:
    with open(file_name, "r") as file:
        safe = 0
        while True:
            line = file.readline()
            if not line:
                break
            splited = list(map(int, line.split()))
            is_increase = True
            is_safe = True
            if (splited[0] > splited[1]):
                is_increase = False
            for i in range(1, len(splited)):
                if (is_increase):
                    if (splited[i] <= splited[i - 1] or splited[i] - splited[i - 1] > 3):
                        is_safe = False
                        break
                else:
                    if (splited[i] >= splited[i - 1] or splited[i - 1] - splited[i] > 3):
                        is_safe = False
                        break
            
            if (is_safe):
                safe += 1
        
        print(safe)
        

except:
    print("Error")