/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_coding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:41:36 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 15:11:38 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

t_list	**huffman_coding(const unsigned char *text_to_encode);

t_list	**huffman_coding(const unsigned char *text_to_encode)
{
	t_list	**dictionary;
	t_tree	**huffman;

	dictionary = list_new();
	populate_list(dictionary, text_to_encode);
	sort_list_by_frequency(dictionary);
	huffman = convert_list_to_tree(dictionary);
	set_codes_to_dictionary(dictionary, huffman);
	tree_clear(huffman);
	return (dictionary);
}
