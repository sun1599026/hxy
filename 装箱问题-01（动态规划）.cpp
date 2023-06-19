#include<iostream>
using namespace std;
//定义两个常量V，N，分别表示物品体积上限，物品个数上限
#define V 20001
#define N 31
//v:箱子容量，n:物品个数，a数组：每个物品的体积 ，c[i][j]:前i件物品放在容量为j的箱子里的最大占有体积
int v,n,a[N],c[N][V];
int main(){
	//读入箱子的体积，物品的个数以及体积
	cin>>v>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//初始化第0行和第0列，表示当物品数为0时能占据箱子的最大体积为0，当箱子体积为0时能占据箱子的体积为0
	for(int i=1;i<=v;i++){
		c[0][i]=0;
	}
	for(int j=1;j<=n;j++){
		c[j][0]=0;
	}
	//遍历n个物品，每个物品遍历不同体积的购物车，如果购物车剩余的体积不能装下第i个物体，那么c[i][j]=c[i-1][j];
	//如果购物车的剩余容量能放下物品的话，则考虑是否要放进去，c[i][j]=max(c[i-1][j],c[i-1][j-v[i]]+v[i])
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(j<a[i]){
				c[i][j]=c[i-1][j];
			}
			else{
				c[i][j]=max(c[i-1][j],c[i-1][j-a[i]]+a[i]);
			}
		}
	}
	//遍历填完矩阵后c[n][v]表示的从是n个物品中选若干放入体积为v的购物车中占据的最大体积，所以剩余最少空间为v-c[n][v]
	cout<<v-c[n][v];
	return 0;
}