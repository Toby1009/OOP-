/************************************************************************
 * File: Atoi.h
 * Author: ·¨¶v¦w
 * Create Date: 2023-04-13
 * Editor: ·¨¶v¦w
 * Update Date:2023-04-13
 * Description: Define Atoi class
 ************************************************************************/
#pragma once
#include <string>
using namespace std;
//Atoi class define,can set string ,get string ,check digital ,return number length,convert string to int
class Atoi {

private:
	string beTrans;
	
public:
	//init Atoi class
	Atoi();
	//init Atoi class and set beTrans
	Atoi(string s);
	//set beTrans
	void SetString(string s);
	//get beTrans
	const string GetString();
	//get number length
	int Length();
	//check beTrans is digital or not
	bool IsDigital();
	//convert string to int
	int StringToInteger();

};