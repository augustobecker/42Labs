/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:37:33 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:59:51 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

static int	count_element(t_list **head, char it);

void	populate_list(t_list **head, const char *text)
{
	int		i;

	i = 0;
	while (text[i])
	{
		if (!count_element(head, text[i]))
			list_add_back(head, list_elem_new(text[i]));
		i++;
	}
}

static int	count_element(t_list **head, char it)
{
	t_list	*element;

	if (!*head)
		return (false);
	element = *head;
	while (element)
	{
		if (element->c == it)
		{
			element->frequency++;
			return (element->frequency);
		}
		element = element->next;
	}
	return (0);
}
