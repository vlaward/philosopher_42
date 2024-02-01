/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstante.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrombez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:59:22 by ncrombez          #+#    #+#             */
/*   Updated: 2023/10/12 16:04:48 by ncrombez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstante(t_list **lst, t_list *node)
{
	t_list	*temp;

	temp = *lst;
	if (temp == node)
		return (ft_lstlast(*lst));
	while (temp->next != node)
		temp = temp->next;
	return (temp);
}
