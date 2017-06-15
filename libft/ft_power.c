#include "libft.h"

long	ft_power(long n, long pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_power(n, pow - 1));

}
