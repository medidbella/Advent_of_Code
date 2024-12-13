file_name = "input_Red-Nosed_Reports_P2.txt"

try:
    with open(file_name, "r") as file:
        safe = 0
        while True:
            line = file.readline()
            if not line:
                break
            sp = list(map(int, line.split()))
            for i in range(0, len(sp)):
                splited = sp.copy()
                splited.pop(i)
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
                    break
        
        print(safe)
        

except:
    print("Error")