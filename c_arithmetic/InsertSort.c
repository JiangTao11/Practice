#include<stdio.h>
void InsertSort(int mylist[], int n)
{
	int i, j;
	for (j = 1; j < n; j++)
	{
		i = j - 1;
		int key = mylist[j];
		while (i >= 0 && mylist[i] >key)
		{
			mylist[i+1] = mylist[i];
			i = i - 1;
		}
		mylist[i + 1] = key;
	}
	for (int k = 0; k < n; k++)
		printf("%2d ", mylist[k]);
}
int main(void)
{
	int mylist[] = { 5, 2, 4, 6, 1, 3 };
	int n = 6;
	InsertSort(mylist, n);
}
