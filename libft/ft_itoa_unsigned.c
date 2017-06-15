#include "libft.h"

char 	*ft_itoa_unsigned(uintmax_t num, int base)
{
	uintmax_t	value;
	long		i;
	char		*s;

	i = 0;
	value = num;
	while (value)
	{
		i++;
		value /= base;
	}
	s = ft_strnew(i);
	s[i] = 0;
	while (num)
	{
		s[--i] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (s);
}