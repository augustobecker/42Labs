/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:20:13 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 14:59:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	sort_tree(t_tree **root)
{
	while (true)
	{
		if (!(*root)->next)
				break;
		tree_link_add_back(root, branch_new(*root, (*root)->next));
		tree_remove_first_link(root);
		tree_remove_first_link(root);
	}
}
