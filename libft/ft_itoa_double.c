#include "libft.h"

static char *zero(int k, int sign)
{
	char *s;

	s = (char*)ft_memalloc(k + sign + 3);
	s[k + sign + 2] = '\0';
	while (--k >= 0)
	{
		s[k + sign + 2] = '0';
		if (k == 0)
			s[sign + 1] = '.';
	}
	s[sign] = '0';
	if (sign == 1)
		s[0] = '-';
	return (s);
}

static char	*build(uintmax_t n, int k, int i, int sign)
{
	char *n_nbr;

	if (n == 0)
		return (zero(k, sign));
	n_nbr = (char*)ft_memalloc(i + 1);
	n_nbr[i] = '\0';
	while (k-- >= 0 || n > 0)
	{	
		n_nbr[--i] = (n % 10) + '0';
		n /= 10;
		if (k == 0)
		{
			n_nbr[--i] = '.';
			if (n == 0)
				n_nbr[--i] = '0';
		}
	}
	if (i > 0)
		n_nbr[0] = '-';
	return (n_nbr);
}

static char *counting(long double nbr, int k, int sign, long i)
{
	uintmax_t n;
	uintmax_t nbrcpy;
	long double nbr_d;

	nbr_d = nbr; 
	nbr_d *= ft_power(10, k + 1);
	n = (uintmax_t)nbr_d;
	if (((((n / 10) + 1) * 10) - n) < 6)
		n = n + 10;
	if (nbr < 1)
	{
		i++;
		while ((nbr *= 10) < 1 || (k - i) > -2)
			i++;
	}
	else
	{
		nbrcpy = n;
		while ((nbrcpy = nbrcpy / 10) > 0)
			i++;
		if (k == 0)
			i--;
	}
	return (build(n / 10, k, i + sign, sign));
}

char	*ft_itoa_double(long double nbr, int k)
{
	int sign;
	long i;

	i = 1;
	sign = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = 1;
	}
	if (nbr == 0.0)
		return (zero(k, sign));
	return (counting(nbr, k, sign, i));
}