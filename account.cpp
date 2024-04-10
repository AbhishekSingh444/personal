#include <iostream>
using namespace std;

class Account{
    protected:
    float threshold { 1'000 };
    float penalty {100};
    float balance {0};
    float interest {0.0485};
    void check_ir(){
        //interest rates
        if(balance >= 5'00'000){
            interest = 0.075;
        }
        if(balance >= 3'00'000){
            interest =  0.069;
        }
        if(balance >= 1'00'000){
            interest =  0.060;
        }
        if(balance >= 50'000){
            interest =  0.055;
        }
        interest = 0.0485;
    }
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
};

class SavingsAccount: public Account{
    float threshold {2'000};
    public:
    void deposit(){
        cout << "Enter the deposit amount for the savings account : \n";
        float amt;
        cin >> amt;
        if(amt <= 0){
            cout << "Invalid deposit amount, TRY AGAIN! \n";
            return;
        }
        this->balance += amt;
        check_ir();
    }
    void withdraw(){
        cout << "Enter the withdrawal amount for the savings account : \n";
        float amt;
        cin >> amt;
        if(amt <= 0){
            cout << "Invalid withdrawal amount, TRY AGAIN \n";
            return;
        }
        if(this->balance - amt <0){
            cout << "Account lacks sufficient balance! Current Balance : Rs." << this->balance << " ... TRY AGAIN \n";
            return;
        }
        this->balance -=amt;
        check_ir();
    }
    void transfer(SavingsAccount& acc, float amt){
        if(amt < 0){
            cout << "Invalid transfer amount! \n";
            return;
        }
        if(this->balance < amt){
            cout<< "Insufficient Balance! TRY AGAIN! \n";
            return;
        }
        this->balance -= amt;
        acc.balance += amt;
        cout << amt << " transferred from your account ! \n";
    }
};


class CreditAccount: public Account{
    float threshold {2'000};
    public:
    void deposit(){
        cout << "Enter the deposit amount for the savings account : \n";
        float amt;
        cin >> amt;
        if(amt <= 0){
            cout << "Invalid deposit amount, TRY AGAIN! \n";
            return;
        }
        this->balance += amt;
        check_ir();
    }
    void withdraw(){
        cout << "Enter the withdrawal amount for the savings account : \n";
        float amt;
        cin >> amt;
        if(amt <= 0){
            cout << "Invalid withdrawal amount, TRY AGAIN \n";
            return;
        }
        if(this->balance - amt <0){
            cout << "Account lacks sufficient balance! Current Balance : Rs." << this->balance << " ... TRY AGAIN \n";
            return;
        }
        this->balance -=amt;
        check_ir();
    }
    void transfer(CreditAccount& acc, float amt){
        if(amt < 0){
            cout << "Invalid transfer amount! \n";
            return;
        }
        if(this->balance < amt){
            cout<< "Insufficient Balance! TRY AGAIN! \n";
            return;
        }
        this->balance -= amt;
        acc.balance -= amt;
    }
};

class VerifyAccount: public Account{
    void checkthreshold(){
        if(balance  >= 5'00'000){
            check_ir();
        }   
        else if(balance < threshold){
            balance -= penalty;
        }
    }
};



int main(){
    SavingsAccount obj1;
    obj1.deposit();
    
    SavingsAccount obj2;
    obj2.deposit();

    obj1.transfer(obj2, 100000);

    obj2.withdraw();
}
