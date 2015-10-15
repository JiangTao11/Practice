#include<stdio.h>
void exchange(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int PARTITION(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
		if (A[j] < x)
		{
			i = i + 1;
			exchange(&A[i], &A[j]);
		}
	exchange(&A[i + 1], &A[r]);
	return i + 1;
}
void QUICKSORT(int A[], int p, int r)
{
	if (p < r)
	{
		int q = PARTITION(A, p, r);
		QUICKSORT(A, p, q - 1);
		QUICKSORT(A, q + 1, r);

	}
}
int main(void)
{
	int A[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	QUICKSORT(A, 0, 7);
	for (int i = 0; i < 8; i++)
		printf("%2d ", A[i]);
	return 0;


		

}