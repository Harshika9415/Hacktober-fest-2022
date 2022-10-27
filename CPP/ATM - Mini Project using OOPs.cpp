#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/* Mini Project - ATM
   -> Check Balance
   -> Cash Withdraw
   -> User Details
   -> Update Mobile No.
*/


class atm										// class atm
{
private:										// private member variables
	long int account_No;
	string name;
	int PIN;
	double balance;
	string mobile_No;

public:											// public member functions

	// setData function is setting the Data into the private member variables
	void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
	{
		account_No = account_No_a;	 // assigning the formal arguments to the private member variables
		name = name_a;
		PIN = PIN_a;
		balance = balance_a;
		mobile_No = mobile_No_a;
	}

	//getAccountNo function is returning the user's account no.
	long int getAccountNo()
	{
		return account_No;
	}

	//getName function is returning the user's Name
	string getName()
	{
		return name;
	}

	//getPIN function is returning the user's PIN
	int getPIN()
	{
		return PIN;
	}

	//getBalance is returning the user's Bank Balance
	double getBalance()
	{
		return balance;
	}

	//getMobileNo is returning the user's Mobile No.
	string getMobileNo()
	{
		return mobile_No;
	}

	//setMobile function is Updating the user mobile no
	void setMobile(string mob_prev, string mob_new)
	{
		if (mob_prev == mobile_No)						// it will check old Mobile no
		{
			mobile_No = mob_new;						// and Update with new, if old matches
			cout << endl << "Successfully Updated Mobile No.";
			_getch();				//_getch() is to hold the screen ( until user presses any key )
		}

		else							// Does not update if old mobile no. does not matches
		{
			cout << endl << "Incorrect !!! Old Mobile No.";
			_getch();			  //_getch() is to hold the screen ( until user presses any key )
		}
	}

	//cashWithDraw function is used to withdraw money from ATM
	void cashWithDraw(int amount_a)
	{
		if (amount_a > 0 && amount_a <= balance)		// check entered amount validity
		{
			balance -= amount_a;		// balance = balance - amount_a
			cout << endl << "Please Collect Your Cash !";
			cout << endl << "Available Balance: " << balance;
			_getch();				//_getch() is to hold the screen(until user presses any key )
		}

		else
		{
			cout << endl << "Invalid Input or Insufficient Balance";
			_getch();				//_getch() is to hold the screen ( until user presses any key )
		}
	}

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int choice = 0, enterPIN;		//enterPIN and enterAccountNo. ---> user authentication
	long int enterAccountNo;

	system("cls");

	// created User ( object )
	atm user1;
	// Set User Details ( into object )         ( Setting Default Data )
	user1.setData(1234567, "Jack", 1111, 100000.0, "9087654321");


	do
	{
		system("cls");

		cout << endl << "***** Welcome to ATM *****" << endl;
		cout << endl << "Enter Your Account No.: ";	  // asking user to enter account no
		cin >> enterAccountNo;

		cout << endl << "Enter PIN: ";				 // asking user to enter PIN
		cin >> enterPIN;



		// check whether enter values matches with user details
		if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
		{
			do
			{
				int amount = 0;
				string oldMobileNo, newMobileNo;

				system("cls");
				// user Interface
				cout << endl << "***** Welcome to ATM *****" << endl;
				cout << endl << "Select Options:";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash Withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile No.";
				cout << endl << "5. Exit" << endl;
				cin >> choice;						// taking user choice

				switch (choice)						// switch condition
				{
				case 1:								// if user presses 1
					cout << endl << "Your Bank Balance is: " << user1.getBalance();
													// getBalance is ... printing the users	bank balance
					_getch();
					break;


				case 2:									// if user presses 2
					cout << endl << "Enter the Amount: ";
					cin >> amount;
					user1.cashWithDraw(amount);			// calling cashWithdraw function
													    // passing the withdraw amount
					break;


				case 3:										// if user presses 3
					cout << endl << "*** User Details are :- *** ";
					cout << endl << "-> Account No.: " << user1.getAccountNo();
					cout << endl << "-> Name: " << user1.getName();
					cout << endl << "-> Balance: " << user1.getBalance();
					cout << endl << "-> Mobile No.: " << user1.getMobileNo();
													// getting and printing user details
					_getch();
					break;


				case 4:								   //  if user presses 4
					cout << endl << "Enter Old Mobile No. ";
					cin >> oldMobileNo;							// take old mobile no

					cout << endl << "Enter New Mobile No. ";
					cin >> newMobileNo;							// take new mobile no

					user1.setMobile(oldMobileNo, newMobileNo);	// now set new mobile no
					_getch();
					break;


				case 5:                             // if user presses 5
					exit(0);						// exit application

				default:							// handle invalid user inputs
					cout << endl << "Enter Valid Data !!!";
					_getch();
				}

			} while (1);				// MENU	   // condition will always TRUE and loop is capable of running infinite times
		}

		else
		{
			cout << endl << "User Details are Invalid !!! ";
			_getch();
		}
	} while (1);					    //LOGIN	   // condition will always TRUE and loop is capable of running infinite times

	return 0;
}
