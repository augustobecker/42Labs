/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionalities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:27:30 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:59:43 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

t_list	*list_last_elem(t_list *elem);
void	list_add_front(t_list **head, t_list *elem);
void	list_add_back(t_list **head, t_list *elem);
void	list_remove_first_elem(t_list **head);
t_list	*list_find_elem(t_list **head, unsigned char c_to_find);
size_t	list_size(t_list **head);
void	list_print(t_list **head);

t_list	*list_last_elem(t_list *elem)
{
	if (!elem)
		return (NULL);
	while (elem->next)
		elem = elem->next;
	return (elem);
}

void	list_add_front(t_list **head, t_list *elem)
{
	if (*head)
		(*head)->previous = elem;
	elem->previous = NULL;
	elem->next = *head;
	*head = elem;
}

void	list_add_back(t_list **head, t_list *elem)
{
	t_list *last_elem;

	if (!*head)
		*head = elem;
	else
	{
		last_elem = list_last_elem(*head);
		last_elem->next = elem;
		elem->previous = last_elem;
	}
}

void	list_remove_first_elem(t_list **head)
{
	t_list	*new_first_elem;

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return ;
	}
	new_first_elem = (*head)->next;
	free(*head);
	*head = new_first_elem;
}

t_list	*list_find_elem(t_list **head, unsigned char c_to_find)
{
	t_list	*ptr_i;

	ptr_i = *head;
	if (*head == NULL)
		return (NULL);
	while (ptr_i)
	{
		if (ptr_i->c == c_to_find)
			return (ptr_i);
		ptr_i = ptr_i->next;
	}
	return (NULL);
}

size_t	list_size(t_list **head)
{
	t_list	*ptr_i;
	size_t	length;

	length = 0;
	ptr_i = *head;
	if (*head == NULL)
		return (length);
	while (ptr_i)
	{
		length++;
		ptr_i = ptr_i->next;
	}
	return (length);
}

void	list_print(t_list **head)
{
	t_list	*ptr_i;

	ptr_i = *head;
	if (*head == NULL)
		return ;
	printf("Dictionary\n");
	printf("char |frequency| codes\n");
	while (ptr_i)
	{
		if (is_whitespace(ptr_i->c))
		{
			printf("[");
			print_whitespace(ptr_i->c);
		}
		else
			printf(" [%c", ptr_i->c);
		printf("] |	%ld", ptr_i->frequency);
		if (ptr_i->code)
			printf("\t[%s]", ptr_i->code);
		printf("\n");
		ptr_i = ptr_i->next;
	}
	printf("**************************\n");
}
