#include<stdio.h>
#include<stdlib.h>
#define N 10
float *romente(float A[N][N], float B[N], int n)
{
	float *x;
	x = malloc(sizeof(float)*n);
	float s;
	x[n-1]=B[n-1]/A[n-1][n-1];
	for (int i=n-2; i>=0; i--)
	{
		s=0;
		for(int j=i+1; j<=n-1; j++)
		{
			s+=A[i][j]*x[j];
		}
		
		x[i]=(B[i] - s)/A[i][i];
	}
	return x;
}
int main()
{

	float A[N][N],B[N];
	float *x;
	int n;
	printf ("enter the size of the matrix: ");
	scanf ("%d", &n);
	printf ("filling the matrix A\n");
	for (int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf ("A[%d][%d] = ", i,j);
			scanf("%f", &A[i][j]);
		}
	}
	printf ("filling the vector B\n");
	for (int i=0; i<n; i++)
	{
		printf("B[%d]= ",i);
		scanf("%f",&B[i]);
	}
	x = romente(A,B,n);
	printf ("\n the resulting vector: [");
	for (int i=0; i<n; i++)
		printf("%f%c",x[i], ",]"[i == n-1]);
}
	


		

			
	
