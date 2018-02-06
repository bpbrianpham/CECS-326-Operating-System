
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

int recursiveFunction(int);
bool validateInput(string);

int main()
{
    // Initial Setup of the Program
    int arraySize = 3;
    bool menuStatus = true;
    bool subMenuStatus;
    string decision;
    int arrayInteger [arraySize];
    char* ptrChar[arraySize];
    int rand();
    srand (time(NULL));
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Welcome to the Array Structure Program!" << endl;

    for (int i = 0; i < arraySize; i++)
    {
        arrayInteger[i] = recursiveFunction(i);
        ptrChar[i] = new char[arrayInteger[i]];
        for (int j = 0; j < arrayInteger[i]; j++)
        {
            ptrChar[i][j] = alphabet[rand()%26];
        }
    }
    

    while (menuStatus)
    {
        cout << "Please select an option:\n\t1. Access a Pointer\n\t2. List Deallocated Memory (index)\n\t3. Deallocate All Memory\n\t4. Exit Program\nYour input: ";
        cin >> decision;
        cout << "\n";
        subMenuStatus = validateInput(decision);
        if (subMenuStatus)
        {
            int decisionValue = stoi(decision);
            switch (decisionValue)
            {
                case 1:
                {
                    while (subMenuStatus)
                    {
                        cout << "Which pointers to access?\n\t1\t2\t3\t4\t5\n\t6\t7\t8\t9\t10\n\t11\t12\t13\t14\t15\n\t16\t17\t18\t19\t20\nYour Input: ";
                        cin >> decision;
                        cout << "\n";
                        if (validateInput(decision))
                        {
                            decisionValue = stoi(decision);
                            if (decisionValue > 0 && decisionValue < 21)
                            {
                                if (ptrChar[decisionValue-1] != NULL)
                                {
                                    cout << "The pointer at index " << decisionValue << " contains: ";
                                    for (int k=0; k < arrayInteger[decisionValue-1]; k++)
                                    {
                                        cout << ptrChar[decisionValue-1][k];
                                    }
                                    cout <<"\n";
                                }
                                else
                                {
                                    cout << "The pointer at index " << decisionValue << " contains: NULL" <<endl;
                                }
                                subMenuStatus = false;
                                cout <<"\n";
                            }
                            else
                            {
                                cout << "Invalid Input!!! Input must be a valid pointer number."<<endl;
                            }
                        }
                        else
                        {
                            cout << "Invalid Input!!! Input must contain all number values."<<endl;
                        }
                    }
                    break;
                }
                case 2:
                {
                    cout << "Deallocated Memory:";
                    for (int i=0; i < arraySize; i++)
                    {
                        cout << "\n\t" << i+1 << ". " << &ptrChar[i];
                    }
                    cout << "\n\n";
                    break;
                }
                case 3:
                {
                    cout << "Deallocating All Memory......\n" << endl;
                    for (int i=0; i < arraySize; i++)
                    {
                        ptrChar[i] = NULL; 
                    }
                    break;
                }
                case 4:
                {
                    cout << "Thank you for using the program. GoodBye! :)" << endl;
                    // for (int i = 0; i < (sizeof(arrayInteger)/sizeof(arrayInteger[0])); ++i)
                    // {
                    //     delete ptrChar[i];
                    // }
                    delete[] ptrChar;
                    menuStatus = false;
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
            menuStatus = true;
        }
    }
}

/*--------------------------------------------*/
// Given recursive function
int recursiveFunction(int i)
{
    if (i == 0)
    {
        return 2;
    }
    else
    {
        return recursiveFunction(i-1) * 2;
    }
}

// Decision validation function
bool validateInput(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}