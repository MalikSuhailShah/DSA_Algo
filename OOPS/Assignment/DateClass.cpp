#include<iostream>
using namespace std;

class Date{

    private:
    int date;
    int month;
    int year;

    public:

    //getters::

    void getDate(){
        cout<<this->date<<endl;
    }

     void getMonth(){
        cout<<this->month<<endl;
    }


     void getYear(){
        cout<<this->year<<endl;
    }

    //Constructor

    Date (int date,int month,int year){
        this->date=date;
        
        this->month=month;
        this->year=year;
    }


    //Member Function

    void CheckDates(Date d){
        if(this->date==d.date && this->month==d.month && this->year==d.year){
                cout<<"EQUAL DATES!!"<<endl;
        }

        else cout<<"UNEQUAL DATES!!"<<endl;
    }
};

int main (){

    Date one(15,9,2025);
    Date Two(15,10,2025);

    Two.CheckDates(one);


}