#if !defined _CLNT
#define _CLNT

#define MAX_MESSAGE_LEN 256
#define MAX_RECEIVED_LEN 1024

//#define CLIENT_TO_SERVER_FIFO "/tmp/client_to_server_fifo"
//#define SERVER_TO_CLIENT_FIFO "/tmp/server_to_client_fifo"

struct message
{
    int client_pid;
    char sending_message_data[MAX_MESSAGE_LEN];
    char receiving_message_data[MAX_RECEIVED_LEN];
};

void fifo_verify_stc(int descr);
void fifo_verify_cts(int descr);
#endif