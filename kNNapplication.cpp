// kNNapplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComputeData.h"


int main(int argc, char* argv[])
{

	if (argc < 4) 
	{
		std::cerr << "Not enough command line arguments!\n";
		return 1;
	}
	else
	{
		ComputeData*c = new ComputeData(argv);

		int success=c->classifyCompany(3);

		if (success == 1)
			std::cout << "Company will be successful!\n";
		else
			std::cout << "Company will NOT be successful!\n";
		

		delete c;
		c = NULL;
	
	}
    return 0;
}

