
#include<iostream>
using namespace std;

int recursiveFunction(int);

int main()
{
    bool keepGoing = true;
    string decision;
    cout << "Welcome to the Array Structure Program!" << endl;
    while (keepGoing)
    {
        cout << "Please select an option:\n\t1. Access a Pointer\n\t2. List Deallocated Memory (index)\n\t3. Deallocate All Memory\n\t4. Exit Program"<<endl;
        cin >> decision;
        for (int i = 0; i < decision.length(); i++)
        {
            char c = decision[i];
            if (!isdigit(c))
            {
                keepGoing = false;
            }
        }
        if (keepGoing)
        {
            int arrayInteger [20];
            char* arrayChar[20];
            for (int i = 0; i < sizeof(arrayInteger); i++)
            {
                arrayInteger[i] = recursiveFunction(i);
            }
               
        }
        else
        {
            cout << "fail" << endl;
        }
    }
}

/*--------------------------------------------*/
// Given recursive function
int recursiveFunction(int i)
{
    if (i == 0)
    {
        return 2700;
    }
    else
    {
        return recursiveFunction(i-1) * 2;
    }
}