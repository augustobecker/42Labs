/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:30:19 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:56:30 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

#include "decoder.h"

// memory
t_list  **list_new(void);
t_list	*list_elem_new(char c);
t_list	**list_dup(t_list **head);
void	list_clear(t_list **head);

// populate
void	populate_list(t_list **head, const char *text);

// functionalities
t_list	*list_last_elem(t_list *elem);
void	list_add_front(t_list **head, t_list *elem);
void	list_add_back(t_list **head, t_list *elem);
void	list_remove_first_elem(t_list **head);
t_list	*list_find_elem(t_list **head, unsigned char c_to_find);
size_t	list_size(t_list **head);
void	list_print(t_list **head);

// sort
void	sort_list_by_frequency(t_list **head);

#endif