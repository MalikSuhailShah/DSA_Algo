#include <iostream>
using namespace std;

class Gun
{
public:
    string name;
    int ammo;
    int damage;
    int scope;
};

class Player
{
private:
    class Helmet
    {
    private:
        int hp;
        int level;

    public:
        void setLevel(int level)
        {
            this->level = level;
        }

        void setHp(int hp)
        {
            this->hp = hp;
        }

        int getHp()
        {
            return hp;
        }

        int getLevel()
        {
            return level;
        }
    };

    int health;
    int age;
    int score;
    bool alive;
    Gun gun;
    Helmet helmet;

public:
    void getGun()
    {
        cout << gun.name << "=>" << gun.ammo << " " << gun.damage << " " << gun.scope << endl;
    }

    int getHealth()
    {
        return health;
    }

    int getScore()
    {
        return score;
    }

    int getAge()
    {
        return age;
    }

    bool isAlive()
    {
        return alive;
    }

    void setHealth(int health)
    {
        this->health = health;
    }

    void setScore(int score)
    {
        this->score = score;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setAlive(bool alive)
    {
        this->alive = alive;
    }

    void setHelmet(int level)
    {
        // create a dynamic object and set in into the attributes of player class
        Helmet *helmet1 = new Helmet;
        helmet1->setLevel(level);
        int hp = 0;
        if (level == 1)
            hp = 25;
        else if (level == 2)
            hp = 50;
        else if (level == 3)
            hp = 100;
        else
            cout << "error, invalid level!!";

        helmet1->setHp(hp);
        this->helmet = *helmet1;
    }

    void getHelmet()
    {
        cout << helmet.getHp() << endl;
        cout << helmet.getLevel() << endl;
    }
};

int main()
{

    Gun akm;
    akm.name = "akm";
    akm.ammo = 100;
    akm.scope = 2;
    akm.damage = 50;

    Gun awm;
    awm.name = "awm";
    awm.ammo = 15;
    awm.damage = 150;
    awm.scope = 8;

    Player A, B;

    A.setAge(25);
    A.setAlive(true);
    A.setHealth(60);
    A.setScore(100);
    A.setHelmet(3);

    B.setAge(30);
    B.setAlive(true);
    B.setHealth(70);
    B.setHelmet(2);
    B.setScore(150);

    cout << B.getAge() << " " << B.getScore() << " " << B.getHealth() << " " << B.isAlive();
    B.getHelmet();
    B.getGun();
    cout << A.getAge() << " " << A.getScore() << " " << A.getHealth() << " " << A.isAlive();
    A.getHelmet();
    A.getGun();
}