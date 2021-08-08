#include "minitalk.h"

static int	ft_counter(int n)
{
	int			counter;
	long int	i;

	counter = 0;
	i = n;
	if (i < 0)
	{
		counter = 1;
		i *= -1;
	}
	while (i >= 10)
	{
		i = (i / 10);
		counter++;
	}
	return (counter + 1);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		strsize;

	strsize = ft_counter(n);
	if (!(str = malloc(sizeof(char) * (strsize + 1))))
		return (NULL);
	str[strsize] = '\0';
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		n *= -1;
	strsize -= 1;
	while (n >= 10 && strsize >= 0)
	{
		str[strsize--] = (n % 10) + 48;
		n /= 10;
	}
	str[strsize] = n + 48;
	return (str);
}

void    get_it(int sig_num)
{
    (void)sig_num;
    ft_putstr("Message successfully sent and received by the server\n");
    exit(0);
}

int main(int argc, char **argv)
{
    int		pid;
	pid_t	pid_client;
	char	*str_pid;
	char	*str;
	int		i;

    signal(SIGUSR1, get_it);
    str = ft_strdup(argv[2]);
    pid_client = getpid;
    if (argc != 3)
        exit(0);
    str_pid = ft_itoa(pid_client);
    i = 0;
    pid = 0;
    while (argv[1][i] != '\0')
    {
        pid = (pid * 10) + argv[1][i] - '0';
        i++;
    }
    
}