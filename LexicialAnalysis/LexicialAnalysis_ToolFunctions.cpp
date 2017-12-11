#include "stdafx.h"
#include "LexicialAnalysis.h"

void LexicialAnalysisProgram::preprocessor()
{
	skipNBC();
	/*while (getChar() == "/")
	{
		nextChar();
		if (getChar() == "*")
		{
			while (true)
			{
				do
				{
					nextChar();
				} while (getChar() != "*");
				nextChar();
				if (getChar() == "/")
				{
					nextChar();
					break;
				}
			}
		}
		else if (getChar() == "/")
		{
			do
			{
				nextChar();
			} while (getChar() != "\n");
			nextChar();
		}
		else
		{
			lastChar();
			break;
		}

		skipNBC();
	}*/

}

void LexicialAnalysisProgram::skipNBC()
{
	while (isNBC(getChar()))
	{
		nextChar();
	}
}

string LexicialAnalysisProgram::getChar()
{
	return inputStream.substr(len, 1);
}

void LexicialAnalysisProgram::nextChar()
{
	++len;
}

void LexicialAnalysisProgram::lastChar()
{
	--len;
}

void LexicialAnalysisProgram::catToken(string str, string &token)
{
	token += str;
}

string LexicialAnalysisProgram::composeStrToken()
{
	string token = "";
	while (isLetter(getChar()) || isDigit(getChar()))
	{
		catToken(getChar(), token);
		nextChar();
	}

	return token;
}

string LexicialAnalysisProgram::composeDigToken()
{
	string token = "";
	while (isDigit(getChar()))
	{
		catToken(getChar(), token);
		nextChar();
	}
	if (getChar() == ".")
	{
		nextChar();
		if (isDigit(getChar()))
		{
			catToken(".", token);
			while (isDigit(getChar()))
			{
				catToken(getChar(), token);
				nextChar();
			}
		}
		else
		{
			lastChar();
		}
	}
	return token;
}

