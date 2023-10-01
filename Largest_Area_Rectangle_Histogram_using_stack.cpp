#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int arr[7]={6,2,5,4,5,1,6};
    int pse[7];
    stack<int>st;
    st.push(0);//Doing it from Left To Right,since it'll be easier that way!!!!!
    pse[0]=-1;
    for(int i=1;i<7;i++){
        while(st.empty()!=true && arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()==true){
            pse[i]=-1;
        }
        else{
            pse[i]=st.top();
        }
        st.push(i);
    }
    // for(int val:pse){
    //     cout<<val;
    // }
    // cout<<endl;
    int nse[7];
    stack<int>st1;
    st1.push(6);//Doing it from right to left,since it'll will be easier!!!!!(Can be done using indexing too.)
    nse[6]=7;//array's length.
    for(int i=5;i>=0;i--){
        while(st1.empty()!=true && arr[i]<=arr[st1.top()]){
            st1.pop();
        }
        if(st1.empty()==true){
            nse[i]=7;//which is your array's length.
        }
        else{
            nse[i]=st1.top();
        }
        st1.push(i);
    }
    // for(int val:nse){
    //     cout<<val;
    // }
    // cout<<endl;
    int max=0;
    for(int i=0;i<7;i++){
        int width=nse[i]-pse[i]-1;
        int area=arr[i]*width;
        if(area>max){
            max=area;
        }
    }
    cout<<max;
return 0;
}
