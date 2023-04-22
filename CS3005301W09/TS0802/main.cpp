/***********************************************************************
 * File: main.cpp
 * Author: ·¨¶v¦w
 * Create Date: 2023/04/22
 * Editor: ·¨¶v¦w
 * Update Date: 2023/04/22
 * Description: Matrix multiplication.
***********************************************************************/
#include<iostream>
#include<vector>
using namespace std;

int main()
{	
	//a matrix row and col , b matrix row and col
	int rowA, rowB, colA, colB;
	//input rowA colA rowB colB
	cin >> rowA >> colA >> rowB >> colB;
	//if colA not equal row B print Matrix multiplication failed and quit 
	if (colA != rowB)
	{	
		cout << "Matrix multiplication failed.";
		return 0;
	}
	//init the a b c matrix
	vector<vector<int>>a(rowA, vector<int>(colA, 0));
	vector<vector<int>>b(rowB, vector<int>(colB, 0));
	vector<vector<int>>c(rowA, vector<int>(colB, 0));
	//input a matrix
	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colA; j++)
		{
			cin >> a[i][j];
		}
	}
	//input b matrix
	for (int i = 0; i < rowB; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			cin >> b[i][j];
		}
	}
	//multip a and b to c matrix
	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			for (int k = 0; k < colA; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	//ouput c matrix
	for (int i = 0; i < rowA; i++)
	{	
		//if i > 0 need \n
		if (i > 0)cout << endl;
		for (int j = 0; j < colB; j++)
		{	
			//if j > 0 need " "
			if (j > 0)cout << " ";
			cout << c[i][j];
		}
	}
	return 0;
}