// Mukil Chitty Babu Problem Set 1

#include "Polynomial.h"
#include <cmath>

double Polynomial::operator()(double aX) const {
	double Result = 0.0;

	for (int i = 0; i <= fDegree; i++)
		Result += fCoeffs[i] * pow(aX, i);

	return Result;
}

Polynomial Polynomial::getDerivative() const {
	Polynomial Result;

	Result.fDegree = fDegree - 1;

	for (int i = 0; i <= fDegree; i++)
		Result.fCoeffs[i] = fCoeffs[i + 1] * (i + 1);
		
	if (fDegree == 0 ) Result.fDegree = 0;

	return Result;
}


Polynomial Polynomial::getIndefiniteIntegral() const {
	Polynomial Result;

	Result.fDegree = fDegree + 1;
	
	Result.fCoeffs[0] = 0;
	
	for (int i = 1; i <= Result.fDegree; i++)
		Result.fCoeffs[i] = fCoeffs[i - 1] / i;
	
	return Result;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {
	Polynomial Integral = getIndefiniteIntegral();
	return Integral(aXHigh) - Integral(aXLow);
}
