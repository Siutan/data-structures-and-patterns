#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector
(const int aArrayOfIntegers[], size_t aNumberOfElements)
	: SortableIntVector(aArrayOfIntegers, aNumberOfElements)
{}

void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{

	size_t mNumberOfElements = IntVector::size();
	
	bool swapped = true;
	int start = 0;
	int end = mNumberOfElements - 1;

	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end; ++i)
		{
			if (aOrderFunction(IntVector::get(i), IntVector::get(i+1)) > 0)
			{
				swap(i, i + 1);
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
		else
		{
			swapped = false;
		}
		end--;
		for (int i = end; i >= start; --i)
		{
			if (aOrderFunction(IntVector::get(i), IntVector::get(i + 1)) > 0)
			{
				swap(i, i + 1);
				swapped = true;
			}
		}
		start++;
	}
}


