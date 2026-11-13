#include<iostream>
using namespace std;


void print(){
    //Every time function is called new variable 'b' is created and after successfull execution it destroys
    int b=10;
    cout<<b<<endl;
    b++;
}


void print2()
{
    //no matters how many time function is called memory is fixed for 
    //variable "b" and it created one time and never destroys till complete execution of program
  static int b=10;

  cout<<b<<endl;
  b++;

}
int main (){

print();
print();
print();

cout<<endl;
print2();
print2();
print2();

}