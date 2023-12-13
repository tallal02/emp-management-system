#include <iostream>
#include "User.h"
#include "Patient.h"
#include "Admin.h"
#include "Doctor.h"
//#include "Payment.h"

using namespace std;

int main() 
{
	unsigned long long int a = 0;
	int choice = 0, choice2 = 0, choice3 = 0, choice4 = 0;
	User* ptr;
	string n;
	cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * " << endl;
	cout << "\t\t\t\t*                                             *" << endl;
	cout << "\t\t\t\t*         Welcome to OLADOC !!                *" << endl;
	cout << "\t\t\t\t*                                             *" << endl;
	cout << "\t\t\t\t*	   Press 1 for Admin                  *" << endl;
	cout << "\t\t\t\t*          Press 2 for Doctor                 *" << endl;
	cout << "\t\t\t\t*          Press 3 for Patient                *" << endl;
	cout << "\t\t\t\t*                                             *" << endl;
	cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * " << endl;
	cout << endl << endl;
	cout << "\t\tEnter Choice: ";
	cin >> choice;
	system("CLS");
	switch (choice) 
	{
		case 1:
		{
			Admin ad;
			cout << "\t\tDo you wish to \n\t\t1)Login \n\t\t2)Register \n\t\tEnter: ";
			cin >> choice2;
			cout << endl;
			if (choice2 == 1)
			{
				ptr = &ad;
				ptr->Login();
			}
			else if (choice2 == 2) 
			{
				ptr = &ad;
				ptr->Register();
				/*obj.Login();*/
			}
			int option = 0;
			while (option != 7) 
			{
				system("CLS");
				cout << "\t\tMENU" << endl;
				cout << "\t\tPress 1 to Add Doctor : " << endl;
				cout << "\t\tPress 2 to View Doctor: " << endl;
				cout << "\t\tPress 3 to Delete Doctor : " << endl;
				cout << "\t\tPress 4 to View Patient Data : " << endl;
				cout << "\t\tPress 5 to Schedule Doctor Appointments : " << endl;
				cout << "\t\tPress 6 to View Doctor Appointments : " << endl;
				cout << "\t\tPress 7 to logout" << endl;
				cout << "\n\t\tEnter Option : ";
				cin >> option;
				if (option == 3)
				{
					cout << "\n\t\tEnter Doctor CNIC: ";
					cin >> a;
					ad.DelDoc(a);
				}
				else if ( option == 2)
				{
					cout << "\n\t\tEnter Doctor Name: ";
					cin >> n;
					ad.ViewDoc(n);
				}
			}
			break;
		}
		case 2:
		{
			Doctor doc;
			cout << "\t\tDo you wish to \n\t\t1)Login \n\t\t2)Register \n\t\tEnter: ";
			cin >> choice3;
			cout << endl;
			if (choice3 == 1)
			{
				ptr = &doc;
				ptr->Login();
			}
			else if (choice3 == 2)
			{
				ptr = &doc;
				ptr->Register();
			}
			int option = 0;
			while (option != 7)
			{
				system("CLS");
				cout << "\n\t\tMENU" << endl;
				cout << "\t\tPress 1 to Add Availability : " << endl;
				cout << "\t\tPress 2 to Edit Availability: " << endl;
				cout << "\t\tPress 3 to Delete Availability : " << endl;
				cout << "\t\tPress 4 to View Appointments: " << endl;
				cout << "\t\tPress 5 to Set Status of Pending Appointment : " << endl;
				cout << "\t\tPress 6 to Edit Own Details : " << endl;
				cout << "\t\tPress 7 to logout" << endl;
				cout << "\n\t\tEnter Option : ";
				cin >> option;
			}
			break;
		}
		case 3:
		{
			Patient p;
			cout << "\t\tDo you wish to \n\t\t1)Login \n\t\t2)Register \n\t\tEnter: ";
			cin >> choice4;
			cout << endl;
			if (choice4 == 1) {
				ptr = &p;
				ptr->Login();
			}
			else if ( choice4 == 2) 
			{
				ptr = &p;
				ptr->Register();
			}
			int option = 0;
			while (option != 10)
			{
				system("CLS");
				cout << "\t\tMENU" << endl;
				cout << "\t\tPress 1 to Reset Password : " << endl;
				cout << "\t\tPress 2 to Search Doctor: " << endl;
				cout << "\t\tPress 3 to Doctor Availability : " << endl;
				cout << "\t\tPress 4 to Book Appointments: " << endl;
				cout << "\t\tPress 5 to Cancel Appointments : " << endl;
				cout << "\t\tPress 6 to Update Appointment Details : " << endl;
				cout << "\t\tPress 7 to Change Details" << endl;
				cout << "\t\tPress 8 to Specify Type of Appointment(F2F/Online)" << endl;
				cout << "\t\tPress 9 to Recharge Account" << endl;
				cout << "\t\tPress 10 to logout" << endl;
				cout << "\n\t\tEnter Option : ";
				cin >> option;
			}
			break;
		}
		default:
			cout << "Wrong Choice!";
	}
	/*Payment p;
	p.Method();*/

}
	
