#include<stdio.h>
int main(){
    //注意要将这些变量定义成long long类型的：10^18
    //方案数、要判断的区间的右端点T、第di天、bi捆干草、上一次送干草的日期、当前的干草数量、贝茜能吃到干草的总天数
    long long n,t,di,bi,day=0,g=0,s=0;
    //用scanf读入，比用cin读入更快，对于long long类型用"%ld"
    scanf("%ld %ld",&n,&t);
    while(n--){
        scanf("%ld %ld",&di,&bi);
        //当下次去送干草的时候只可能出现两种情况：
        //1.草吃完了：di-day>=g，例如5-2=3，因为从第2天开始吃3捆，那么第四天就吃完了，到了第5天去送干草的时候已经没有干草了
        //那么更新总天数和当前草的捆数：s+=g,g=bi
        if(di-day>=g){
            s+=g;
            g=bi;
        }else{
            //2.第二种情况就是当第di去送草的时候草还没有吃完，那么就s+=di-day(不包括第day天，因为是白天去送草，吃草是在晚上，还没吃就不要加到s中)
            //g-=di-day:表示剩余的草捆数，g+=bi:在剩余的草的捆数的基础上再加上新送来的草的捆数
            s+=di-day;
            g-=di-day;
            g+=bi;
        }
        //更新上一次送草是第几天
        day=di;
    }
    //判断一下，如果当前的草够后面的第day天~第t天吃的话（g>=t-day+1）,那么就让s+=t-day+1;
    //否则就s+=g
    if(g>=t-day+1){
        s+=t-day+1;
    }else{
        s+=g;
    }
    printf("%ld",s);
    return 0;
}