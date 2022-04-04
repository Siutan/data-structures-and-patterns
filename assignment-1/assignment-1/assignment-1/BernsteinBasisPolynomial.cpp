// Mukil Chitty Babu Problem set 1

#include "BernsteinBasisPolynomial.h"
#include <cmath>


BernsteinBasisPolynomial::
BernsteinBasisPolynomial(unsigned int aV, unsigned int aN) {

	Combination bbp(aN, aV);

	fFactor = bbp;

}

double BernsteinBasisPolynomial::operator()(double aX) const {
	
	double Result = 0.0;

	Result =
		fFactor() *
		pow(aX, fFactor.getK()) *
		pow((1 - aX), (fFactor.getN() - fFactor.getK()));

	return Result;

}