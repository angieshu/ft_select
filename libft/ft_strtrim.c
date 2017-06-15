/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:27:07 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/02 16:27:09 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spaces(char const *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_cword(char const *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			n++;
		}
		i++;
	}
	return (n);
}

static int	ft_suffix(char const *str)
{
	int i;

	i = ft_strlen(str) - 1;
	if (ft_cword(str) == 0 && ft_spaces(str) >= 0)
		return (0);
	else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		while (i >= 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i--;
		i = ft_strlen(str) - i - 1;
		return (i);
	}
	return (0);
}

static char	*ft_build_str(char *str, char const *s)
{
	int i;
	int k;

	i = ft_spaces(s);
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			str[k++] = s[i++];
		if (ft_cword(s + i) > 0)
		{
			while ((s[i] == ' ' || s[i] == '\t' ||
				s[i] == '\n') && s[i] != '\0')
				str[k++] = s[i++];
		}
		else
			break ;
	}
	str[k] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) *
		(ft_strlen(s) - ft_suffix(s) - ft_spaces(s)) + 1);
	if (str == NULL)
		return (NULL);
	str = ft_build_str(str, s);
	return (str);
}
