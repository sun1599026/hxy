#include<iostream>
using namespace std;
//定义两个常量N：水晶的数目的上限，C：两座塔的高度差上限（因为N块水晶的高度总和最大值为2000，所以两座塔的高度差的最大值为2000
#define N 101
#define C 20001
//n:水晶的数量，h数组：每块水晶的高度，c[i][j]：前i块水晶组成的两座塔的高度差为j时，矮的那座塔的最大高度，sum[i]：前i块水晶的高度之和
int n,h[N],c[N][C],sum[N];
void update(int i,int j){
	//第一种情况：如果之后的if语句的条件都不满足，那么表示不能放第i块水晶，那么c[i][j]=c[i-1][j]
	c[i][j]=c[i-1][j];
	//第二种情况：再判断是否满足j-h[i]>=0,如果满足，则可以把第i块水晶放在高塔上，当然也可以选择不放这块水晶，那么c[i][j]=max(c[i][j],c[i-1][j-h[i]]);
	//由于当第i块水晶还没有放到高塔上时，c数组的为c[i-1][j-h[i]],因为当第i块水晶放到高塔上后，高度差变大，从j-h[i]变成j，但是由于放到高塔上，所以矮的塔的最大高度没改变
	//第三种情况，当j+h[i]<=sum[i-1]（因为j+h[i]是c[i-1]那一层的,所以j+h[i]要小于等于第i-1层的高度差最大值sum[i-1]),如果满足该条件，那么可以把水晶放在矮的塔上（当然也可以不放），且当放上去两座塔的高低关系不改变，
	//那么c[i][j]=max(c[i][j],c[i-1][h[i]+j]+h[i]),当第i块水晶还没放在矮的塔上时，高度差为h[i]+j,当第i块水晶放在矮的塔上后高度差减小变为j,矮的塔的最大高度值增加h[i]
	//第四种情况：当h[i]-j>=0时，可以把塔放在矮的塔上（当然也可以不放）且当两座塔的高低关系发生改变后，当还没放第i块水晶时，高度差为h[i]-j,当放上第i块水晶后高度差变为j（满足前i块水晶组成的塔的高度差为j),矮的塔(变成了之前高的那座塔）的最大高度增加h[i]-j
	if(j-h[i]>=0){
		c[i][j]=max(c[i][j],c[i-1][j-h[i]]);
	}
	if(j+h[i]<=sum[i-1]){
		c[i][j]=max(c[i][j],c[i-1][j+h[i]]+h[i]);
	}
	if(h[i]-j>=0){
		c[i][j]=max(c[i][j],c[i-1][h[i]-j]+h[i]-j);
	}
	
}
int main(){
	//读入水晶的数目，每块水晶的高度，并求前i块水晶的前缀和
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		sum[i]=sum[i-1]+h[i];
	}
	//初始化c数组，由于要求矮的那座塔的高度的最大值，所以c数组初始化为很小的值-03xf,并且初始化c[0][0]=0
	memset(c,-0x3f,sizeof(c));
	c[0][0]=0;
	//用01背包的方式，外层遍历n块水晶，内层循环遍历高度差在0~sum[i]的j，因为前i块水晶建成的两座塔的高度差一定小于等于前i块水晶的高度和sum[i]
	//由于此题放不放第i块水晶的状态转移有多种可能，每种可能对不同的状态转移方程，因此用update函数进行分类讨论
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum[i];j++){
			update(i,j);
		}
	}
	//最后如果c[n][0]即前n块水晶组成的高度差为0的两座塔中矮的那座塔的最大高度为0，表明无法组成两座高度一样的塔，所以输出不可能，否则输出c[n][0]的值，表示n块水晶组成的两座一样高的塔的最大高度
	if(c[n][0]==0){
		cout<<"Impossible";
	}
	else{
		cout<<c[n][0];
	}
	return 0;
	
}
