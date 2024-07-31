#include<iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

struct sinhvien{
    string MaSV;
    string hoten;
    int tuoi;
    double avg;


    bool operator ==(const sinhvien& x) const {
        if(this->MaSV == x.MaSV && 
            this->hoten == x.hoten &&
            this->tuoi == x.tuoi && 
            this->avg == x.avg)return true;
        else return false;
    }

};

struct node
{
    sinhvien data;
    node* next;
};

node* CreateNode(sinhvien x){
    node* p = new node();
    p->data = x;
    p->next = nullptr;
    return p;
}

void themsau(node* &head, sinhvien x){
    node* p = CreateNode(x);
    if(head == nullptr){
        head = p;
    }
    else{
        node* a = head;
        while(a->next != nullptr){
            a = a->next;
        }
        a->next = p;
    }
}

void ThemSV( node* &head){
    sinhvien x;
    cout << "   (+) Nhap MSSV: "; cin >> x.MaSV;
    cout << "   (+) Nhap ten : "; cin.ignore(); getline(cin, x.hoten);
    cout << "   (+) Nhap tuoi: " ; cin >> x.tuoi;
    cout << "   (+) Nhap diem: "; cin >> x.avg;

    themsau(head, x);
}




void XuatSV(sinhvien x){
    //tạo đường ( +-----------+---------------------+-----------+-----------+)
    cout << setfill(' ');
	cout << setw(10) << right << "";
	cout << setfill('-');
	cout << "+" << setw(7) << right << "";
	cout << "+" << setw(20) << left << "";
	cout << "+" << setw(41) << right << "";
	cout << "+" << setw(12) << right << "";
	cout << "+" << setw(12) << right << "" << "+" << endl;
    // điền thông tin vào bảng in danh sách
	cout << setfill(' ');
	cout << setw(10) << right  << "";
	cout << "| " << setw(6) << left <<  " STT";
	cout << "| " << setw(19) << left << "       MSSV";
	cout << "| " << setw(40) << left << "               Ho va Ten";
	cout << "| " << setw(11) << left << "   Tuoi";
	cout << "| " << setw(11) << left << "   Diem" << "|" << endl;
	//tạo đường ( +-----------+---------------------+-----------+-----------+)
	cout << setw(10) << right << "";
	cout << setfill('-');
	cout << "+" << setw(7) << right << "";
	cout << "+" << setw(20) << left << "";
	cout << "+" << setw(41) << right << "";
	cout << "+" << setw(12) << right << "";
	cout << "+" << setw(12) << right << "" << "+" << endl;
	//----------------------------------------------------------------------------------
	cout << setfill(' ');
	cout << setw(10) << right  << "";
	cout << "| " << setw(6) << left <<  "1";
	cout << "| " << setw(19) << left << x.MaSV;
	cout << "| " << setw(40) << left << x.hoten;
	cout << "| " << setw(11) << left << x.tuoi;
	cout << "| " << setw(11) << left << x.avg << "|" << endl;
	//tạo đường ( +-----------+---------------------+-----------+-----------+)
	cout << setfill(' ');
	cout << setw(10) << right << "";
	cout << setfill('-');
	cout << "+" << setw(7) << right << "";
	cout << "+" << setw(20) << left << "";
	cout << "+" << setw(41) << right << "";
	cout << "+" << setw(12) << right << "";
	cout << "+" << setw(12) << right << "" << "+" << endl;
}

