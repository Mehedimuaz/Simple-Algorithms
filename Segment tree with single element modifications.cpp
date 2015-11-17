#include<bits/stdc++.h>
using namespace std;
#define N 1000

int ar[2*N];
int n,m,q;

void build()
{
    for(int i=n-1;i>=1;i--) ar[i]=ar[i<<1]+ar[i<<1|1]; //ar[i]=ar[i*2]+ar[i*2+1];
}

void modify(int p,int val)
{
    for(ar[p+=n]=val;p>1;p>>=1) ar[p>>1]=ar[p]+ar[p^1];
}

int query(int l,int r)
{
    int sum=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) sum+=ar[l++];
        if(r&1) sum+=ar[--r];
    }
    return sum;
}

int main()
{
    int a,b;
    scanf("%d %d %d",&n,&m,&q); // n is the length of array, m is number of modifications, q is number of queries for sum at any interval
    for(int i=0;i<n;i++){
        scanf("%d",ar+n+i);
    }
    ar[n+n]=0;
    build();
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        modify(a-1,b); // ath element is stored in ar[n+a-1]
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",query(a-1,b));
    }
    return 0;
}
