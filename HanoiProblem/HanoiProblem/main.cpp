/*
 Hanoi Problem
 by N.H.J.
 2021.3.16
 */

#include<iostream>
using namespace std;

void move(int n,char A,char B,char C);
int total,n=0;

int main()
{
    cout<<"Please input the number of Hanois:"<<endl;
    cin>>n;
    move(n,'a','b','c');
    cout<<"Total steps is "<<total<<endl;
    system("pause");
    return 0;
}

void move(int n,char A,char B,char C)
{
    if(n==1)
    {
        cout<<++total<<". Move "<<'1'<<" from "<<A<<" to "<<C<<". "<<endl;
    }
    else
    {
        move(n - 1, A , C , B);
        cout<<++total<<". Move "<<n<<" from "<<A<<" to "<<C<<". "<<endl;
        move(n - 1 , B, A , C);
    }
}
