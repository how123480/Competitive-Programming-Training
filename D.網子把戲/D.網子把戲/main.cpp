//
//  main.cpp
//  D.網子把戲
//
//  Created by HowardHoward on 17/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int T,N,M,Max;
int map[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>T;
    
    for(int k=0;k<T;++k){
        cin>>N>>M;
        Max=0;
        
        memset(map,0x3f,sizeof(map));
        
        for(int i=0;i<M;++i){
            int a,b,c;
            cin>>a>>b>>c;
            map[a][b]=map[b][a]=min(map[a][b],c);
        }
        
        for(int i=0;i<N;++i){
            map[i][i]=0;
        }
        
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                for(int h=0;h<N;++h){
                    map[j][h]=min(map[j][h],map[j][i]+map[i][h]);
                }
            }
        }
        
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(Max<map[i][j]) Max=map[i][j];
            }
        }
        cout<<Max<<"\n";
    }
    return 0;
}
