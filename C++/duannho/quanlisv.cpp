#include <bits/stdc++.h>

using namespace std;

class Person{
    private:
        string name;
        int age;
        string address;
    public:
        Person(string name = "", int age = 0, string address = " "): name(name), age(age), address(address) {}
        
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        string getAddress(){
            return address;
        }
};

class Student : public Person{
    private:
        string MaSV;
    public:
        Student(string MaSV = "0",string name = "", int age = 0, string address = " " ) : Person(name, age, address), MaSV(MaSV){}
        string getMaSV(){
            return MaSV;
        }

        friend bool operator == (Student a,Student b ){
            return (a.getAddress() == b.getAddress() && 
                a.getAge() == b.getAge() && 
                a.getMaSV() == b.getMaSV() &&
                a.getName() == b.getName() );
        }
    
};

Student Search(vector<Student> St, string masv){
    for(int i = 0; i < St.size(); i++){
        if(St[i].getMaSV() == masv)return St[i];
    }
}

void Display(vector<Student> St){
    cout << "Danh sach Sing Vien :";
    cout << "MaSV" << "\t Name" << "\tAGE" <<"\t Address." << endl;
    for(int i = 0; i < St.size(); i++){
        cout << St[i].getMaSV() << "\t" << St[i].getName() <<"\t " << St[i].getAge() <<"\t" << St[i].getAddress() << endl;
    }
}

void ThemSV(vector<Student> St){
    int  a = St.size();
    string name;
    string address;
    int age;
    string Masv;
    cout << "Nhap ma Sv: "; cin >> Masv;
    cin.ignore();
    cout << "Nhap ho va ten: ";getline(cin, name);
    cout << "Nhap tuoi: "; cin>> age;
    cout << "Nhap dia chi: "; cin >> address;
    St[a] = Student(Masv, name, age, address);
}

void DeleteSV(vector<Student> St, string Masv){
    
    for(int i = 0; i < St.size(); i++){
        if(St[i] == Search(St, Masv)){
            for(int )
            St[i] = St[i + 1];
        }
    }
}

int main(){

}