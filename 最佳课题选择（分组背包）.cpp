#include<iostream>
using namespace std;
//定义两个常量：N：论文的数量上限，M：课题数的上限
#define N 201
#define M 21
//定义long long类型的变量，因为本题每个课题完成的时间是a[i]*x^b[i],是指数次不用long long的话可能超范围
//n:论文的数量，m：课题的数量，dp[i]:表示要完成i篇论文所需要的最少时间，a数组用来存每种课题的ai,b数组：存每种课题的bi
long long n,m,dp[N],a[M],b[M];
//定义一个solved函数，读入某个课题的论文数k，和该种课题的bi,计算出k^bi后返回
long long solved(int k,int b){
	long long sum=1;
	for(int i=1;i<=b;i++){
		sum*=k;
	}
	return sum;
}
int main(){
	//读入论文的数量和课题的数目，每种课题的ai,bi
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	//千万不要忘记对dp数组进行初始化，因为dp[i]数组求完成i篇论文所需要的最少时间，所以要把dp每个值初始化成很大的数!!(如果求最大值，那么要把每个数初始化为0），以便能使得dp[1]一定比dp中的每个数都小
	//并且初始化dp[0]=0
	memset(dp,0x3f3f3f,sizeof(dp));
	dp[0]=0;
	//由于有m个不同的课题，把每个课题看做一个组，这个组的每个数分别表示论文数，从0篇~n篇，但只能选择一种可能，要使得最后的总时间最短，可见是一个分组背包问题
	//对于分组背包问题，要有三层for循环，第一层for循环表示遍历m个组，（里面的两层for循环表示每组课题又是一个01背包问题），第二层for循环表示逆向遍历n~0篇论文，表示能
	//写的总论文数，（逆向遍历是由于用一维数组dp代替二维数组，因此为了防止掩盖，要逆向遍历），第三层循环遍历每组课题可能的论文数0~n,
	//如果满足j>=k(表示剩需要的论文数还是大于k，那么要更新dp[j]=min(dp[j],dp[j-k]+a[i]*solved(k,b[i])),这个课题要不要选择k篇论文
	for(int i=1;i<=m;i++){
		for(int j=n;j>=0;j--){
			for(int k=0;k<=n;k++){
				if(j>=k){
					dp[j]=min(dp[j],dp[j-k]+a[i]*solved(k,b[i]));
				}
			}
		}
	}
	//最后输出dp[n],即为完成n篇论文所需的最少时间
	cout<<dp[n];
	return 0;
}
