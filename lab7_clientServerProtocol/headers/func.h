#if !defined _FUNCS
#define _FUNCS
int Exists(char pathAndName[]);
int checkfifo_creating(int fd);
int checkfifo_opening(int fd);
int checkwriting_to_server(int fd);
int checkreading_from_server(int fd);
void checkWrite(int desc);
#endif