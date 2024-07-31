#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Contact
{
private:
    string name_;
    string phone_;
public:
    Contact(const string&name , const string &phone) : name_(name) , phone_(phone) {}
    
    string getName() const{
        return name_;
    }
    string getPhone() const{
        return phone_;
    }
};
class AddressBook{
    private:
        vector<Contact>contact_;
    public:
        void AddContact(const Contact& contact){
            contact_.push_back(contact);
        }
        void RemoveContact(const string& name){
            for(auto it = contact_.begin(); it != contact_.end(); it++){
                if (it->getName() == name){
                    contact_.erase(it);
                    break;
                }
            }
        }
        void ViewContact() const {
            cout << "\nContacts in the address book: " << endl;
            for(const Contact& contact : contact_){
                cout << "Name : " << contact.getName() << "  Phone: " << contact.getPhone() <<endl;
            }
        }
};

int main(){
    AddressBook myAddressBook;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1 : Add Contact" << endl;
        cout << "2 : Remove Contact" << endl;
        cout << "3 : View Contact" << endl;
        cout << "4 : Quit" << endl;

        int choice;
        cin >> choice;
    
        if (choice == 1){
            string name,phone;
            cout << "Enter name : ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter phone number : ";
            cin >> phone ;
            Contact newcontact(name, phone);
            myAddressBook.AddContact(newcontact);
            cout << name << " has been added to the address book." << endl;
        }  
        else if(choice == 2){
            string name;
            cout << "Enter the name to remove : " ;
            cin >> name ;
            myAddressBook.RemoveContact(name);
            cout << name << " has been removed from the address book." << endl;
        }
        else if(choice == 3){
            myAddressBook.ViewContact();
        }
        else if(choice == 4){
            cout << "Goodbye!" << endl;
            break;
        }
        else{
            cout << "Invalid choice. Please choose again." << endl;
        }
    }
    return 0;
}