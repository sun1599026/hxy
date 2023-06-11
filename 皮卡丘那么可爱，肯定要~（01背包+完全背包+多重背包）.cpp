#include<iostream>
#define N 10005
using namespace std;
int h1,h2,m1,m2,n,w;
char a,b;
int t[N],q[N],s[N],dp[5*N];
int main(){
	cin>>h1>>a>>m1>>h2>>b>>m2>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>q[i]>>s[i];
	}
	if(m2-m1>0){
		w=(h2-h1)*60+(m2-m1);
	}else{
		w=(h2-h1-1)*60+(60-m1+m2);
	}
	for(int i=1;i<=n;i++){
		if(s[i]==0||s[i]*t[i]>=w){
			for(int j=t[i];j<=w;j++){
				dp[j]=max(dp[j],dp[j-t[i]]+q[i]);
			}
		}else{
			int d=1;
			while(s[i]-d>0){
				for(int k=w;k>=t[i]*d;k--){
					dp[k]=max(dp[k],dp[k-t[i]*d]+q[i]*d);
				}
				s[i]-=d;
				d*=2;
			}
			if(s[i]){
				for(int ii=w;ii>=t[i]*s[i];ii--){
					dp[ii]=max(dp[ii],dp[ii-t[i]*s[i]]+q[i]*s[i]);
				}
			}
		}
	}
	cout<<dp[w]<<endl;
	return 0;
	
}

