#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class User {
protected:
	char name[30];
	char password[30], type[30], retry[30];
	unsigned long long int CNIC;
public:
	User(string n = "", string pass = "", string t = "", string rtry = "", unsigned long long int c = 0) {
		strcpy_s(name,n.c_str());
		strcpy_s(password, pass.c_str());
		strcpy_s(type, t.c_str());
		strcpy_s(retry, rtry.c_str());
		CNIC = c;

	};
	
	void setCNIC(unsigned long long int cnic) {
		CNIC = cnic;
	}
	char* getname() {
		return name;
	}
	char* getpassword() {
		return password;
	}
	char* gettype() {
		return type;
	}
	unsigned long long int getCNIC() {
		return CNIC;
	}
	virtual void Display() {
		cout << name << endl << password << endl << CNIC << endl;
	}
	virtual void Login() {
		string n, pass, usertype, repass;
		unsigned long long int c;
		int ch = 0;
		system("CLS");
		cout << "Enter your username:" << endl;
		cin >> n;
		cout << "Enter your password:" << endl;
		cin >> pass;
		cout << "Re-enter Password; " << endl;
		cin >> repass;
		while (pass != repass) {
			cout << "Both Passwords Must Match! " << endl;
			cout << "Enter Password: ";
			cin >> pass;
			cout << "Re-enter Password; ";
			cin >> repass;
		}
		cout << "Enter your CNIC:" << endl;
		cin >> c;
		cout << "Press 1 for Patient: \nPress 2 for Doctor: \nPress 3 for Admin :" << endl;
		cout << "Enter: ";
		cin >> usertype;
		//passing the given information to an User obj and making obj to check
		User x(usertype, n, pass,repass, c);
		//checking validity of info - mainly CNIC and password
		infochecker(x, c);
	
	}
	
	//To check whether CNIC and Password match
	void infochecker(User obj, int cnic) {
		User temp;
		bool x = true;
		int c = 0;
		ifstream fin("User.bin", ios::binary);
		while (fin.read((char*)&temp, sizeof(temp)))
		{
			system("CLS");
			if (temp.getCNIC() != cnic || temp.getpassword() != obj.password)
			{
				cout << "Login Failed !";
				x = false;
				break;
			}
			else cout << "Login Successful!" << endl;
		}

		if (x == false)
		{
			cout << "Press 1 to go back \nPress 2 to Register \nEnter: ";
			cin >> c;
			if (c == 1) Login();
			else if (c == 2) Register();
		}
		fin.close();
	}
	
	//Polymorphism
	virtual void Register(){}

	//Now counting objects in Binary File
	int obj_in_file() {
		unsigned long long int c = 0;
		User obj;
		ifstream fin("User.bin", ios::binary);
		while (fin.read((char*)&obj, sizeof(obj))) c++;
		fin.close();

		return c;
	}

	void passwordchecker(string p)
	{
		string pp;
		int size = 0, small = 0, large = 0, special = 0, number = 0;
		char checker[30];
		char spec[35]= "@(~!@#$%^&*_-+=`|\\(){}[]:;'<>,.?/)";
		strcpy_s(checker, p.c_str());
		//now to check size of password
		//for (int i = 0; checker[i] != '\0'; i++) size++;
		for (int i = 0; i < strlen(checker); i++)
		{
			if (checker[i] > 47 && checker[i] < 58) number++;
			if (checker[i] > 96 && checker[i] < 123) small++;
			if (checker[i] > 64 && checker[i] > 91) large++;
			for (int j = 0; j < 35; j++) 
			{
				if (checker[i] == spec[j]) 
					special++;
			}
			//if ((checker[i] > 31 && checker[i] < 48) || (checker[i] > 57 && checker[i] < 65) || (checker[i] > 90 && checker[i] < 97)) special++;
		}
		//system("CLS");
		if (number != 0 || small != 0 || large != 0 || special != 0)
		{
			cout << "Password Saved!";
			strcpy_s(this->password, p.c_str());
		}
		else {
			cout << "Wrong Password ! \nPassword Must contain 1 small, 1 large, 1 number & 1 special character !!";
			cout << endl << "Enter Again: ";
			cin >> pp;
			passwordchecker(pp);
			
		}
	}

	void UserWiper() {
		for (int i = 0; i < 30; i++)
			name[i] = '\0';
		for (int i = 0; i < 30; i++)
			password[i] = '\0';
		for (int i = 0; i < 30; i++)
			type[i] = '\0';
		CNIC = 0;

	}
};