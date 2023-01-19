/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:05:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 15:01:12 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

bool    is_whitespace(unsigned const char c);
void    print_whitespace(unsigned char whitespace);

bool    is_whitespace(unsigned const char c)
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

void    print_whitespace(unsigned char whitespace)
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

void debugger_find_myself(char *message)
{
    printf("debugger: %s\n", message);
}