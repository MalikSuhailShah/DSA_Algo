#include <iostream>
using namespace std;

class bikes
{

public:
    static int noOfBikes;
    int tyreSize;
    int engineSize;

    void increaseBikes()
    {
        noOfBikes++;
    }
};
int bikes::noOfBikes=10;
int main()
{

    bikes tvs;
    tvs.tyreSize = 10;
    tvs.engineSize = 150;

    cout<<tvs.noOfBikes<<endl;
    tvs.increaseBikes();

    bikes honda;
    honda.tyreSize = 10;
    honda.engineSize = 150;

    
   

     cout<<tvs.noOfBikes<<" "<<honda.noOfBikes<<endl;
}