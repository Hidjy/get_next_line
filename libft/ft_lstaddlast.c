/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:12:41 by laime             #+#    #+#             */
/*   Updated: 2014/11/25 16:32:11 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstaddlast(t_list **start, t_list *new)
{
	t_list		*lst;

	lst = *start;
	if (!(*start))
		*start = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
