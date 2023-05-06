import math
C = 50
H = 30
D = list(eval(input("nhap cac gia tri cua D: ")))
a = []
for i in D:
    Q =int( math.sqrt((2*C*i)/H))
    a.append(str(Q))
    
print(",".join(a))