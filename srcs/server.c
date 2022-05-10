#include <unistd.h>
#include <signal.h>
#include "../ft_printf/includes/ft_printf.h"

void handleSigs(int sig)
{
	static int i;
	static char c;
	int	bit;

	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;

	c += (bit << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int main()
{
	struct sigaction	sa;

	ft_printf("SERVER PID: %d\n", getpid());
	sa.sa_handler = handleSigs;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();

	return (0);
}