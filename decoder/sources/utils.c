/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:37:16 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 13:27:02 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

size_t			ft_strlcat(unsigned char *dest, const unsigned char *src, size_t dest_size);
size_t			ft_strlcpy(unsigned char *dest, const unsigned char *src, size_t destsize);
unsigned char	*ft_strappend_char(unsigned char **str, const unsigned char c);
unsigned char	*ft_strappend(unsigned char **s1, unsigned const char *s2);
bool    		is_whitespace(char c);
void    		print_whitespace(char whitespace);

unsigned char	*ft_strappend(unsigned char **s1, unsigned const char *s2)
{
	unsigned char	*str;

	if (!s1[0])
		return (NULL);
	if (!s2)
		return (*s1);
	str = calloc((strlen((char *)s1[0]) + strlen((char *)s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1[0], strlen((char *)s1[0]) + 1);
	ft_strlcat(str, s2, strlen((char *)s1[0]) + strlen((char *)s2) + 1);
	free(s1[0]);
	return (str);
}

unsigned char	*ft_strappend_char(unsigned char **str, const unsigned char c)
{
	unsigned char	*new_str;
	int				size_str;

	if (!str[0])
		return (NULL);
	size_str = strlen((char *)str[0]);
	new_str = calloc(size_str + 2, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str[0], size_str + 1);
	new_str[size_str] = c;
	free(str[0]);
	return (new_str);
}

size_t	ft_strlcat(unsigned char *dest, const unsigned char *src, size_t dest_size)
{
	size_t	i;
	size_t	dest_length;
	size_t	src_length;
	size_t	expected_dest_size;

	i = 0;
	dest_length = strlen((char *)dest);
	src_length = strlen(((char *)src));
	if (dest_size > dest_length)
	{
		expected_dest_size = dest_length + src_length;
		while (src[i] && dest_length < dest_size - 1)
			dest[dest_length++] = src[i++];
		dest[dest_length] = 0;
		return (expected_dest_size);
	}
	else
		return (src_length + dest_size);
}

size_t	ft_strlcpy(unsigned char *dest, const unsigned char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize <= 0)
		return (strlen((char *)src));
	while (src[i] && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (strlen((char *)src));
}

bool  is_whitespace(char c)
{
    if ((c == ' ')
    || (c == '\t')
    || (c == '\n')
    || (c == '\v')
    || (c == '\f')
    || (c == '\r'))
        return (true);
    return (false);
}

void    print_whitespace(char whitespace)
{
    switch (whitespace)
    {
        case (' '):
            printf ("%s", "  ");
            return ;
        case ('\t'):
            printf ("%s", "\\t");
            return ;
        case ('\n'):
            printf ("%s", "\\n");
            return ;
        case ('\v'):
            printf ("%s", "\\v");
            return ;
        case ('\f'):
            printf ("%s", "\\f");
            return ;
        case ('\r'):
            printf ("%s", "\\r");
            return ;
        default:
            bad_usage_msg("print_whitespace");
            return ;
    }
}
