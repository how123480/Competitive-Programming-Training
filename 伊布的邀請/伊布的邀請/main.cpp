#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double a1,a2,b1,b2,ans1,ans2;
    char oper;
    
    scanf("%lf %lf %c %lf %lf",&a1,&a2,&oper,&b1,&b2);
    
    if(oper =='+'){
        ans1=a1+b1;
        ans2=a2+b2;
    }else if(oper =='-'){
        ans1=a1-b1;
        ans2=a2-b2;
    }else if(oper=='*'){
        ans1=a1*b1-a2*b2;
        ans2=a1*b2+a2*b1;
    }else {
        ans1=(a1*b1+a2*b2)/(b1*b1+b2*b2);
        ans2=(a2*b1-a1*b2)/(b1*b1+b2*b2);
    }
    
    printf("%.2f%+.2fi\n",ans1,ans2);
    
    return 0;
}
