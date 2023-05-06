def kiem_tra_doi_xung(lst):
    return lst == lst[::-1]

def sx_doi_xung(lst):
    if kiem_tra_doi_xung(lst):
        return lst
    else:
        for i in range(len(lst)//2):
            if lst[i] != lst[-i-1]:
                for j in range(i+1, len(lst)):
                    if lst[j] == lst[-i-1]:
                        lst[i], lst[j] = lst[j], lst[i]
                        break
        return lst

lst = list(map(int, input("Nhập dãy số nguyên, cách nhau bởi dấu cách: ").split()))

if kiem_tra_doi_xung(lst):
    print("Dãy số đã đối xứng.")
else:
    new_lst = sx_doi_xung(lst)
    if kiem_tra_doi_xung(new_lst):
        print("Dãy số đã khả đối xứng và biến đổi thành dãy số đối xứng: ", new_lst)
    else:
        print("Dãy số không khả đối xứng.")