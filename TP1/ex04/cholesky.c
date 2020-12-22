#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define N 10
float *cholesky (float A[N][N], float B[N], int n)
{

	float *x;
	x=malloc(sizeof(float)*n);
	
	float c[N][N];
	float s1, s2;

	c[0][0]=sqrt(A[0][0]);
	for (int i=1; i<n; i++)
	{
		c[i][0]=A[i][0]/c[0][0];
	}
	for (int j=1; j<n; j++)

		{
			for (int i=0; i<=j-1; i++)
				c[i][j]=0;
			{
	

			s1=0.0;
			for(int k=0;k<j;k++)
				s1+=pow(c[j][k], 2);
			}
			c[j][j]=sqrt(A[j][j]-s1);
			for(int i=j+1;i<n;i++)
			{
				s2=0.0;
				for(int k=0;k<j;k++)
					s2+=c[i][k]*c[j][k];
				c[i][j]=(1.0/c[j][j])*(A[i][j]-s2);
			}
		}
	float T[N][N];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n;j++)
		{
			T[i][j]=c[j][i];
		}
	}

	float Y[N];
	float s;
	Y[0]= B[0]/c[0][0];
	for (int i=1; i<n; i++)
	{
		s=0;
		for (int j=0; j<i; j++)
			s+=c[i][j]*Y[j];
		Y[i]=(B[i]-s)/c[i][i];
	}
	x[n - 1] = Y[n - 1] / A[n - 1][n - 1];
	for(int i = n-2 ; i>=0 ; i--)
	{
		s=0;
		for(int j = i+1; j < n; j++)
			s = s + T[i][j] * x[j];
		 x[i] = (Y[i] - s) / T[i][i];
	}
	return (x);
}
int main ()
{

	float   A[N][N], B[N];
	int n;
	float *x;
	 printf("Enter the size of the matrix: ");
	 scanf("%d", &n);
	 /* Filling the matrix A */
	 printf("Filling the matrix A\n");

	 for(int i = 0; i < n; i++)
	 {
		 for(int j = 0; j < n; j++)
		 {
			 printf("A[%d][%d] = ", i, j);
			 scanf("%f", &A[i][j]);
		 }
	 }
	  /* Filling the vector B*/
	  printf("Filling the matrix B\n");

	  for (int i = 0; i < n; i++)
	  {
		  printf("B[%d] = ", i);
		  scanf("%f", &B[i]);
	  }
	  /* The calculation of the result */
	  x=cholesky(A,B,n);
	  printf("\nThe solution is : ");
	  for (int i = 0; i < n; i++)
		  printf("%f\n", x[i]);
}

	
