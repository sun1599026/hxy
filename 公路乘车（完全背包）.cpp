#include<iostream>
using namespace std;
//定义一个常量：N：行驶的公里数的上限100
#define N 101
//n:行驶的公里数，dp[j]；表示达到行驶公里数为j时最少的费用，a数组：存到每个站的费用
int n,dp[N],a[11];
int main(){
	//读入公里数，到达每个站点的费用
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	cin>>n;
	//由于要求的是最少的费用，所以初始化时把整个数组dp初始化为0x3f3f3f3f(无穷大）
	//但是矩阵中的其他的点都是从dp[0]推断出来的，所以dp[0]先要初始化为0，这样基于该点推导出来的一定是正确的
    memset(dp,0x3f3f3f,sizeof(dp));
    dp[0]=0;
    //最外层的for循环用于遍历10个车站，中层循环用来遍历剩余的可行驶公里数(注意要逆序，防止掩盖），内层循环用来枚举同一个站点要行驶几次，（k=0,k<=j/i;k++)
    //状态转移方程：dp[j]=min(dp[j],dp[j-k*i]+k*a[i])，用一维数组dp优化空间复杂度
    for(int i=1;i<=10;i++){
    	for(int j=n;j>=i;j--){
    		for(int k=0;k*i<=n;k++){
    			dp[j]=min(dp[j],dp[j-k*i]+k*a[i]);
			}
		}
	}
	//最后输出dp[n]，表示行驶n公里所需要的费用
	cout<<dp[n];
	return 0;
} 