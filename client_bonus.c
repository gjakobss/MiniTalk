#include "minitalk.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1);
	dest = (char*)malloc((len + 1) * sizeof(char));
	if (!dest)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


void	convert_b(unsigned char c, int pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit != 0)
	{
		if (bit & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit = bit >> 1;
		usleep(100);
	}
}

void    get_it(int sig_num)
{
    (void)sig_num;
    ft_putstr("Message successfully sent and received by the server\n");
    exit(0);
}

void	conv_organizer(char *str, char *str_pid, int pid)
{
	while (*str_pid != '\0')
	{
		convert_b(*str_pid, pid);
		str_pid++;
	}
	convert_b(0, pid);
	while(*str)
	{
		convert_b(*str, pid);
		str++;
	}
	convert_b(0, pid);
}

int main(int argc, char **argv)
{
    int		pid;
	pid_t	pid_client;
	char	*str_pid;
	char	*str;
	int		i;

	if (argc != 3)
        exit(0);
    signal(SIGUSR1, get_it);
    str = ft_strdup(argv[2]);
    pid_client = getpid();
    str_pid = ft_itoa(pid_client);
    i = 0;
    pid = 0;
    while (argv[1][i] != '\0')
    {
        pid = (pid * 10) + argv[1][i] - '0';
        i++;
    }
	conv_organizer(str, str_pid, pid);
	free(str_pid);
	free(str);
    pause();
	return (0);
}