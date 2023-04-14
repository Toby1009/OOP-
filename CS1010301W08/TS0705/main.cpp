/***********************************************************************
 * File: main.cpp
 * Author: ·¨¶v¦w
 * Create Date: 2023/04/15
 * Editor: ·¨¶v¦w
 * Update Date: 2023/04/15
 * Description: Cow Calculation
***********************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Intent:Convet string to int
//Pre:input string
//Post:int vector
vector<int> stringToNumber(string s)
{	
	vector<int> res;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
	{	
		switch (s[i])
		{
			case 'V':
				res.push_back(0);
			break;
			case 'U':
				res.push_back(1);
			break;
			case 'C':
				res.push_back(2);
			break;
			case 'D':
				res.push_back(3);
			break;
		}
	}

	return res;
}
//Intent:Convert int to string
//Pre:input int vectr
//Post:string
string numberToString(vector<int> a)
{	
	string res;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 0)
		{
			res = res + 'V';
		}
		else if (a[i] == 1)
		{
			res = res + 'U';
		}
		else if (a[i] == 2)
		{
			res = res + 'C';
		}
		else if (a[i] == 3)
		{
			res = res + 'D';
		}
	}
	reverse(res.begin(), res.end());
	return res;
}
//Intent:sum two int vector
//Pre:input two int vector
//Post:return int vector
vector<int> sum(vector<int> a, vector<int> b)
{
	int l = max(a.size(), b.size());
	int sum = 0;
	int carry = 0;
	vector<int> res;
	for (int i = 0; i < l; i++)
	{
		sum = carry;
		if (i < a.size())sum += a[i];
		if (i < b.size())sum += b[i];
		res.push_back(sum % 4);
		carry = sum / 4;
	}
	if (carry)
	{
		res.push_back(carry);
	}
	return res;
}
//Intent:right the int 
//Pre:input int vector
//Post:return int vector
vector<int> right(vector<int> b)
{	
	for (int i = 0; i < b.size()-1; i++)
	{
		b[i] = b[i + 1];
	}
	b[b.size() - 1] = 0;
	return b;
}
//Intent:left the int 
//Pre:input int vector
//Post:return int vector
vector<int> left(vector<int> b)
{	
	b.push_back(b[b.size() - 1]);
	for (int i = b.size() - 1; i > 0; i--)
	{
		b[i] = b[i - 1];
	}
	b[0] = 0;
	return b;
}
//Intent:accroding operation calcu two int vector
//Pre:input two int vector
//Post:return int vector
vector<int> calcu(vector<int> a, vector<int> b)
{
	char op;
	vector<string> res;
	cin >> op;
	switch (op)
	{
	case 'A':
		//if A sum
		b = sum(a, b);
		break;
	case 'R':
		//if R right
		b = right(b);
		break;
	case 'L':
		//if L left
		b = left(b);
		break;
	case 'N':
		//no action
		break;
	default:
		break;
	}
	return b;
}
int main()
{	
	int n; 
	cin >> n;
	cout << "COWCULATIONS OUTPUT" << endl;
	for (;n > 0; n--)
	{
		string num1, num2,res;
		cin >> num1 >> num2;
		//convert 
		vector<int> a = stringToNumber(num1);
		vector<int> b = stringToNumber(num2);
		//calcu accroding operation
		for (int i = 0; i < 3; i++)
		{
			b = calcu(a, b);
		}
		//format the result
		for (int i = b.size(); i < 8; i++)
		{
			b.push_back(0);
		}
		//convert
		num2 = numberToString(b);
		//input 
		cin >> res;
		//compare if true print YES,or print NO
		if (num2 == res)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

