//
//  main.cpp
//  第三帝國
//
//  Created by HowardHoward on 16/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M;
long long ans;
bool didit=true;

struct edge{
    int s,e,w;
}E[1000001];

int lead[100001];

void init(int N){
    for(int i=0;i<=N;++i)
        lead[i]=i;
}

int find(int x){
    if(lead[x]==x) return x;
    else return lead[x]=find(lead[x]);
}
bool same(int a,int b){
    return find(a)==find(b);
}
void U(int a,int b){
    lead[find(a)]=find(b);
}

bool operator<(const edge &a,const edge &b){
    return a.w<b.w;
}

long long  Kruskal(){
    sort(E,E+M);
    init(N);
    long long  W=0;
    
    for(int i=0;i<M;++i){
        if(!same(E[i].s,E[i].e)){
            U(E[i].s,E[i].e);
            W+=E[i].w;
        }
    }
    return W;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        cin>>E[i].s>>E[i].e>>E[i].w;
    }
    
    ans=Kruskal();
    
    for(int i=1;i<N;++i){
        if(!same(0,i)){
            didit=false;
            break;
        }
    }
    
    if(!didit)
        cout<<"Und doch habe ich allein\n";
    else
        cout<<ans<<"\n";
    
}
