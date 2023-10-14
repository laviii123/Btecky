#include<iostream>
#include<conio.h>

using namespace std;

class A {
    int a;
    public:
    void memberfn(int x)
    {
        a = x;
        cout << "Member Function Inside"
             << "Class Declared \n"; 
    }
    void memberfn2();
};

void A::memberfn2()
{
    cout << "Member Function Declared\n"
         << "Outside the class";
}

void nonmemberfn()
{
    cout << "Non Member Function \n";
}

int main(){
    A obj;

    obj.memberfn(5);
    obj.memberfn2();

    nonmemberfn();
    getch();
    return 0;
}