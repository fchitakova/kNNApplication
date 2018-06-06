#pragma once

#ifndef COMPUTE_DATA_H
#define COMPUTE_DATA_H


#include "Company.h"

class ComputeData
{

public:
	
	ComputeData(char*argv[4]);
	
	~ComputeData();
   

	int classifyCompany(int K);

	void printData();


private:
	
	Company::Characteristics getCharacteristics(char*str)const;

	void readData();

private:
	
	char*filename;

	Company*toTest;

	//training samples
	std::vector<Company>companies;
};





#endif