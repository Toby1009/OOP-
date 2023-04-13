#define PI 3.14159265358979323846 
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm> 
using namespace std;

int main()
{
   double r;
   while(cin>>r)
   {
       cout<<fixed<<setprecision(6)<<(double)((double)4/3)*PI*r*r*r<<endl;
   }
}
