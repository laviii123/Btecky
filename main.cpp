#include <iostream>
using namespace std;
class bank{
    int principle;
    int years;
    float interestrate;
    float returnvalue;
     
public:
    bank(){}
    bank(int p , int y, float r);
    void show();
};
 bank::bank(int p ,int y ,float r)
{
    principle=p;
    years=y;
    interestrate=r;
    returnvalue=principle;
     for (int i = 0; i<y;i++)
     {
         returnvalue =returnvalue * (1+r);
     }
    
 }
void bank::show(){
    cout<<endl<<"Principle Amount was"<<endl
    << ". Return Value after "<<years
    << " is "<< returnvalue<<endl;
    
}
int main(){
    bank bd1 ,bd2,bd3;
    int p ,y;
    float r;
    
    cout<<"Enter the value of p , y ,r"<<endl;
    cin>>p>>y>>r;
    bd1= bank(p,y,r);
    bd1.show();
    cout<<"Enter the value of p , y ,r"<<endl;
    cin>>p>>y>>r;
    bd2=bank(p,y,r);
    bd2.show();
    cout<<"Enter the value of p , y ,r"<<endl;
    cin>>p>>y>>r;
    bd3=bank(p,y,r);
    bd3.show();
    return 0;
}

