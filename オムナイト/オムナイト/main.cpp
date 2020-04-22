//
//  main.cpp
//  オムナイト
//
//  Created by HowardHoward on 05/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int N,M;
int check[17];
int input[17];

vector<int> o[16];
int s[16];

void DFS(int num,int size){
    int len=(int)o[num].size();
    vector<int> temp=o[num];
    
    check[num]=1;
    s[size-1]=input[num];
    if(size==M){ //顯示
        for(int i=0;i<M;i++){
            cout<<s[i]<<" ";
        }
        cout<<"\n";
    }else{
        for(int i=0;i<len;i++){
            if(!check[temp[i]]){
                if(i==0)
                    DFS(temp[i],size+1);
                else
                    if(input[temp[i]]!=input[temp[i]-1])
                        DFS(temp[i],size+1);
            }
        }
    }
    check[num]=0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>N>>M){
        memset(check,0,sizeof(check));
        memset(o,0,sizeof(o));
        for(int j=1;j<=N;j++){
            cin>>input[j];
        }
        sort(input+1,input+N+1);
        for(int j=2;j<=N;j++){
            
            for(int i=1;i<j;i++){
                
                o[i].push_back(j);
            }
        }

        for(int i=1;i<=N;i++){
            if(i==1)
                DFS(i,1);
            else{
                if(input[i]!=input[i-1])
                    DFS(i,1);
            }
        }
    }
}
