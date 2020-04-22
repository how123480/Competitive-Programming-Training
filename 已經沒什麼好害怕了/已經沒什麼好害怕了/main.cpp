//
//  main.cpp
//  已經沒什麼好害怕了
//
//  Created by HowardHoward on 24/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
using namespace std;
int damage[40000005]={0};
long long  attack[40000005]={0};

void setDamage(){
    int i=0;
    for(i=2;i<=40000000;i++){
        if(damage[i]==0){
            damage[i]=i;
            for(int j=i*2;j<=40000000;j+=i){
                if(damage[j]==0)
                    damage[j]=i;
            }
        }
    }
}
void setAttack(){
    int i=2;
    for(i=2;i<=40000000;i++) attack[i]=attack[i-1]+damage[i];
}
int main() {
    int T,a,b;
    long long ans=0;
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    
    setDamage();
    setAttack();
    for(int i=0;i<T;i++){
        cin>>a>>b;
        ans=0;
        //cout<<attack[39999999]<<"\n";
        ans=attack[b]-attack[a-1];
        //for(int i=0;i<100;i++) cout<<damage[i]<<endl;;
        cout<<"Case "<<i+1<<":\n";
        cout<<ans<<"\n";
    }
    
    return 0;
}
