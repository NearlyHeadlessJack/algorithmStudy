/*
MergeSort
by N.H.J.
2021.3.13
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int tarray[100];// Input array
int numOfNumbers=0;

int i,j,k=0;

int _Input(void);// Input Function

int mergeSort(int [],int);


// int strlength(int a[])
// {
//     int t=0;
//     while(a[t]!='\0')
//     {
//         t++;
//     }
//     return t;
// }
// int cut(int a[],int b[],int c[])
// {
//     int mid=strlength(a)/2-1;
//     int length=strlength(a)-1;

//     int t=0;
//     int count=0;
//     for(t=0;t<=mid;t++)
//     {
//         b[count]=a[t];
//         count++;
//     }
//     count=0;
//     for(t=mid+1;t<=length;t++)
//     {
//         c[count]=a[t];
//         count++;
//     }
//     return 0;
// }

int main()
{
    _Input();
    mergeSort(tarray,numOfNumbers);
    for(i=0;i<=numOfNumbers-1;i++)
    {
        cout<<tarray[i]<<endl;
    }
    return 0;






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

    return 0;
}


int mergeSort(int the_arrary[],int length)
{
    int merge(int[],int[],int[],int,int);
    
        
    if (length>1)
    {
        int mid=length/2;
        int temp_arrary_left [100];
        int temp_arrary_right [100];
        for(int i=0;i<mid;i++)
            temp_arrary_left[i]=the_arrary[i];       //建立临时数组存储左半部分序列
        for(int j=mid;j<length;j++)
            temp_arrary_right[j-mid]=the_arrary[j];  //建立临时数组存储右半部分序列

        

        
        mergeSort(temp_arrary_left,mid);
        mergeSort(temp_arrary_right,length-mid);

        
        merge(the_arrary,temp_arrary_left,temp_arrary_right,mid-1,length-mid-1);


    }
    return 0;
}
    
int merge(int array_total[],int array_left[],int array_right[],int bound_left,int bound_right)
{
    
int i=0;
int j=0;
int k=0;

    while(i<=bound_left&&j<=bound_right)
    {
        if(array_left[i]<=array_right[j])
        {
            array_total[k++]=array_left[i++];
        }
        else
        {
            array_total[k++]=array_right[j++];

        }
    }
        while(j<=bound_right)
        {
            array_total[k++]=array_right[j++];
        }

        while(i<=bound_left)
        {
            array_total[k++]=array_left[i++];
        }
    return 0;
}





