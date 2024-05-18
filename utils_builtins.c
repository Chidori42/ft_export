/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:06:36 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/05/17 11:24:31 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	ft_builts_error(char *cmd, char *err, char *des)
{
	ft_putstr_fd("mini: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(des, 2);
}

static void	display(char *envp, char *nm, char *vl, int fd)
{
	ft_putstr_fd("declare -x ", fd);
	ft_putstr_fd(nm, fd);
	if (vl && ft_strchr(envp, '='))
	{
		ft_putstr_fd("=\"", fd);
		print_value(vl, 1);
		ft_putstr_fd("\"", fd);
	}
	write(fd, "\n", 1);
}

void	ft_display_env(char **envp)
{
	char	*v_name;
	char	*v_value;
	int		i;

	i = -1;
	while (envp && envp[++i])
	{
		v_name = ft_substr(envp[i], 0, \
			ft_var_len(envp[i]));
		if (!v_name)
			break ;
		v_value = ft_substr(envp[i], \
			(ft_var_len(envp[i]) + 1), \
			(ft_strlen(envp[i]) - ft_strlen(v_name)));
		if (v_name && ft_strcmp(v_name, "_"))
			display(envp[i], v_name, v_value, 1);
		(free(v_name), free(v_value));
	}
}
