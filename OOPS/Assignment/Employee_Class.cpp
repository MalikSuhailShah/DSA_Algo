#include <Iostream>
using namespace std;

class employee
{
private:
    int ID;
    int salary;
    string name;

public:
    // constructor

    employee(int ID, string name, int salary)
    {
        this->name = name;
        this->ID = ID;
        this->salary = salary;
    }

    void Display()
    {
        cout << ID << " " << name << " " << salary << endl;
    }

    int Average(employee a[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i].salary;
        }

        return sum / n;
    }

    void maxSalary(employee arr[], int n)
    {
        int idx = -1;

        int max = arr[0].salary;

        for (int i = 0; i < n; i++)
        {
            if (max < arr[i].salary)
            {
                max = arr[i].salary;
                idx = i;
            }
        }

        cout << "highest salary employee name " << arr[idx].name << " salary ->" << arr[idx].salary << endl;
    }
};

int main()
{

    employee arr[5] = {{123, "rajesh", 25000}, 
                       {124, "rakesh", 35000}, 
                       {125, "Sudesh", 50000},
                        {126, "Ritesh", 100000}, 
                        {127, "Sandseh", 125740}};

            arr[0].maxSalary(arr,5);

            cout<<"The average salary of all employees:"<<arr[0].Average(arr,5)<<endl;

            arr[0].Display();
}