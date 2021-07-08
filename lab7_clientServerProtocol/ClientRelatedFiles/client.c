#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "func.h"
#include "client.h"

int main(int argc, char *argv[])
{
   //объявляем необходимые переменные
   int client_to_server;
   int server_to_client;
   ssize_t nread;
   ssize_t written;
   struct message msg;
   //pid клиента
   msg.client_pid = getpid();
   printf("Client %d started.\n", msg.client_pid);
   //фифо каналы
   char *myfifo1 = "/tmp/client_to_server_fifo";
   char *myfifo2 = "/tmp/server_to_client_fifo";
   //открытие и проверка
   client_to_server = open(myfifo1, O_RDWR);
   fifo_verify_cts(client_to_server);

   server_to_client = open(myfifo2, O_RDWR);
   fifo_verify_stc(server_to_client);
   //ввод пути к файлу
   printf("Enter message to server: ");
   scanf("%s", msg.sending_message_data);
  // printf("message: %s\n", msg.sending_message_data);
   
   //запись пути к файлу серверу
   written = write(client_to_server, msg.sending_message_data, sizeof(msg));
   if(written < 0) //если не удалось записать
   {
      fprintf(stderr, "Writing from client to server error: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
   else //иначе
   {
      printf("Writing to server done.\n");
   }
   nread = read(server_to_client, msg.receiving_message_data, sizeof(msg));

   if(nread < 0) //если не удалось прочесть
   {
      fprintf(stderr, "Reading from server to client error: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
   else //иначе
   {
      printf("Received from server: %s\n", msg.receiving_message_data);
   }
   //закрытие
   close(client_to_server);
   close(server_to_client);
  printf("Client %d work ended.\n", msg.client_pid);
}

void fifo_verify_cts(int descr)
{
   if(descr < 0)
   {
      fprintf(stderr, 
      "Error opening fifo from client to server: %s\n", 
      strerror(errno));
      exit(EXIT_FAILURE);
   }
   else
   {
      printf("Opened fifo from client to server.\n");
   }
}

void fifo_verify_stc(int descr)
{
    if(descr < 0)
   {
      fprintf(stderr, 
      "Error opening fifo from server to client: %s\n", 
      strerror(errno));
      exit(EXIT_FAILURE);
   }
   else
   {
      printf("Opened fifo from client to server.\n");
   }
}