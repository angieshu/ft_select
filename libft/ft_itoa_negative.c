#include "libft.h"

static char *ft_octal(char *s)
{
	int i;
	int p;
	int j;
	char *oct;

	p = 3;
	i = ft_strlen(s);
	j = i / 3;
	if (i % 3 != 0)
		j++;
	oct = (char*)ft_memalloc(j + 1);
	oct[j] = 0;
	while (i >= 0)
	{
		if (p == 3)
		{
			p = 0;
			oct[--j] = '0';
		}
		if (s[--i] == '1')
			oct[j] = oct[j] + ft_power(2, p);
		p++;
	}
	return (oct);
}

static char	*ft_hex(char *s, int i)
{
	int p;
	int j;
	char *hex;
	p = 3;
	j = i / 4;
	if (i % 4 != 0)
		j++;
	hex = (char*)ft_memalloc(j + 1);
	hex[j] = 0;
	while (i >= 0)
	{
		if (++p == 4)
		{
			p = 0;
			hex[--j] = '0';
		}
		if (s[--i] == '1')
			hex[j] = hex[j] + ft_power(2, p);
		if (hex[j] > '9')
			hex[j] = 'a' + hex[j] - '9' - 1;
	}
	return (hex);
}

static char	*ft_conv(char *s, int b)
{
	int i;
	char *tmp;

	tmp = NULL;
	i = ft_strlen(s) - 1;
	while (s[i] != '0')
		s[i--] = '0';
	s[i] = '1';
	if (b == 8)
		tmp = ft_octal(s);
	else if (b == 16)
		tmp = ft_hex(s, ft_strlen(s));
	else if (b == 10)
		tmp = ft_itoa_negative_decimal(s);
	free(s);
	return (tmp);
}

static void	help(char *s, char *tmp, int i, int len)
{
	s[i] = 0;
	while (len-- > 0)
	{
		if (tmp[len] == '0')
			s[--i] = '1';
		else
			s[--i] = '0';
	}
	while (i > 0)
		s[--i] = '1';
}

char		*ft_itoa_negative(intmax_t v, int b)
{
	int i;
	long len;
	char *tmp;
	char *s;

	i = 64;
	v = v * -1;
	tmp = ft_itoa_base(v, 2);
	len = ft_strlen(tmp);
	if (i >= len)
	{
		s = (char*)ft_memalloc(i + 1);
		help(s, tmp, i, len);
	}
	else
		s = ft_strdup(tmp);
	free(tmp);
	return (ft_conv(s, b));
}
