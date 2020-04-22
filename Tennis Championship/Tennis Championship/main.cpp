//
//  main.cpp
//  Tennis Championship
//
//  Created by HowardHoward on 31/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
using namespace std;
long long F[10001];

void setF(){
    int i=0;
    F[0]=1;
    F[1]=2;
    for(i=2;i<10000;i++)
        F[i]=F[i-1]+F[i-2];
}

int main() {
    long long  num;
        setF();
        cin>>num;
        int i=0;
        while(F[i]<=num) i++;
        cout<<i-1<<'\n';
    return 0;
}
