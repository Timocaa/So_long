/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:39:20 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:45:36 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_free_tab(int len, char **tab)
{
	int	i;

	i = 0;
	while (len--)
		free(tab[i++]);
	free(tab);
}

static int	ft_nb_split(const char *s, char c)
{
	int	i;
	int	nb_split;

	i = 0;
	nb_split = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nb_split++;
		i++;
	}
	return (nb_split);
}

static char	*ft_put_split(const char *s, char c, int *i)
{
	char	*split;
	int		j;
	int		len;

	len = *i;
	while (s[len] && s[len] != c)
		len++;
	split = malloc(sizeof(*split) * ((len - *i) + 1));
	if (split == NULL)
		return (NULL);
	j = 0;
	while (s[*i] && s[*i] != c)
	{
		split[j++] = s[*i];
		*i += 1;
	}
	split[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_nb_split(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < ft_nb_split(s, c) && s[i])
	{
		tab[j] = ft_put_split(s, c, &i);
		if (tab[j] == NULL)
		{
			ft_free_tab(j, tab);
			return (NULL);
		}
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
