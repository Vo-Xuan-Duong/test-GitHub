s = input("nhap dau vao:")
count = 0
a = 0
for i in s:
    if i.isupper()==True:
        count +=1
    elif i.islower()==True:
        a+=1
    else:
        pass
       
print("chữ hoa :",count)
print("chữ thường:",a)