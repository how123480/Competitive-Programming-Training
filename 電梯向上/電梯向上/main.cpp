#include <iostream>
#include <cstdio>

using namespace std;

int cus[200000];
int N, K;

bool Test(int P)
{
    int now = 0, cnt = 0;
    
    for(int i = 0; i < N; i++)
    {
        if( now + cus[i] > P ){ cnt++; now = 0; }
        now += cus[i];
    }
    cnt++;
    
    return cnt <= K;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while( T-- )
    {
        
        scanf("%d %d", &N, &K);
        
        int sum = 0; int mx = 0;
        
        for(int i = 0; i < N; i++)
        {
            int id, w;
            scanf("%d %d", &id, &w);
            
            
            mx = max(mx, w);
            cus[id] = w;
            sum += w;
        }
        
        int l = mx-1, r = sum;
        
        // cout<<Test(5)<<endl;getchar();
        
        while( l+1 != r )
        {
            int mid = (l+r)/2;
            
            if( Test(mid) == true ) r = mid;
            else l = mid;
        }
        
        printf("%d\n", r);
        
    }   
}
