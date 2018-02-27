#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <time.h>

using namespace std;

bool validateInput(string);

int main()
{
	// Setting the seed for a random generator
    int rand();
    srand (time(NULL));

	// Booleans for Menu
	bool keepGoing = true;

	// Variables to use
	string decision;

    // Grabbing the existing queue from the other program
    int qid = msgget(ftok(".",'u'), 0);
	
    // declare my message buffer and its size
	struct buf 
	{
		long mtype; // required
		string message; // mesg content
	};
	buf msg;
	int size = sizeof(msg)-sizeof(long);

	cout << "Welcome Sender 251"<<endl;

	while(keepGoing)
	{
		cout << "What number would you like to send to Reciever 1? (\"quit\" to quit)\nYour Number: ";
		cin >> decision;
		if(decision.compare("quit") == 0)
		{
			cout << "\nSending quit to queue...\n\tQuiting, GoodBye! :)\n";
			msg.message = decision;
			msg.mtype = 117;
			cout << 
			msgsnd(qid, (struct msgbuf *)&msg, size, 0);
			cout << endl;
			exit(0);
		}
		if(validateInput(decision))
		{
			cout << "\nSending your number.....\n";
			msg.message = decision;
			msg.mtype = 117;
			cout <<
			msgsnd(qid, (struct msgbuf *)&msg, size, 0);
			cout <<endl;
		}
		else
		{
			cout << "Invalid Input!! please send number only!!\n\n";
		}
	} 
    return 0;
}

// -------------- Custom Functions ---------//
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
