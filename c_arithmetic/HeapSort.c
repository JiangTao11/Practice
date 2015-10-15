#include<stdio.h>
int PARENT(int i)
{
	return i / 2;
}
int LEFT(int i)
{
	return 2 * i;
}
int RIGHT(int i)
{
	return (2 * i + 1);
}

void exchange(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void MAX_HEAPIFY(int A[], int i)
{
	int l, r,largest,heap_size;
	heap_size = 10;

	l = LEFT(i);
	r = RIGHT(i);
	
	if (l <= heap_size && A[l] > A[i])
		largest = l;

	else
		largest = i;
	
	
	if (r <= heap_size && A[r] > A[largest])
		largest = r;
	
	if (largest != i)
	{
		exchange(&A[largest], &A[i]);
		MAX_HEAPIFY(A, largest);
	}	
} 


void BUILD_MAX_HEAP(int A[],int n)
{
	int heap_size = n;
	for (int i =heap_size / 2; i>0; i--)
		MAX_HEAPIFY(A, i);

}

void HEAPSORT(int A[],int n)
{
	BUILD_MAX_HEAP(A, n);
	for (int i = n; i >= 2; i--)
	{
		exchange(&A[1], &A[i]);
		n = n - 1;
		MAX_HEAPIFY(A, 1);
	}

}


int main(void)
{
	int A[] = { 22,5, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
	int B[] = { 22, 5, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
	/*
	MAX_HEAPIFY(A, 2);
	for (int i = 0; i < 11; i++)
		printf("%2d ", A[i]);
	putchar('\n');
	BUILD_MAX_HEAP(A, 10);
	*/
	HEAPSORT(A, 10);
	for (int i = 0; i < 11; i++)
		printf("%2d ", A[i]);
	
	return 0;

}