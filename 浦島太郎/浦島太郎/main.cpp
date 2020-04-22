//
//  main.cpp
//  浦島太郎
//
//  Created by HowardHoward on 16/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//
#include <iostream>
#include <cstring>
using namespace std;

struct edge{
    long long  s,e,w;
}E[100000];

long long  N,M;

int main() {
    long long  dist[1001];
    int record[1001]={0};
    bool update=false;
    bool negc=false;
    cin>>N>>M;
    
    for(int i=0;i<M;++i)
        cin>>E[i].s>>E[i].e>>E[i].w;
    
    memset(dist,0x3f,sizeof(dist));
    dist[0]=0;
    
    do{
        update=false;
        for(auto &v: E){
            if(dist[v.e]>dist[v.s]+v.w){
                dist[v.e]=dist[v.s]+v.w;
                update=true;
                record[v.e]++;
            }
        }
        for(int i=1;i<N;++i)
            if(record[i]>=N) {
                negc=true;
                break;
            }
    }while(update && !negc);
    /*
     for(int i=1;i<N;++i){
     cout<<i<<":"<<record[i]<<endl;
     cout<<i<<":"<<dist[i]<<endl;
     }
     */
    if(record[N-1]==0){
        cout<<"alone forever"<<"\n";
    }else if(negc && record[N-1]>=1){
        cout<<"hug hug"<<"\n";
    }else{
        cout<<dist[N-1]<<"\n";
    }
    return 0;
}
