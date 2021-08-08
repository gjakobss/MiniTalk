#include "minitalk.h"

t_minitalk info;

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' \
			|| c == '\r' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int			i;
	long long	nmr;
	int			signal;

	i = 0;
	nmr = 0;
	signal = 1;
	while (ft_is_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nmr = nmr * 10 + ((str[i++] - 48));
	}
	nmr = nmr * signal;
	if (nmr > 2147483647)
		return (-1);
	else if (nmr < -2147483648)
		return (0);
	return (nmr);
}

void    init(t_minitalk *info)
{
    pid_t pid;
    int i;

    info->c = 0;
    info->flag = 0;
    info->client = 0;
    info->index = 0;
    i = 0;
    while (i < 4096)
    {
        info->msg[i] = 0;
        i++;
    }
    pid = getpid();
    ft_putnbr(pid);
    write(1, "\n", 1);
}

void    signal(t_minitalk *info)
{
    ft_putstr(info->msg);
    write(1, "\n", 1);
    kill(info->client, SIGUSR1);
    info->flag = 0;
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
	{
		dst[i] = 0;
		i++;
	}
}


void    pick(t_minitalk *info)
{
    if (info->flag = 0)
    {
        info->client = ft_atoi(info->msg);
        info->flag = 1;
    }
    else
        signal(&info);
    ft_bzero(info->msg, 4096);
}

int main(void)
{
    int i;

    init(&info);
    signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
    while (1)
    {
        pause();
        if (info.index == 8)
        {
            i = 0;
            while (info.msg[i] != 0)
                i++;
            info.msg[i] = info.c;
            if (info.c == '\0')
                pick(&info);
            info.index = 0;
            info.c = 0;
        }
    }
    return (0);
}