/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:39:17 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:59:31 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

t_tree		**root_new(void);
t_tree		*leaf_new(const char c, const size_t frequency);
t_tree		*branch_new(t_tree *left, t_tree *right);
void		tree_clear(t_tree **root);
static void	tree_clear_node(t_tree *node);

t_tree	**root_new(void)
{
	t_tree	**root;

	root = malloc(sizeof(t_tree **));
	if (!root)
		error_msg(MALLOC_ERROR, "root_new");
	*root = NULL;
	return (root);
}

t_tree	*leaf_new(const char c, const size_t frequency)
{
	t_tree	*leaf_node;

	leaf_node = malloc(sizeof(t_tree));
	if (!leaf_node)
		error_msg(MALLOC_ERROR, "leaf_new");
	leaf_node->c = c;
	leaf_node->frequency = frequency;
	leaf_node->left = NULL;
	leaf_node->right = NULL;
	leaf_node->next = NULL;
	leaf_node->prev = NULL;
	return (leaf_node);
}

t_tree	*branch_new(t_tree *left, t_tree *right)
{
	t_tree	*branch_node;

	branch_node = leaf_new(0, 0);
	if (left)
	{
		branch_node->left = left;
		branch_node->left->prev = branch_node;
		branch_node->frequency += left->frequency;
	}
	if (right)
	{
		branch_node->right = right;
		branch_node->right->prev = branch_node;
		branch_node->frequency += right->frequency;
	}
	return (branch_node);
}

void tree_clear(t_tree **root)
{
	tree_clear_node(*root);
	free(root);
}

static void tree_clear_node(t_tree *node)
{
	if (node)
	{
		if (!node->left && !node->right)
		{
			if (node->prev)
				node->prev->next = NULL;
			node->next = NULL;
			free(node);
			return;
		}
		tree_clear_node(node->left);
		tree_clear_node(node->right);
	}
}
