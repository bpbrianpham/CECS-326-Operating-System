
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int recursiveFunction(int);
bool validateInput(string);

int main()
{
    // Initial Setup of the Program
    int arraySize = 20;
    bool menuStatus = true;
    bool subMenuStatus;
    bool pointerAccessMenu;
    string decision;
    int arrayInteger[arraySize];
    char* ptrChar[arraySize];
    int rand();
    srand (time(NULL));
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Welcome to the Array Structure Program!" << endl;

    // Initializing all the memory and assigning Characters to ptrChar based off arrayInteger's size
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
                                    pointerAccessMenu = true;
                                    while (pointerAccessMenu)
                                    {
                                        cout << "What would you like to do with pointer " << decisionValue << "?\n\t1. Print the first 10 Char\n\t2. Delete all the Char in pointer and return to Main Menu\n\t3. Return to Main Menu\nYour Input: ";
                                        cin >> decision;
                                        cout << "\n";
                                        if (validateInput(decision))
                                        {
                                            switch (stoi(decision))
                                            {
                                                case 1:
                                                {
                                                    cout << "First 10 Chars at Pointer " << decisionValue << " are: '";
                                                    for (int k=0; k < 10; k++)
                                                    {
                                                        cout << ptrChar[decisionValue-1][k];
                                                    }
                                                    cout <<"'\n\n";
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    cout << "Deleting all Char at Pointer "<<decisionValue<<"\nReturning to Main Menu\n"<<endl;
                                                    ptrChar[decisionValue-1] = NULL;
                                                    pointerAccessMenu = false;
                                                    subMenuStatus = false;
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    cout << "\n";
                                                    pointerAccessMenu = false;
                                                    subMenuStatus = false;
                                                    break;
                                                }
                                                default:
                                                {
                                                    cout << "Invalid Input!!! Please enter 1 - 3"<<endl;
                                                    break;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cout << "Invalid Input!! Please select a number, no other characters allow!"<<endl;
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "The pointer at index " << decisionValue << " contains: NULL Char" <<endl;
                                    cout << "Reinitializing the Char now....\n" << endl;
                                    ptrChar[decisionValue-1] = new char[arrayInteger[decisionValue-1]];
                                    for (int j = 0; j < arrayInteger[decisionValue-1]; j++)
                                    {
                                        ptrChar[decisionValue-1][j] = alphabet[rand()%26];
                                    }
                                }
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
                        if (ptrChar[i] == NULL)
                        {
                            cout << "\n\t" << i+1 <<". NULL";
                        }
                        else
                        {
                            cout << "\n\t" << i+1 << ". " << &ptrChar[i];
                        }
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
                    for (int i = 0; i < (sizeof(arrayInteger)/sizeof(arrayInteger[0])); ++i)
                    {
                        delete ptrChar[i];
                    }
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
        return 2700;
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