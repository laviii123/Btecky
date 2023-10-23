#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 110
#define inf 1e9

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int, int>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, d;

    sff(n, m), sf(d);

    pp a[n];
    for(i = 0; i < n; i++)
        sf(a[i].first), a[i].second = i;

    sort(a, a + n);

    int ans[n];
    memset(ans, 0, sizeof(ans));

    k = 1;
    for(i = 0; i < n; i++)
    {
        if(!ans[a[i].second])
        {
            ans[a[i].second] = k;
            j = upper_bound(a, a + n, make_pair(d + a[i].first + 1, -1)) - a;
            while(j < n && ans[a[j].second])
                j++;

            if(j < n)
                ans[a[j].second] = k;

            k++;
        }

        else
        {
            j = upper_bound(a, a + n, make_pair(d + a[i].first + 1, -1)) - a;
            while(j < n && ans[a[j].second])
                j++;

            if(j < n)
                ans[a[j].second] = ans[a[i].second];
        }
    }

    pf(k - 1); nl;
    for(i = 0; i < n; i++)
        pf(ans[i]), pfs(" ");

    return 0;
}
