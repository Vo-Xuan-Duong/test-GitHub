#include <iostream>
#include <vector>
#include <string>

using namespace std;

class book{
private:
    string masach;
    string booktitle;
    string author;
    double price;
public:
    book(string masach, string booktitle, string author, double price) : masach(masach), booktitle(booktitle), author(author), price(price) {}
    string getMasach(){
        return masach;
    }
    string getBooktitle(){
        return booktitle;
    }
    string getAuthor(){
        return author;
    }
    double getPrice(){
        return price;
    }
    void display(){
        cout << "Ma sach: " << masach << endl;
        cout << "Ten sach: " << booktitle << endl;
        cout << "Tac gia: " << author << endl;
        cout << "Gia tien: " << price << endl;
    }
};

class khosach {
    private:
        int stt;
        book* books;
        double quantity;
    public:
        khosach(book* books, double quantity) : books(books), quantity(quantity) {}
        
        book* getBooks(){
            return books;
        }
        void display(){
            books->display();
            cout << "So luong sach: " << quantity << endl;
        }

};

class thongtinkhachhang{
    private:
        int makhachhang;
        string name;
        string sdt;
    public:
        thongtinkhachhang( int makhachhang, string name, string sdt) : makhachhang(makhachhang), name(name), sdt(sdt){}
        
        int getMakhachhang(){
            return makhachhang;
        }
        string getName(){
            return name;
        }
        string getSdt(){
            return sdt;
        }
        void display(){
            cout << "Ma khach hang: " << makhachhang << endl;
            cout << "Ten khach hang: " << name << endl;
            cout << "SDT: " << sdt << endl;
        }
};
class cuahang{
    private:
    vector <khosach> book2;
    vector <thongtinkhachhang> tt;
    public:
    void addbook(khosach b){
        book2.push_back(b);
    }
    void addkhachhang(thongtinkhachhang khach){
        tt.push_back(khach);
    }
    void removebook(string masach_){
        for(auto it = book2.begin(); it != book2.end(); it++){
            if(it->getBooks()->getMasach() == masach_ ){
                book2.erase(it);
                break;
            }
        }
    }
    void removekhachhang(string ten){
        for(auto it = tt.begin(); it != tt.end(); it++){
            if(it->getName() == ten){
                tt.erase(it);
                break;
            }
        }
    }


};

int main(){
    cuahang ch;
    while (1)
    {
        cout << "1.Nhap cac loai sach trong kho."<< endl;
        cout << "2.Nhap thong tin khach hang da da ky tai cua hang." << endl;
        cout << "3.Chon khach hang muon mua sach nao. " << endl;
        cout << "4. Xoa 1 loai sach khoi kho." << endl;
        cout << "5. Xoa 1 khach hang khoi danh sach." << endl;
        cout << "thoat...." << endl;

        int c; cin >> c;

        if(c == 1){
            cout << "Nhap ma sach: " ;string masach;
            cin >> masach;
            cout << "Nhap ten sach: " ; string tensach;
            cin.ignore();
            getline(cin, tensach);
            cout << "Nhap ten tac gia: " ; string tentacgia;
            getline(cin,tentacgia);
            cout << "Nhap gia tien: " ;double giatien;
            cin >> giatien;
            book book3(masach, tensach, tentacgia, giatien);
            cout << "Nhap so luong sach trong kho: ";int a; cin >> a;
            khosach ks(&book3, a);
        }
        else if
    }
    
}