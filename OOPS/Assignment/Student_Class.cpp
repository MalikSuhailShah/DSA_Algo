#include <iostream>
#include <string>
using namespace std;

class student
{

private:
    int rno;
    int YearOfJoining;
    string name;
    string course;

public:
    // Constructor

    student(int rno, int YearOfJoining, string name, string course)
    {
        this->rno = rno;
        this->course = course;
        this->name = name;
        this->YearOfJoining = YearOfJoining;
    }

    // Getters

    void getAttributes()
    {
        cout << rno << " " << YearOfJoining << " " << name << " " << course << endl;
    }

    // Member Function

    void CheckCourse(student s)
    {
        if (this->course == s.course)
        {
            cout << "Students belongs to the same course!!" << endl;
        }
        else
            cout << "both Students do not belongs to the same course!!" << endl;
    }
};

int main()
{

    student a(39, 2023, "Suhail", "CSEAI");
    student b(49, 2023, "Roshan", "CSER");

    b.CheckCourse(a);
}