void XuatDSSV(node* head){
    cout << "Danh sach sinh vien.." << endl;
    //tạo đường ( +-----------+---------------------+-----------+-----------+)
    cout << setfill(' ');
	cout << setw(10) << right << "";
	cout << setfill('-');
	cout << "+" << setw(7) << right << "";
	cout << "+" << setw(20) << left << "";
	cout << "+" << setw(41) << right << "";
	cout << "+" << setw(12) << right << "";
	cout << "+" << setw(12) << right << "" << "+" << endl;
    // điền thông tin vào bảng in danh sách
	cout << setfill(' ');
	cout << setw(10) << right  << "";
	cout << "| " << setw(6) << left <<  " STT";
	cout << "| " << setw(19) << left << "       MSSV";
	cout << "| " << setw(40) << left << "               Ho va Ten";
	cout << "| " << setw(11) << left << "   Tuoi";
	cout << "| " << setw(11) << left << "   Diem" << "|" << endl;
	//tạo đường ( +-----------+---------------------+-----------+-----------+)
	cout << setw(10) << right << "";
	cout << setfill('-');
	cout << "+" << setw(7) << right << "";
	cout << "+" << setw(20) << left << "";
	cout << "+" << setw(41) << right << "";
	cout << "+" << setw(12) << right << "";
	cout << "+" << setw(12) << right << "" << "+" << endl;
	//----------------------------------------------------------------------------------
    int i = 1;
    while(head != nullptr){
        cout << setfill(' ');
        cout << setw(10) << right  << "";
        cout << "| " << setw(6) << left << i ;i++;
        cout << "| " << setw(19) << left << head->data.MaSV;
        cout << "| " << setw(40) << left << head->data.hoten;
        cout << "| " << setw(11) << left << head->data.tuoi;
        cout << "| " << setw(11) << left << head->data.avg << "|" << endl;
        head = head->next;
    }
	
	//tạo đường ( +-----------+---------------------+-----------+-----------+)
	cout << setfill(' ');
	cout << setw(10) << right << "";
	cout << setfill('-');
	cout << "+" << setw(7) << right << "";
	cout << "+" << setw(20) << left << "";
	cout << "+" << setw(41) << right << "";
	cout << "+" << setw(12) << right << "";
	cout << "+" << setw(12) << right << "" << "+" << endl;
}

sinhvien Search123(node* head){
    sinhvien x;
    x.MaSV = "0";
    cout << "Nhap MSSV can lam viec: ";string ma; cin >> ma;
    while(head != nullptr && head->data.MaSV != ma){
        head = head->next;
    }
    if(head == nullptr) {
        cout << "Sinh vien can tim khong co trong danh sach." << endl ;
        return x;
    }
    else {
        cout << "Da tim thay sinh vien trong danh sach" << endl;
        return head->data;
    }
}

#include <string>

