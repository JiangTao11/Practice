#include<stdio.h>
void BubbleSort(int mylist[], int n)
{
	int i, j,temp;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1- i; j++)
		{
			if (mylist[j]>mylist[j+1])
			{
				temp = mylist[j];
				mylist[j ] = mylist[j+1];
				mylist[j + 1] = temp;
			}
		}
	for (int k = 0; k < n; k++)
		printf("%2d ", mylist[k]);
}
int main(void)
{
	int mylist[] = { 9, 3, 4, 2, 1, 6, 8, 7,5};
	int n = 9;
	BubbleSort(mylist, n);
	return 0;
}