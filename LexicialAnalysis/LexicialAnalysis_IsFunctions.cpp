#pragma once
#include "stdafx.h"
#include "LexicialAnalysis.h"


bool LexicialAnalysisProgram::isLetter(string str)
{
	string pattern{ "[A-Za-z]" };
	regex re(pattern);
	return regex_match(str, re);
}

bool LexicialAnalysisProgram::isDigit(string str)
{
	regex pattern("[0-9]");
	return regex_match(str, pattern);
}

bool LexicialAnalysisProgram::isDelimiter(string str)
{
	for (int i = 0; i < Delimiters.size(); i++)
		if (str == Delimiters[i].name)
			return true;

	return false;
}

bool LexicialAnalysisProgram::isOperator(string str)
{
	for (int i = 0; i < Operators.size(); i++)
		if (str == Operators[i].name)
			return true;
	if (str == ":")
	{
		nextChar();
		try
		{
			if (getChar() == "=")
			{
				lastChar();
				return true;
			}
		}
		catch (const std::exception&)
		{
		}
		lastChar();
	}
	return false;
}

bool LexicialAnalysisProgram::isBinaryOperator(string str)
{
	for (int i = 0; i < BinaryOperators.size(); i++)
		if (str == BinaryOperators[i].name)
			return true;

	return false;
}

bool LexicialAnalysisProgram::isNBC(string chr)
{
	return chr == " " || chr == "\t" || chr == "\n";
}

bool LexicialAnalysisProgram::isKeyword(string token)
{
	for (int i = 0; i < KeyWords.size(); i++)
		if (token == KeyWords[i].name)
			return true;
	return false;
}

bool LexicialAnalysisProgram::isEOF(string token)
{
	return token == "" ? true : false;
}
