#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 200100
#define inf 100000000
#define pp pair<int,int>

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d ",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int,int>

using namespace std;

bool cmp(pp a,pp b)
{
    return abs(a.first-a.second)>(b.first-b.second);
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i,j,k;
    int n,m;
    int x,y;

    sff(n,m);

    pp a[n];
    ll sum=0;

    for(i=0;i<n;i++)
    {
        sff(x,y);
        a[i]={x,y};
        sum+=(ll)x;
    }

    sort(a,a+n,cmp);

    int ans=0;
    for(i=0;i<n;i++)
    {
        if(sum<=m)
            break;

        sum-=(ll)a[i].first;
        sum+=(ll)a[i].second;
        ans++;
    }

    if(sum>m)
        pf(-1);
    else
        pf(ans);

    return 0;
}
