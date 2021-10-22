/********************************************************************************************************
 * Author: Zachary Pringle
 * Program: HW2
 * Date Created: 10/18/2021
 * Date Last Modified: 10/20/2021
 * Problem:
 * Create Classes that allow a functioning CheckBook to work
 * -Use Check pointer that points to the CheckBookSize
 * -Use a copy constructor, Overloaded operator, a deconstructor, and overloaded contructors
 * -write functions to get and set private data members
 * -use a function to run test the checkbook
 *******************************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Check {
    int checkNum;
    string checkMemo;
    float checkAmount;
};

bool operator > (Check& check, float amount);

ostream& operator << (ostream& os, Check& check);

class CheckBook{
public:
    Check *chkPtr;
    void lastDeposit();//still need to write
    void setBalance(float amount){balance=amount;}
    void setCheckBookSize(int num){checkBookSize=num;}
    void setNumberOfChecks(int num){numberOfChecks=num;}
    int const getNumberOfChecks(){return numberOfChecks;}
    int const getCheckBookSize(){return checkBookSize;}
    float const getBalance(){return balance;}
    CheckBook(): balance(0), numberOfChecks(0), checkBookSize(4){}
    CheckBook(int num): numberOfChecks(0), checkBookSize(2) {balance=num; chkPtr= new Check[checkBookSize];}
    ~CheckBook(){};
    void doubleCheckBookSize();
    //CheckBook(const Check &check) {=check.checkAmount; }//still need to write - Copy Constructor
    void deposit(int amount){balance+=amount;}
    bool writeCheck(Check c_amount);
    void const displayChecks();
private:
    float balance;
    int numberOfChecks,checkBookSize;
};

void checkTest(CheckBook checkBook, int bal);

int main() {
    int bal = 5000;
    CheckBook checkBook(bal);
    checkTest(checkBook,bal);

    return 0;
}

bool operator > (Check& check, float amount){
   if (check.checkAmount>amount){
       return true;
   }
   return false;
}

ostream& operator << (ostream& os, Check& check){
    os << check.checkNum << " " << check.checkAmount << " " << check.checkMemo << endl;
    return os;
}

bool CheckBook::writeCheck(Check c_amount) {
        if (c_amount > balance)
            return true;
        else {
            const string randomMemo[6] = {"Pizza", "Food", "Drinks", "Wedding", "Ice Hockey", "Football Game"};
            int randomNumberGen = rand() % 6;
            c_amount.checkMemo = randomMemo[randomNumberGen];
            c_amount.checkNum = numberOfChecks + 1;
            chkPtr[numberOfChecks] = c_amount;
            numberOfChecks++;
            balance -= c_amount.checkAmount;
        }
}

void const CheckBook::displayChecks() {
    for(int i=numberOfChecks;i>0;i--)
        cout << chkPtr[i-1];
}

void checkTest(CheckBook checkBook, int bal){
    cout << "_________________________________________\nLast Deposit written as a check is made and notification for the new checkbook being ordered:\n"<< endl;
    while (checkBook.getBalance()>0) {
    Check c_amount;
    checkBook.setBalance(bal);
    c_amount.checkAmount = 50;
    checkBook.writeCheck(c_amount);
    checkBook.lastDeposit();
        if(checkBook.getCheckBookSize()==checkBook.getNumberOfChecks())
            checkBook.doubleCheckBookSize();
    bal-=c_amount.checkAmount;
    }
    cout << "\n_________________________________________\nChecks from most recent to the first written check:\n"<< endl;
    checkBook.displayChecks();
    cout << "\n_________________________________________\n"<< endl;
}
void CheckBook::lastDeposit() {
    cout<<chkPtr[numberOfChecks-1];
}

void CheckBook::doubleCheckBookSize(){
    Check *ptr = new Check [2*checkBookSize];
    for(int i=0; i<numberOfChecks;i++){
        ptr[i]=chkPtr[i];
    }
    checkBookSize*=2;
    delete [] chkPtr;
    chkPtr=ptr;
    cout << "New Check Book Ordered!" << endl;
}