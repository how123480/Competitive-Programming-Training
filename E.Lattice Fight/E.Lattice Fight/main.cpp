//
//  main.cpp
//  E.Lattice Fight
//
//  Created by HowardHoward on 22/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
int gcd(int a,int b){
    while((a%=b)&&(b%=a));
    return a+b;
}
int main() {
    int x1,y1,x2,y2,ans=0,g,p;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>x1>>y1>>x2>>y2){
        ans=0;
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        
        if(x1==x2){
            ans+=y2-y1+1;
        }else if(y1==y2){
            ans+=x2-x1+1;
        }else{
            g=gcd(y2-y1,x2-x1);
            ans+=x2-x1+1;
            ans+=y2-y1+1;
            p=(y2-y1)/g;
            //cout<<g<<endl;
            //cout<<p<<endl;
            ans+=(int)((y2-y1)/p+1);
            ans-=3;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
