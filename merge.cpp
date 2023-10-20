#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int h,int mid){
  int i=l, j=mid +1, k=l , b[h+1];
  while(i<=mid && j <=h){
    if(a[i]< a[j]) b[k++] = a[i++];
    else b[k++] = a[j++];
  }
  while(i<=mid) b[k++] = a[i++];
  while(j<=h) b[k++] = a[j++];
  for(i = l ; i<=h; i++) a[i] = b[i];
  }

void mergesort(int a[],int l,int h){
  int mid;
  if(l<h){
    mid = (l+h)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,h);
    merge(a,l,h,mid);
  }
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0; i<n;i++) cin >> a[i];
  mergesort( a , 0 , n);
  for(int i=0; i<n; i++){
    cout << a[i] << " " ;
  }
  cout << endl;
}
