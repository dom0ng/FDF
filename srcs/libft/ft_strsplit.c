/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:01:51 by julin             #+#    #+#             */
/*   Updated: 2017/11/30 22:36:43 by julin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static char	*prepare_str(char *str, int *len, int *word, char sep)
{
	if (str == NULL)
		return (NULL);
	while (str[*len])
	{
		if (str[*len] && is_separator(str[*len], sep) && str[(*len) - 1] &&
				!is_separator(str[(*len) - 1], sep))
			(*word)++;
		else if ((str[(*len) + 1] == '\0') && !is_separator(str[*len], sep))
			(*word)++;
		if (is_separator(str[*len], sep))
			str[*len] = '\0';
		(*len)++;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	int		word;
	char	*str;
	char	**tab;

	if (s == NULL)
		return (NULL);
	len = 0;
	word = 0;
	if ((str = prepare_str(ft_strdup((char *)s), &len, &word, c)) == NULL)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(char *) * (word + 1))) == NULL)
		return (NULL);
	word = 0;
	i = -1;
	while (++i < len)
	{
		if (str[i] && (!str[i - 1] || (i == 0)))
			tab[word++] = ft_strdup(&str[i]);
	}
	tab[word] = NULL;
	return (tab);
}
