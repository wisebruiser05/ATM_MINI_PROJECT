#include<conio.h>
#include<iostream>
#include<string>

using namespace std;

/*
    Mini Project - ATM
    -> Check Balance
    -> Check Withdraw
    -> User Details
    -> Update Mobile No.
*/

class atm  // atm class
{
    private:    // private member variables
        long int account_no;
        string name;
        int pin;
        double balance;
        string mobile_no;

    public:    // public member variables
        //setdata function is setting the data into the private member variables.

        void setdata(long int account_no_a, string name_a, int pin_a, double balance_a, string mobile_no_a)
        {   
            account_no = account_no_a;      // assigning the formal argument to the private member variables
            name = name_a;
            pin = pin_a;
            balance = balance_a;
            mobile_no = mobile_no_a;
        }

        //getAccountNo function is returning the user's account number.
        long int getaccountno()
        {
            return account_no;
        }

        //getName function is returning the user's name.
        string getname()
        {
            return name;
        } 

        //getPIN function is returning the user's PIN.
        int getpin()
        {
            return pin;
        }

        //getBalance function is returning the user's balance.
        double getbalance()
        {
            return balance;
        }

        //getMobileNo function is returning the user's mobile number.
        string getmobileno()
        {
            return mobile_no;
        }

        //setmobile function is uapdating user's mobile number.
        void setmobileno(string mobile_old, string mobile_new)
        {
            if(mobile_old == mobile_no)
            {
                mobile_no = mobile_new;
                cout << endl << "Successfully updated mobile number" ;
                _getch();
            }
            else
            {
                cout << endl << "Incorrect!!! Old Mobile No. " ;
                _getch();
            }
        }

        //cashWithdraw function is used to withdraw money from ATM wallet
        void cashwithdraw(int amount_a)
        {
            if(amount_a > 0 && amount_a < balance)
            {
                balance -= amount_a;
                cout << endl << "Please collect your caseh " ;
                cout << endl << "Available Balance: " << balance ;
                _getch();
            }
            else
            {
                cout << endl << "Insufficient balance : " << balance ;
                _getch();                                     //getch is to hold the screen ("Until user press any key")
            }
        }
};

int main()
        {
            int choice = 0, enterpin;      //enterPIN and enterAccountNo. ---> user authentication
            long int enteraccount_no;

            system("cls");

            //created user(object)
            atm user1;

            // Set user Details(into object)         (Setting Default Data)
            user1.setdata(12345687, "Tim", 1111, 45000.0, "9509018184");

            do
            {
                system("cls");
                cout << endl << "************Welcome to ATM**************" ;
                cout << endl <<"Enteraccountno " ;
                cin >> enteraccount_no;

                cout << endl << "Enter PIN ";
                cin >>  enterpin;

                //check whether enter values match with user details
                if((enteraccount_no == user1.getaccountno()) && (enterpin == user1.getpin()))
                {
                    do
                    {
                        int amount = 0;
                        string oldmobileno, newmobileno;

                        system("cls");
                        // user Interface
                        cout << endl << "******** Welcome to ATM **********" << endl ;
                        cout << endl << "Select Options " ;
                        cout << endl << "1. Check Balance " ;
                        cout << endl << "2. Cash Withdraw " ;
                        cout << endl << "3. Show User Details " ;
                        cout << endl << "4. Update Mobile No. " ;
                        cout << endl << "5. Exit " << endl ;
                        cin >> choice;                                    // Taking input from user

                        switch(choice)                                   // switch condition
                        {
                            case 1:                                     // if user press 1
                                cout << endl << "Your Bank Balance is : " << user1.getbalance();  // getbalance() is.... printing the user account balance
                                _getch();
                                break;
                            case 2:                                     // if user press 2
                                cout << endl << "Enter the amount : " ;
                                cin >> amount;
                                user1.cashwithdraw(amount);     //calling cashwithdraw function and passing the withdraw amount 
                                _getch();
                                break;
                            case 3:                                     // if user press 3
                                cout << endl << "User Details are :- ";
                                cout << endl << "--> Account No. " << user1.getaccountno();
                                cout << endl << "--> Name " << user1.getname();
                                cout << endl << "--> Balance " << user1.getbalance();
                                cout << endl << "--> Mobile No. " << user1.getmobileno();    // getting and printing details
                                _getch();
                                break;
                            case 4:                                     // if user press 4
                                cout << endl << "Enter Old Mobile No. " ;
                                cin >> oldmobileno;                    //take old mobile no.

                                cout << endl << "Enter New Mobile No. " ;
                                cin >> newmobileno;                     //take new mobile no.

                                user1.setmobileno(oldmobileno, newmobileno);      // now set user's new mobile number
                                _getch();
                                break;
                            case 5:                                     // if user press 5
                                exit(0);
                            default:                                   //handle invalid input
                                cout << endl << "Enter Valid Data!!!";
                        }
                    }
                    while(1);       //MENU   condition always true and loop 
                }

                else
                {
                    cout << endl << "User Details are Invalid !!!";
                    _getch();
                }
            }
            while(1);                               // LOGIN  condition will always True nad loop is

            return 0;
        }