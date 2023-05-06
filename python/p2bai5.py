def f(n):
    if n ==0:
        return 0
    else:
        return f(n-1) + 100
    
number =int( input("nhap so n>0: "))
print(f(number))