/*
 
 
 
BinarySearchExampleWithRecursion
by N.H.J.
2021.3.10
*/
#include <iostream>

using namespace std;

int tarray[100];// Input array
int numOfNumbers=0;
int target;
int i,j,k=0;

int _Input(void);// Input Function

int binarySearch(int target,int right,int left);


int main()
{
    _Input();
    int a=binarySearch(target,numOfNumbers-1,0);
    if(a==-1)
        cout<<"No target found!"<<endl;
    else
        cout<<target<<" is No."<<a+1<<endl;

}

int _Input()
{
    cout<<"Please input the number of numbers:"<<endl;
    cin>>numOfNumbers;
    cout<<"Please input the array:"<<endl;
    for(i=0;i<=numOfNumbers-1;i++)
    {
        cin>>tarray[i];
    }

    cout<<"Please input your target:"<<endl;
    cin>>target;

    return 0;

}

int binarySearch(int target,int right,int left)
{
    if(left==right)//adhoc()
    {
        if(tarray[left]==target)
            return left;
            
        else
            return -1;
            
    }
    else
    {
        int mid=left+(right-left)/2;//To avoid overflow
        if(tarray[mid]==target)
            return mid;
        else if(tarray[mid]<target)
        {
            return binarySearch(target,right,mid+1);
        }
        else if(tarray[mid]>target)
        {
            return binarySearch(target,mid-1,left);
        }

    }
    return -1;
}
