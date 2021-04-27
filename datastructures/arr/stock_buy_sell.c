/*
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
*/

#include <stdio.h>

void stock_buy_sell(int a[], int n)
{
	int buy = 0, sell = 0;

	for (int i = 0; i < n-1; i++) {
		int j = i;
		buy = a[i];
		sell = a[i];

		if (n - j > 1) {
			while (a[j] >= a[j+1]) j++;
		}
		sell = a[j];
		printf("buy: %d sell: %d j: %d\n", buy, sell, j);
		i = j;
	}
}

void main(void)
{
	int a[] =  {100, 180, 260, 310, 40, 535, 695};
	int n = sizeof(a)/sizeof(a[0]);

	stock_buy_sell(a, n);
}

