/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:41:42 by mlamothe          #+#    #+#             */
/*   Updated: 2020/11/07 13:30:59 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*curr_new;

	if (!lst || !del)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	curr_new = new;
	lst = lst->next;
	while (lst)
	{
		if (!(curr_new->next = ft_lstnew(f(lst->content))))
			return (NULL);
		curr_new = curr_new->next;
		lst = lst->next;
	}
	return (new);
}
