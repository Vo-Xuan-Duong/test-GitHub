from cmath import sqrt
import math
up = int(input("nhap up:"))
down = int(input("nhap down: "))
left = int(input("nhap left: "))
right = int(input("nhap right: "))

abs_updown = abs(up - down)
abs_leftright = abs(left- right)
distance =sqrt(abs_updown**2 + abs_leftright**2) 
rnumber = distance.real
integernumber = math.floor(rnumber)
print("khoang cach robot di chuyen duoc : " ,rnumber)
print (" khoang cach so nguyen gan nhat",integernumber)


