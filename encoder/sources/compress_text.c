/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:56:16 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 13:51:22 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static unsigned char	*byte_as_bit_compress_to_str(t_list **dictionary, unsigned char *text);
static unsigned char	*get_binary_code(t_list **dictionary, char c);

u_int8_t	*compress_text(t_list **dictionary)
{
	unsigned char		*str_temp;
	u_int8_t			*compressed_text;

	str_temp = byte_as_bit_compress_to_str(dictionary, g_data->text);
	g_data->bit_array_len = strlen((char *)str_temp);
	compressed_text = convert_str_to_bit_array(str_temp);
	return (compressed_text);
}

static unsigned char	*byte_as_bit_compress_to_str(t_list **dictionary, unsigned char *text)
{
	unsigned char	*compressed;
	unsigned char	*code;
	int		i;

	i = 0;
	if (!*dictionary)
		return (NULL);
	compressed = (unsigned char *)strdup("");
	while (text[i])
	{
		code = get_binary_code(dictionary, text[i]);
		compressed = ft_strappend(&compressed, code);
		i++;
	}
	return (compressed);
}

static unsigned char	*get_binary_code(t_list **dictionary, char c)
{
	t_list *ptr_i;

	if (!*dictionary)
		return (NULL);
	ptr_i = *dictionary;
	while (ptr_i)
	{
		if (ptr_i->c == c)
			return(ptr_i->code);
		ptr_i = ptr_i->next;
	}
	return (NULL);
}
