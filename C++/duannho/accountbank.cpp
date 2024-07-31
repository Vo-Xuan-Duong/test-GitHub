#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
    private:
        string name_;
        string stk_;
        double surplus_;
    public:
        Account(const string& name, const string& stk,const double& surplus) : name_(name) , stk_(stk) , surplus_(surplus) {}

        string getName() const{
            return name_;
        }
        string getStk() const{
            return stk_;
        }
        double getSurplus() const{
            return surplus_;
        }
};
class Bank{
    private:
        vector<Account>account_;
    public:
        void createAccount(const Account& account) {
            account_.push_back(account);
        }
        void removeAccount(const string& name,const string& stk){
            for(auto it = account_.begin(); it != account_.end(); it++){
                if(it->getName() == name && it->getStk() == stk){
                    account_.erase(it);
                    break;
                }
            }
        }
        void viewAccount(){
            for(const Account& account : account_){
                cout << "Account number : " << account.getStk() << " //Name: " << account.getName() << " //Surplus: " << account.getSurplus() << "VND" << endl;
            }
        }
};
int main(){
    Bank Mybank;

    while (true){
        cout << "\nCHAO MUNG BAN DEN VOI NGAN HANG" << endl;
        cout << "---------VIETCOMBANK----------" << endl;
        cout << "1. CreateAccount" << endl;
        cout << "2. RemoveAccount" << endl;
        cout << "3. ViewAccount" << endl;
        cout << "4. Transfer Money" << endl;
        cout << "5. Quit" << endl;
        cout << "Please enter your choice : ";

        int choice;
        cin >> choice;

        if(choice == 1){
            string name;
            string stk;
            int surplus;
            cout << " Enter name: ";
            cin.ignore();getline(cin,name);
            cout << " Enter stk: "; cin >> stk;
            cout << " Enter surplus: "; cin >> surplus;
            Account myAccount(name,stk,surplus);
            Mybank.createAccount(myAccount);
            cout << "Account "<< name << "(" << stk << ") has been added to the system." << endl;
            
        }
        else if(choice == 2){

        }
        else if(choice == 3){
            Mybank.viewAccount();
            
        }
        else if(choice ==  4){

        }
        else if(choice == 5){
            cout << "THANK YOU FOR USING THE SERVICE" << endl;
            cout << "------------GOODBYE------------" << endl;
            break;
        }
        else{
            cout <<"Invalid selection. Please select again." << endl;
        }
    
    }
    

    return 0;
}