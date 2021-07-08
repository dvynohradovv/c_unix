#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>

// 6. Напишіть програму, яка після одержання сигналу SIGUSR1 ігнорує
// сигнали SIGUSR1 та SIGINT, а при одержанні сигналу SIGUSR2
// відновлює обробку цих сигналів за замовчуванням і видає
// повідомлення про кількість отриманих за цей час сигналів SIGUSR1
// та SIGINT.
static void sigusr1_handler(int signum);
static void sigint_handler(int signum);
static void sigusr2_handler(int signum);

int signalCounter = 0;
bool isStopped = false;

int main()
{
	pid_t pid_main = getpid();
	printf("Main process pid: %d\n",pid_main);
	signal(SIGUSR1,sigusr1_handler);
	signal(SIGINT,sigint_handler);
	signal(SIGUSR2,sigusr2_handler);
	while(1)
	{
		pause();
	}
}
static void sigusr1_handler(int signum)
{
	if (signum == SIGUSR1 && isStopped)
	{
		signalCounter++;
	}
	else if (signum == SIGUSR1)
	{
		signal(SIGUSR1,SIG_IGN);
		signal(SIGINT,SIG_IGN);
		isStopped = true;
	}
	
}
static void sigint_handler(int signum)
{
	if (signum == SIGINT && isStopped )
	{
		signalCounter++;
	}
}
static void sigusr2_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		signal(SIGUSR1,SIG_DFL);
		signal(SIGINT,SIG_DFL);
		printf("Counter signal: %d\n",signalCounter);
		isStopped = false;
		signalCounter = 0;
	}
}