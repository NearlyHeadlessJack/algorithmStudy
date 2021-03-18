/*
 CatalanNumberGenerator
 by N.H.J.
 2021.3.18
 */

#include<iostream>

using namespace std;
long long catalanNumber(int);

int main()
{
    int n=0;
    cout<<"Please input n:"<<endl;
    cin>>n;
    cout<<"The No."<<n<<" Catalan Number is "<<catalanNumber(n)<<endl;
    
}
long long catalanNumber(int n)
{
    if(n==0)
        return 1;
    else
        return ((catalanNumber(n-1))*(4*n-2))/(n+1);
}
