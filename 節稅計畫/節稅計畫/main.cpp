//
//  main.cpp
//  節稅計畫
//
//  Created by HowardHoward on 08/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool notprime[50000];
int num=0;
int prime[7000];
int counter;

void primeSet(){
    int i,j,k,len=(int)sqrt(50000);
    notprime[0]=true;
    notprime[1]=true;
    
    for(i=2;i<=len;i++){
        if(!notprime[i]){
            for(k=(50000-1)/i,j=i*k ;k>=i;k--,j-=i)
                if(!notprime[k])
                    notprime[j]=true;
        }
    }
    
    for(i=0;i<49000;i++){
        if(!notprime[i]){
            prime[counter]=i;
            counter++;
        }
    }
}
bool isPrime(long n){
    int i;
    
    if(n>=44000){
        for(i=0;i<counter;i++){
            if(n%prime[i]==0){
                return 0;
            }
        }
        return 1;
    }else{
        if(!notprime[n])
            return 1;
        else return 0;
    }
}
/*
bool isPrime(long n){
    long q=(long)sqrt(n);
    
    for(int i=2;i<=q;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

void findPrime(long n){
    long i;
    
    if(n%2==0 && n!=2){
        num+=2;
        return ;
    }else{
        if(n==0){
            return;
        }else {
            if(n<500000){
                for(i=n;i>0;i--){
                    if(!notprime[i])
                        break;
                }
                // cout<<i<<endl;
                num++;
                findPrime(n-i);
            }else{
                for(i=n;i>0;i--){
                    if(isPrime(i)){
                        break;
                    }
                }
                // cout<<i<<endl;
                num++;
                findPrime(n-i);
            }
        }
    }
}
*/
int findPrime(long n){
    
    if(isPrime(n)){
        return 1;
    }else if(isPrime(n-2)){
        return 2;
    }else   return 3;
    
}
int main() {
    long money;
    
    primeSet();
    
    while(cin>>money){
       if(money!=2 &&money%2==0)
          cout<<"2\n";
       else{
            num=findPrime(money);
            cout<<num<<"\n";
            num=0;
       }
    }
    return 0;
}
