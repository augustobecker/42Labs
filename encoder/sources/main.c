/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:54:18 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/10 16:19:05 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

t_data *g_data;

int main(int argc, char **argv)
{
	t_list			**dictionary;
	u_int8_t		*compressed_text;
	unsigned char 	*txt_elem;
	size_t			*frequency;

	if (!arguments_validation(argc, argv))
	{
		printf(HOW_TO_USE);
		return (1);
	}
	set_global_data();
	get_files_content(argc, argv);
	g_data->text = ft_strappend_char(&g_data->text, END_OF_BIT_ARRAY);
	dictionary = huffman_coding(g_data->text);
	txt_elem = parse_dictionary_to_str(dictionary);
	compressed_text = compress_text(dictionary);
	frequency = get_frequency_array(dictionary);
	write_to_shared_memory(txt_elem, strlen((char *)txt_elem));
	write_to_shared_memory(frequency, (strlen((char *)txt_elem) + EXTRA_ELEM_BIT_ARRAY_LEN) * sizeof(size_t));
	write_to_shared_memory(compressed_text, g_data->bit_array_len);
	clear_global_data();
}
