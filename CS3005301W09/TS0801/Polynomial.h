#pragma once

class Polynomial
{	
private:
	int power;
	double* coefficient;
public:
	Polynomial(double arr[], int n);
	Polynomial();
	~Polynomial();
	int mySize()const;
	double operator [] (int index);
	Polynomial operator + (const Polynomial& other);
	Polynomial operator - (const Polynomial& other);
	Polynomial operator * (const Polynomial& other);
	Polynomial& operator = (const Polynomial& other);
	double* getCoefficient()const;

};

double evaluate(const Polynomial& poly, const double& var);





