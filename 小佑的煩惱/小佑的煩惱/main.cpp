//
//  main.cpp
//  小佑的煩惱
//
//  Created by HowardHoward on 16/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int bag[100001];
int ans[100001];
int question,lower,upper;
int n,q,i;
bool cmp(const int &a,const int &b){
    return a<b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    if(q==0) return 0;
    for(i=0;i<n;i++) cin>>bag[i];
    
    sort(bag,bag+n,cmp);
    
    for(i=0;i<q;i++){
        cin>>question;
        lower=(int)(lower_bound(bag,bag+n,question)-bag);
        upper=(int)(upper_bound(bag,bag+n,question)-bag);
        cout<<upper-lower<<"\n";
    }
    /*
    for(i=0;i<q;i++)
        cout<<ans[i]<<'\n';
     */
    return 0;
}
