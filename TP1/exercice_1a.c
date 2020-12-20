#include<stdio.h>
#include<stdlib.h>

#define N 10
float *descente (float A[N][N], float B[N], int n)
{
	float *x;
	/*alloaction*/ 
	x = malloc(sizeof(float)*n);
	/*solution*/
	double S;
	x[0]=B[0]/A[0][0];
		for (int i=1;i<n; i++)
		{
			S=0;
			for(int j=0;j<=i-1;j++)
				S+=A[i][j]*x[j];
			x[i]=(B[i]-S)/A[i][i];
		}
		return (x);
}
int main()
{
	float A[N][N], B[N];
	float *x;
	int n;
	printf("enter the size of the matrix: ");
	scanf("%d", &n);
	/* Filling the matrix A */
	printf("Filling the matrix A\n");
	for(int i = 0; i < n; i++)
	{
		for (int j=0; j<n; j++)
		{
			printf ("A[%d][%d] = ", i, j);
			scanf("%f", &A[i][j]);
		}
	}
	/* Filling the vector B*/
	printf ("Filling the vector B\n");
	for (int i =0; i < n; i++)
	{
		printf("B[%d] =",i);
		scanf ("%f", &B[i]);
	}
	x=descente(A, B, n);
	/* printing the results */
	printf("\n the resulting vector: [");
	for (int i=0; i<n;i++)
		printf("%f%c",x[i], ",]"[i==n-1]);
}



				
	
