#include "SortableIntVector.h"
#include "IntVector.h"
#include <iostream>

using namespace std;


SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) 
	: IntVector(aArrayOfIntegers, aNumberOfElements)
{}
	

void SortableIntVector::sort(Comparable aOrderFunction) {
	// implement bubble sort using a and b
	// a is the index of the element to be compared
	// b is the index of the element to be compared with
	// aOrderFunction is a function that returns true if the first element is less than the second
	// and false otherwise
	// if aOrderFunction returns true, swap the elements at a and b
	// repeat this process until the array is sorted
	// you can use the swap function from IntVector
	

	size_t fNumberOfElements = IntVector::size();
	
	
		
	for (int a = 0; a < fNumberOfElements; a++) {
		for (int b = 0; b < fNumberOfElements - 1; b++) {
			int firstInt = IntVector::get(b);
			int secondInt = IntVector::get(b + 1);
			if (aOrderFunction(secondInt, firstInt)) {
				swap(b + 1, b );
			}
		}
	}

}