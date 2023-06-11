#include<bits/stdc++.h>
using namespace std;
#define N 10005
int t,n,s,w[N],v[N],dp[N],cnt[N];
int main(){
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		cin>>n>>s;
		for(int i=1;i<=n;i++){
			cin>>w[i]>>v[i];
		}
		for(int i=0;i<=s;i++){
			dp[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=s;j>=w[i];j--){
				if(dp[j]<dp[j-w[i]]+v[i]){
					dp[j]=dp[j-w[i]]+v[i];
					cnt[j]=cnt[j-w[i]]+1;//注意这里的计数，不能直接num++，必须从上个状态的cnt中推出2当前状态的cnt
				}
			}
		}
		cout<<dp[s]<<" "<<cnt[s]<<endl;
	}
	return 0;
}