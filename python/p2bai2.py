input1 = input(" nhap chuoi : ")
input_list =list(input1)
count = 0
a = 0
for i in input_list:
    if i.isalpha()==True:
        count +=1
    elif i.isdigit()==True:
        a +=1
    else:
        pass
print("so chu cai : ", count)
print("so chu so : ", a)
        