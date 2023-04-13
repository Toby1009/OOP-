/***********************************************************************
 * File: main.cpp
 * Author: ���v�w
 * Create Date: 2023/04/13
 * Editor: Brendon
 * Update Date: 2023/04/13
 * Description: Levenshtein Distance 
***********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//Intent:find the two word levenshtein distance
//Pre:input two string s1 and s2
//Post:return int levenshtein distance
int levenshtein_distance(string s1, string s2)
{
	int n = s1.size();
	int m = s2.size();
	//creat 2D vector and init
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = i;
	}
	for (int j = 0; j <= m; j++)
	{
		dp[0][j] = j;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int c = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
			dp[i][j] = min({ dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + c });
		}
	}
	return dp[n][m];
}

int main()
{	
	string s1, s2;
	//get two line until eof
	while (getline(cin,s1)&&getline(cin,s2))
	{	
		//print the levenshtein distance
		cout << levenshtein_distance(s1, s2) << endl;
	}
	return 0;
}