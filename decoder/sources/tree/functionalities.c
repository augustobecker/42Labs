/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionalities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:51:27 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:59:05 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

t_tree		*find_node(t_tree *node, const unsigned char c);
void		tree_link_add_front(t_tree **root, t_tree *branch);
void		tree_link_add_back(t_tree **root, t_tree *branch);
void		tree_remove_first_link(t_tree **root);
t_tree		*tree_last_link(t_tree *node);
void		link_tree_print(t_tree **root);
void		print_tree(t_tree **root);
static void	print_node(t_tree *node);

t_tree	*find_node(t_tree *node, const unsigned char c)
{
	t_tree *value;

	value = NULL;
	if (node)
	{
		if (!node->left && !node->right && node->c == c)
			return (node);
		value = find_node(node->left, c);
		if (value)
			return (value);
		value = find_node(node->right, c);
		if (value)
			return (value);
	}
	return (NULL);
}

void	tree_link_add_front(t_tree **root, t_tree *branch)
{
	if (*root)
		(*root)->prev = branch;
	branch->prev = NULL;
	branch->next = *root;
	*root = branch;
}

void	tree_link_add_back(t_tree **root, t_tree *branch)
{
	t_tree	*last_link;

	if (!*root)
		*root = branch;
	else
	{
		last_link = tree_last_link(*root);
		last_link->next = branch;
	}
}

void	tree_remove_first_link(t_tree **root)
{
	t_tree	*new_first_link;

	if ((*root)->next == NULL)
	{
		free(*root);
		*root = NULL;
		return ;
	}
	new_first_link = (*root)->next;
	*root = new_first_link;
}

t_tree		*tree_last_link(t_tree *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	link_tree_print(t_tree **root)
{
	t_tree	*ptr_i;
	int		i;

	i = 1;
	ptr_i = *root;
	if (*root == NULL)
		return ;
	printf("Tree links (tree as a list)\n");
	while (ptr_i)
	{
		printf("/t[%d° node]\t %ld\n", i,  ptr_i->frequency);
		ptr_i = ptr_i->next;
		i++;
	}
	printf("**************************\n");
}

void	print_tree(t_tree **root)
{
	printf("Huffman Tree\n");
	print_node(*root);
	printf("**************************\n");
}

static void	print_node(t_tree *node)
{
	if (node)
	{
		if (!node->left && !node->right)
		{
			printf(PINK"\t[");
			if (is_whitespace(node->c))
				print_whitespace(node->c);
			else
				printf("%c", node->c);
			printf("] %ld\n"RESET, node->frequency);
			return ;
		}
		print_node(node->left);
		print_node(node->right);
	}
}
