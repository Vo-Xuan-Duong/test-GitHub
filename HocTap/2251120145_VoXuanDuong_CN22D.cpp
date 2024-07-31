#include <iostream>
#include <valarray>
#include <bits/stdc++.h>

using namespace std;

struct BenhNhan{
    string hoten;
    int namsinh;
    string CCCD;
    int DSKQXN[3];
    int KQXN[3];
};

struct node{
    BenhNhan data;
    node* next;
};

void CreateList(node* &head){
    head = nullptr;
}

void InputBenhNhan(BenhNhan &value){
    cin.ignore();
    cout << "Nhap ho va ten: " ; getline(cin, value.hoten);
    cout << "Nhap nam sinh: "; cin >> value.namsinh;
    cout << "Nhap CCCD: " ; cin >> value.CCCD;
    cout << "Nhap loai xet nghiem va ket qua tuong ung \n (loai XN: 1- test nhanh, 2- PCR)(ket qua: 1- duong tinhs, 0- am tinh)" << endl;
    cout << "Nhap so lan xet nghiem: "; int n; cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Nhap loai xet nghiem dot " << i + 1 << ": ";
        cin >> value.DSKQXN[i];
        cout << "Nhap ke qua : " ; cin >> value.KQXN[i];
    }
}

node* CreateNode(BenhNhan &value){
    node* p = new node();
    p->data = value;
    p->next = nullptr;
    return p;

}
int Size(node* head){
    int count = 0;
    while(head != nullptr){
        head = head->next;
        count++;
    }
    return count;
}

void InputLast(node* &head, BenhNhan value){
    node* p = CreateNode(value);
    if(head == nullptr){
        head = p;
    }
    else {
        node* a = head;
        while(a->next != nullptr){
            a = a->next;
        }
        a->next = p;
    }
}

void InputList(node* &head){
    cout << "Nhap so luong danh sach: ";
    int n; cin >> n;
    cout << "-----------------------------\n";
    BenhNhan a[n];
    for(int i = 0; i < n; ++i){
        cout << "Nhap Benh Nhan thu  " << i+ 1 << endl;
        cout << "-----------------------------\n";
        InputBenhNhan(a[i]);
        InputLast(head, a[i]);
        cout << "-----------------------------\n";
    }
}

void OutputBenhNhan(BenhNhan &value){
    cout << "Ho va Ten: " << value.hoten << "\t Nam Sinh: " << value.namsinh << endl;
    cout << "CCCD: " << value.CCCD << endl;
    for(int i = 0; i < sizeof(value.DSKQXN); i++){
        cout << "Xet nghiem lan " << i + 1 <<":" << endl;
        cout << "Loai xet nghiem: "  << value.DSKQXN[i] << "\t Ket qua: " << value.KQXN[i] << endl;
    }
}

void OutputList(node* &head){
    cout << "Danh sach benh nhan:::" << endl;
    int a = 1;
    node* p = head;
    while (p != nullptr){
        cout << "-----------------------------\n";
        cout << "Mat hang thu " << a << endl;
        cout << "-----------------------------\n";
        OutputBenhNhan(p->data);
        a++;
        p = p->next;
        cout << "-----------------------------\n";
    }
}

void SearchBenhNhan(node* & head, string CCCD){
    node* p = head;

    while(p != nullptr){
        
        if(p->data.CCCD == CCCD){
            cout << "Da tim thay va tra ve ket qua: " << endl;
            OutputBenhNhan(p->data);
        }
        p  = p->next;
    }
}

void Outputlist_con(node* &head){
    
    cout << "Danh sach con hang: " << endl;
    int a = 1;
    node* p = head;
    while (p != nullptr){
        
        if((2023- p->data.namsinh) > 18){

            cout << "Benh Nhan thu " << a << endl;
            cout << "-----------------------------\n";
            OutputBenhNhan(p->data);
            a++;
            cout << "-----------------------------\n";
        }
        p = p->next;
    }
}

int  Kiemtraamtinh(node* &head){
    node * p = head;
    int am = 0;
    while(p != nullptr){
        for(int i = 0; i < sizeof(p->data.DSKQXN); i++){
            if(p->data.KQXN[i] == 0)am++;
        }
        p = p->next;
    }
    return am;
}

void Delete_het(node* &head){
    
    node* p = head;
    while(p != nullptr){
        node* truoc = nullptr;
        node* sau = head;
        while(sau->next != nullptr && Kiemtraamtinh(sau) != 3){
            truoc = sau;
            sau = sau->next;
        }
        if(truoc == nullptr){
            head = head->next;
        }
        else{
            truoc->next = sau->next;
        }
        p = p->next;
    }
    cout << "Da xoa thanh cong.\n";       
}



