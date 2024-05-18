/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:11:29 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/05/17 10:22:56 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int    ft_free_2_dm(char **arr)
{
    int            i;

    i = -1;
    while (arr && arr[++i])
        free (arr[i]);
    free (arr);
    return (0);
}

int	ft_strcmp(char *s_1, char *s_2)
{
	int			i;

	i = 0;
	if (!s_1 || !s_2)
		return (-1);
	while (s_1[i] && s_2[i] && (s_1[i] == s_2[i]))
		i++;
	return (s_1[i] - s_2[i]);
}

char    *ft_strs_join(char *s1, char *s2)
{
    char        *str;

    str = NULL;
    if (!s1 && s2)
        str = ft_strdup(s2);
    else if (s1 && !s2)
        str = ft_strdup(s1);
    else if (s1 && s2)
        str = ft_strjoin(s1, s2);
    return (free (s1), free (s2), str);
}
