#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool notprime[1000000];
int prime[500000];
int counter=0;
bool table[1000000]={0};
int ans;

void primeSet(){
    int i,j,k,len=(int)sqrt(1000000);
    notprime[0]=true;
    notprime[1]=true;
    
    for(i=2;i<=len;i++){
        if(!notprime[i]){
            for(k=(1000000-1)/i,j=i*k ;k>=i;k--,j-=i)
                if(!notprime[k])
                    notprime[j]=true;
        }
    }
    
    for(i=2;i<=1000000;i++){
        if(!notprime[i]){
            prime[counter]=i;
            counter++;
        }
    }
}
void primetable(long long a,long long b){
    long long k;
    int i;
    
    for(i=0;i<counter;i++){
        k=a;
        k-=k%prime[i];
        if(k<a){
            k+=prime[i];
        }
        
        for(;k<=b;k+=prime[i]){
            if(table[k-a]==0){
                table[k-a]=1;
                ans++;
            }
        }
    }
    
}


int main() {
    long long A,B;
    int lower ,upper;
    primeSet();
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>A>>B){
        if(B<A) swap(A,B);
        ans=0;
        
        if(A<1000000 && B<1000000){
            lower=(int)(lower_bound(prime,prime+counter,A)-prime);
            upper=(int)(upper_bound(prime,prime+counter,B)-prime);
            cout<<upper-lower<<"\n";
        }else if(A<1000000 && B>=1000000){
            lower=(int)(lower_bound(prime,prime+counter,A)-prime);
            upper=(int)(upper_bound(prime,prime+counter,999999)-prime);
            primetable(1000000,B);
            //cout<<upper-lower<<" "<<B-1000000+1-ans;
            memset(table,0,sizeof(table));
            cout<<upper-lower+B-1000000+1-ans<<"\n";
        }else{
            primetable(A,B);
            memset(table,0,sizeof(table));
            cout<<B-A+1-ans<<"\n";
        }
        
    }
}
