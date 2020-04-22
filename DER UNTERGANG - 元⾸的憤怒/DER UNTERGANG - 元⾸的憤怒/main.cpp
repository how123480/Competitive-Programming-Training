//
//  main.cpp
//  DER UNTERGANG - 元⾸的憤怒
//
//  Created by HowardHoward on 27/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int N,T,A;
int input[100005];
int record[100005];

int gcd(int a,int b){
    while((a%=b) && (b%=a));
    return a+b;
}

int main() {
    
    cin>>N;
    
    for(int i=0;i<N;++i) cin>>input[i];
    
    cin>>T;
    
    for(int z=0;z<T;++z){
        cin>>A;
        int len=0;
        bool find=false;
        
        for(int i=0;i<N;++i){
            if(input[i]%A==0){
                record[len++]=input[i];
            }
        }
        for(int i=0;i<len;++i){
            for(int j=i;j<len;++j){
                if(A==gcd(record[i],record[j])){
                    find=true;
                    break;
                }
            }
            if(find) break;
        }
        if(find) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}
