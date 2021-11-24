/**
 amazon-interview-questions

Given an array of 0s and 1s. find maximum no of consecutive 1s.
If you have given chance to flip a bit to 1 such that it maximises the consecutive 1s.
find out that flipped bit and after flipping that bit maximum no of consecutive 1s.
Above question but you have options to flip k bits.
*/

#include <stdio.h>


int count_1s(int a[], int n) {
	int ss = 0;
	int es = 0;
	int is = 0;
	int c = 0;

	for (int i = 0; i < n-1; i++) {
		if (a[i] == 1 && a[i+1] == 0) {
			es = 1;	// end sequence
			ss = 0;
			is = 0;
		} else if (a[i] == 0 && a[i+1] == 1) {
			ss = 1; // start sequence
			es = 0;
			is = 0;
		} else if (a[i] == 1 && a[i+1] == 1) {
			is = 1; // in the sequence
			ss = 0;
			es = 0;	
		} else {
			is = ss = es = 0;
		}

		if (ss) {
			c = 1;
		}
		if (es) {
			c++;
		}
		if (is) {
			c++;
		}
	}
	return c;
}

int count_1s2(int a[], int n) {
	int c = 0;

	for (int i = 1; i < n-1; i++) {
		if (a[i-1] == 0 && a[i] == 0 && a[i+1] == 0) {
			// nothing to be done
		} else if (	a[i-1] == 0 && a[i] == 0 && a[i+1] == 1) {
		} else if ( a[i-1] == 0 && a[i] == 1 && a[i+1] == 0)
		} else if (	a[i-1] == 0 && a[i] == 1 && a[i+1] == 1) {
		} else if (	a[i-1] == 1 && a[i] == 0 && a[i+1] == 0) {
		} else if (	a[i-1] == 0 && a[i] == 0 && a[i+1] == 1) {
		} else if ( a[i-1] == 0 && a[i] == 1 && a[i+1] == 0) {
		} else if ( a[i-1] == 0 && a[i] == 1 && a[i+1] == 0) {
		}
	}
}

int count_0s(int a[], int n) {
}

void main(void) {
	//int a[] = {1,1,1,0,1,0,0,0,0,1,1,1,1};
	int a[] = {0,0,0,0,0,0,0,1,0,0,0,0,0};
	int n = sizeof(a)/sizeof(a[0]);
	int res = count_1s(a, n);
	printf("number of consecutive 1s: %d\n", res);
}

