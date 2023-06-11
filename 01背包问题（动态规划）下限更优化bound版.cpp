#include<iostream>
#include<cmath>
using namespace std;
#define m 10005
#define maxn 105
//bound用来表示下限，sum[i]数组用来求前i个物品重量的前缀和
int n,W,bound,w[maxn],v[maxn],x[maxn],sum[maxn];
//dp[i]数组表示的是i容量的购物车能装下的物品的最大价值，相当于之前的c[i][j]
int dp[m];
int main(){
	cin>>n>>W;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	//初始化第0行的dp[i]=0，表示0个物品装在i容量的购物车里的最大价值为0
	for(int i=0;i<=W;i++){
		dp[i]=0;
	}
	//初始化sum[0]=0,用一个for循环遍历1~W容量的购物车，求出前i个物品的前缀和
	sum[0]=0;
	for(int i=1;i<=W;i++){
		sum[i]=sum[i-1]+w[i];
	}
	//外层循环遍历n个物品，内循环1.倒着遍历W~1容量的购物车，因为只有倒着遍历才能保证dp[j]来自子问题的dp[j]或dp[j-w[i]]+v[i],
	//正着遍历会会导致子问题dp[j]或dp[j-w[i]]更新，这样在求dp[j]时就无法调用前一个主循环中求出来的dp[j]或dp[j-w[i]]+v[i]
	//2.不要忘记dp[i-w[i]]要加上v[i]的价值
	for(int i=1;i<=n;i++){
		//下限bound取w[i]与剩余容量之间的最大值
		//W-(sum[n]-sum[i-1])中的(sum[n]-sum[i-1])表示第i（注意包含第i个物品的重量）到第n个物品的重量和，W-(sum[n]-sum[i-1])就表示剩余的容量，
		//由于即使是j>=w[i],也不一定要更新dp[j],因为例如逆向回溯时，如果第5件是放入车中，那么c[5][W]=max(c[4][W],c[4][w-w[5]]+v[5]),由此可见不一定要访问
		//所有>=w[i]的j了，只需要访问到W-(sum[n]-sum[i-1])与w[i]之间的最大值bound过就可以了，所以那些即使大于等于w[i]的但是低于bound的j是不需要访问的，即不需要更新这些dp[j]
		bound=max(w[i],W-(sum[n]-sum[i-1]));
		for(int j=W;j>=bound;j--){
			///优化下限：因为只有j>=w[i],物品才能放进去，只有这种情况才需要更新dp[j]
			//只有当购物车放的下时才需要更新dp[j]，否则就保留上一个主循环中求出的dp[j],相当于c[i][j]=c[i-1][j]
			
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		
		}
	}
	//输出最后的dp[W]就是最大价值，相当于c[n][W]
	//但是也存在问题，由于dp[j]是一维的，在每一次主循环后都被更新了，所以无法逆向回溯，判断哪些物品放入了购物车中了
	cout<<dp[W];
	return 0;
	
}