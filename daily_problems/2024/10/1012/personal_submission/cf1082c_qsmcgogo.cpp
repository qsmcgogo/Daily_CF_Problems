#include<bits/stdc++.h>
using namespace std;
int res=0;
vector<int>g[202020];
long long sum[202020];
int main(){
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(i=1;i<=m;i++)sort(g[i].rbegin(),g[i].rend());
    set<int>s;
    for(i=1;i<=m;i++){
        if(g[i].size())
            s.insert(i);
    }
    long long temp=0,ma=0;
    for(i=1;i<=n;i++){
        set<int>stemp;
        for(auto j:s){
            temp+=g[j][i-1];
            sum[j]+=g[j][i-1];
            if(sum[j]<0){temp-=sum[j];stemp.insert(j);}
        }
        ma=max(ma,temp);
        
        for(auto j:s){
            //cout<<j<<' ';
            if(g[j].size()==i&&sum[j]>=0)stemp.insert(j),temp-=sum[j];
        }
       // cout<<'\n';
        for(auto j:stemp){
            s.erase(j);
        }
    }
    cout<<ma;
}
