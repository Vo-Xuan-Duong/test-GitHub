//#include "Customer.cpp"
#include <iostream>

using namespace std;

class Invoice{
    private:
     int id;
     Customer customer;
     double amount;
    public:
        Invoice(int id, Customer customer, double amount){
            this->id = id;
            this->customer = customer;
            this->amount = amount;
        }
        int getId(){
            return id;
        }
        void setCustomer(Customer customer){
            this->customer = customer;
        }
        Customer getCustomer(){
            return customer;
        }
        void setAmount(double amount){
            this->amount = amount;
        }
        double getAmount(){
            return amount;
        }
        string getCustomerName(){
            return customer.getName();
        }
        double getAmountAfterDiscount(){
            return amount- amount*customer.getDiscount()/100;
        }
};
int main() {
	Customer customer1(1000, "Tuan", 20);
	Invoice invoice1(1000, customer1, 100000);
	cout << "Customer name: " << invoice1.getCustomerName() << endl;
	cout << "Invoice after discount: " << invoice1.getAmountAfterDiscount() << endl;
    
	return 0;
}