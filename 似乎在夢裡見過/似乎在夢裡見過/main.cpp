#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

int magic[1000000];
char metrix[10];
int index_m;

void setMagicNum(int size,char add){
    if(size>=9){
        return ;
    }else{
        stringstream ss;
        int i;
        metrix[size]=add;
        ss<<metrix;
        ss>>i;
        magic[index_m++]=i;
        setMagicNum(size+1,'1');
        setMagicNum(size+1,'2');
        setMagicNum(size+1,'7');
        metrix[size]='\0';
    }
}

int main() {
    int A,B,lower,upper;
    ios::sync_with_stdio(false);
    cin.tie(0);
    setMagicNum(0,'1');
    setMagicNum(0,'2');
    setMagicNum(0,'7');
    sort(magic,magic+index_m);
    
        while(cin>>A>>B){
        lower=(int)(lower_bound(magic,magic+index_m,A)-magic);
        upper=(int)(upper_bound(magic,magic+index_m,B)-magic);
        cout<<upper-lower<<"\n";
    }
    return 0;
}
