#include "minitalk.h"

t_minitalk info;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = ft_strlen(s);
	write(1, s, i);
}


void	get_sig(int sig_num)
{
	unsigned char	bit;

	bit = 0b10000000;
	if (sig_num == SIGUSR2)
		info.index++;
	if (sig_num == SIGUSR1)
	{
		bit = bit >> info.index;
		info.c = info.c | bit;
		info.index++;
	}

}

void	roger_that(t_minitalk *info)
{
	int i;

	pause();
	if (info->index == 8)
	{
		i = 0;
		while (info->msg[i] != 0)
			i++;
		info->msg[i] = info->c;
		if (info->c == '\0')
		{
			ft_putstr(info->msg);
			write(1, "\n", 1);
			i = 0;
			while (i < 4096)
			{
				info->msg[i] = 0;
				i++;
			}
		}
		info->index = 0;
		info->c = 0;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
}


int	main(void)
{
	pid_t pid;
	int x;

	x = 0;
	info.c = 0;
	info.index = 0;
	while (x < 4096)
	{
		info.msg[x] = 0;
		x++;
	}
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	while (1)
		roger_that(&info);
	return (0);
}