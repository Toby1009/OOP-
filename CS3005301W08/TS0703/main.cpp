/***********************************************************************
 * File: main.cpp
 * Author: ·¨¶v¦w
 * Create Date: 2023/04/12
 * Editor: ·¨¶v¦w
 * Update Date: 2023/04/12
 * Description: Write a program that allowed users to input a string and then print the number characters with the style of seven-segment display.
***********************************************************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//0-9number have 7-segment so row is 10 column is 7
int num[10][7] =
{ 
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int main()
{
	string s;
	//getline until eof
	while (getline(cin, s))
	{	

		string c[6] = { "_" ," ","|"," ", " _ ","   "};
		//record first to third line
		vector<int> one;
		vector<int> two;
		vector<int> three;
		//string convet to  number and record the first to third line   
		for (int i = 0; i < s.size(); i++)
		{	
			//check the number is valid or not
			if (s[i] < '0' || s[i]>'9')continue;
			int n = s[i] - '0';
			//in 0 segment
			if (num[n][0])
			{
				one.push_back(4);
			}
			else
			{
				one.push_back(5);
			}
			//in 5 segment
			if (num[n][5])
			{
				two.push_back(2);
			}
			else
			{
				two.push_back(3);
			}
			//in 6 segment
			if (num[n][6])
			{
				two.push_back(0);
			}
			else
			{
				two.push_back(1);
			}
			//in 1 segment
			if (num[n][1])
			{
				two.push_back(2);
			}
			else
			{
				two.push_back(3);
			}
			//in 4 segment
			if (num[n][4])
			{
				three.push_back(2);
			}
			else
			{
				three.push_back(3);
			}
			//in 3 segment
			if (num[n][3])
			{
				three.push_back(0);
			}
			else
			{
				three.push_back(1);
			}
			//in 2 segment
			if (num[n][2])
			{
				three.push_back(2);
			}
			else
			{
				three.push_back(3);
			}
		}
		//print the first line
		for (int i = 0; i < one.size(); i++)
		{
			cout << c[one[i]];
		}
		cout << endl;
		//print the second line
		for (int i = 0; i < two.size(); i++)
		{
			cout << c[two[i]];
		}
		cout << endl;
		//print the third line
		for (int i = 0; i < three.size(); i++)
		{
			cout << c[three[i]];
		}
		cout << endl;
	}
}