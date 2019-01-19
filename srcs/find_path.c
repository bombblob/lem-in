/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <callen@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:53:25 by callen            #+#    #+#             */
/*   Updated: 2019/01/17 18:53:27 by callen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	fp_cronch(t_lem *info)
{
	if (!ft_strcmp(info->p1->content, info->p2->content))
	{
		if (ft_lstlen(info->p1) > ft_lstlen(info->p2))
		{
			info->flag = 1;
			ft_lstdel(&info->l1[info->k], free_);
			info->l1[info->k] = info->l1[info->j - 1];
			info->l1[info->j - 1] = NULL;
			info->j--;
			return (1);
		}
		else
		{
			info->flag = 1;
			ft_lstdel(&info->l1[info->j - 1], free_);
			info->l1[info->j - 1] = NULL;
			info->j--;
			return (1);
		}
	}
	info->p1 = info->p1->next;
	info->k++;
	return (0);
}

static void	fp_finna(t_lem *info)
{
	if (info->v != S)
		ft_lstadd_tail(&info->l1[info->j], ft_lstnew(info->rooms[info->v]->name,
		ft_strlen(info->rooms[info->v]->name) + 1));
	info->i = 0;
	while (info->i < info->num_rooms)
	{
		if (!info->rgraph[info->v][info->i] && info->rgraph[info->i][info->v])
		{
			info->rgraph[info->i][info->v] = 1;
			info->rgraph[info->v][info->i] = 1;
			info->v = info->i;
			break ;
		}
		info->i++;
	}
}

static void	fp_donk(t_lem *info)
{
	ft_lstadd_tail(&info->l1[info->j], ft_lstnew(info->rooms[info->v]->name,
	ft_strlen(info->rooms[info->v]->name) + 1));
	info->j++;
	info->p2 = info->l1[info->j - 1];
	info->flag = 0;
	while (info->p2 && info->p2->next)
	{
		info->k = 0;
		while (info->k < info->j - 1)
		{
			info->p1 = info->l1[info->k];
			while (info->p1 && info->p1->next)
			{
				if (fp_cronch(info))
					break ;
				info->p1 = info->p1->next;
				info->k++;
			}
			if (info->flag)
				break ;
		}
		if (info->flag)
			break ;
		info->p2 = info->p2->next;
	}
}

t_list		**find_path(t_lem *info)// Uses original graph and residual graph and finds which paths were taken
{
	if (!(info->l1 = ft_memalloc(info->num_rooms * sizeof(t_list *))))
		panic(MALLOC_ERR);
	info->j = 0;
	info->y = 0;
	while (info->y < info->num_rooms)
	{
		info->x = 0;
		while (info->x < info->num_rooms)
		{
			if (info->conns[info->y][info->x] &&
				!info->rgraph[info->y][info->x])
			{
				info->v = S;
				while (info->v != info->num_rooms - 1)
					fp_finna(info);
				fp_donk(info);
			}
			info->x++;
		}
		info->y++;
	}
	info->l1[info->j] = NULL;
	return (info->l1);
}
