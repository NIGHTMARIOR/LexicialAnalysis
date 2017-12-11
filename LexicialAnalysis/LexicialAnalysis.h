#pragma once
#include "stdafx.h"
#include <regex>
#include <sstream>
#include "WORD.h"
#include "Exception.h"
using namespace std;

class LexicialAnalysisProgram
{
public:
	LexicialAnalysisProgram(string);
	WORD GetToken();
private:
	string inputStream;
	int len = 0;
private:
	WORD decideWord();
	//�жϺ���
	bool isLetter(string);
	bool isDigit(string);
	bool isDelimiter(string);
	bool isOperator(string);
	bool isBinaryOperator(string);
	bool isNBC(string);
	bool isKeyword(string);
	bool isEOF(string);
	//��ȡ����
	WORD getStrToken();
	WORD getDigToken();
	WORD getDelToken();
	WORD getOperator();
	WORD getBinaryOperator(string);
	WORD getIllegalChar();
	//���ߺ���
	void skipNBC();
	string getChar();
	void nextChar();
	void lastChar();
	void catToken(string, string&);
	string composeStrToken();
	string composeDigToken();
	void preprocessor();
};