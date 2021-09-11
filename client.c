/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjakobss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:57:03 by gjakobss          #+#    #+#             */
/*   Updated: 2021/09/11 16:57:26 by gjakobss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1);
	dest = (char *)malloc((len + 1) * sizeof(char));
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

void	convert(unsigned char c, int pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit != 0)
	{
		if ((bit & c))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit = bit >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;
	int		i;

	if (argc != 3)
		exit(0);
	msg = ft_strdup(argv[2]);
	i = 0;
	pid = 0;
	while (argv[1][i])
	{
		pid = (pid * 10) + argv[1][i] - '0';
		i++;
	}
	while (*msg)
	{
		convert(*msg, pid);
		msg++;
	}
	convert(0, pid);
	return (0);
}
