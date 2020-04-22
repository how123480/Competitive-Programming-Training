#include <iostream>
#include <cstring>
using namespace std;

int w[101];
int c[101];
int dp[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int S,N,count=1;
    
    while(cin>>S>>N){
        if(count>200) break;
        //for(int i=0;i<N;i++)
        //    cin>>w[i]>>c[i];
        
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
            cin>>w[i]>>c[i];
        
        for(int i=0;i<N;i++){
            for(int v=w[i];v<=S;v++){
                dp[v]= max(dp[v],dp[v-w[i]]+c[i]);
            }
        }
        cout<<dp[S]<<endl;
        count++;
    }
    return 0;
}
