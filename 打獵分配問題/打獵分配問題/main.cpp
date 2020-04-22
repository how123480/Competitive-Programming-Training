//
//  main.cpp
//  打獵分配問題
//
//  Created by HowardHoward on 07/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Cat{
    string name;
    string status;
    int old;
    int statusnum;
};

vector<Cat> cat;
int recordnum=0;

int findstatus(string str){
    if(str == "elder")
        return 1;
    else if(str == "nursy")
        return 2;
    else if(str == "kit")
        return 3;
    else if(str == "warrior")
        return 4;
    else if(str == "appentice")
        return 5;
    else if(str == "medicent")
        return 6;
    else if(str == "deputy")
        return 7;
    else
        return 8;
}

bool cmp(const Cat &a, const Cat &b ){
    
    if(a.statusnum==b.statusnum){
        if(a.old==b.old){
            return a.name<b.name;
        }else{
            if(a.statusnum==5 && b.statusnum==5)
                return a.old<=b.old;
            else
                return a.old>=b.old;
        }
    }else{
        return a.statusnum<b.statusnum;
    }
}

int main() {
    int i=0,num,shownum;
    Cat insert;
    
    
    while(cin>>num>>shownum){
        
        recordnum=0;
        if(num<shownum) shownum=num;
        for(i=0;i<num;i++){
            cin>>insert.name>>insert.status>>insert.old;
            insert.statusnum=findstatus(insert.status);
            cat.push_back(insert);
        }
        sort(cat.begin(),cat.end(),cmp);
        
        for(i=0;i<shownum;i++)
            cout<<cat[i].name<<"\n";
        
        cat.clear();
    }
    return 0;
}
