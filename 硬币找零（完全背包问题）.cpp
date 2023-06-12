#include<iostream>
using namespace std;
//定义两个常量：M:需要找零的钱的上限值，N：硬币种类的上限
#define M 10001
#define N 21
//n:硬币的种类数，m:需要找零的钱数，a数组：存每种硬币的面值，dp[j]数组：表示当所需找零的钱为j时所需的最少硬币数
int n,m,a[N],dp[M];
int main(){
	//读入硬币的种类数以及每种硬币的面值，需找零的钱数，
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//初始化dp数组，由于要求的是找零所需的硬币的最少数量，所以刚开始初始化dp数组中的每个元素为无穷大，0x3f3f3f3f,把dp[0]=0；
	//这样基于dp[0]=0推导出来的就都是正确的
	memset(dp,0x3f3f3f,sizeof(dp));
	dp[0]=0;
	//完全背包的方法：外层循环遍历n种硬币，内层循环正向遍历（因为正向遍历可以实现状态叠加，刚好满足完全背包问题每个物品可以放无数次的问题）大于a[i]小于m的所有钱数
	//状态转移方程：dp[j]=min(dp[j],dp[j-a[i]]+1)（加一表示找零的硬币数加一）
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=m;j++){
			dp[j]=min(dp[j],dp[j-a[i]]+1);
		}
	}
	//最后输出dp[m]，即为找零m块钱所需的最少的硬币数
	cout<<dp[m];
	return 0;
}