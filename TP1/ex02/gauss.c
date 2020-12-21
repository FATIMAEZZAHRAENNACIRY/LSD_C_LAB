#include <stdio.h>
#include <stdlib.h>
#define N 10

double *remontee(double A[N][N], double B[N], int n)
{

  /******Implement the solution here******/
  double *x;
  x= malloc(sizeof(double)*n);
  double s;
  x[n-1]=B[n-1]/A[n-1][n-1];
  for (int i=n-2; i>=0; i--)
  {
	  s=0;
	  for (int j=i+1; j<=n-1;j++)
		  s+=A[i][j]*x[j];
	  x[i]=(B[i]-s)/A[i][i];
  }

		   
  
  return x;
}

double *gauss(double A[N][N] ,double B[N], int n)
{
  /******Implement the Gaussian elimination******/
  /**********************************************/
  double *x;
  x=malloc(sizeof(double)*n);
  double f;
  for(int k=0;k<n-1;k++)
  {
	  for(int i=k+1;i<n;i++)
	  {
		  f=A[i][k]/A[k][k];
		  for(int j=0;j<n;j++)
		  {
			  A[i][j]=A[i][j]-f*A[k][j];
		  }
		  B[i]=B[i]-f*B[k];
	  }

  }

	  

  x = remontee(A, B, n);
  return(x);
}

int main()
{
  double   A[N][N], B[N];
  double  *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%lf", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%lf", &B[i]);
  }

  /* The calculation of the result */
  x = gauss(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%lf%c", x[i], ",]"[i == n - 1]);
}

