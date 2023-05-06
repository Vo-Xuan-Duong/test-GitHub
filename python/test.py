def bancuuchuong(a):
    for i in range(1,10+1):
        print(a," * ",i," = ",a*i)
        
x = int (input("nhập số muốn: "))     
for i in range(1,x+1):
    print("ban cuu chuong ",i)
    bancuuchuong(i)