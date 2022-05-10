#include <signal.h>
// #include <stdio.h>
#include "../ft_printf/includes/ft_printf.h"

void sendChar(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i++) & 1)
		{
			kill(pid, SIGUSR2);
			// ft_printf("send 1\n");
		}
		else
		{
			kill(pid, SIGUSR1);
			// ft_printf("send 0\n");
			
		}
		usleep(100);
		// sleep(1);
	}
}

void sendStr(int pid, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		sendChar(pid, str[i++]);
	}
	sendChar(pid, '\0');
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int pid;
		char *str;

		pid = ft_atoi(argv[1]);
		str = argv[2];
		sendStr(pid, str);
		// char *str = argv[2];
		// char testr = argv[2][0];
		// char testr2;
		// printf("%s\n", argv[2]);
	/* 	if (argv[2][0] == '1')
		{
			
			// usleep(69);
			// kill(pid, SIGUSR2);
		}
		else 
		{
			kill(pid, SIGUSR2);
			// usleep(69);
			// kill(pid, SIGUSR1);
		} */
	}
	return (0);
}