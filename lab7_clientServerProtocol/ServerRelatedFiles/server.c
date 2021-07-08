#include "func.h"
#include "server.h"
#include "client.h"

#include <syslog.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>

int SERVER()
{
   //Объявление перменных, структур, указателей
   int client_to_server;
   int server_to_client;

   int file_exist = -1;
   int written = -1;
   ssize_t ret;

   char *myfifo1 = "/tmp/client_to_server_fifo";
   char *myfifo2 = "/tmp/server_to_client_fifo";
 
   struct message msg_sever;
   

   //Создание и проверка fifo
   int f1 = mkfifo(myfifo1, PERM_FILE);
   check_if_fifo_created(f1);
   int f2 = mkfifo(myfifo2, PERM_FILE);
   check_if_fifo_created(f2);

   //Открытие и проверка каналов 
   client_to_server = open(myfifo1, O_RDWR);
   check_if_fifo_opened(client_to_server);
   server_to_client = open(myfifo2, O_RDWR);
   check_if_fifo_opened(server_to_client);
  
   while (1)
   {
      ret = read(client_to_server, msg_sever.receiving_message_data, sizeof(msg_sever));
      check_if_ret(ret);

      //вызываем фунцию для того, чтобы узнать, существует ли файл
      file_exist = Exists(msg_sever.receiving_message_data);

      if(file_exist == 0) //существует
      {
         syslog(LOG_INFO, "File was found.");
        
         
         written = write(server_to_client, FOUND, sizeof(FOUND));
         check_if_written(written);
      }
      else // нет
      {
         syslog(LOG_INFO, "File wasn't found");
         
         written = write(server_to_client, NOTFOUND, sizeof(NOTFOUND));
         check_if_written(written);
      }
      
   }
   //закрываем дескритор FIFO-файла
   close(client_to_server);
   close(server_to_client);

   //удаляем FIFO-файлы из системы
   unlink(myfifo1);
   unlink(myfifo2);
   return 0;
}

void check_if_ret(int rd_desc)
{
    if(rd_desc > 0)
   {
      syslog(LOG_INFO, "Reading from client done.");
   }
   else
   {
      syslog(LOG_ERR, "Reading from client error: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
}

void check_if_written(int wr_desc) //проверка записи сообщения клиенту
{
   if(wr_desc >= 0)
   {
      syslog(LOG_INFO, "Writing to client done.");
   }
   else
   {
      syslog(LOG_ERR, "writing to client error: %s\n", strerror(errno));
       exit(EXIT_FAILURE);
   }
}

void check_if_fifo_created(int created)
{
	if(created)
	{
		syslog(LOG_INFO, "Fifo created succsessfully.");
	}
	else
	{
		syslog(LOG_ERR, "Error while creaing fifo channel: %s\n", strerror(errno));
		 exit(EXIT_FAILURE);
	}
}

void check_if_fifo_opened(int opened)
{
	if(opened)
	{
		
		syslog(LOG_INFO, "Fifo opened succsessfully.");
		
	}
	else
	{
		syslog(LOG_ERR, "Error while opening fifo channel: %s\n", strerror(errno));
		 exit(EXIT_FAILURE);
	}
}