#include<stdio.h>
#include<limits>
void MERGE(int A[], int p, int q, int r)
{
	
	
	const int n1 = 3;
	const int n2 = 4;
	int L[n1 + 1], R[n2 + 1];
	
	for (int i = 0; i < n1; i++)
		L[i] = A[i + p];

	L[n1] = INT_MAX;
	for (int j = 0; j < n2; j++)
		R[j] = A[j + q];
	L[n2] = INT_MAX;

	
	int i, j;
	i = 0;
	j = 0;

	for (int k = 0; k < n1 + n2; k++)
	{	

		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}

	
	for (int k = 0; k < n1 + n2; k++)
	printf("%2d ", A[k]);
	
	

}
int main(void)
{
	int A[7] = { 1, 3, 6, 2, 4, 5, 8 };
	int p = 0;
	int q = 3;
	int r = 7;
	MERGE(A, p, q, r);
	return 0;


}