/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:12:35 by acarlson          #+#    #+#             */
/*   Updated: 2018/09/25 21:09:56 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (*s)
		{
			f(s);
			s++;
		}
	}
}
