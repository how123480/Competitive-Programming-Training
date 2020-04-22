//
//  main.cpp
//  SMM數
//
//  Created by HowardHoward on 22/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int ms[1000001];
int result[1000000];
bool mms[1000001];
//int num_ms=0;
int num_mms=0;
/*
void msSet(){
    int i=2;
    ms[0]=0;
    ms[1]=1;
    ms[2]=1;
    
    for(i=3;i<=100;i++) ms[i]=ms[i-1]+ms[i-2];
    return ;
}
*/
/*
void mmsSet(){
    int i=1;
    //將非mms數設為0
    for(i=3;i<=100;i++){
        if(ms[i]!=0){
            int j=i+1;
            while(j<=100){
                if(ms[j]!=0){
                    if(ms[j]%ms[i]==0)
                        ms[j]=0;
                    j++;
                }
            }
        }
    }
    for(i=3;i<=100;i++){
        if(ms[i]!=0){
            mms[num_mms]=ms[i];
            num_mms++;
        }
    }
}
 */

void mmsSet(){
    int i=3;
    mms[0]=-1;
    mms[1]=-1;
    mms[2]=-1;
    for(i=3;i<=1000000;i++){
        if(mms[i]==0){
            for(int j=i*2;j<=1000000;j+=i){
                if(mms[j]==0){
                    mms[j]=-1;
                }
            }
        }
    }
    //for(i=0;i<=100;i++) cout<<mms[i]<<'\n';
    
    memset(result,0,sizeof(result));
    result[0]=0;
    for(i=1;i<=1000000;i++){
        result[i]=result[i-1];
        if(mms[i]==0){result[i]++;}
    }
}
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //msSet();
    mmsSet();
    
    int n,turn=1;
    while(cin>>n){
        if(n==0) return 0;
        
        cout<<"Case #"<<turn<<": "<<result[n]<<"\n";
        turn++;
    }
    mmsSet();
    
}
