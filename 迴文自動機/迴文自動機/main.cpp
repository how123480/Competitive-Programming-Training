//
//  main.cpp
//  迴文自動機
//
//  Created by HowardHoward on 05/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int dp[1001][1001];

int main() {
   
    string rev;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>rev){
        string input;
        int slen=(int)rev.size();
        input=rev;
        reverse(rev.begin(),rev.end());
        for (int i=0; i<=slen; i++) dp[i][0]=0,dp[0][i]=0;
        
        for(int i=0;i<slen;i++){
            for(int j=0;j<slen;j++){
                if(input[i]==rev[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        cout<<slen-dp[slen][slen]<<"\n";

        
    }
    return 0;
}
