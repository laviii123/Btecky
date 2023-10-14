// Program to show the use of classes in C++

#include<iostream>
#include<conio.h>

using namespace std;

class Room
{
    public:
    double lenght;
    double breadth;
    double height;
    double calculateArea()
{
    return lenght * breadth;
}
double calculateVolume()
{
    return lenght * breadth * height;
}
};
int main(){
    Room room1;
    room1.lenght=42.5;
    room1.breadth=30.8;
    room1.height=19.2;
    cout<<"Area of the room is : "<<room1.calculateArea()<<endl;
    cout<<"Volume of the room is :  "<<room1.calculateVolume()<<endl;
    getch();
    return 0;
}



