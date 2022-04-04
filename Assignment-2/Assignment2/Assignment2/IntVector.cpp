
#include "IntVector.h"
#include <stdexcept>
#include <iostream>

using namespace std;


IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) {
	
	fNumberOfElements = aNumberOfElements;
	fElements = new int[fNumberOfElements];

	for (size_t i = 0; i < fNumberOfElements; ++i)
	{
		fElements[i] = aArrayOfIntegers[i];
	}

}

// free memory
IntVector::~IntVector()
{
	delete[] fElements;
}

// size getter
size_t IntVector::size() const {
	return fNumberOfElements;
}

// element getter
const int IntVector::get(size_t aIndex) const {
	return (*this)[aIndex];
}

// swap two elements within the vector
// aSourceIndex - a
// aTargetIndex - b
void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex) {

	if (fNumberOfElements >= aSourceIndex || fNumberOfElements <= aTargetIndex)
		//aSourceIndex <= fNumberOfElements && aTargetIndex <= fNumberOfElements
	{
		size_t s = fElements[aSourceIndex];
		fElements[aSourceIndex] = fElements[aTargetIndex];
		fElements[aTargetIndex] = s;
	}
	else
	{
		throw out_of_range("Illegal vector Indicies");

	}
}

const int IntVector::operator[](size_t aIndex) const
{
	if (aIndex < fNumberOfElements)
	{
		return fElements[aIndex];
	}

	throw out_of_range("Illegal vector index");	
}
