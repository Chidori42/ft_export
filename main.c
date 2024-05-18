/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:04:13 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/05/18 21:52:09 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int main(int ac, char **av, char **envp)
{
    int i;
    int j;

    i = -1;
    j = 0;
    if (ac > 1 && av && envp)
    {
        if (av[1] && !ft_strcmp(av[0], "./export"))
        {
            ft_export(&envp, av, &j);
            if (j == 0)
            {
                while (envp[++i])
                    printf ("%s\n", envp[++i]);
            }
        }
        else
            printf("Invalide cmd\n");
    }
    else
        printf("invalide argiments\n");
    
}