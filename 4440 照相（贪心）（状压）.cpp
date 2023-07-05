#include<iostream>
using namespace std;
#define M 200000
int main(){
    //解除绑定就可以使得cin与cout与scanf和printf有相近的读取和输出效率
    //cin与cout比较慢是因为它们要先将数据存在缓存区，之后再将数据读入或输出
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
    int n,count=0,a[M],ans=0;
    string s;
    cin>>n>>s;
    //因为n是偶数，进行反转的字符串的长度也是偶数，所以最小的单位就是两个字符：
    //HH、GG、HG、GH，而HH和GG反转是没有用的，应该尽可能地将GH反转成HG
    //所以先两个两个遍历字符串，将HG标记为0，GH标记为1，存入a数组中，类似于dp中的状态压缩
    //用0和1表示GH和HG两种状态
    for(int i=0;i<n;i+=2){
        if(s[i]!=s[i+1]&&s[i]=='H'){
            a[count++]=0;
        }else if(s[i]!=s[i+1]&&s[i]=='G'){
            a[count++]=1;
        }
    }
    //遍历数组a，如果找到相邻的两个元素不是相同的，就将该元素的前的所有的进行反转
    //例：0101 -> 1101 -> 0001 -> 1111 -> 0000，每次反转不一定是使GH变成HG，也可能是
    //把HG变成GH，目的是让前面的最好更长的连续的字符串能够相同状态，这样可以进行一次性反转
    //注意反转是前缀都反转，不能中间的某个单独进行反转
    //最后一次反转肯定是整体反转（最后一位是1）或者是已经反转好了（最后一位是0），i=count-1时
    //由于a数组中的每个原先默认为0，所以能把整体反转的那一次计数进去
    for(int i=0;i<count;i++){
        if(a[i]!=a[i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}