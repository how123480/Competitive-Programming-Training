//
//  main.cpp
//  那樣的事，我絕不容許
//
//  Created by HowardHoward on 04/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[1002][1002];
string input;
int N,ans;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    cin>>input;
    
    for(int i=0;i<=N;++i)
        dp[1][i]=1;
    
    /*
    for(int i=2;i<=N;++i){
        for(int j=1;j<=N;++j){//現在的
            if(input[i-2]=='>'){
                for(int k=j+1;k<=N;++k)
                    dp[i][j]+=dp[i-1][k];
                
            }else if(input[i-2]=='<'){
                for(int k=1;k<j;++k)
                    dp[i][j]+=dp[i-1][k];
                
            }else if(input[i-2]=='='){
                dp[i][j]+=dp[i-1][j];
            }
        }
    }
    */
    
        for(int i=2;i<=N;++i){
            if(input[i-2]=='>'){
                for(int j=N-1;j>=1;--j){
                    dp[i][j]=(dp[i][j+1]+dp[i-1][j+1])%(1000000009);
                }
            }else if(input[i-2]=='<'){
                for(int j=2;j<=N;++j){
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%(1000000009);
                }
            }else if(input[i-2]=='='){
                for(int j=1;j<=N;++j){
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    /*
    for(int i=0;i<=N;++i){
        for(int j=0;j<=N;++j)
            cout<<dp[i][j]<<" ";
            cout<<"\n";
    }
    */
    for(int i=1;i<=N;++i){
        ans+=(dp[N][i])%(1000000009);
        ans%=1000000009;
    }
    cout<<ans<<"\n";
}
