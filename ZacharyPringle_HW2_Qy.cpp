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

using namespace std;

struct Check {
    int checkNum;
    string checkMemo;
    float checkAmount;
};

bool operator > (Check& check, float amount);

ostream& operator << (ostream& os, Check& check);

bool operator <= (Check& check, float amount);

class CheckBook{
public:
    Check *chkPtr;
    void lastDeposit();//displays last check
    void setBalance(float amount){balance=amount;}//sets balance to an amount
    void setCheckBookSize(int num){checkBookSize=num;} //sets checkBookSize to a num
    void setNumberOfChecks(int num){numberOfChecks=num;}//sets numberOfChecks to a num
    int const getNumberOfChecks(){return numberOfChecks;}//returns the number of checks
    int const getCheckBookSize(){return checkBookSize;}//returns the size of the checkbook
    float const getBalance(){return balance;}//returns the current balance
    CheckBook(): balance(0), numberOfChecks(0), checkBookSize(4){}//default constructor
    CheckBook(int num): numberOfChecks(0), checkBookSize(2) {balance=num; chkPtr= new Check[checkBookSize];} //constructor that sets the starting numbers in main
    ~CheckBook(){};//deconstructor
    void doubleCheckBookSize();//doubles the size of the checkbook
    void deposit(int amount){balance+=amount;}//adds an amount to the current balance
    bool writeCheck(Check c_amount);//writes the check and updates the necessary elements while doing so
    void const displayChecks();//displays all checks in order starting with the most recent check
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
//lets a check be compared to an amount to see if the check amount is less than or equal to the float amount
bool operator <= (Check& check, float amount){
    if (check.checkAmount<=amount){
        return true;
    }
    return false;
}
//lets a check be compared to an amount to see if the check amount greater than the float amount
bool operator > (Check& check, float amount){
   if (check.checkAmount>amount){
       return true;
   }
   return false;
}
//allows the cout of a check and displays the information within a check
ostream& operator << (ostream& os, Check& check){
    os << check.checkNum << " " << check.checkAmount << " " << check.checkMemo << endl;
    return os;
}
//writes the check and updates members as needed
bool CheckBook::writeCheck(Check c_amount) {
        if (c_amount > balance)
            return false;
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
//display checks in chronological order staring from the most recent
void const CheckBook::displayChecks() {
    for(int i=numberOfChecks;i>0;i--)
        cout << chkPtr[i-1];
}
//runs the functions created to make sure checkbook doubles when necessary, makes sure the writecheck function is working properly, and makes sure the displayChecks function is also working properly
void checkTest(CheckBook checkBook, int bal){
    cout << "_________________________________________\nLast Deposit written as a check is made, balance after the check goes through, and notification for the new checkbook being ordered:\n"<< endl;
    Check c_amount;
    c_amount.checkAmount = 37;
    while (c_amount<=checkBook.getBalance()) {
    checkBook.setBalance(bal);
    c_amount.checkAmount = 334;
    checkBook.writeCheck(c_amount);
    checkBook.lastDeposit();
    cout << checkBook.getBalance() << endl;
        if(checkBook.getCheckBookSize()/2==checkBook.getNumberOfChecks())
            checkBook.doubleCheckBookSize();
    bal-=c_amount.checkAmount;
    }
    cout << "\n_________________________________________\nChecks from most recent to the first written check:\n"<< endl;
    checkBook.displayChecks();
    cout << "\n_________________________________________\n"<< endl;
}
//displays the last deposited amount
void CheckBook::lastDeposit() {
    cout<<chkPtr[numberOfChecks-1];
}
//doubles the size of the check book
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