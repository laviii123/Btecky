#include <iostream>
#include<math.h>
using namespace std;
class rational{
    public:
    int num,den;
     rational(int num,int den){
     this->num=num;
     this->den=den;
    }
friend rational operator +(rational p1,rational p2);
friend ostream & operator <<(ostream &os,rational &p);
};
ostream & operator <<(ostream &os,rational &p){
    int num,den;
    os<<p.num<<"/"<<p.den;
    return os;
}

rational operator +(rational p1, rational p2){
    rational temp(0,0);
    temp.num= p1.num * p2.den + p2.num * p1.den;
    temp.den=p1.den*p2.den;
    return temp;
}
int main()
{
    rational p1(0,0),p2(0,0),p3(0,0);
    cin>>p1.num>>p1.den;
    cin>>p2.num>>p2.den;
    p3=p1+p2;
    cout<<"sum of "<<p1<< " and "<<p2<<" is "<<p3<<endl;
    return 0;
}
