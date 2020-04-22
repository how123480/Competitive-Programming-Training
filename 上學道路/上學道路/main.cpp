//
//  main.cpp
//  上學道路
//
//  Created by HowardHoward on 05/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> map[1001];
bool check[1001];

int N,M,s,t,f,d;
bool can=0;

void DFS(int num){
    
    int len=(int)map[num].size();
    vector<int> temp=map[num];
    
    check[num]=1;
    
    if(num==t){
        can=1;
        return ;
    }
    
    for(int i=0;i<len;i++){
        if(!check[temp[i]])
            DFS(temp[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>N>>M){
        can=0;
        memset(check,0,sizeof(check));
        memset(map,0,sizeof(map));
        
        for(int j=0;j<M;++j){
            cin>>f>>d;
            map[f].push_back(d);
        }
        
        cin>>s>>t;
        
        DFS(s);
        
        if(can)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        
    }
    return 0;
}
