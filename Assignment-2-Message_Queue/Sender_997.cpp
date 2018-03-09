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

	cout << "Welcome Sender 997"<<endl;

	messageContent = rand() % 100000;
	while(messageContent > 100)
	{

		cout << "Sending to Reciever 1: " << messageContent;
		msg.message = messageContent;
		msg.mtype = 117;
		cout << 
			msgsnd(qid, (struct msgbuf *)&msg, size, 0);
			cout << endl;

		cout << "Sending to Reciever 2: " << messageContent;
		msg.message = messageContent;
		msg.mtype = 118;
		cout << 
			msgsnd(qid, (struct msgbuf *)&msg, size, 0);
			cout << endl;
		

		cout << "\nWaiting For Reciever 1 to recieve . . . " << endl;
		msgrcv(qid, (struct msgbuf *)&msg, size, 1, 0);
		cout << "Message Recieved." << endl;
		cout << "\nWaiting For Reciever 2 to recieve . . . " << endl;
		msgrcv(qid, (struct msgbuf *)&msg, size, 1, 0);
		cout << "Message Recieved." << endl;
		
		messageContent = rand() % 100000;
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
