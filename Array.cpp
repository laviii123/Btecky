//To get data from user and Display it as array.
#include<iostream>
#include<conio.h>
using namespace std;

class employee{
    int id;
    char name[30];

    public:
    void getdata();     //Funtion Declaration
    void putdata();
};

void employee::getdata(){       // Function Definition 
    cout <<"Enter ID:";
    cin  >> id;
    cout << "Enter the name:";
    cin  >> name ;
}

void employee::putdata(){
    cout << id << "";
    cout << name << "";
    cout << endl;
}

int main(){
    employee emp [30];
    int n , i;
    cout << "Enter the number of employee";
    cin >> n;

    for(i=0; i<n ; i++)
    emp[i].getdata();
    cout << "Employee data" << endl;

    for(i=0; i<n ; i++)
    emp[i].putdata();
    getch();
}

