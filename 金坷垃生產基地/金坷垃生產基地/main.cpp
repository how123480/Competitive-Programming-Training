//
//  main.cpp
//  金坷垃生產基地
//
//  Created by HowardHoward on 19/04/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//
#include <iostream>
#include <cstring>

using namespace std;

int map[17][17]={0};
int dp[(1<<17)-1][17];

int main() {
    int i,j,n,T,k,p;
    int ans;
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>T;
    for(int z=0;z<T;z++) {
        cin>>n;
        memset(map,0,sizeof(map));
        for (i=0; i<n; i++) {
            for (j=i+1; j<n; j++) {
                cin>>map[i][j],map[j][i]=map[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        dp[1][0]=0;
        // TSP solution here,bitmask and DP
        for (i=1; i<(1<<n); i++) {// the current state
            for (j=0; j<n; j++) {// during the current state,the last station is j
                if (dp[i][j]==-1) continue;
                for (k=1; k<n; k++) {//the next state is k
                    if ((i & (1<<k))!=0) continue; //一樣
                    p=(i | (1<<k));// the new state(join k)
                    if (dp[p][k]==-1) dp[p][k]=dp[i][j]+map[j][k];
                    dp[p][k]=min(dp[p][k],dp[i][j]+map[j][k]);
                }
            }
        }
        //ans=dp[(1<<n)-1][1]+map[1][0];
        //ans=9223372036854775807;
        ans=2147483647;
        // get answer
        for (i=1; i<n; i++) {
            if (dp[(1<<n)-1][i]>0) ans=min(ans,dp[(1<<n)-1][i]+map[i][0]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
