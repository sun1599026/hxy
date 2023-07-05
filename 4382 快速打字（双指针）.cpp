#include<iostream>
using namespace std;
int main(){
    //解除绑定，加快cin和cout的速度
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string a,b;
    cin>>t;
   for(int k=1;k<=t;k++){
        cin>>a>>b;
        //设置双指针，指针i指向a字符串，指针j指向b字符串，进行字符串匹配
        int i=0,j=0;
        //如果a[i]==b[i]，那么i指针向后移动，同时也可以作为计数变量
        //如果没匹配到，那么就j指针向后移动
        //如果指针j走到b串最后了，也还是没有匹配到，那么就跳出结束
        for(;j<b.size();j++){
            if(a[i]==b[j]){
                i++;
            }
            //如果i指针已经走到a串的最后了，那么就可以break出去了
            if(i>=a.size()){
                break;
            }
        }
        //最后只要判断一下计数变量i是否等于字符串a的长度，如果是，那么就表明
        //是可以通过删除b串得到a串的，删除的字符的数量就是b串的长度减去a串的长度
        if(i==a.size()){
            cout<<"Case #"<<k<<": "<<b.size()-i<<endl;
        }else{
            cout<<"Case #"<<k<<": "<<"IMPOSSIBLE"<<endl;
        }
        
    }
    return 0;
}