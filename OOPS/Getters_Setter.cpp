#include<iostream>
using namespace std;

class player{

    private:
    int health;
    int score;

    public:

    //SETTER FUNCTION

    void setScore(int s){
        cout<<"Score is modified"<<endl;
        score=s;
    }

    void setHealth(int h){
        cout<<"Health is modified"<<endl;
        health=h;
    }

    //GETTER FUNCTION

    int getScore(){
        return score;
    }

    int getHealth(){
        return health;
    }

};

int main (){

    player A;
    A.setScore(181);
    A.setHealth(60);


    
    cout<<A.getHealth()<<" "<<A.getScore()<<endl;


}