#include "libft.h"

char	*ft_itoa_signed(intmax_t num)
{
	uintmax_t	value;
	long		i;
	char		*s;

	value = (num < 0) ? num * -1 : num;
	i = 0;
	if (num < 0)
		i++;
	while (value)
	{
		i++;
		value /= 10;
	}
	value = (num < 0) ? num * -1 : num;
	s = ft_strnew(i);
	s[i] = 0;
	while (value)
	{
		s[--i] = "0123456789"[value % 10];
		value /= 10;
	}
	if (i != 0)
		s[0] = '-';
	return (s);
}