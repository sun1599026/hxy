#include<iostream>
using namespace std;
#define N 105
int t,n,a[N][N];
int main(){
	cin>>t;
	//基本dp思想：
	//将大问题分解成小问题，再通过决策解决小问题后，将小问题的决策结果与大问题联系，再解决大问题
	//本题数塔：
	//小问题：就是解决当只有倒数两层的时候，从塔顶走到塔底能得到的最大和，状态转移方程：a[i][j]（父节点）=max(a[i+1][j]（左孩子）,a[i+1][j+1]（右孩子）)+a[i][j],i表示是在塔的第几层，j表示的位于盖层道德第几个节点
	//所以从下往上依次取每一个位置连接的下方两个数中较大的数与父节点做和，即顶层最后的值就是从顶层到底层可能得到的最大的值
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cin>>a[i][j];
			}
		}
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=i;j++){
				a[i][j]=max(a[i+1][j],a[i+1][j+1])+a[i][j];
			}
		}
		cout<<a[1][1]<<endl;
	}
	return 0;
}