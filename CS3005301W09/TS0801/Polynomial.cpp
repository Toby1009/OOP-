#include "Polynomial.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

Polynomial::Polynomial()
{
	this->power = 1;
	this->coefficient = (double*)malloc(1 * sizeof(double));
}

Polynomial::~Polynomial()
{
	this->power = 0;
	this->coefficient = NULL;
}

Polynomial::Polynomial(double arr[], int n)
{
	this->power = n;
	this->coefficient = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		*(this->coefficient + i) = arr[i];
	}
}


double Polynomial::operator [] (int index)
{
	return this->power>index?this->coefficient[index]:NULL;
}

Polynomial& Polynomial::operator = (const Polynomial& other)
{
	this->power = other.power;
	if (this->coefficient != NULL)
	{
		double* temp = (double*)realloc(this->coefficient, other.power * sizeof(double));
		if (temp != NULL)
		{
			this->coefficient = (double*)realloc(temp, other.power * sizeof(double));
		}
	}
	for (int i = 0; i < other.power; i++)
	{
		*(this->coefficient + i) = *(other.coefficient + i);
	}
	return *this;
}

Polynomial Polynomial::operator + (const Polynomial& other)
{
	Polynomial result;
	int l = max(this->power, other.power);
	result.coefficient = (double*)realloc(result.coefficient,l * sizeof(double));
	for (int i = 0; i < l; i++)
	{
		double first = i < this->power ? this->coefficient[i] : double(0);
		double second = i < other.power ? other.coefficient[i] : double(0);
		*(result.coefficient + i) = first + second;
	}
	for (int i = l - 1; i >= 0; i--)
	{
		if (*(result.coefficient + i) == 0)l--;
		else break;
	}
	if (result.coefficient != NULL)
	{
		double* temp = (double*)realloc(result.coefficient, l * sizeof(double));
		if (temp != NULL)
		{
			result.coefficient = (double*)realloc(temp, l * sizeof(double));
		}
	}
	result.power = l;
	return result;
}

Polynomial Polynomial::operator - (const Polynomial& other)
{
	Polynomial result;
	int l = max(this->power, other.power);
	result.coefficient = (double*)realloc(result.coefficient,l *sizeof(double));
	for (int i = 0; i < l; i++)
	{	
		double first = i < this->power ? this->coefficient[i] : double(0);
		double second = i < other.power ? other.coefficient[i] : double(0);
		*(result.coefficient + i) = first - second;
	}
	for (int i = l-1; i >= 0; i--)
	{
		if (*(result.coefficient + i) == 0)l--;
		else break;
	}
	if (result.coefficient != NULL)
	{
		double* temp = (double*)realloc(result.coefficient,l * sizeof(double));
		if (temp != NULL)
		{
			result.coefficient = (double*)realloc(temp, l * sizeof(double));
		}
	}
	result.power = l;
	return result;
}

Polynomial Polynomial::operator * (const Polynomial& other)
{
	Polynomial result;
	unsigned int l = this->power + other.power -1;
	result.coefficient = (double*)realloc(result.coefficient,l * sizeof(double));
	for (int i = 0; i < l; i++)*(result.coefficient + i) = 0;
	for (int i = 0; i < this->power; i++)
	{
		for (int j = 0; j < other.power; j++)
		{
			*(result.coefficient + i + j) += this->coefficient[i] * other.coefficient[j];
		}
	}
	for (int i = l - 1; i >= 0; i--)
	{
		if (*(result.coefficient + i) == 0)l--;
		else break;
	}
	if (result.coefficient != NULL)
	{
		double* temp = (double*)realloc(result.coefficient, l * sizeof(double));
		if (temp != NULL)
		{
			result.coefficient = (double*)realloc(temp, l * sizeof(double));
		}
	}
	result.power = l;
	return result;
}

double* Polynomial::getCoefficient()const
{
	return this->coefficient;
}

int Polynomial::mySize()const
{
	return this->power;
}

double  evaluate(const Polynomial& poly, const double& var)
{	
	double result = 0 ;
	int  power = poly.mySize();
	double* coefficient = poly.getCoefficient();
	for (int i = 0; i < power; i++)
	{	
		if (i == 0)
		{
			result += coefficient[i];
			continue;
		}
		double value = (double)coefficient[i] * pow(var, i);
		result += value;
	}
	return result;
}
