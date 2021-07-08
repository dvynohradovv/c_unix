
#include "server.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <signal.h>
#include <sys/resource.h>

int main(void) {
        
        //Идентификатор процесса и сессии (pid & sid)
        
        int serverwork;
        int i;
        pid_t pid, sid;     
        struct sigaction sa;
        struct rlimit rl;

        pid = fork();
        if (pid < 0) 
        {
            exit(EXIT_FAILURE);
        }
        //при помощи fork выходим из процесса родителя
        if (pid > 0) 
        {
            exit(EXIT_SUCCESS);
        }
        //сбрасываем маску режима создания  файлов
        umask(0);  

        //определение максимально возможного номера дексриптора 
        if(getrlimit(RLIMIT_NOFILE, &rl) < 0)
            return -1;
        
        //открываем журнал для сервера
        openlog ("SERVER_LOG", LOG_CONS | LOG_PID | LOG_ERR | LOG_NDELAY, LOG_INFO);

        //создаём новый идентификатор сессии для потомка
        sid = setsid();
        if (sid < 0) 
        {
           //запись ошибки в журнал
            syslog(LOG_ERR, "ERROR_SET_SID\n");
            exit(EXIT_FAILURE);
        }
        
        //т.к. демон не зависит от терминала, то нужно 
        //воспрепятствовать получению управляющего терминала
        sa.sa_handler = SIG_IGN;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        if(sigaction(SIGHUP, &sa, NULL) < 0)
            return -1;
        //повторно вызываем fork() и завершаем родительский процесс чтобы второй потомок
        //работал в качестве демона
        
        if( (pid = fork()) < 0 )
            return -1;
        else if(pid != 0)
            exit(0);
        

        //изменить текущую рабочую директорию на корневой каталог
        if ((chdir("/")) < 0) 
        {
            syslog(LOG_ERR,"ERROR_CHNG_DIR");
            exit(EXIT_FAILURE);
        }
        
        //закрыть ненужные дексрипторы
        if(rl.rlim_max == RLIM_INFINITY)
            rl.rlim_max = 1024;
        
        for(i = 0; i < rl.rlim_max; i++)
            close(i);
        

        while (1) 
        {
            //работа демона
            syslog(LOG_INFO, "Server on.");
            serverwork = SERVER();
            if(serverwork < 0)
            {
                syslog(LOG_INFO, "Ending server work.");
                break;
            }
        }
  
    closelog();
    exit(EXIT_SUCCESS);
}
