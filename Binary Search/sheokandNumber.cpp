#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define all(x)  (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define endl "\n"
#define fr(i,b) for(int i=0; i<b; i++)
#define fastio  cin.tie(0), cout.tie(0),ios_base::sync_with_stdio(false);
#define input(v,n) for(int i=0; i<n; i++){cin>>v[i];}

map<int,int>m;
int lcm(int a, int b){
    return (a / __gcd(a, b)) * b;
}
bool is_prime(int x){
    for(int i = 2; i*i <= x ;i++)
        if(x%i == 0)
            return 0;
    return 1;
}

void solve(){
    int n;
    cin>>n;
    
    int ans=INT_MAX;
    int x=0;
    for(auto i: m){
        x=abs(i.first-n);
        ans=min(ans, x);
    }
    cout<<ans<<endl;
        
}

int main() {
    
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            if(i!=j){
                m[pow(2,i)+pow(2,j)]++;
            }
        }
    }
    fastio;
    int t;
    cin>>t;
    while(t--){
        
        solve();
        
    }
}








