#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int findPeakUtil(int *mas, int low, int high, int n)
{
	// Find index of middle element 
	int mid = low + (high - low) / 2;

	// Compare middle element with its neighbours (if neighbours exist) 
	if ((mid == 0 || mas[mid - 1] <= mas[mid]) &&
		(mid == n - 1 || mas[mid + 1] <= mas[mid]))
		return mas[mid];
	// If middle element is not peak and its left neighbour is greater  
	// than it, then left half must have a peak element 
	else if (mid > 0 && mas[mid - 1] > mas[mid])
		return findPeakUtil(mas, low,(mid - 1), n);
	// If middle element is not peak and its right neighbour is greater 
	// than it, then right half must have a peak element 
	else return findPeakUtil(mas, (mid + 1), high, n);
		

}

int findPeak(int *mas, int n)
{
	return findPeakUtil(mas, 0, n-1, n);
}
int main()
{
	unsigned int Size = 0;
	cout << "Size of array: ";
	cin >> Size;
	cin.sync();
	int *Array = new int[Size];
	cout << "-------ENTER OF ARRAY---"<<endl;
		for (int i = 0; i < Size; ++i)
		{
			//cout << "Enter " << i << " element of array: ";
			cin >> Array[i];
			cin.sync();
		}
	cout << "Peak is: " << findPeak(Array,Size);
}
