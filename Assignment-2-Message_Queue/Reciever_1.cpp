#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

int main() 
{

    // Using ftok() to generate a queue
	int qid = msgget(ftok(".",'u'), IPC_EXCL|IPC_CREAT|0600);

    // declare my message buffer and its size
	struct buf 
	{
		long mtype; // required
		string message; // mesg content
	};
	buf msg;
	int size = sizeof(msg)-sizeof(long);

    // Reading send messages
    msgrcv(qid, (struct msgbuf *)&msg, size, 117, 0);
    cout << getpid() << ": gets message" << endl;
    cout << "message: " << msg.message << endl;

    msg.message = " and adios";

    cout << getpid() <<": Send to the nearest queu";
    msg.mtype = 314; // only reading mesg with type mtype = 314
	msgsnd(qid, (struct msgbuf *)&msg, size, 0);
	cout << getpid() << ": now exits" << endl;

    msgrcv (qid, (struct msgbuf *)&msg, size, -112, 0);
	msgrcv (qid, (struct msgbuf *)&msg, size, 0, 0);
	msgrcv (qid, (struct msgbuf *)&msg, size, 117, 0);

    // Deleting the Message Queue	
    msgctl (qid, IPC_RMID, NULL);

    return 0;
}