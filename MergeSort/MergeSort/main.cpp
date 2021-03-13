/*
MergeSort
by N.H.J.
2021.3.13
*/
extern "C"{
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int tarray[100];// Input array
int numOfNumbers=0;

int i,j,k=0;

int _Input(void);// Input Function

int mergeSort(int []);

int merge(int[],int[],int[]);
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
    mergeSort(tarray);
    for(i=0;i<=strlen(tarray);i++)
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


int mergeSort(int the_arrary[])
{
    if (strlen(the_arrary)==1)
        return 0;
    else
    {
        int temp_arrary_left [100];
        int temp_arrary_right [100];
        int length=strlen(the_arrary);
        strncpy(the_arrary_left,the_arrary,length-1);
        strcpy(temp_arrary_right,the_arrary+length);

        

        
        mergeSort(temp_arrary_left);
        mergeSort(temp_arrary_right);

        
        merge(the_arrary,temp_arrary_left,temp_arrary_right);
return 0;

    }

    }
int merge(int array_total[],int array_left[],int array_right[])
{
    int bound_left=strlen(array_left)-1;
    int bound_right=strlen(array_right)-1;

    while(array_left[i]<=bound_left&&array_right[j]<=bound_right)
    {
        if(array_left[i]<=array_right[j])
        {
            array_total[k]=array_left[i];
            i++;
            k++;
        }
        else
        {
            array_total[k]=array_right[j];
            j++;
            k++;
        }
    }
    if(i>bound_left)
    {
        while(k<=bound_right)
        {
            array_total[k]=array_right[j];
            j++;
            k++;
        }
    }
    else if(j>bound_right)
    {
        while(k<=bound_left)
        {
            array_total[k]=array_right[i];
            i++;
            k++;
        }
    }
    return 0;
}
}




