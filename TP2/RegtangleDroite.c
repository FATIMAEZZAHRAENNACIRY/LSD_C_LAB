#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Q1, Q2*/
double f(double t)
{
	       
	return (exp(-pow(t,2)/2));
	
}




double RectangleDroite(double (*f)(double ),double a,double b,int n)
{


	double h=(b-a)/n;
	double I=0;
	double x=a;
	for (int i=0; i<n; i++)
	{
		I+=f(x);
	        x+=h;
	}
	return (h*I);
}
double RectangleGauche(double (*f)(double ) , double a , double b,int  n)

{
	double h = (b - a)/n;
	double I=0;
	double x=a+h;
	for ( int i = 0 ; i <= n -1 ; i++)
	{

	       I+=f(x);
	       x+=h;
	}

	return(h*I);
}
double Trapeze( double (*f)(double ), double a, double b , int n)
{
	double h = (b -a )/n;
	double I = 0.5 * (f(a ) + f(b));
        double x=a+h;
	for (int i = 0; i < n-1;i++)
	{
            I+=f(x);
	    x=x+h;
	}
	return h*I;
}
double Simpson(double (*f)(double ), double a, double b , int  n)
{
	double h = (b -a )/n;
	double x=a+h;
	double z=a+h/2;
	double I1=0;
	double I2=f(z);
	for (int i = 0; i< n-1 ; i++)
	{
		z+=h;
	        I1+=f(x);
	        I2+=f(z);
	        x+=h;
	}
        return (h/6)*(f(a)+f(b)+2*I1+4*I2);

	
}

//Q3
double NombreNecessaire(double(*f)(double),int a,int b, double(*Methode)(double(*)(double), double, double, int), double Err)
{
	double I=0.855624391892149;
	double n=1;
	while (fabs(Methode(f, a, b, n) - I) > Err)
	{
		n++;
	}
	return n;
}

// Q5
double Romberg(double (*f)(double),int a, int b, double Err, int nmax)
{

	double R[nmax][nmax];
	int N;
	int i,k;
	for ( i=0; i<nmax; i++)
	{
		N=pow(2,i);
		R[i][0]=Trapeze(f,a,b,N);
		for (k=0;k<i;k++)
		{
			double n=k+2;
			R[i][k+1]=1.0/(pow(4,n-1)-1)*(pow(4,n-1)*R[i][k]-R[i-1][k]);
			if (i>0)
			{
				if(fabs(R[i][k+1]-R[i][k])<Err)
					 return R[i][k+1];
			}
		}
	}
	return R[i][k+1];
}

		



int main ()
{
	int a;
	int b;
        
  	int n;
	int nmax;
 
	printf ("donner la valeur de a : ");
	scanf ("%d",&a);
	printf ("doner la valeur de b: ");
	scanf ("%d",&b);
	printf ("Enter n: ");
	scanf ("%d",&n);
	printf("enter nmax: ");
	scanf("%d",&nmax);
		
       printf ("%lf\n" , RectangleDroite(f,a,b,n));
    
       printf ("%lf\n" , RectangleGauche(f, a,b,n));
       printf ("%lf\n" , Trapeze(f,a,b,n));
  
        printf ("%lf\n" , Simpson(f, a,b,n));
        double Err=pow(10,-9);
	printf("Nombre necessaire est: ");
	printf("%lf", NombreNecessaire(f, a, b, Simpson, Err));
        printf("\n");
	printf("%lf\n", Romberg(f, a, b, Err, nmax));
	return 0;
}





	


		
	


		
		


			


		


