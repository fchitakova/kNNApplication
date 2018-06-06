#include "stdafx.h"
#include "ComputeData.h"

ComputeData::ComputeData(char*argv[4])
{

	toTest = new Company(atoi(argv[1]), getCharacteristics(argv[2]));


	int size = strlen(argv[3]) + 1;

	this->filename = new char[size];

	strcpy_s(this->filename, size, argv[3]);


	readData();
}


ComputeData::~ComputeData()
{
	delete toTest;
	toTest = 0;
	delete[]filename;
	filename = 0;
}

int ComputeData::classifyCompany(int K)
{
	for (std::vector<Company>::iterator it = companies.begin(); it != companies.end(); ++it) 
	{
		it->setDist(it->calculateDist(*toTest));
	}

	std::sort(companies.begin(), companies.end());

	int freq0 = 0, freq1 = 0;     // Frequency of group 0 and 1
	
	int i = 0;
	for (std::vector<Company>::iterator it=companies.begin();i<K && it!=companies.end();++it,++i)
	{
		if (!(it->getSuccess()))
			++freq0;
		else
			++freq1;
	}

	return (freq0 > freq1 ? 0 : 1);

}

Company::Characteristics ComputeData::getCharacteristics(char * str) const
{
	Company::Characteristics ch;
	if (strcmp(str, "Weak") == 0)
		ch = Company::Characteristics::Weak;
	if (strcmp(str, "Average") == 0)
		ch = Company::Characteristics::Average;
	if (strcmp(str, "Strong") == 0)
		ch = Company::Characteristics::Strong;
	if (strcmp(str, "Very Strong") == 0)
		ch = Company::Characteristics::VeryStrong;

	return ch;
}

void ComputeData::readData()
{

	std::ifstream data(filename);

	std::string line;
	std::getline(data, line);
	
	if (data.is_open())
	{

		while (std::getline(data, line))
		{
			int size = line.length() + 1;

			char*str = new char[size];

			strcpy_s(str, size, line.c_str());

			char*helperStr = new char[size];

			int i = 0, j = 0;

			unsigned income;
			bool success;

			while (str[i] != ';')
			{
				helperStr[j++] = str[i++];
			}
			helperStr[j] = '\0';

			income = atoi(helperStr);

			++i;

			j = 0;

			while (str[i] != ';')
			{
				helperStr[j++] = str[i++];
			}
			helperStr[j] = '\0';

			Company::Characteristics ch = getCharacteristics(helperStr);

			++i;

			j = 0;

			while (i < size - 1)
			{
				helperStr[j++] = str[i++];
			}
			helperStr[j] = '\0';

			success = (atoi(helperStr) == 1) ? true : false;




			delete[]helperStr;
			helperStr = NULL;
			delete[]str;
			str = NULL;

			Company toInsert(income, ch, success);

			companies.push_back(toInsert);
		}

		data.close();
	}
	else
		std::cout << "File cannot be opened!\n";
}



void ComputeData::printData()
{
	for (std::vector<Company>::iterator it = companies.begin(); it != companies.end(); ++it)
		(*it).print();
	std::cout << '\n';
}
