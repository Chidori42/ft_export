/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:06:22 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/05/18 21:53:10 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

static int	ft_dup_env(char ***envp, char ***new, char *var)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	if (!tmp)
		return (free(var), -1);
	while ((*envp) && (*envp)[i])
	{
		tmp = ft_strs_join(tmp, \
			ft_strs_join(ft_strdup((*envp)[i]), \
			ft_strdup("\n")));
		if (!tmp)
			return (free(var), -1);
		i++;
	}
	str = ft_strs_join(tmp, ft_strdup(var));
	if (!str)
		return (free(var), -1);
	*new = ft_split(str, '\n');
	if (!new)
		return (free(str), free(var), -1);
	return (free(str), free(var), 0);
}

static int	ft_set_variable(char ***envp, char *par)
{
	int			i;
	int			b;
	char		**new;

	b = 1;
	i = -1;
	while (par && (*envp) && (*envp)[++i])
		if (!ft_update_env(&(*envp), par, &b, i))
			break ;
	if (b && par && (*envp))
		if (!ft_dup_env(&(*envp), &new, \
			ft_new_var(ft_strdup(par), NULL)))
			(*envp) = new;
	return (0);
}

int	ft_export(char ***envp, char **pars, int *j)
{
	int		i;
	int		st;

	i = 0;
	st = 0;
	if ((*envp) && pars && !pars[1])
	{
		ft_display_env((*envp));
		*j = 1;
	}
	else
	{
		while ((*envp) && pars && pars[++i])
		{
			if (!ft_check_var(pars[i], &st) && \
				!ft_check_arg(pars[i], &st))
				ft_set_variable(&(*envp), pars[i]);
		}
	}
	return (st);
}
