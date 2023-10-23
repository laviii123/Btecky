#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long P[100010] = {0};

long long sum( int a, int b )
{
    return P[b+1] - P[a] ;
}

bool ok( int p , long long m , int k )
{
    int st = p-m+1;
    int en = p ;
    long long s = sum( st , en );
    long long cap = m*k ;
    long long need = cap-s ;
    
    int L = p+1 ;
    int have = L-m ;
    
    return need <= have ;
}

int go( int p , int k )
{
    long long l = 0 ;
    long long h = p ;

    while( l < h )
    {
        long long m = (l+h)>>1 ;
        if(ok( p , m , k ))
        l = m+1 ;
        else
        h = m-1;
    }
    
    // clean up for one off solution 
    
    for( int m = h+1 ; m >= h-1 ; m-- )
    {
        if( ok(p,m,k) )
        return m ;
    }
    return h ;
}

int solve(vector<int>&A , int k ){

     int N = A.size();
     int pth = lower_bound( A.begin() , A.end() , k ) - A.begin() ;

     return N-pth + go( pth-1 , k );
}

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test ;
	cin>>test;
	while(test--)
	{
	    int N , Q ;
	    cin>>N>>Q;
	    vector<int>A(N);
	    for( auto &x: A )
	    cin>>x ;
	    sort( A.begin() , A.end() );
	    
	    P[0] = 0 ;
	    for( int i = 0 ; i < N ; i++ )
	    P[i+1] = P[i] + A[i] ;
	    
	    for( int i = 0 ; i < Q ; i++ )
	    {
	        int k ;
	        cin>>k ;
	        cout<<solve( A , k )<<endl;
	    }
	}
	
	return 0;
}
