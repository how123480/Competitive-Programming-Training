#include <stdio.h>
#include <stdlib.h>
int min=999999;
int temp=0;


void merge1(int x,int n,int *matrix){
    int *newitem=malloc(sizeof(int)*(n-1));
    int i=0;
    if(n<=1){
        if(temp<=min) min=temp;
        return;
    }else if(x>=n-1){
        return ;
    }else {
        temp+=matrix[x]+matrix[x+1];
        for(i=0;i<n-1;i++){
            if(i<x){
                newitem[i]=matrix[i];
            }else if(i==x){
                newitem[i]=matrix[i]+matrix[i+1];
            }else{
                newitem[i]=matrix[i+1];
            }
        }
        merge1(0,n-1,newitem);
        temp-=(matrix[x]+matrix[x+1]);
        merge1(x+1,n,matrix);
        
        free(newitem);
        return;
    }
}

int main()
{
    int i,n;
    int item[152];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&item[i]);
    }
    merge1(0,n,item);
    
    printf("%d\n",min);
    return 0;
}
