#pragma once
#include <iostream>
#include <fstream>
#include "User.h"
#include "Patient.h"
#include "Admin.h"
#include "Doctor.h"

using namespace std;

class Admin : public User{
public:
	void DelDoc(unsigned long long int cnic) {
		////////////////
		Doctor a;
		ifstream fin("Doctor.bin", ios::binary | ios::app);
		while (fin.read((char*)&a, sizeof(a))) {
			a.Display();
		}
		fin.close();
		//////////////////
		Doctor obj;
		fstream f("Doctor.bin", ios::in | ios::binary);
		fstream t("temp.bin", ios::out | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{
			if (obj.getCNIC() != cnic)
			{
				t.write((char*)&obj, sizeof(obj));
			}
		}
		f.close();
		t.close();

		remove("Doctor.bin");
		rename("temp.bin", "Doctor.bin");
		/////////////////
		
	}
	void ViewDoc(string un)
	{
		Doctor temp;
		bool invalid = false, same = false;
		do
		{
			invalid = false;
			same = false;
			ifstream fin("User.dat");
			while (fin.read((char*)&temp, sizeof(User)))
			{
				//int tempn = 0;
				string ptrtemp = temp.getname();

				if (un == ptrtemp)
				{
					same = true;
					break;
				}
				else if (un.length() > 20) {
					invalid = true;
				}
			}
			fin.close();
			

		} while (same == true);
		if (same = true) cout << temp.getname() << endl << temp.gethospital() << endl << temp.getcity() << endl << temp.gethourlycharges();
	}
	friend ostream& operator << (ostream& out, const Admin& c);
	friend istream& operator >> (istream& in, Admin& c);
};
ostream& operator << (ostream& out, const Admin& c)
{
	out << c.name;
	out << c.CNIC;
	return out;
}

istream& operator >> (istream& in, Admin& c)
{
	in >> c.name;
	in >> c.password;
	in >> c.CNIC;
	return in;
}