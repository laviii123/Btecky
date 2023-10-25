
// Bubble Sort algorithm
// See the readme

#include <iostream>

using namespace std;

int main()
{
    int n,x,y;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    // Loop for repeating step 1 and step 2 (n-1) times
    for (int i=0;i<(n-1);i++){
        // This loop comprises of step 1 and step2
        for (int j=0;j<(n-1);j++){
            // Step 1
            x = arr[j];
            y = arr[j+1];
            // Step 2
            if (x>y){
                arr[j+1]=x;
                arr[j]=y;
            }
        }
    }
    // Loop for printing the elements of the array with spaces in between
    for (int i=0;i<(n-1);i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[n-1];
    return 0;
}
