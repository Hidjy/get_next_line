/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsimpledel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 23:00:12 by laime             #+#    #+#             */
/*   Updated: 2015/01/15 23:00:26 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsimpledel(t_list **alst)
{
	if (*alst)
	{
		ft_lstsimpledel(&(*alst)->next);
		ft_lstsimpledelone(alst);
	}
}
