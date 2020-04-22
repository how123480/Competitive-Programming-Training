#ifndef EVAL
#include<iostream>
#include<algorithm>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::ios;
int record[1000001];
int Answer(int N,int P,int *H,int *L,int *R,int *V);

int main()
{
    const int maxN = 1000000;
    const int maxP = 1000000;
    int *H = new int[maxN];
    int *L = new int[maxP];
    int *R = new int[maxP];
    int *V = new int[maxP];
    int N,P;
    while( cin>>N>>P )
    {
        for(int i=0;i<N;++i)
            cin>>H[i];
        for(int i=0;i<P;++i)
            cin>>L[i]>>R[i]>>V[i];
        cout<<Answer(N,P,H,L,R,V)<<endl;
    }
}
#endif
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*Write Your Program Here*/
/*Notice: You should include header for yourself*/

int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
    int max,min;
    memset(record,0,sizeof(record));
    for(int i=0;i<P;i++){
        record[L[i]-1]+=V[i];
        record[R[i]]-=V[i];
    }
    //min=max=record[0];
    
    for(int i=1;i<N;i++){
        record[i]+=record[i-1];
        //cout<<record[i]<<endl;
    }
    min=max=record[0]+H[0];
    for(int i=0;i<N;i++){
        record[i]+=H[i];
        //cout<<record[i]<<endl;
        if(min>record[i]) min=record[i];
        if(max<record[i]) max=record[i];
    }
    return max-min;
}
