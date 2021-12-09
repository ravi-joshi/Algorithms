/*
Minimum no. of operations required to make all Array Elements Zero
Difficulty Level : Easy
Last Updated : 22 Jun, 2021
Given an array of N elements and each element is either 1 or 0. You need to make all the elements of the array equal to 0 by performing below operations:

If an element is 1, You can change it?s value equal to 0 then, 
if the next consecutive element is 1, it will automatically get converted to 0.
if the next consecutive element is already 0, nothing will happen.
Now, the task is to find the minimum number of operations required to make all elements equal to 0.
Examples:  

Attention reader! Don?t stop learning now. Get hold of all the important DSA concepts with the DSA Self Paced Course at a student-friendly price and become industry ready.  To complete your preparation from learning a language to DS Algo and many more,  please refer Complete Interview Preparation Course.

In case you wish to attend live classes with experts, please refer DSA Live Classes for Working Professionals and Competitive Programming Live for Students.

Input : arr[] = {1, 1, 0, 0, 1, 1, 1, 0, 0, 1} 
Output : Minimum changes: 3 

Input : arr[] = {1, 1, 1, 1}
Output : Minimum changes: 1
*/

#include <stdio.h>

//approach-1: sort the array in decending order, change the first element
// min operation is always 1

//approach-2: hashmap or hashtable. hash location saves the count of concecutive 1's before changing to 0

//approach-3: 2-loop approach. change the element 1 to 0 and loop until the next 0 is occured
//all intermittent 1 change to 0 automatically

int sort(int a[], int n) {
}

int min_ops1(int a[], int n) {
	// descending sort and change method
	sort(a, n);
	a[0] = 1; // changes all remaininig 1's to 0
}

int min_ops2(int a[], int n) {
	// 2-loop approach
	int c = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			for (int j = i+1; j < n; j++) {
				if (a[j] == 0) break;
			}
		}

		// jump to jth location
		i += j;
		c++;
	}
	return c;
}

int min_ops3(int a[], int n) {
}

void main(void) {
}

