#include <iostream>
using namespace std;

class Book
{
public:
    string name;
    int price;
    int noOfPages;

    
    int countBooks(int p)
    {

        int count = 0;

        if (price <= p)
            count++;
        return count;
    }
   
    bool isBookPresent(string title)
    {

        return (title == name);
    }
};

int main()
{

    Book harry_poter;

    harry_poter.name = "Harry Poter 1";
    harry_poter.price = 1080;

    harry_poter.noOfPages = 500;

    string str = "Happy Ending";

    cout <<harry_poter.countBooks(1080) << endl;
    cout<<harry_poter.isBookPresent(str);
}