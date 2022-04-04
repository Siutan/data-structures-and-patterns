#include "Combination.h"

// Constructor
Combination::Combination(size_t aN, size_t aK) {
    fN = aN;
    fK = aK;
}

// Current row
size_t Combination::getN() const 
{ return fN; }
// Current column
size_t Combination::getK() const
{ return fK; }

// Operator
unsigned long long Combination::operator()() const {

    unsigned long long Result = fN;

    /*Bounds:
    * if K > N = 0
    * if K = 0, = 1
    */
    if (fK > fN) return 0;
    if (fK == 0) return 1;

    for (int i = 2; i <= fK; ++i) {
        Result *= (fN - i + 1);
        Result /= i;
    }

    return Result;
}