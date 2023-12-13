#pragma once
#include <iostream>
#include "User.h"
#include "Doctor.h"
#include <fstream>
#include <cstring>
using namespace std;

//because Patient inherits User's functionalities
class Patient : public User{
protected:
	int age;
	char gender[10];
	double bal;
public:
	Patient(int a = 0, string g = "", double b = 5000, unsigned long long int c = 0, string usertype = "Patient", string n = "", string pass = "") {
		age = a;
		strcpy_s(gender, g.c_str());
		strcpy_s(name, n.c_str());
		strcpy_s(password, pass.c_str());
		CNIC = c;
		bal = b;
		/*Patient temp;
		bool check = false;
		ifstream fin("Patient.dat", ios::binary);
		string usernem;
		while (fin.read((char*)&temp, sizeof(Patient))) {
			if (usernem.compare(temp.getname()) == 0)
			{
				bal = temp.bal;
				check = true;
				break;
			}
		}
		fin.close();
		if (check == false)
		{
			
			ofstream f("Patient.bin", ios::binary | ios::app);
			f.write((char*)&*this, sizeof(Patient));
			f.close();
		}*/
	}
	bool checkerCNIC(unsigned long long int c)
	{
		if (c > 999999999999 && c < 10000000000000) return true;
		else return false;
	}
	void Register() {
		cout << "\t\t\nPatient Panel Registration: " << endl;
		cout << "\t\tUsername: ";
		cin >> this->name;
		cout << endl << "\t\tPassword: ";
		cin >> this->password;

		cout << endl << "\t\tRe-enter Password: ";
		cin >> this->retry;
		passwordchecker(this->password);
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

		cout << "\t\tAge: ";
		cin >> this->age;
		cout << "\t\tGender: ";
		cin >> this->gender;
		cout << "\t\tBalance: ";
		cin >> this->bal;
		
		/*Patient(int a = 0, string g = "", double b = 5000, 
		unsigned long long int c = 0, string usertype = "Patient", string n = "", string pass = "")*/
		//saving all given info in an Patient obj with type Patient
		Patient pat(this->age, this->gender, this->bal, this->CNIC, "Patient", this->name, this->password);
		
		//Copying informatio from Patient obj to Binary File
		ofstream fout("Patient.bin", ios::binary | ios::app);
		fout.write((char*)&pat, sizeof(pat));
		fout.close();
	}
	void DocSearch() {

	}
	bool DocAvail() {

	}
	void DocCharges() {

	}
	void updateProfile() {

	}
	void resetPass() {

	}
};
//void Doctor::DataEntry(string emel, string spec, string cit, string hos, string av_from, string av_to, unsigned long long int c, int hourly, string usertype, string n, string pass);


