/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:35:35 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 11:35:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

static bool		is_list_sorted(t_list **head);
static t_list	*find_a_unsorted_node(t_list **head);
static void		swap_nodes(t_list *node_a, t_list *node_b);

void	sort_list_by_frequency(t_list **head)
{
	t_list	*ptr_i;

	ptr_i = *head;
	if (!*head)
		return ;
	while (!is_list_sorted(head))
	{
		if (!ptr_i->next)
			ptr_i = find_a_unsorted_node(head);
		if (ptr_i->frequency > ptr_i->next->frequency)
			swap_nodes(ptr_i, ptr_i->next);
		ptr_i = ptr_i->next;
	}
}

static bool	is_list_sorted(t_list **head)
{
	t_list	*ptr_i;

	if (*head == NULL)
		return (false);
	ptr_i = *head;
	while (ptr_i->next)
	{
		if (ptr_i->frequency > ptr_i->next->frequency)
			return (false);
		ptr_i = ptr_i->next;
	}
	return (true);
}

static t_list *find_a_unsorted_node(t_list **head)
{
	t_list	*ptr_i;

	if (*head == NULL)
		return (NULL);
	ptr_i = *head;
	while (ptr_i->next)
	{
		if (ptr_i->frequency > ptr_i->next->frequency)
			return (ptr_i);
		ptr_i = ptr_i->next;
	}
	return (NULL);
}

static	void swap_nodes(t_list *node_a, t_list *node_b)
{
	node_a->c ^= node_b->c;
	node_b->c ^= node_a->c;
	node_a->c ^= node_b->c;
	node_a->frequency ^= node_b->frequency;
	node_b->frequency ^= node_a->frequency;
	node_a->frequency ^= node_b->frequency;
}
