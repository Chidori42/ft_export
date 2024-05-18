/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:47:53 by bramzil           #+#    #+#             */
/*   Updated: 2024/05/17 11:26:52 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

//**************************** included header files *************************//

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>

int		g_sig;

void	ft_cd_error(int ref);
int		ft_var_len(char *arg);
int     ft_free_2_dm(char **arr);
void	ft_display_env(char **envp);
void	print_value(char *str, int fd);
int     ft_strcmp(char *s_1, char *s_2);
int		ft_check_var(char *arg, int *st);
int		ft_check_arg(char *arg, int *st);
char    *ft_strs_join(char *s1, char *s2);
char	*ft_new_var(char *var, char *old_vl);
int     ft_export(char ***envp, char **pars, int *j);
void	ft_builts_error(char *cmd, char *err, char *des);
int		ft_update_env(char ***envp, char *par, int *b, int i);
#endif

//****************************************************************************//