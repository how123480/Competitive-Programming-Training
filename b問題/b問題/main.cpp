#include<cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int Dec[200000];
int check[200000];
int num,site,type;


void devide(int a,int b){
    int neg=0,temp=0;
    
    if(a%b == 0){
        cout<<a/b<<endl;
        return ;
    }
    
        if(a<0&&b>0 || a>0&&b<0) neg=1;
        if(a<0) a=-a;
        if(b<0) b=-b;
    
        num=0;
        temp=a/b;
        check[0]=a%b;
        while(1){
            a=check[num]*10;
            num++;
            Dec[num]=a/b;
            check[num]=a%b;
            if(a%b == 0){
                type=2;
                break;
            }
            for(int i=0;i<num;i++){
                if(check[num]==check[i]){
                    type=3;
                    site=i;
                    break;
                }
            }
            if(type==3) break;
        }

        if(neg)
            cout<<"-";
        cout<<temp<<".";
        if(type==2){
            for(int i=1;i<=num;i++)
                cout<<Dec[i];
            cout<<endl;
        }else if(type==3){
            if(site==0) cout<<"(";
            for(int i=1;i<=site;i++)
                cout<<Dec[i];
            if(site!=0) cout<<"(";
            for(int i=site+1;i<=num;i++)
                cout<<Dec[i];
            cout<<")"<<endl;
        }
}

int main()
{
    int a,b;
    
    while(scanf("%d/%d = ?",&a,&b)!=EOF){
        devide(a,b);
        num=0;
        site=0;
        type=0;
    }
}



/*
 int Dec[2000000];
 int check[2000000];
 int type=0,num=0,site=0;

int recorded(int n){
    int i=0;
    
    for(i=0;i<num;i++){
        if(n==check[i]){
            site=i;
            return 1;
        }
    }
    return 0;
}
void devide(int a,int b){
    int neg=0,temp;
    double temp2=(double)a/(double)b;
    temp=a/b;
    if((a<0&&b>0) || (a>0&&b<0)) neg=1;
    if(a<0) a=-a;
    if(b<0) b=-b;
    
    if(a%b==0){
        type=1;
    }else{
        //remain=a%b;
        //dectemp=a/b;
        check[0]=a%b;
        while(1){
        //
            if(remain==0){
                type=2;
                break;
            }else if(recorded(remain)){
                type=3;
                break;
            }
            Dec[num]=dectemp;
            check[num]=remain;
            num++;
            remain%=b;
            remain*=10;
           // dectemp=remain/b;
 
            
            a=check[num]*10;
            num++;
            Dec[num]=a/b;
            check[num]=a%b;
            if(a%b == 0){
                type=2;
                break;
            }
            if(recorded(check[num])) {
                type=3;
                break;
            }
        }
    }
    
    if(type==1){
        cout<<temp<<endl;
    }else if(type==2){
        cout<<temp2<<endl;
    }else{
        if(neg){
            cout<<'-'<<temp<<'.';
        }else
            cout<<temp<<'.';
        
        
       // for(i=1;i<num;i++){
            if(i==site) cout<<'('<<Dec[i];
            else
                cout<<Dec[i];
        }
       // cout<<')'<<endl;
        
        
        if(site==0) cout<<"(";
        for(int i=1;i<=site;i++)
            cout<<Dec[i];
        if(site!=0) cout<<"(";
        for(int i=site+1;i<=num;i++)
            cout<<Dec[i];
        cout<<")"<<endl;
    }
    
}

int main(){
    int a,b;
    char c;
    while(cin>>a>>c>>b>>c>>c){
        
        devide(a,b);
        
       memset(check,0,2000000);
        memset(Dec,0,2000000);
        type=0,num=0,site=0;
        
        
    }
}
*/
        
/*
int num=0; //小數長
//int remainder; //重複於數
int type;// 1==整除 2==有限小數 3==無限小數
int Dec[100000];
int checkboard[100000];
int start,end1;

void showans(int a,int b){
    
    int i;
    
    if(type==1){
        printf("%d\n",a/b);
    }else if(type==2){
        printf("%.*f\n",end1,(float)a/(float)b);
    }else{
        if((double)a/(double)b>=0)
            printf("%d.",a/b);
        else
            printf("-%d.",a/b);
        if(start==0){
            printf("(");
            for(i=0;i<end1;i++){
                if(i==end1-1)
                    printf("%d)\n",Dec[i]);
                else
                    printf("%d",Dec[i]);
            }

        }else{
            for(i=0;i<end1;i++){
                if(i==start-1)
                    printf("%d(",Dec[i]);
                else if(i==end1-1)
                    printf("%d)\n",Dec[i]);
                else
                    printf("%d",Dec[i]);
            }
        }
    }
    return;
    
}

int check(int n){
    int i;
    for(i=0;i<num;i++){
        if(checkboard[i]==n){    //找到出現過的餘數
            //remainder=checkboard[i];
            start=i;
            return 1;
        }
    }
    return 0;
    
}

void findlen(int a,int b){
    
    int remain,i=0;
    int a2,b2;
    
    
    if(a<0) a2=-a;
    else a2=a;
    if(b<0) b2=-b;
    else b2=b;
    
    if(a2%b2==0){
        type=1;
        return ;
    }else {
        remain=a2%b2;
        
        while(!check(remain) && remain!=0){
            checkboard[i]=remain;
            num++;
            remain*=10;
            Dec[i]=remain/b2;
            i++;
            remain=remain%b2;
        }
        if(remain==0) {
            type=2;
            end1=i;
        }
        else{
            end1=i;
            type=3;
        }
        return ;
    }
}

int main() {
    int a,b;
    while(scanf("%d/%d = ?",&a,&b)!=EOF){
        
        findlen(a,b);
        showans(a,b);

        num=0;
       // remainder=0;
        start=0;
        end1=0;
        type=0;
        //memset(Dec,0,100000);
        //memset(checkboard,0,100000);
    }
    return 0;
}

*/