void SortList(node* head){
    node* p = head;
    node* s ;
    while( p->next != nullptr){
        p = p->next;
        s = p;
        while(s != nullptr){
            if(p->data.CCCD > s->data.CCCD){
                swap(p->data, s->data);
            }
            s = s->next;
        }
    }
    ofstream outFile("danhsachbenhnhan.txt");
    if (outFile.is_open()) {
        node* temp = head;
        while (temp != NULL) {
            outFile << "Ho ten: " << temp->data.hoten << endl;
            outFile << "Nam sinh: " << temp->data.namsinh << endl;
            outFile << "CCCD: " << temp->data.CCCD << endl;
            outFile << "Ket qua xet nghiem:" << endl;
            for (int i = 0; i < sizeof(temp->data.DSKQXN) / sizeof(temp->data.DSKQXN[0]); i++) {
                outFile << "  Loai xet nghiem: " << temp->data.DSKQXN[i] << ", Ket qua: " << temp->data.KQXN[i] << endl;
            }
            outFile << endl;
            temp = temp->next;
        }
        outFile.close();
        cout << "Da ghi danh sach benh nhan da sap xep vao file danhsachbenhnhan.txt" << endl;
    }
    else {
        cout << "Khong the mo file de ghi danh sach benh nhan." << endl;
    }
}

void OutputList_2duongtinh(node* &head){
    node* p =  head;
    int a = 1;
    cout << "Danh sach benh nhan 2 lan duong tinh " << endl;
    while(p != nullptr){
        if(Kiemtraamtinh(p) == 2){
            cout << "Benh nhan " << a << endl;
            OutputBenhNhan(p->data);
            a++;
        }
        p = p->next;
    }
}

int main(){
    node *head;
    CreateList(head);
    ofstream outFile("danhsachbenhnhan.txt");
    while(1){
        
        cout << "---------------------------------------------------------------------------\n";
        cout << "Menu"<< endl;
        cout << "1. Nhap danh sach benh nhan.\n";
        cout << "2. Xuat danh sach benh nhan.\n";
        cout << "3. Dem so luong benh nhan.\n";
        cout << "4. Tim benh nhan theoi CCCD.\n";
        cout << "5. Xuat danh sach benh nhan nhiem COVID-19 tren 18 tuoi.\n";
        cout << "6. Xoa benh nhan 3 lan xet nghiem am tinh.\n";
        cout << "7. Xuat benh nhan co 2 lan duong tinh.\n";
        cout << "8. Sap xep danh sach quan ao  theo CCCD, va ghi ra file nhi phan.\n";
        cout << "9. Exit.\n";
        cout << "---------------------------------------------------------------------------\n";
        cout << "Vui long nhap lua chon cua ban: ";
        int c;
        cin >> c;
        cout << "---------------------------------------------------------------------------\n";
        if(c == 1){
            cout << "---------------------------------------------------------------------------\n";
            InputList(head);
            cout << "---------------------------------------------------------------------------\n";
        }
        else if(c == 2){
            cout << "---------------------------------------------------------------------------\n";
            OutputList(head);
            cout << "---------------------------------------------------------------------------\n";
        }
        else if(c == 3){
            cout << "---------------------------------------------------------------------------\n";
            int si = Size(head);
            cout << "So luong quan ao: " << si << endl;
            cout << "---------------------------------------------------------------------------\n";
        }
        else if(c == 4){
            cout << "---------------------------------------------------------------------------\n";
            cout << "Nhap ma san pham ban muon tim: ";
            string CCCD; cin >> CCCD;
            SearchBenhNhan(head, CCCD);
            cout << "---------------------------------------------------------------------------\n";
        }
        else if(c == 5){
            cout << "---------------------------------------------------------------------------\n";
            Outputlist_con(head);
            cout << "---------------------------------------------------------------------------\n";
        }
        else if(c == 6){
            cout << "---------------------------------------------------------------------------\n";
            Delete_het(head);
            cout << "---------------------------------------------------------------------------\n";
        }
        else if(c == 7){
             cout << "---------------------------------------------------------------------------\n";
             OutputList_2duongtinh(head);
              cout << "---------------------------------------------------------------------------\n";
        }
        else if(c == 8){
            cout << "---------------------------------------------------------------------------\n";
            SortList(head);

            cout << "Da sap xep thanh cong!\n";
            cout << "---------------------------------------------------------------------------\n";
        }
        
        else if(c == 9){
            cout << "---------------------------------------------------------------------------\n";
            cout << "Cam on da su dung tool!!\n";
            break;
            cout << "---------------------------------------------------------------------------\n";
        }

        else cout << "Lua chon khong hop le. Vui long nhap lai\n";
    }

}