/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_validations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:19:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/10 00:03:58 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

bool		arguments_validation(int argc, char *const *argv);
static bool	check_arguments_nbr(int argc);
static bool	there_is_any_valid_string(int argc, char *const *argv);
static bool	there_is_any_valid_file(int argc, char *const *argv);

bool	arguments_validation(int argc, char *const *argv)
{
	if (!check_arguments_nbr(argc))
		return (false);
	else if(!there_is_any_valid_string(argc, argv))
		return (false);
	else if(!there_is_any_valid_file(argc, argv))
		return (false);
	return(true);
}

static bool	check_arguments_nbr(int argc)
{
	if (argc < MIN_ARGS_NBR)
		return (false);
	return (true);
}

static bool	there_is_any_valid_string(int argc, char *const *argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0])
			return (true);
		i++;
	}
	return (false);
}

static bool	there_is_any_valid_file(int argc, char *const *argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!access(argv[i], F_OK | R_OK))
			return (true);
		i++;
	}
	return (false);
}
