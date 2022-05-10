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
	{
		bit = 1;
		// ft_printf("1\n");
	}
	// ft_printf("%d\n", i);
	c += bit << i;

	i++;
	if (i >= 8)
	{
		// ft_printf("reset i\n\n");
		i = 0;
		
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		c = 0;
	}
}

int main()
{
	struct sigaction	sa;
	

	// ft_printf("SERVER PID: %d\n", getpid());
	
	// write(1, "Server PID : ", 13);
	// ft_putnbr_fd((int) getpid(), 1);
	// write(1, "\n", 1);

	// sa.sa_handler = handleSigs;
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	// sa.sa_handler = handleSigs;
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);

	// while (1)
	// {
	// 	pause();
	// }

	write(1, "Server PID : ", 13);
		ft_putnbr_fd((int) getpid(), 1);
		write(1, "\n", 1);
		sa.sa_handler = handleSigs;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	
	return (0);
}