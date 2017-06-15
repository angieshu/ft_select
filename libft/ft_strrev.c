#include "libft.h"

char	*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	temp;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	return (str);
}
