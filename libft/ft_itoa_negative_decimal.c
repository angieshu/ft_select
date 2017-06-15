#include "libft.h"
#include <stdio.h>
char	*ft_itoa_negative_decimal(char *s)
{
	long long n;
	int i;
	int p;

	n = 0;
	p = 0;
	i = ft_strlen(s);
	while (--i >= 0)
	{
		if (s[i] == '1')
			n += ft_power(2, p);
		p++;
	}
	return (ft_itoa_base(n, 10));
}