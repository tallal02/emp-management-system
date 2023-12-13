#pragma once
#include <iostream>
#include "User.h"
#include "Patient.h"
#include "Admin.h"
#include "Doctor.h"

using namespace std;

class Appointment {
protected:
	double charge;
	char pat_name[20], doc_name[20], feedback[50];
	char checker;
public:
	Appointment()
	{
		for (int i = 0; i < 20; i++)
		{
			pat_name[i] = '\0';
		}
		for (int i = 0; i < 20; i++)
		{
			doc_name[i] = '\0';
		}
		for (int i = 0; i < 50; i++)
		{
			feedback[i] = '\0';
		}
		charge = 0.00;
		checker = 0;
	}

		void setpat_name(string p) 
		{
			for (int i = 0; p[i] != '\0'; i++)
				pat_name[i] = p[i];
		}
		void setdoc_name(string d){
			for (int i = 0; d[i] != '\0'; i++)
				doc_name[i] = d[i];
		}
		void setfeedback(string f){
			for (int i = 0; f[i] != '\0'; i++)
				feedback[i] = f[i];
		}
		void setcharge(double c){
			charge = c;
		}
		void setchecker(char c) {
			checker = c;
		}

		char* getpat_name() {
			return pat_name;
		}
		char* getdoc_name() {
			return doc_name;
		}
		char* getfeedback() {
			return feedback;
		}
		double getcharge() {
			return charge;
		}
		char getchecker() {
			return checker;
		}

	
};

class Time {
protected:
	char start[7], end[7];
	int hour1, min1, ampm, hour2, min2, AMPM;
public:
	Time(string s = "", string e = "", int hour1 = 0, int min1 = 0, int ampm = 0, int hour2= 0, int min2 = 0, int AMPM = 0) {
		strcpy_s(start, s.c_str());
		strcpy_s(end, e.c_str());
		this->hour1 = hour1;
		this->hour2 = hour2;
		this->min1 = min1;
		this->min2 = min2;
		this->ampm = ampm;
		this->AMPM = AMPM;
	}

	void setter() {
		cout << "\n\t\tAppointment Start Time: " << endl;
		cout << "\t\tEnter Hours: ";
		cin >> hour1;
		cout << "\t\tEnter Minutes: ";
		cin >> min1;
		cout << "\t\tEnter 1 for A.M \n\t\tEnter 2 for P.M \n\t\tEnter: ";
		cin >> ampm;

		cout << "\n\t\tAppointment End Time: " << endl;
		cout << "\t\tEnter Hours: ";
		cin >> hour2;
		cout << "\t\tEnter Minutes: ";
		cin >> min2;
		cout << "\t\tEnter 1 for A.M \n\t\tEnter 2 for P.M \n\t\tEnter: ";
		cin >> AMPM;

		if (hour1 >= 10)
		{
			start[0] = 48;
			start[0] = start[0] + (hour1 / 10);
			start[1] = 48;
			start[1] = start[1] + (hour1 % 10);
		}
		else
		{
			start[2] = 48;
			start[3] = 48 + hour1;
		}
		if (hour1 >= 10)
		{
			start[3] = 48;
			start[3] = start[0] + (min1 / 10);
			start[4] = 48;
			start[4] = start[1] + (min1 % 10);
		}
		else
		{
			start[3] = 48;
			start[4] = 48 + min1;
		}
		start[2] = ':';
		if (ampm == 1)
		{
			start[5] = 'A';
			start[6] = 'M';
		}
		else if (ampm == 2)
		{
			start[5] = 'P';
			start[6] = 'M';
		}
		/////////////////////////////////////
		if (hour2 >= 10)
		{
			end[0] = 48;
			end[0] = end[0] + (hour2 / 10);
			end[1] = 48;
			end[1] = end[1] + (hour2 % 10);
		}
		else
		{
			end[2] = 48;
			end[3] = 48 + hour2;
		}
		if (hour2 >= 10)
		{
			end[3] = 48;
			end[3] = end[0] + (min2 / 10);
			end[4] = 48;
			end[4] = end[1] + (min2 % 10);
		}
		else
		{
			end[3] = 48;
			end[4] = 48 + min2;
		}
		end[2] = ':';
		if (AMPM == 1)
		{
			end[5] = 'A';
			end[6] = 'M';
		}
		else if (AMPM == 2)
		{
			end[5] = 'P';
			end[6] = 'M';
		}
	}
	void getter() {
		cout << "Starting Time:";
		for (int i = 0; i < 7; i++)
			cout << start[i] << " - " << end[i];

	}
};
