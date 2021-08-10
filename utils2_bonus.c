#include "minitalk.h"

void	ft_putstr(char *s)
{
	int	i;

	i = ft_strlen(s);
	write(1, s, i);
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
