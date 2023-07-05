#include<iostream>
using namespace std;
int main(){
    int t,l,n,m;
    char op;
    //读入测试数据的组数t
    cin>>t;
    for(int i=1;i<=t;i++){
        //对于每组测试数据都读入对应的操场的长度l和跑步的段数n
        long long sum=0,cnt=0;
        cin>>l>>n;
        while(n--){
            //读入每段跑步的路程和方向
            cin>>m>>op;
            //如果是顺时针就用+,即用正数来表示
            if(op=='C'){
                sum+=m;
            }else{
                //如果是逆时针就用-,即负数表示
                sum-=m;
            }
            //得到sum的绝对值，进行对操场的长度l整除，得到的就是机器能计数的跑步的圈数
            cnt+=abs(sum)/l;
            //最后计数完一个就进行取余得到剩余的距离起跑线的距离
            sum%=l;
        }
        cout<<"Case #"<<i<<": "<<cnt<<endl;
    }
    return 0;
   
}