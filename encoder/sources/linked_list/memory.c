/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:17:09 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:59:47 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

t_list  **list_new(void);
t_list	*list_elem_new(const unsigned char c);
t_list	**list_dup(t_list **head);
void	list_clear(t_list **head);

t_list **list_new(void)
{
	t_list	**head;

	head = malloc(sizeof(t_list **));
	if (!head)
		error_msg(MALLOC_ERROR, "list_new");
	*head = NULL;
	return (head);
}

t_list	*list_elem_new(const unsigned char c)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		error_msg(MALLOC_ERROR, "list_elem_new");
	new->c = c;
	new->code = NULL;
	new->frequency = 1;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_list	**list_dup(t_list **head)
{
	t_list	**dup_head;
	t_list	*dup_elem;
	t_list	*ptr_i;

	ptr_i = *head;
	dup_head = list_new();
	while (ptr_i)
	{
		dup_elem = list_elem_new(ptr_i->c);
		dup_elem->frequency = ptr_i->frequency;
		list_add_back(dup_head, dup_elem);
		ptr_i = ptr_i->next;
	}
	return (dup_head);
}

void	list_clear(t_list **head)
{
	t_list	*ptr_i;
	t_list	*next_elem;

	if (*head == NULL)
	{
		free(head);
		return ;
	}
	ptr_i = *head;
	while (ptr_i)
	{
		next_elem = ptr_i->next;
		ptr_i->next = NULL;
		free(ptr_i);
		if (next_elem)
			next_elem->previous = NULL;
		ptr_i = next_elem;
	}
	*head = NULL;
	free(head);
}
