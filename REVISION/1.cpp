#include<bits/stdc++.h>
using namespace std;


class player{
    int score;
    int health;
    
    public:
    
    void setScore(int v){
        this->score=v;
    }

    void setHealth(int val){
        this->health= val;
    }

    int getHealth(){
        return this->health;
    }

    int getScore(){
        return this->score;
    }
};

int main (){
    player A;
   A.setHealth(90);
  A.setScore(110);
=41
}