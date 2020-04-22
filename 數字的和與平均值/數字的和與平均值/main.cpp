#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main() {
    char c[1000001];
    
    int ans=0,i=0,a;
    
    while(cin.getline(c,1000001)){
        for(i=0;i<(int)strlen(c);i++){
            if(isdigit(c[i])){
                a=c[i]-'0'; i++;
                while(isdigit(c[i])){
                    a=a*10+c[i]-'0';
                    i++;
                }
                ans+=a;
                a=0;
            }
        }
        
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
