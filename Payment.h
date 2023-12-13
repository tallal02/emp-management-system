#pragma once
#include <iostream>
#include "User.h"
#include "Patient.h"
#include "Admin.h"
#include "Doctor.h"

using namespace std;


class Payment {
protected:
	int ch, ch2, ch3;
public:
	Payment(int c = 0, int c2 = 0, int c3 = 0) {
		ch = c;
		ch2 = c2;
		ch3 = c3;
	}
	//virtual void bill() = 0;
	void Method() {
		system("CLS");
		Bank* ptr;
		ETransaction* pp;
		cout << "\n\t\tYour Payment Method: \n\t\t1)Bank Transfer \n\t\t2)E-Transaction \n\t\tEnter: ";
		cin >> ch;
		if (ch == 1)
		{
			cout << "\n\t\t1)PayPak \n\t\t2)UnionPay \n\t\tEnter: ";
			cin >> ch2;
			if (ch2 == 1) {

				PayPak p;
				ptr = &p;
				ptr->bill();
			}
			else if (ch2 == 2) {
				//Bank* ptr;
				UnionPay u;
				ptr = &u;
				ptr->bill();
			}
		}
		else if (ch == 2)
		{
			cout << "\n\t\t1)JazzCash \n\t\t2)Eidipaisa \n\t\tEnter: ";
			cin >> ch3;
			if (ch2 == 1) {

				JazzCash j;
				pp = &j;
				pp->bill();
			}
			else if (ch2 == 2) {
				//ETransaction* ptr;
				Eidipaisa e;
				pp = &e;
				pp->bill();
			}
		}

	}

};
class Bank : public Payment {
public:
	//Abstract Class Concept Used Here
	virtual void bill() = 0;
	//void bill(){}
};

class PayPak :public Bank {
public:

	void bill() {cout << "\t\tTransaction Successful! \n\t\tPayPak Used!" << endl;}
};

class UnionPay : public Bank {
public:

	void bill() {cout << "\t\tTransaction Successful! \n\t\tUnionPay Used!" << endl;}
};

class ETransaction : public Payment {
public:
	virtual void bill() = 0;
	//void bill(){}
};
class JazzCash : public ETransaction {
public:

	void bill() {cout << "\t\tTransaction Successful! \n\t\\JazzCash Used!" << endl;}
};
class Eidipaisa : public ETransaction {
public:

	void bill() {cout << "\t\tTransaction Successful! \n\t\\Eidipaisa Used!" << endl;}
};


