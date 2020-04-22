//
//  main.cpp
//  害羞的火精靈
//
//  Created by HowardHoward on 19/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
using namespace std;
long long  extGCD(long long  a,long long  b, long long  &x,long long  &y){
    long  d=a;
    
    if(b!=0){
        d=extGCD(b,a%b,y,x);
        y-=(a/b)*x;
    }else{
        x=1,y=0;
    }
    return d;
}
long long  modInverse(long long  n){
    long long  x,y;
    extGCD(n,24851,x,y);
    return(24851+x%24851)%24851;
}

int main() {
    long long  N,M,up=1,down=1,mod_down;
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    if(M-1>=(N-1)/2){
        M=N+1-M;
    }
   // cout<<M<<" "<<N<<endl;
    for(int i=0;i<M-1;i++){
        up*=(N-i-1); //cout<<up<<endl;
        up%=24851;
        down*=(i+1); //cout<<down<<endl;
        down%=24851;
    }
    
    mod_down=modInverse(down);
    
    cout<<(mod_down*up)%24851<<"\n";
    
        return 0;
}
