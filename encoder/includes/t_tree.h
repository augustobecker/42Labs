/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:31:10 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:56:13 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TREE_H
# define T_TREE_H

#include "encoder.h"

// memory
t_tree	**root_new(void);
t_tree	*leaf_new(const char c, const size_t frequency);
t_tree	*branch_new(t_tree *left, t_tree *right);
void	tree_clear(t_tree **root);

// convert from 
t_tree	**convert_list_to_tree(t_list **head);
t_tree	*list_to_leaf(t_list *elem);
t_tree	**convert_str_to_tree(char *dictionary);

// functionalities
t_tree	*find_node(t_tree *node, const unsigned char c);
void	tree_link_add_front(t_tree **root, t_tree *branch);
void	tree_link_add_back(t_tree **root, t_tree *branch);
void	tree_remove_first_link(t_tree **root);
t_tree	*tree_last_link(t_tree *node);
void	link_tree_print(t_tree **root);
void	print_tree(t_tree **root);

// sort
void	sort_tree(t_tree **root);

#endif