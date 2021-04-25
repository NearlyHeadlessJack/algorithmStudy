#include<iostream>
using namespace std;
int V[100][100];    //    前i个物品放入容量为j的背包的最大价值

int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void packet(int n, int C, int v[], int w[])
{
    int i, j, x[100] = { 0 };
    //填表,其中第一行和第一列全为0
    for (i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }
    for (i = 0; i <= C; i++)
    {
        V[0][i] = 0;
    }
    //从开始放入第一个物品开始
    for (i = 1; i <= n; i++)
    {
        int temp1=0,temp2=0;
        cout<<"Stage "<<i;
        for (j = 1; j <= C; j++)
        {
            
            if (j < w[i])
            {
                V[i][j] = V[i-1][j];
            }
            else               //只要这个物品的重量小于背包的容量就有可以放进去进行比较的资格
            {
                V[i][j] = max(V[i-1][j], V[i-1][j - w[i]] + v[i]);
            }
            if(V[i][j]>temp2)
            {
                temp2=V[i][j];
                temp1=j;
            }
            
            
            cout<<" "<<V[i][j];
        }
        cout<<"     "<<temp2<<"/"<<temp1<<endl;
    }
    cout << "The opt. value:"<<V[n][C] << endl;
    //判断哪些物品被选中
    for (i = n; i > 0; i--)
    {
        if (V[i - 1][C - w[i]] + v[i] >= V[i - 1][C])
        {
            x[i] = 1;
            C -= w[i];
        }
        else
            x[i] = 0;
    }
    cout << "Result:" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << x[i];
    }
 
}
int main()
{
    int n;        //输入的物品个数
    int C;        //最大的容量
    
    int v[100] = { 0 };        //第i个物品的价值
    int w[100]={ 0 };        //第i个物品的重量
    cout << "Please input the number of items:" << endl;
    cin >> n;
    cout << "Please input the capacity of bag:" << endl;
    cin >> C;
    cout << "Please input the value of each item:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cout << "Please input the weight of each item:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    packet(n,  C,  v, w);
    while (1);
}
