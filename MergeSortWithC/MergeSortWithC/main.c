/*
MergeSort
by N.H.J.
2021.3.13
*/

//#include<iostream>
#include<stdio.h>
#include<string.h>
//using namespace std;

int tarray[100];// Input array
int numOfNumbers=0;

int i,j,k=0;

int _Input(void);// Input Function

int mergeSort(int [],int,int);


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
    mergeSort(tarray,0,strlen(tarray)-1);
    for(i=0;i<=numOfNumbers-1;i++)
    {
        printf("%d\n",tarray[i]);
        // cout<<tarray[i]<<endl;
    }
    return 0;






}
int _Input()
{
    printf("Please input the number of numbers:\n");
    // cout<<"Please input the number of numbers:"<<endl;
    scanf("%d",&numOfNumbers);
    // cin>>numOfNumbers;
    printf("Please input the array:\n");
    // cout<<"Please input the array:"<<endl;
    for(i=0;i<=numOfNumbers-1;i++)
    {
        scanf("%d",&tarray[i]);
        // cin>>tarray[i];
    }

    return 0;
}


int mergeSort(int the_arrary[],int begin,int end)
{
    int merge(int[],int,int);
    if (begin==end)
        return 0;
    else
    {
        
        int mid=(end-begin)/2;

        // strncpy(temp_arrary_left,the_arrary,length/2-1);
        // strcpy(temp_arrary_right,the_arrary+length/2);

        

        
        mergeSort(the_arrary,begin,mid);
        mergeSort(the_arrary,mid+1,end);

        
        merge(the_arrary,begin,end);
return 0;

    }

    }

int merge(int the_arrary[],int begin,int end)
{
    int mid=(begin+end)/2-1;
    int i=begin;
    int k=mid+1;
    int o=begin;
    int array_total[end-begin+1];
    while(i<=mid&&k<=end)
    {
        if(the_arrary[i]<=the_arrary[k])
        {
            array_total[o]=the_arrary[i];
            i++;
            o++;
        }
        else
        {
            array_total[o]=the_arrary[k];
            k++;
            o++;
        }
    }
    if(i>mid)
    {
        while(o<=end-begin+1)
        {
            array_total[o]=the_arrary[k];
            o++;
            k++;
        }
    }
    else if(k>end)
    {
        while(o<=end-begin+1)
        {
            array_total[k]=the_arrary[i];
            i++;
            k++;
        }
    }
    strcpy(the_arrary+begin,array_total);
    return 0;
}





