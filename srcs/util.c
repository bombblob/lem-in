/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:24:32 by acarlson          #+#    #+#             */
/*   Updated: 2019/01/06 16:25:47 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_str_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		i++;
	}
	free((*tab));
}

void		print_input(t_lem *info)
{
	t_list		*ptr;

	ptr = info->lines;
	ft_printf("%d\n", info->num_ants);
	while (ptr)
	{
		ft_printf("%s\n", (char *)ptr->content);
		ptr = ptr->next;
	}
}