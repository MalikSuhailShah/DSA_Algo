#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Cricketer{
    private:
    int age;
    int NoOfTestMatches;
    string name;
    int average;

    public:

    void setAge(int age){
        this->age=age;
    }

    void setName(string name){
        this->name=name;
    }

    void setNoOfTestMatches( int matches){
        NoOfTestMatches=matches;
    }

    void setAverage(int average){
        this->average=average;
    }

    int getAge(){
        return age;
    }

    int getNoOfTestMatches(){
        return NoOfTestMatches;
    }

    int getAverage(){
         return average ;
    }

    string getName(){
        return name;
    }
};



int main (){

    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;

    Cricketer arr[n];

    for(int i=0;i<n;i++){
        Cricketer* cricketer=new Cricketer;

        string str;
        cin>>str;
    
        int age,average,matches;
        cin>>age>>average>>matches;


        cricketer->setAge(age);
        cricketer->setAverage(average);
        cricketer->setName(str);
        cricketer->setNoOfTestMatches(matches);

       arr[i]=(*cricketer);
    }



    cout<<"\n\n\n\n\n\n\n";
    for(int i=0;i<n;i++){
       cout<< arr[i].getName()<<endl;
       cout<< arr[i].getAge()<<endl;
       cout<< arr[i].getAverage()<<endl;
       cout<< arr[i].getNoOfTestMatches()<<endl;
    }

}