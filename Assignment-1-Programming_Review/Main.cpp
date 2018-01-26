
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;


int main()
{
    bool keepGoing = true;
    string decision;
    cout << "Welcome to the Array Structure Program!" << endl;
    while (keepGoing)
    {
        cout << "Please select an option:\t1. Access a Pointer\n\t2. List Deallocated Memory (index)\n\t3. Deallocate All Memory\n\t4. Exit Program"<<endl;
        cin >> decision;
        for (int i = 0; i < decision.length(); i++)
        {
            char c = decision[i];
            if (!c.isdigit())
            {
                keepGoing = false;
            }
        }
        if (keepGoing)
        {
            cout << "success" << endl;   
        }
        else
        {
            cout << "fail" << endl;
        }
    }


}