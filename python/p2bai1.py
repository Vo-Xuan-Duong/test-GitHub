input1 = input(" nhập chuỗi nhị phân có 4 chữ số: ")
binary_list = input1.split(",")
integer_list = []
for i in binary_list:
    integer_munber=(int(i,2))
    if integer_munber%5==0:
        integer_list.append(integer_munber)
binary =[]
for a in integer_list:
    binary.append(str(format(a,'04b')))
    
print(",".join(binary))
    
