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