/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjakobss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:03:48 by gjakobss          #+#    #+#             */
/*   Updated: 2021/09/11 17:04:55 by gjakobss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_minitalk
{
	int				index;
	unsigned char	c;
	char			msg[4096];
	int				flag;
	int				client;
}				t_minitalk;

int		ft_strlen(const char *str);
void	ft_putstr(char *s);
void	get_sig(int sig_num);
void	roger_that(t_minitalk *info);
void	ft_putnbr(int n);
char	*ft_strdup(const char *s1);
void	convert(unsigned char c, int pid);
void	ft_putchar(char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	ft_putstr(char *s);
void	ft_putstr(char *s);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_strdup(const char *s1);
#endif
