#include <iostream>
#include <cmath>
#include <fstream>
using namespace std ;
double func(double x , double y)
{
	double result ;
	
	result = pow(x,2)+pow(y,2);
	return result ;
	
}

int main()
{
	ofstream fout ;
	int n ;
	cin>> n ;
	
  double y[n],x[n],h=0.1;
 	
 	y[0]=0;
	
	for(int i=0;i<=n;i++)
	{
		x[i]=i*h;
		
	}
	
	fout.open("Runge-Kutta.dat");
	for(int i=1 ;i<=n;i++)
	{
		y[i]=y[i-1]+h*func(x[i-1],y[i-1]);
		cout<<y[i]<<endl;
		
	}
	
	fout<<"X"<<"\t"<<"Y"<<endl;
	
	for(int i=0;i<=n;i++)
	{
		fout<<x[i]<<"\t"<<y[i]<<endl;
	}
	
	fout.close();
	
	
	
	
	return 0 ;
	
	
}
