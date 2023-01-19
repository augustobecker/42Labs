/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_from.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:50:07 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:58:48 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

t_tree	**convert_list_to_tree(t_list **head);
t_tree	*list_to_leaf(t_list *elem);
t_tree	**convert_str_to_tree(char *dictionary);
t_tree	**set_tree(unsigned char *elements, size_t *frequency);

t_tree **convert_list_to_tree(t_list **head)
{
	t_list	*ptr_i;
    t_tree  **root;

    root = root_new();
	ptr_i = *head;
	while (ptr_i)
	{
		tree_link_add_back(root, list_to_leaf(ptr_i));
		ptr_i = ptr_i->next;
	}
	sort_tree(root);
	return (root);
}

t_tree **convert_str_to_tree(char *dictionary)
{
	t_tree  **root;
	int		order;
	int		i;

	i = 0;
	order = 0;
	root = root_new();
	while (dictionary[i])
	{
		if (dictionary[i] > BITS_IN_A_BYTE)
		{
			tree_link_add_front(root, leaf_new(dictionary[i], order));
			order++;
		}
		i++;
	}
	sort_tree(root);
	return (root);
}

t_tree  *list_to_leaf(t_list *elem)
{
	t_tree	*leaf_node;

	leaf_node = malloc(sizeof(t_tree));
	if (!leaf_node)
		error_msg(MALLOC_ERROR, "list_to_leaf");
    leaf_node->c = elem->c;
    leaf_node->frequency = elem->frequency;
    leaf_node->left = NULL;
	leaf_node->right = NULL;
    leaf_node->next = NULL;
	leaf_node->prev = NULL;
	return (leaf_node);
}

t_tree **set_tree(unsigned char *elements, size_t *frequency)
{
	t_tree	**root;
	t_tree	*node;
	int len;
	int	i;

	i = 0;
	len = strlen((char *) elements);
	root = root_new();
	while (i < len)
	{
		node = leaf_new(elements[i], frequency[i]);
		tree_link_add_back(root, node);
		i++;
	}
	sort_tree(root);
	return (root);
}
