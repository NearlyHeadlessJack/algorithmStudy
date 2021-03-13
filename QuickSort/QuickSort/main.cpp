/*
QuickSort
by N.H.J.
2021.3.13
*/
#include <iostream>
using namespace std;
int tarray[100];// Input array
int numOfNumbers=0;
int i,j,k=0;
int _Input(void);// Input Function
void quickSort(int [],int,int);

int main()
{
    _Input();
    quickSort(tarray,numOfNumbers,0);

     for(i=0;i<=numOfNumbers-1;i++)
    {
        cout<<tarray[i]<<endl;
    }


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

void quickSort(int arrays[],int num,int begin)
{
    if(num>1)
    {
        int low,high,stand;
        stand=arrays[begin];
        low=begin;
        high=low+num-1;

        while(low<high)
        {
            if(arrays[high]>stand)
            {
                high--;
                continue;
            }
            else
            {
                arrays[low]=arrays[high];
                while(low<high)
                {
                    if(arrays[low]<=stand)
                    {
                        low++;
                        continue;
                    }
                    else
                    {
                        arrays[high]=arrays[low];
                        break;
                    }
                    
                }

            }
        
        }
         arrays[low]=stand;

         quickSort(arrays,num/2,begin);
         quickSort(arrays,num-(num/2),num/2);
    }




}
