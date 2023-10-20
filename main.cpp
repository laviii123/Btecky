#include <iostream>

using namespace std;
class pointer{
    int first;
    int second;
public:
    pointer(){}
    pointer(int a , int b);
    void displaypoint();
    
    
};


pointer ::pointer(int a , int b)
{
    first = a;
    second = b;
}
void pointer ::displaypoint()
{
    cout<<"The Point Is ("<<first<<","<<second<<")"<<endl;
}
int main(){
    pointer pw,pl;
    int a ,b;
    cout<<"Enter the pointer ";
    cin>>a>>b;
    pw=pointer(a,b);
    pw.displaypoint();
    cout<<"Enter the pointer ";
    cin>>a>>b;
    pl = pointer(a,b);
    pl.displaypoint();
    
    return 0;
}
