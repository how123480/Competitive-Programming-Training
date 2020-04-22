#include <iostream>
#include <cstring>
using namespace std;

int dp[201][201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char s[201];
    char t[201];
    char r[201];
    
    while(cin>>s>>t>>r){
        int i,j,k,lens=(int)strlen(s),lent=(int)strlen(t),lenr=(int)strlen(r);
        
        for(i=0;i<lens;i++){
            for(j=0;j<lent;j++){
                for(k=0;k<lenr;k++){
                    if(s[i]==t[j] && t[j]==r[k]){
                        if(i-1<0 || j-1<0 || k-1<0)
                            dp[i][j][k]=1;
                        else{
                            dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                        }
                    }else{
                            if(i-1<0 || j-1<0 || k-1<0){
                                if(i>0 && j==0 && k==0){
                                    dp[i][j][k]=dp[i-1][j][k];
                                }else if(i==0 && j>0 && k==0){
                                    dp[i][j][k]=dp[i][j-1][k];
                                }else if(i==0 && j==0 && k>0){
                                    dp[i][j][k]=dp[i][j][k-1];
                                }else if(i==0 && j>0 && k>0){
                                    dp[i][j][k]=max(dp[i][j-1][k],dp[i][j][k-1]);
                                }else if(i>0 && j==0 && k>0){
                                    dp[i][j][k]=max(dp[i-1][j][k],dp[i][j][k-1]);
                                }else if(i>0 && j>0 && k==0){
                                    dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k]);
                                }else {
                                    dp[i][j][k]=0;
                                }
                            }
                            else{
                                int a1=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                                int a2=max(dp[i][j-1][k-1],max(dp[i-1][j][k-1],dp[i-1][j-1][k]));
                                dp[i][j][k]=max(a1,a2);
                            }
                    }
                }
            }
        }
        cout<<dp[lens-1][lent-1][lenr-1]<<endl;
    }
}
