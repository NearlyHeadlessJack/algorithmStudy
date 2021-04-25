#include <iostream>
#include <stdio.h>
//#include <conio.h>
using namespace std;
int n;//物品数量
double c;//背包容量
double v[100];//各个物品的价值　value
double w[100];//各个物品的重量　weight
double cw = 0.0;//当前背包重量　current weight
double cp = 0.0;//当前背包中物品总价值　current value
double bestp = 0.0;//当前最优价值best price
double perp[100];//单位物品价值(排序后) per price
int order[100];//物品编号
int put[100];//设置是否装入，为1的时候表示选择该组数据装入，为0的表示不选择该组数据
 
 
//按单位价值排序
void knapsack()
{
    int i,j;
    int temporder = 0;
    double temp = 0.0;
 
    for(i=1;i<=n;i++)
        perp[i]=v[i]/w[i]; //计算单位价值（单位重量的物品价值）
    for(i=1;i<=n-1;i++)
    {
        for(j=i+1;j<=n;j++)
            if(perp[i]<perp[j])//冒泡排序perp[],order[],sortv[],sortw[]
        {
            temp = perp[i];  //冒泡对perp[]排序
            perp[i]=perp[j];
            perp[j]=temp;
 
            temporder=order[i];//冒泡对order[]排序
            order[i]=order[j];
            order[j]=temporder;
 
            temp = v[i];//冒泡对v[]排序
            v[i]=v[j];
            v[j]=temp;
 
            temp=w[i];//冒泡对w[]排序
            w[i]=w[j];
            w[j]=temp;
        }
    }
}
 
//回溯函数
void backtrack(int i)
{   //i用来指示到达的层数（第几步，从0开始），同时也指示当前选择玩了几个物品
    double bound(int i);
    if(i>n) //递归结束的判定条件
    {
        bestp = cp;
        return;
    }
    //如若左子节点可行，则直接搜索左子树;
    //对于右子树，先计算上界函数，以判断是否将其减去
    if(cw+w[i]<=c)//将物品i放入背包,搜索左子树
    {
        
        cw+=w[i];//同步更新当前背包的重量
        cp+=v[i];//同步更新当前背包的总价值
        put[i]=1;
        cout<<"x[1]="<<put[1]<<" x[2]="<<put[2]<<" x[3]="<<put[3]<<" x[4]="<<put[4]<<" cw="<<cw<<" cp="<<cp<<" bestp="<<bestp<<endl;
        backtrack(i+1);//深度搜索进入下一层
        cw-=w[i];//回溯复原
        cp-=v[i];//回溯复原
        cout<<"x[1]="<<put[1]<<" x[2]="<<put[2]<<" x[3]="<<put[3]<<" x[4]="<<put[4]<<" cw="<<cw<<" cp="<<cp<<" bestp="<<bestp<<endl;
    }
    if(bound(i+1)>bestp)//如若符合条件则搜索右子树
        backtrack(i+1);
}
 
//计算上界函数，功能为剪枝
double bound(int i)
{   //判断当前背包的总价值cp＋剩余容量可容纳的最大价值<=当前最优价值
    double leftw= c-cw;//剩余背包容量
    double b = cp;//记录当前背包的总价值cp,最后求上界
    //以物品单位重量价值递减次序装入物品
    while(i<=n && w[i]<=leftw)
    {
        leftw-=w[i];
        b+=v[i];
        i++;
    }
    //装满背包
    if(i<=n)
        b+=v[i]/w[i]*leftw;
    return b;//返回计算出的上界
 
}
 
 
 
int main()
{
    int i;
    printf("请输入物品的数量和背包的容量：");
    scanf("%d %lf",&n,&c);
    /*printf("请输入物品的重量和价值：\n");
    for(i=1;i<=n;i++)
    {
        printf("第%d个物品的重量：",i);
        scanf("%lf",&w[i]);
        printf("第%d个物品的价值是：",i);
        scanf("%lf",&v[i]);
        order[i]=i;
    }*/
    printf("请依次输入%d个物品的重量:\n",n);
    for(i=1;i<=n;i++){
        scanf("%lf",&w[i]);
        order[i]=i;
    }
 
    printf("请依次输入%d个物品的价值:\n",n);
    for(i=1;i<=n;i++){
        scanf("%lf",&v[i]);
    }
 
 
    knapsack();
    backtrack(1);
 
 
    printf("最优价值为：%lf\n",bestp);
    printf("需要装入的物品编号是：");
    for(i=1;i<=n;i++)
    {
        if(put[i]==1)
            printf("%d ",order[i]);
    }
    return 0;
}
