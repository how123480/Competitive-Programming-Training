
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[100005];
int g[100005];
int input[100005];


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    
    while(cin>>N){
        for(int i=0;i<N;i++)cin>>input[i];
        
        memset(dp, 0, sizeof(int)*N);
        int len = 1;
        dp[0] = input[0];
        for (int i = 1; i < N; ++i){

            int pos = (int)(lower_bound(dp, dp + len, input[i]) - dp);
            dp[pos] = input[i];
            len = max(len, pos + 1);
        }
        cout<<len<<endl;
    }
}


/*
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,j,i;
    dp[0]=1;
    g[0]=1;
    while(cin>>N){
        for(i=0;i<N;i++) cin>>input[i];
        
        for(i=1;i<N;i++){
            j=i-1;
            while(j>0){
               if(input[j]<input[i])
                   break;
                j--;
            }
            if(j==0 && input[i]<=input[j]) g[i]=1;
            else{
                g[i]= g[j]+1;
            }
            dp[i]=max(g[i],dp[i-1]);
        }
        cout<<dp[N-1]<<endl;
    }
    return 0;
}
*/
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n){
        vector<int> s(n+1);
        for(int i=0;i<n;i++)
            cin >> s[i];
        vector<int> v;
        v.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            int t=s[i];
            if(t>v.back()) v.push_back(t);
            else *lower_bound(v.begin(),v.end(),t)=t;
        }
        cout<<s[0]<<endl;
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
        
        cout << v.size() << '\n';
        v.clear();
    }
}
*/
