/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:11:55 by abdelilah         #+#    #+#             */
/*   Updated: 2024/11/08 20:11:56 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nv;

	nv = (t_list *)malloc(sizeof(t_list));
	if (!nv)
		return (0);
	nv->content = content;
	nv->next = NULL;
	return (nv);
}
