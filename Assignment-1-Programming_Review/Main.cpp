
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
        cout << "Please select an option:\n\t1. Access a Pointer\n\t2. List Deallocated Memory (index)\n\t3. Deallocate All Memory\n\t4. Exit Program\nYour input: ";
        cin >> decision;
        cout << "\n";
        for (int i = 0; i < decision.length(); i++)
        {
            char c = decision[i];
            if (!isdigit(c))
            {
                keepGoing = false;
                break;
            }
        }
        if (keepGoing)
        {
            int trueDecision = stoi(decision);
            // int arrayInteger [20];
            // char* arrayChar[20];
            // for (int i = 0; i < sizeof(arrayInteger); i++)
            // {
            //     arrayInteger[i] = recursiveFunction(i);
            // }
            switch (trueDecision)
            {
                case 1:
                {

                    break;
                }
                case 2:
                {

                    break;
                }
                case 3:
                {

                    break;
                }
                case 4:
                {
                    cout << "Thank you for using the program. GoodBye! :)" << endl;
                    keepGoing = false;
                    break;
                }
                default: 
                {
                    cout << "Invalid input!!! please choose one of the 4 options!" << endl;
                    break;
                }

            }  
        }
        else
        {
            cout << "Invalid input!!! Input must be a number!" << endl;
            keepGoing = true;
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