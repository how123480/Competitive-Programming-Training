#include <iostream>
#include <algorithm>
using namespace std;

long long dp[100001][2];
int n,cost[100001];
string string_collect[100001][2];

int main() {
    cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>cost[i];
        
    for(int i=1;i<=n;i++){
        cin>>string_collect[i][0];
        string_collect[i][1]=string_collect[i][0];
        reverse(string_collect[i][1].begin(),string_collect[i][1].end());
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            
            dp[i][j]=1000000000000000000;
            
            for(int k=0;k<2;k++){
                if(string_collect[i][j]>=string_collect[i-1][k]){
                    if(j==1)
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+cost[i]);
                    else if(j==0)
                        dp[i][j]=min(dp[i][j],dp[i-1][k]);
                }
            }
        }
    }
    long long ans=min(dp[n][0],dp[n][1]);
    if(ans>=1000000000000000000) ans=-1;
    cout<<ans<<endl;
    
    return 0;
}
