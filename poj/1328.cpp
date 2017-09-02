#include<cstdio>  //������ת����̰��˼�������ѡ������
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1003;
int X[MAXN],Y[MAXN];
struct Line{
    double l,r;
}line[MAXN];
int n,d;
int cmp(const Line &a,const Line &b){
    return a.r<b.r;
}
int solve(){
    if(d<=0||n<=0)return -1;   //ע�⼫����������
    for(int i=0;i<n;i++){
        double dis=d*d*1.0-Y[i]*Y[i]*1.0;
        if(dis<0)return -1;   //����������
        line[i].l=X[i]-sqrt(dis);
        line[i].r=X[i]+sqrt(dis);
    }
    sort(line,line+n,cmp);
    int t=0,ans=1;   //��һ���״�վ�϶�Ҫ����
    for(int i=1;i<n;i++){
        if(line[i].l>line[t].r){
            t=i;
            ans++;
        }
    }
    return ans;
}
int main()
{
    int t=0;
    while(scanf("%d%d",&n,&d)){
        if(n==0&&d==0)break;
        for(int i=0;i<n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        int res=solve();
        printf("Case %d: %d\n",++t,res);
    }
    return 0;
}
