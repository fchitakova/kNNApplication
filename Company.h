#pragma once


#ifndef COMPANY_H
#define COMPANY_H


#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

class Company
{


public:

	enum Characteristics { Weak, Average, Strong, VeryStrong };

	Company(unsigned income = 0, Characteristics ch = Weak,bool isSuccessful = false, double d = 0.0);
	
	double calculateDist(const Company&other)const;

	double getDist()const { return this->distToTestC; }

	bool getSuccess()const { return this->isSuccessful; }

	bool operator<(const Company & other)const;

	void setDist(double d) { this->distToTestC = d; }

	void print();


private:

	unsigned income;
    
	Characteristics ch;

	bool isSuccessful;

	double distToTestC; //distance to test company

};


#endif
