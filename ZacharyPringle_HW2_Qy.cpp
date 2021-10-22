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
    void setBalance(int amount){balance=amount;}
    void setCheckBookSize();//still need to write
    void setNumberOfChecks(int num){numberOfChecks=num;}
    int const getNumberOfChecks(){return numberOfChecks;}
    int const getCheckBookSize(){return checkBookSize;}
    float const getBalance(){return balance;}
    CheckBook(): balance(0), numberOfChecks(0), checkBookSize(4){}
    CheckBook(int num): numberOfChecks(0), checkBookSize(2) {balance=num;}
    ~CheckBook();
    //CheckBook(const Check &check) {=check.checkAmount; }//still need to write - Copy Constructor
    //CheckBook operator=(&)//still need to write - overloaded assignment operator
    void deposit(int amount){balance+=amount;}
    bool writeCheck(Check c_amount);
    void displayChecks();
private:
    float balance;
    int numberOfChecks,checkBookSize;
};

//CheckBook operator=(&)//still need to write - overloaded assignment operator


int main() {


    return 0;
}

bool operator > (Check& check, float amount){
   if (check.checkAmount>amount){
       cout << "The amount is greater" << endl;
       return true;
   }
   cout << "The amount is not greater" << endl;
    return false;
}

ostream& operator << (ostream& os, Check& check){
    os << check.checkNum << " " << check.checkAmount << " " << check.checkMemo << endl;
    return os;
}


void CheckBook::displayChecks() {

}