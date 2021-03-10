/*
BinarySearchExampleWithRecursion
by N.H.J.
2021.3.10
*/
#include <iostream>

int array[100];// Input array
int numOfNumbers=0;
int target;
int i,j,k=0;

int _Input(void);// Input Function

void binarySearch(int target,int length,int position);


int main()
{
	_Input();
	int a=binarySearch(target,numOfArrays-1,0);
	if(a==-1)
		cout<<"No target found!"<endl;
	else
		cout<<target<<" is No."<<a<<endl;

}

int _Input()
{
	cout<<"Please input the number of numbers:"<<endl;
	cin>>numOfArrays;
	cout<<"Please input the array:"<<endl;	
	for(i=0;i<=numOfArrays-1;i++)
	{
		cin>>array[i];
	}

	cout<<"Please input your target:"<<endl;
	cin>>target;

	return 0;

}

void binarySearch(int target,int right,int left)
{
	if(left==right)//adhoc()
	{
		if(array[left]==target)
			return left;
			
		else
			return -1;
			
	}
	else
	{
		int mid=left+(right-left)/2;//To avoid overflow
		if(array[mid]==target)
			a=mid;
		else if(array[mid]<target)
		{
			return binarySearch(target,right,mid+1);
		}
		else if(array[mid]>target)
		{
			return binarySearch(target,mid-1,left);
		}

	}
	
}




