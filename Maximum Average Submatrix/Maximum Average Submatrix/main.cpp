#include <iostream>
#include <ctype.h>
using namespace std;

int R,C;
int matrix[1001][1001];
/*
double countmatrix(int x,int y,int w,int h){
    int i,j,sum=0;
    double aver;
    if(w==1 && h==1) return -1;
    else{
        for(i=x;i<x+h;i++){
            for(j=y;j<y+w;j++){
                sum+=matrix[i][j];
            }
        }
        aver=sum/(w*h);
        return aver;
    }
}

double helper(int x,int y){
    int w,h;
    double aver=0,maxaver=-1;
    
    for(w=1;w<=C-y;w++){
        for(h=1;h<=R-x;h++){
            aver=countmatrix(x,y,w,h);
        }
    }
            if(maxaver<aver) maxaver=aver;
    return maxaver;
}
double findmaxaver(void){
    int i,j;
    double maxaver=0,aver;
    
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            aver=helper(i,j);
            if(maxaver<aver) maxaver=aver;
        }
    }

    return maxaver;
}
*/
double findmaxaver(void){
    int i,j,max=0;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            if(matrix[i][j]>max) max=matrix[i][j];
        }
    }
    return max;
}
int main() {
    int i,j,K;
    double aver;
    scanf("%d %d %d",&R,&C,&K);
    
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            cin>>matrix[i][j];
        }
    }
    aver=findmaxaver();
    printf("%.*lf\n",K,aver);
    return 0;
}