// void SortDSSV(node* head){
//     //Sap xep sinh vien theo ten theo thu tu tang dan
//     sinhvien tmp;
//     string tenSV1;
//     string tenSV2;
//     node * i = head;
//     while(i->next != nullptr){
//         tenSV1 = i->data.hoten;
//         node* j = i;
//         while(j->next != nullptr) {
//             tenSV2 = j->data.hoten;
//             if(tenSV1.compare(tenSV2) > 0) {
//                 swap(i->data, j->data);
//             }
//         }
//     }
// }
//hàm chúng tôi thay thế
                        node* getTail(node* cur) {
                            while (cur != nullptr && cur->next != nullptr)
                                cur = cur->next;
                            return cur;
                        }

                        node* partition(node* head, node* end, node** newHead, node** newEnd) {
                            node* pivot = end;
                            node *prev = nullptr, *cur = head, *tail = pivot;

                            while (cur != pivot) {
                                if (cur->data.hoten < pivot->data.hoten) {
                                    if ((*newHead) == nullptr)
                                        (*newHead) = cur;
                                    prev = cur;  
                                    cur = cur->next;
                                } else {
                                    if (prev)
                                        prev->next = cur->next;
                                    node* tmp = cur->next;
                                    cur->next = nullptr;
                                    tail->next = cur;
                                    tail = cur;
                                    cur = tmp;
                                }
                            }

                            if ((*newHead) == nullptr)
                                (*newHead) = pivot;

                            (*newEnd) = tail;

                            return pivot;
                        }

                        node* quickSortRecur(node* head, node* end) {
                            if (!head || head == end)
                                return head;

                            node *newHead = nullptr, *newEnd = nullptr;

                            node* pivot = partition(head, end, &newHead, &newEnd);

                            if (newHead != pivot) {
                                node* tmp = newHead;
                                while (tmp->next != pivot)
                                    tmp = tmp->next;
                                tmp->next = nullptr;

                                newHead = quickSortRecur(newHead, tmp);

                                tmp = getTail(newHead);
                                tmp->next = pivot;
                            }

                            pivot->next = quickSortRecur(pivot->next, newEnd);

                            return newHead;
                        }

                        void quickSort(node** headRef) {
                            (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
                            return;
                        }

//kết thúc hàm thay thế

int CountDSSV(node* head){
    int count = 0;
    node* hehe = head;
    while(hehe != nullptr){
        count++;
        hehe = hehe->next;
    }
    return count;
}

void InMenu(){
    cout << setfill('-');
    cout << "+" << setw(50) << left << "" << "+" << endl;
//---------------
    cout << setfill(' ');
    cout << "|" << setw(25) << right << "ME" << setw(25) << left << "NU" << "|" << endl;
//                         
    cout << setfill('-');
    cout << "+" << setw(8) << left << "";
    cout << "+-" << setw(40) << left << "" << "+" << endl;
//-----------------------
    cout << setfill(' ');
    cout << "| " << setw(7) << left << "Lenh" ;
    cout << "| " << setw(40) << left << "Noi dung lenh" << "|" << endl;
//
    cout << setfill('-');
    cout << "+" << setw(8) << left << "";
    cout << "+-" << setw(40) << left << "" << "+" << endl;
//---------------------------danh sach---------------
    cout << setfill(' ');
    cout << "| " << setw(7) << left << "  1  " ;
    cout << "| " << setw(40) << left << "In danh sach sinh vien" << "|" << endl;

    cout << "| " << setw(7) << left << "  2  " ;
    cout << "| " << setw(40) << left << "Them sinh vien" << "|" << endl;

    cout << "| " << setw(7) << left << "  3  " ;
    cout << "| " << setw(40) << left << "Sua sinh vien" << "|" << endl;

    cout << "| " << setw(7) << left << "  4  " ;
    cout << "| " << setw(40) << left << "Xoa sinh vien" << "|" << endl;

    cout << "| " << setw(7) << left << "  5  " ;
    cout << "| " << setw(40) << left << "Tim kiem sinh vien" << "|" << endl;

    cout << "| " << setw(7) << left << "  6  " ;
    cout << "| " << setw(40) << left << "Sap xep sinh vien" << "|" << endl;

    cout << "| " << setw(7) << left << "  7  " ;
    cout << "| " << setw(40) << left << "Thong ke sinh vien" << "|" << endl;

    cout << "| " << setw(7) << left << "  8  " ;
    cout << "| " << setw(40) << left << "Sao luu chuong trinh" << "|" << endl;

    cout << "| " << setw(7) << left << "  9  " ;
    cout << "| " << setw(40) << left << "Thoat chuong trinh" << "|" << endl;

    // cout << "| " << setw(7) << left << "  1  " ;
    // cout << "| " << setw(80) << left << "" << "|" << endl;

//--------ket thuc danh sach-----------------
    cout << setfill('-');
    cout << "+" << setw(8) << left << "";
    cout << "+-" << setw(40) << left << "" << "+" << endl;

}

void Saoluu(node* head){
    ofstream myfile("DanhsachSV.txt");
    node* readDS = head;
    while(readDS != nullptr){
        myfile << readDS->data.MaSV << ";" << readDS->data.hoten << ";" << readDS->data.tuoi << ";" << readDS->data.avg << ";" << endl;

        readDS = readDS->next;
    }

    myfile.close();
}

void SuaDS(node* head){
    
    cout << "Nhap MSSV can lam viec: ";string ma; cin >> ma;
    while(head != nullptr && head->data.MaSV != ma){
        head = head->next;
    }
    if(head == nullptr) cout << "Sinh vien can tim khong co trong danh sach." << endl ;
    else cout << "Da tim thay sinh vien trong danh sach" << endl;
    bool a = true;
    while(a){
        cout << "Ban can sua :  (1) Sua MSSV." << endl;
        cout << "               (2) Sua ho va ten." << endl;
        cout << "               (3) Sua tuoi." << endl;
        cout << "               (4) Sua diem." << endl;
        cout << "               (5) Thoat." << endl;
        cout << "Moi ban nhan lua chon: "; int x; cin >> x;
        switch (x)
        {
        case 1:
            cout << "Nhap MSSV moi: ";
            cin >> head->data.MaSV;
            break;
        case 2: 
            cout << "Nhap HovaTen moi: ";
            cin.ignore(); getline(cin, head->data.hoten);
            break;
        case 3:
            cout << "Nhap Tuoi moi: ";
            cin >> head->data.tuoi;
            break;
        case 4:
            cout << "Nhap Diem moi: ";
            cin >> head->data.avg;
            break;
        case 5:
            cout << "Ban da sua thanh cong sinh vien" << endl;
            a = false;
            break;
        default:
            cout << "Nhap lai lua chon ." << endl;
            break;
        }
    }


}

void DeleteSV(node* &head){
    cout << "Nhap MSSV ban can xoa : " ;string ma; cin >> ma;
    node* truoc = nullptr;
    node* sau = head;
    while(sau->next != nullptr && sau->data.MaSV != ma){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == nullptr){
        head = head->next;
    }else {
        truoc->next = sau->next;
    }
    if(sau->next == nullptr) cout << "Sinh vien khong co trong DSsv." << endl;
    else  cout << "Ban da xoa thanh cong sinh vien co MSSV " << ma << " khoi danh sach SV \n";
}


int main(){
    node * head = nullptr;
    

    ifstream readfile123("DanhsachSV.txt");
    string mytext;
    
    while(getline(readfile123,mytext)){
        //cout << mytext <<  endl;
        sinhvien x;
        string temp = "";
        int field = 0; // 0 for MSSV, 1 for ten, 2 for tuoi, 3 for agv
        for(int i = 0; i < mytext.size(); i++){
            if(mytext[i] == ';'){
                if(field == 0){
                    x.MaSV = temp;
                    //cout << temp << endl;
                } else if(field == 1){
                    x.hoten = temp;
                    //cout << temp << endl;
                } else if(field == 2){
                    x.tuoi = stoi(temp);
                    //cout << temp << endl;
                }
                else if(field == 3){
                    x.avg = stoi(temp);
                    //cout << temp << endl;
                }
                temp = "";
                field++;
            } else {
                temp += mytext[i];
            }
        }
        themsau(head, x);

    }
    readfile123.close();

    while(1){
        InMenu();
        int choice;
        cout << "    (+)  Nhap lenh : ";cin >> choice;
        if(choice == 1){
            XuatDSSV(head);
        }
        else if(choice == 2){
            ThemSV(head);
        }
        else if(choice == 3){
            SuaDS(head);
        }
        else if(choice == 4){
            DeleteSV(head);
        }
        else if(choice == 5){
            sinhvien x = Search123(head);
            if(x.MaSV == "0"){
            }else XuatSV(x);
        }
        else if(choice == 6){
            //SortDSSV(head);
            quickSort(&head);
            cout << "Da sap xep DS thanh cong." << endl;
        }
        else if(choice == 7){
            int a = CountDSSV(head);
            cout << "Danh sach co " << a << " sinh vien." << endl;
        }
        else if(choice == 8){
            Saoluu(head);
            cout << "Sao luu thanh cong...." << endl;
        }
        else if(choice == 9){
            cout << "thank you " << endl;
            break;

        }
        
        cout << endl << endl << endl;
        cout << "Nhan phim bat ki de tiep tuc chay chuong trinh...." << endl;
        system("pause");
        
        system("cls");
        
    }


    return 0;
}
