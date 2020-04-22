//
//  main.cpp
//  看著數列的卦長
//
//  Created by HowardHoward on 07/03/2017.
//  Copyright © 2017 HowardHoward. All rights reserved.
//

#include <iostream>
int input[10000000];
int c[10000000];
int num;
using namespace std;

void merge(int* ,int ,int ,int);

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

void merge(int *a, int low, int high, int mid)
{
    int i, j, k,len=mid-low+1;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            len--;
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            num+=len;
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
int main(){
    
    int n,i,turn=1;
    
    while(cin>>n){
        if(n<0)
            break;
        for(i=0;i<n;i++)
            cin>>input[i];
        mergesort(input,0,n-1);
        cout<<"Case #"<<turn<<": "<<num<<endl;
        num=0;
        turn++;
    }
    
    
}
/*
int main() {
    int n,i,j,turn=1;
    
    while(cin>>n){
        if(n<0)
            break;
        
        int count=0;
        
        for(i=0;i<n;i++){
            cin>>input[i];
        }
        
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(input[i]>=input[j])
                    count++;
            }
        }
        
        cout<<"Case"<<" #"<<turn<<": "<<count<<endl;
        turn++;
    }
}
*/
