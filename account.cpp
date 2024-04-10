#include <iostream>
using namespace std;

class Account{
    protected:
    const float threshold { 1'000 };
    const float penalty {100};
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
    virtual void transfer() = 0;
};

class SavingsAccount: public Account{
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
};


class CreditAccount: public Account{

};

class VerifyAccount: public SavingsAccount, public CreditAccount{
    
};



int main(){

}