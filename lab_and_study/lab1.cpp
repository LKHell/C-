/* 
	LiKunhao 	2016/12/19
*/

#include "stdafx.h"
#include <iostream> //dot.cpp 
#include <ctime> // used for generate random number

using std::cout;

int arry_before[10]; //global 

int generateArray() {
	srand(time(0));
	const int max = 1000;
	//int arry_before[10];
	for (int i = 0; i < 10; i++) {
		int temp = rand() % max + 1; // 1--1000
		arry_before[i] = temp;
		//std::cout << temp << std::endl; //for test
	}
	//std::cout << "----" << std::endl;
	//for (int i = 0; i < 10; i++) {
	//	std::cout << arry_before[i] << std::endl;//for test 
	//}

	return 0;
	//return arry_before[10];
}

void bubbleSort(int *sort_arry)
{
	int i, j;
	int n = 10;
	for (i = 0; i < n; i++)
	{
		for (j = 0; i + j < n - 1; j++)
		{
			if (sort_arry[j] > sort_arry[j + 1])
			{
				int temp = sort_arry[j];
				sort_arry[j] = sort_arry[j + 1];
				sort_arry[j + 1] = temp;
			}
			
		}
	}
	for (i = 0; i < 10; i++)  //output
		printf("%d \n", sort_arry[i]);
	return ;
}


int main(int argc, char** argv)
{
	cout << "Before sort: " << "\n";
	
	
	generateArray();
	for (int i = 0; i < 10; i++) {

		std::cout << arry_before[i] << std::endl;//for test 
	}
	cout << "After sort:" << "\n";
	bubbleSort(arry_before);

	return 0; /* ISO C requires main to return int. */
}


// bubble sort algorithm: sort into ascending order 
// 
// 1. Pass an array of int values as a parameter 
// 2. set the marker u for the unsorted section at the end of the array
// 3. repeat Step 4 through 8 until the unsorted section has just one element 
//		then, jump to Step 9 
// 4. set the current element marker c at the second element of the array 
// 5. repeat Steps 6 and 7 until c>u, then, jump to Step 8 
// 6. if a[c] < a[c-1] then exchange these two items 
// 7. let c=c+1, go back to 5.
// 8. u=u-1, go back to Step 3 
// 9. Halt.