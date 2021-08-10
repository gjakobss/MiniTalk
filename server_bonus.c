#include "minitalk.h"

t_minitalk info;

void	get_sig2(int sig_num)
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

void    take_signal(t_minitalk *info)
{
    ft_putstr(info->msg);
    write(1, "\n", 1);
    kill(info->client, SIGUSR1);
    info->flag = 0;
}

void    pick(t_minitalk *info)
{
    if (info->flag == 0)
    {
        info->client = ft_atoi(info->msg);
        info->flag = 1;
    }
    else
        take_signal(info);
    ft_bzero(info->msg, 4096);
}

int main(void)
{
    int i;

    init(&info);
    signal(SIGUSR1, get_sig2);
	signal(SIGUSR2, get_sig2);
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