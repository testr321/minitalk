#include <signal.h>
#include "../ft_printf/includes/ft_printf.h"

void sendChar(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(50);
	}
}

void sendStr(int pid, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		sendChar(pid, str[i]);
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
	}
	return (0);
}