//#include <malloc.h>
#include <stdlib.h>
#include "string.h"
#include<stdio.h>

void Mergesort(int A[],int n);//合并排序的递归主体
int tarray[100];// Input array
 
void merge(int A[],int L[],int R[],int l,int r)  //两个有序序列L、R合并为A，l,r分别为L,R的长度
{
    int i=0,j=0,k=0;
    while(i<l&&j<r)  //两个子序列首元素做比较，小者取出置入父序列
    {
        if(L[i]<=R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }
    while(i<l)       //将左半部分剩余元素置入父序列
    {
        A[k++]=L[i++];
    }
    while(j<r)       //将右半部分剩余元素置入父序列
    {
        A[k++]=R[j++];
    }
}


int numOfNumbers=0;

int i,j,k=0;
int _Input(void);// Input Function

int main()
{
    _Input();
    Mergesort(tarray,numOfNumbers);
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
void Mergesort(int A[],int n)
{
    void merge(int A[], int L[], int R[], int l, int r);  //声明merge函数
    if(n>1)    //多于一个元素才需要排序
    {
        int mid=n/2;
        int *left=(int*)malloc(sizeof(int)*mid);
        int *right=(int*)malloc(sizeof(int)*(n-mid));
        for(int i=0;i<mid;i++)
            left[i]=A[i];       //建立临时数组存储左半部分序列
        for(int j=mid;j<n;j++)
            right[j-mid]=A[j];  //建立临时数组存储右半部分序列
 
        Mergesort(left,mid);    //调用自身对左半部分进行合并排序
        Mergesort(right,n-mid); //调用自身对右半部分进行合并排序
        merge(A,left,right,mid,n-mid);   //两个有序序列的合并操作，封装为函数
        free(left);
        free(right);
    }
}
