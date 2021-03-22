/*
MatrixChain
by N.H.J.
2021.3.22
ver.1
*/
#include<iostream>

using namespace std;

uint32_t p[10000];
uint32_t m[10000][10000];
uint32_t s[10000][10000];
uint32_t n;

void matrixChain(void);
int traceBack(int,int);

int main()
{
    cout<<"Please input the number of matrix:"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"Please input length and width of No."<<i<<" matrix."<<endl;
        cin>>p[i*2-2];
        cin>>p[i*2-1];
    }
    matrixChain();
    cout<<"The Minimum times of multiplication is "<<m[1][n]<<endl;
    if(n!=1)
    {
        cout<<"The Sequence of multiplication is:"<<endl;
        traceBack(1,n);
    }
    return 88;
}
void matrixChain(void)
{
    for(int i=0;i<=0;i++)
        m[i][i]=0;
    for(int r=2;r<=n;r++)
    {
        for(int i=1;i<=n-r+1;i++)
        {
            int j=i+r-1;
            m[i][j]=-1;
            for(int k=i;k<j;k++)
            {
                int temp=m[i][k]+m[k+1][j]+p[i*2-2]*p[k*2-1]*p[j*2-1];
                if(temp<m[i][j]){m[i][j]=temp;s[i][j]=k;}
            }
        }
    }
}
int traceBack(int m,int n)
{
    if(m==n)
        return 0;
    else
    {
        traceBack(m,s[m][n]);
        traceBack(s[m][n]+1,n);
        if(m!=n)
            cout<<"A["<<m<<":"<<n<<"]"<<endl;
        return 0;
    }
}
