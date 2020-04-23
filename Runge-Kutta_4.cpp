#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double func(double x,double y)
{
	double result ;
	
	result =pow(x,2)+pow(y,2);
	
	return result;
	
}

int main()
{
	
	ofstream fout ;
	
	fout.open("Runge-Kutta_4.dat");
	int n ;
	cin>>n ;
	
	double x[n+1],y[n+1];
	double k1,k2,k3,k4;
	x[0]=0;
	y[0]=0;
	double h=0.1;
	
	for(int i=1;i<=n;i++)
	{
		x[i]=i*h;
		
	}
	
	for(int i=0;i<=n;i++)
	{
		k1 =func(x[i],y[i]);
		k2 =func(x[i]+h/2,y[i]+k1*h/2);
		k3 =func(x[i]+h/2,y[i]+k2*h/2);
		k4=func(x[i]+h,y[i]+k3*h);
		y[i+1]=y[i]+(h/6)*(k1+2*k2+2*k3+k4);
	}
	
	fout<<"X"<<"\t"<<"Y"<<endl;
	for(int i=0;i<=n;i++)
	{
		
		fout<<x[i]<<"\t"<<y[i]<<endl;
		
	}
	
	
	fout.close();
	
	
	return 0 ;
}
