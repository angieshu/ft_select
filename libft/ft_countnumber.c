#include "libft.h"

long	ft_countnumber(intmax_t v, int b)
{
	long	i;

	i = 0;
	if (v < 0)
	{
		i = i + 1;
		v = v * -1;
	}
	while (v > 0)
	{
		i = i + 1;
		v = v / b;
	}
	return (i);
}