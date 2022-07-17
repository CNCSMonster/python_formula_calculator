#基本运算模块
def cal_once(num_stack, cal_stack):
    # print("计算前num_stack为:",num_stack)
    # print("计算前cal_satck为:",cal_stack)
    num2 = num_stack.pop(-1)
    num1 = num_stack.pop(-1)
    cal_chr = cal_stack.pop(-1)
    if cal_chr == "+":
        return float(num1) + float(num2)
    elif cal_chr == "-":
        return float(num1) - float(num2)
    elif cal_chr == "*":
        return float(num1) * float(num2)
    # elif cal_chr == 'tan':
    #     return float(math.tan(num2*math.pi/180))
    # elif cal_chr == 'sin':
    #     return float(math.sin(num2*math.pi/180))
    # elif cal_chr == 'cos':
    #     return float(math.cos(num2*math.pi/180))
    else:
        return float(num1) / float(num2)

def cal_stack_process(num_stack, cal_stack, current_cal):
    if len(cal_stack) == 0:
        cal_stack.append(current_cal)
    else:
        head_cal = cal_stack[-1]
        head_level = level_dict[head_cal]
        current_cal_level = level_dict[current_cal]
        if current_cal_level <= head_level:
            result = cal_once(num_stack, cal_stack)
            num_stack.append(result)
            cal_stack_process(num_stack, cal_stack, current_cal)
        else:
            cal_stack.append(current_cal)


def cal_with_no_brac(cal_str):
    # print("当前要处理的字符串:",cal_str)
    num_stack = []
    cal_stack = []
    i = 0
    while i < len(cal_str):
        temp_str = ""
        while i < len(cal_str) and cal_str[i] not in ["(", ")", "+", "-", "*", "/",'sin','cos','tan']:
            temp_str += cal_str[i]
            i += 1
        if len(temp_str): num_stack.append(temp_str)
        if i < len(cal_str):
            if cal_str[i] == "(":
                left_index = i
                while cal_str[i] != ")":
                    i += 1
                result = cal_with_no_brac(cal_str[left_index + 1:i])
                num_stack.append(result)
            else:
                cal_stack_process(num_stack, cal_stack, cal_str[i])
            i += 1

    while len(cal_stack):
        result = cal_once(num_stack, cal_stack)
        num_stack.append(result)

    return num_stack[0]


level_dict = {"*": 1, "/": 1, "+": 0, "-": 0}
# cal_str="1+2.5/3+(6.7-9)"
cal_str = input()
print(cal_with_no_brac(cal_str))




















