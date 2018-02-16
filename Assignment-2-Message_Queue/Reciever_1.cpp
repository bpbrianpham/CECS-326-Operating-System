#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

bool validateInput(string);

int main() 
{
    // Booleans for Menu
	bool keepGoing = true;

	// Variables to use
	string decision;
    string messageFromQueue;
    
    // Using ftok() to generate a queue
	int qid = msgget(ftok(".",'u'), IPC_EXCL|IPC_CREAT|0600);
    cout << "Queue Created, now waiting....." <<endl;

    // declare my message buffer and its size
	struct buf 
	{
		long mtype; // required
		char message[50]; // mesg content
	};
	buf msg;
	int size = sizeof(msg)-sizeof(long);

    while(keepGoing)
    {
        msgrcv(qid, (struct msgbuf *)&msg, size, 117, 0);
        messageFromQueue = msg.message;
        if(messageFromQueue.compare("quit") == 0)
        {
            keepGoing = false;
            cout << "\nQuiting Program....."<<endl;

            // now safe to delete message queue
	        msgctl (qid, IPC_RMID, NULL);
        }
        else
        {
            cout << "Message Received: "<<msg.message<<endl;
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