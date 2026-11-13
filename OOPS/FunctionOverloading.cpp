#include<iostream>
using namespace std;

int calculateArea(int side){
    return side*side;
}

double calculateArea(double radius){
   return 3.14*radius*radius;
}

int main (){


   cout<<calculateArea(5.0)<<endl; //different function called  automatically depending upon parameter passed
    cout<< calculateArea(7)<<endl;

}