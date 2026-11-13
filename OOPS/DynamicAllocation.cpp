#include <iostream>
using namespace std;

class player
{
private:
    int score;
    int health;

public:
    void setScore(int score)
    {
        this->score = score;
    }

    void setHealth(int health)
    {
        this->health = health;
    }

    int getHealth()
    {
        return health;
    }

    int getScore()
    {
        return score;
    }
};

int main()
{

    // static allocation

    player harsh;
    player malik;

    harsh.setScore(90);
    malik.setScore(80);

    harsh.setHealth(70);
    malik.setHealth(60);

    // dynamic allocation

    player *urvi = new player;

    // player urviObject=*urvi;=> creating new player  that points to the address stored in pointer urvi

    // (*urvi).setHealth(90);
    // (*urvi).setScore(90);

    urvi->setHealth(90);
    urvi->setScore(80);

  
    cout<<urvi->getHealth()<<endl;
    cout<<urvi->getScore()<<endl;

}
