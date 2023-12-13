//#pragma once
//#include <iostream>
//using namespace std;
//
//class Doctor {
//	string name;
//	string password, retry;
//	int ID;
//	double hourlycharge;
//	string city;
//	string hospital;
//public:
//	void Register() {
//		cout << "Welcome To The Registration Panel!" << endl;
//		cout << "Please Enter your Name: ";
//		cin >> name;
//		cout << "Please Enter your Password: ";
//		cin >> password;
//		cout << "Please Re-enter your Password: ";
//		cin >> retry;
//		cout << "Please Enter your ID: ";
//		cin >> ID;
//		while (password != retry)
//		{
//			cout << "Password's enter don't match !" << endl;
//			cout << "Please Enter your Password: ";
//			cin >> password;
//			cout << "Please Re-enter your Password: ";
//			cin >> retry;
//		}
//		cout << endl << "Successfully Registered !! Mr/Mrs" << name << endl;
//	}
//	void Login(string n, string p) {
//		if ( n == name && password == p) cout << "Login Successful !! Mr/Mrs" << name << endl;
//	}
//
//
//};

#pragma once
#include <iostream>
#include "User.h"
#include "Patient.h"
#include <fstream>
#include <cstring>
using namespace std;

class Doctor : public User {
protected:
	char specialization[15], city[15], hospital[30], availfrom[15], toavail[15];
	int hourlycharges, yearsexperience;
public:
	Doctor( string spec = "", string cit = "", string hos = "", string av_from = "", string av_to = ""
		, int years = 0, unsigned long long int c = 0, int hourly = 0, string usertype = "doctor", string n = "", string pass = "") {
		//Copy Constructor so copying data given to original data members
		//using built in strcpy_s to copy string data to char
		//strcpy_s(email, emel.c_str());
		strcpy_s(specialization, spec.c_str());
		strcpy_s(city, cit.c_str());
		strcpy_s(hospital, hos.c_str());
		strcpy_s(availfrom, av_from.c_str());
		strcpy_s(toavail, av_to.c_str());
		CNIC = c;
		hourlycharges = hourly;
		yearsexperience = years;
		strcpy_s(name, n.c_str());
		strcpy_s(password, pass.c_str());
	}
	char* getspecialization() {
		return specialization;
	}
	char* getcity() {
		return city;
	}
	char* gethospital() {
		return hospital;
	}
	char* getavailfrom() {
		return availfrom;
	}
	char* gettoavail() {
		return toavail;
	}
	int gethourlycharges() {
		return hourlycharges;
	}
	int getyearsexperience() {
		return yearsexperience;
	}

	void Display() {
		cout << name << endl << CNIC << endl << hourlycharges << endl << specialization << endl;
	}
	bool checkerCNIC(unsigned long long int c)
	{
		if (c > 999999999999 && c < 10000000000000) return true;
		else return false;
	}
	
	void Register() 
	{
		system("CLS");
		cout << "\n\t\tDoctor Panel" << endl << "\t\tRegistration" <<endl;
		cout << "\t\tUsername: ";
		cin >> this->name;
		cout << endl << "\t\tPassword: ";
		cin >> this->password;
		
		cout << endl << "\t\tRe-enter Password: ";
		cin >> this->retry;
		passwordchecker(this->password);
		//passwordchecker(this->retry);
		/*while (this->password != this->retry) {
			cout << "Both Passwords Must Match! " << endl;
			cout << "Enter Password: ";
			cin >> this->password;
			passwordchecker(this->password);
			cout << "Re-enter Password: ";
			cin >> this->retry;
			passwordchecker(this->retry);
		}*/
		
		cout << endl << "\t\tCNIC: ";
		cin >> this->CNIC;
		//this->type = "Doctor";
		bool x = false;
		x = checkerCNIC(CNIC);
		while (x == false)
		{
			cout << "Invalid CNIC  \nEnter Again: ";
			cin >> CNIC;
			x = checkerCNIC(CNIC);
		}

		//passwordchecker(this->password);
		
		//User obj(this->name, this->password, "Doctor", this->retry, this->CNIC);

		
		

		/*ifstream fin("Doctor.bin", ios::binary | ios::app);
		while (fin.read((char*)&obj, sizeof(obj))) {
			obj.Display();
		}
		fin.close();*/

		cout << "\t\tSpecialization: ";
		cin >> this->specialization;
		cout << endl << "\t\tCity: ";
		cin >> this->city;
		cout << endl << "\t\tHospital Name: ";
		cin >> this->hospital;
		cout << endl << "\t\tAvailable From: ";
		cin >> this->availfrom;
		cout << endl << "\t\tAvailable Till: ";
		cin >> this->toavail;
		cout << endl << "\t\tHourly Rate: ";
		cin >> this->hourlycharges;
		cout << endl << "\t\tYears of Experience: ";
		cin >> this->yearsexperience;

	
		/*Doctor( string spec = "", string cit = "", string hos = "", string av_from = "", string av_to = ""
		, int years = 0, unsigned long long int c = 0, int hourly = 0, string usertype = "doctor", string n = "", string pass = "") {*/
		//saving all given info in an Doctor obj with type Doctor
		Doctor doc(this->specialization, this->city, this->hospital, this->availfrom, this->toavail, this->yearsexperience,
			this->CNIC, this->hourlycharges, "Doctor", this->name, this->password);
		

		//Copying informatio from Doctor obj to Binary File
		ofstream fout("Doctor.bin", ios::binary | ios::app);
		fout.write((char*)&doc, sizeof(doc));
		fout.close();
	}
	
	

};

