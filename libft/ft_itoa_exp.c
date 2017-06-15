#include "libft.h"

static char *ft_zero(long double nbr, int k)
{
	char *s;
	char *tmp;

	tmp = ft_itoa_double(nbr, k);
	s = ft_strjoin(tmp, "e+00");
	free(tmp);
	return (s);
}

static int	ft_round(long double nbr, int k)
{
	double check;

	check = 9;
	while (k > 0)
		check += (9 / ft_power(10, k--));
	if (nbr < check)
		return (0);
	return (1);
}

static char	*ft_count_power(long double nbr, int k, int sign)
{
	int i;
	char *s;
	char *tmp;
	
	i = 1;
	if (nbr >= 10)
	{
		while ((nbr = nbr / 10) >= 10)
			i++;
	}
	else
		i = 0;
	if (ft_round(nbr, k))
	{
		i++;
		nbr /= 10;
	}
	tmp = ft_itoa_double(nbr * sign, k);
	if (ft_countnumber(i, 10) < 10)
		s = ft_strjoin(tmp, "e+0");
	else
		s = ft_strjoin(tmp, "e+");
	free(tmp);
	tmp = s;
	s = ft_strjoin(tmp, ft_itoa(i));
	free(tmp);
	return (s);
} 

static char	*ft_count_power_neg(long double nbr, int k, int sign)
{
	int i;
	char *s;
	char *tmp;

	i = 1;
	while ((nbr = nbr * 10) < 1)
		i++;
	if (ft_round(nbr, k))
	{
		i++;
		nbr /= 10;
	}
	tmp = ft_itoa_double(nbr * sign, k);
	if (ft_countnumber(i, 10) < 10)
		s = ft_strjoin(tmp, "e-0");
	else
		s = ft_strjoin(tmp, "e-");
	free(tmp);
	tmp = s;
	s = ft_strjoin(tmp, ft_itoa(i));
	free(tmp);

	return (s);
}

char		*ft_itoa_exp(long double nbr, int k)
{
	int sign;

	sign = 1;
	if (nbr == 0)
		return (ft_zero(nbr, k));
	if (nbr < 0)
	{
		nbr *= -1;
		sign = -1;
	}
	if (nbr < 1)
		return (ft_count_power_neg(nbr, k, sign));
	return (ft_count_power(nbr, k, sign));
}