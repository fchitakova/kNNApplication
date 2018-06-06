#include "stdafx.h"
#include "Company.h"

Company::Company(unsigned income, Characteristics ch, bool isSuccessful,double d)
{
	this->income = income;
	this->ch = ch;
	this->isSuccessful = isSuccessful;
	this->distToTestC = d;
}

double Company::calculateDist(const Company & other)const
{
	return sqrt((this->income - other.income) * (this->income - other.income) +
		(this->ch - other.ch) * (this->ch - other.ch));
}




bool Company::operator<(const Company & other) const
{
	return distToTestC < other.distToTestC;
}

void Company::print()
{
	std::cout << "Income:" << this->income << " ;Team characteristics:" << this->ch << " ;Is successful:" << this->isSuccessful <<" Distance: "<<distToTestC<< '\n';
}



