//
//  main.cpp
//  可愛的小動物
//
//  Created by HowardHoward on 16/05/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
using namespace std;

int N;
int lead[500001];

int find(int x){
    if(lead[x] == x) return x;
    else return lead[x] = find(lead[x]);
}
bool same(int a,int b){
    return find(a)==find(b);
}

void U(int a,int b){
    lead[find(a)]=find(b);
}


int main() {
    cin>>N;
    string cmd1,cmd2,cmd3;
    int a,b;
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>cmd1>>cmd2>>cmd3){
        
         cin>>a>>b;
        
        if(cmd1 == "you" && cmd3 == "friends"){
            if(lead[a] == 0 || lead[b] == 0){
                
                if(lead[a]==0 && lead[b]==0) lead[a]=a,lead[b]=b,U(a,b);
                else if(lead[a]==0) lead[a]=a,U(a,b);
                else lead[b]=b,U(b,a);
                
            }else if(!same(a,b)) cout<<"angry"<<endl;
            
        }else if(cmd1 == "you" && cmd3 == "enemies"){
            if(lead[a]==0 || lead[b]==0){
                
                if(lead[a]==0 && lead[b]==0) lead[a]=a,lead[b]=b;
                else if(lead[a]==0) lead[a]=a;
                else lead[b]=b;
                
            }else if(same(a,b)) cout<<"angry"<<endl;
            
        }else if(cmd1 == "are" && cmd3 == "friends"){
            if(lead[a] ==0 || lead[b] ==0){
                cout<<"nope"<<endl;
            }else{
                if(same(a,b)) cout<<"yeap"<<endl;
                else cout<<"nope"<<endl;
            }
        }else if (cmd1 == "are" && cmd3 == "enemies"){
            if(lead[a] ==0 || lead[b] ==0){
                cout<<"nope"<<endl;
            }else{
                if(!same(a,b)) cout<<"yeap"<<endl;
                else cout<<"nope"<<endl;
            }
        }
        
    }
    return 0;
}
