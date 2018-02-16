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

int main()
{
	// Setting the seed for a random generator
    int rand();
    srand (time(NULL));

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

	// prepare my message to send
	msg.message = "Hello There!!";
	cout << getpid() << ": sends message" << endl;
	msg.mtype = 117; 	// set message type mtype = 117
	msgsnd(qid, (struct msgbuf *)&msg, size, 0); // sending

	msgrcv(qid, (struct msgbuf *)&msg, size, 314, 0); // reading
	cout << getpid() << ": gets reply" << endl;
	cout << "reply: " << msg.message << endl;
	cout << getpid() << ": now exits" << endl;

	msg.mtype = 117;
	msgsnd (qid, (struct msgbuf *)&msg, size, 0);
    return 0;
}