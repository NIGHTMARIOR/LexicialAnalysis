#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include "stdafx.h"
#include "LexicialAnalysis.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bitset>
using namespace std;


ofstream ofile;
string getInputStream()
{
	ifstream inputStream("./data.txt");
	string inputString, line;
	while (getline(inputStream, line))
	{
		inputString += line + "\n";
	}
	return inputString;
}

void printConstant(string string_temp)
{
	bool isFloat = false;
	for (int i = 0; i < string_temp.size(); i++)
		if (string_temp[i] == '.')
		{
			isFloat = true;
			break;
		}

	if (!isFloat)
	{
		int int_temp;
		stringstream stream;
		stream << string_temp;
		stream >> int_temp;
		ofile << bitset<sizeof(int) * 8>(int_temp) << endl;
	}
	else
	{
		ofile << string_temp << endl;
	}
}

int main()
{
	ofile.open("./result.txt");
	ofile.flags(ios::left);
	string inputStream = getInputStream();
	LexicialAnalysisProgram LAP(inputStream);

	try
	{
		//ofile << setw(15) << "name" << setw(15) << "kind" << setw(15) << "value" << endl;
		while (true)
		{
			WORD tmp = LAP.GetToken();
			//ofile << setw(15) << tmp.name << setw(15) << tmp.kind;
			ofile << tmp.name << endl;
			ofile << tmp.kind << endl;

			if (tmp.kind == "KEYWORD" || tmp.kind == "DELIMITER" || tmp.kind == "OPERATOR" || tmp.kind == "BINARYOPERATOR" || tmp.kind == "IDENTIFIER")
				//ofile << setw(15) << tmp.name << endl;
				ofile << tmp.name << endl;

			if (tmp.kind == "CONSTANT")
				printConstant(tmp.name);

			if (tmp.kind == "ERROR")
				ofile << endl;
		}
	}
	catch (const EOFException&)
	{
	}
	ofile.close();
}
