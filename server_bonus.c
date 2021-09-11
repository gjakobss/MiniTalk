/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjakobss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:16:11 by gjakobss          #+#    #+#             */
/*   Updated: 2021/09/11 17:16:22 by gjakobss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_minitalk	g_info;

void	get_sig(int sig_num)
{
	unsigned char	bit;

	bit = 0b10000000;
	if (sig_num == SIGUSR2)
		g_info.index++;
	if (sig_num == SIGUSR1)
	{
		bit = bit >> g_info.index;
		g_info.c = g_info.c | bit;
		g_info.index++;
	}
}

void	roger_that(t_minitalk *g_info)
{
	int	i;

	pause();
	if (g_info->index == 8)
	{
		i = 0;
		while (g_info->msg[i] != 0)
			i++;
		g_info->msg[i] = g_info->c;
		if (g_info->c == '\0')
		{
			ft_putstr(g_info->msg);
			write(1, "\n", 1);
			i = 0;
			while (i < 4096)
			{
				g_info->msg[i] = 0;
				i++;
			}
		}
		g_info->index = 0;
		g_info->c = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	int		x;

	x = 0;
	g_info.c = 0;
	g_info.index = 0;
	while (x < 4096)
	{
		g_info.msg[x] = 0;
		x++;
	}
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	while (1)
		roger_that(&g_info);
	return (0);
}
