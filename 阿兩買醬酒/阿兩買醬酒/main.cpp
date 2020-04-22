#include <iostream>
#include <cstring>
using namespace std;

struct edge{
    long long  s,e,w;
}E[1000005];

int N,M,S;


int main() {
    
    long long  dist[100005];
    bool record[100005]={0};
    bool update=false;
    long long ans=0;
    long long  max=0;
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>E[i].s>>E[i].e>>E[i].w;
        if(max<E[i].w) max=E[i].w;
    }
    cin>>S;
    
    memset(dist,0x3f,sizeof(dist));
    dist[S]=0;
    
    do{
        update=false;
        for(auto &v :E){
            if(dist[v.e]>dist[v.s]+v.w){
                dist[v.e]=dist[v.s]+v.w;
                update=true;
                record[v.e]=true;
            }
        }
    }while(update);
    
    for(int i=0;i<N;i++){
        if(!record[i]) continue;
        else{
            ans=ans%(1000000007)+((dist[i]*i)%1000000007);
        }
    }
    cout<<ans%(1000000007)<<"\n";
    return 0;
}
