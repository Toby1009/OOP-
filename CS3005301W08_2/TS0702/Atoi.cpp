/************************************************************************
 * File: Atoi.cpp
 * Author: 法秜
 * Create Date: 2023-04-13
 * Editor: 法秜
 * Update Date:2023-04-13
 * Description: Imp Atoi class
 ************************************************************************/
#include "Atoi.h"
#include <iostream>
#include<string>
using namespace std;
//init the Atoi class
Atoi::Atoi()
{
	this->beTrans.clear();
}
//Intent:init the Atoi class
//Pre:input the string
//Post:should not return,just set the beTrans use s
Atoi::Atoi(string s)
{
	this->beTrans = s;
}
//Intent:set the beTrans use s
//Pre:input the string
//Post:should not return,just set the beTrans use s
void Atoi::SetString(string s)
{
	this->beTrans = s;
}
//Intent:get the beTrans string
//Pre:should not input
//Post:return beTrans
const string Atoi::GetString()
{
	return beTrans;
}
//Intent:return the number 计
//Pre:should not input
//Post:return the number 计
int Atoi::Length()
{
	return beTrans[0] == '-' ? beTrans.size() - 1 : beTrans.size();
}
//Intent:check the string is digital or not
//Pre:should not input
//Post:return true if the string is digital ,or return false
bool Atoi::IsDigital()
{	
	if (beTrans[0] != '-' && !isdigit(beTrans[0]))return false;
	for (int i = 1; i < beTrans.size(); i++)
	{
		if (!isdigit(beTrans[i]))return false;
	}
	return true;
}
//Intent:string to int
//Pre:should not input
//Post:return int
int Atoi::StringToInteger()
{
	return stoi(beTrans);
}