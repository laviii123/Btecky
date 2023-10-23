#define _CRT_SECURE_NO_WARNINGS

#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 101010
#define inf 1e18

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
#define pp pair<int,int>

using namespace std;

int len, cnt;
string s;

bool solve(int seg)
{
	if (cnt%seg != 0) return false;

	int x = 0, y = cnt / seg;
	for (int i = 0; i < len; i++)
	{
		x += (s[i] - 48);

		if (x == y)
			x = 0;

		if (x > y) return false;
	}

	return true;
}

int main()
{
	freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;

	sf(len);
	cin >> s;

	cnt = 0;
	for (i = 0; i < len; i++)
		cnt += (s[i] - 48);

	for (i = 2; i <= len; i++)
	{
		if (solve(i)) {
			//pf(i); nl;
			pfs("YES\n");
			return 0;
		}
	}

	pfs("NO\n");

	return 0;
}
