/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrombez <ncrombez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:40:51 by ncrombez          #+#    #+#             */
/*   Updated: 2023/05/16 16:00:32 by ncrombez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*t;

	if (lst == NULL || f == NULL)
		return ;
	t = lst;
	while (t->next != NULL)
	{
		(*f)(t->content);
		t = t->next;
	}
	(*f)(t->content);
}
