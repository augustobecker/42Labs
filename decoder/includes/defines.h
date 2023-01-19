/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:05:36 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/09 23:46:34 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define	MORE_SPACE         			1
# define 	BLOCK_SIZE         			(4096 * MORE_SPACE)
# define 	SEM_EMPTY_NAME     			"semempty"
# define 	SEM_FULL_NAME      			"semfull"
# define    FILENAME_MEM_BLOCK          "sample_file.txt"
# define	BITS_IN_A_BYTE				8
# define	WAIT_TO_RECEIVE    			1
# define    EXTRA_ELEM_BIT_ARRAY_LEN    1
# define	BUFFER_SIZE        			50
# define    SECND_TO_MILLISECND        1000
# define    MICRO_TO_MILLISECND        1000
# define    MILLI_TO_MICROSECND        1000
# define	IPC_ERROR          			-1
# define	LEFT						4
# define	RIGHT						5
# define	END_OF_BIT_ARRAY			6
# define    MIN_ARGS_NBR	    		2

# define HOW_TO_SET_MORE_SPACE        \
GREY\
"This program couldn't compress your file due to its size. \
However, you can make a single adjustment and set more space to it.\n\
If it this message continues to be delivered, this file cannot be compressed\
using this program. At least not in this version.\n"\
RESET \
"\n\tInside those files:\n\
\t\t[encoder/includes/defines.h]\n\
\t\t[decoder/includes/defines.h]\n\
\tchange this line of code:\n"\
RED"\t\t# define  "PURPLE"MORE_SPACE\t\t"BLUE"1\n"RESET\
"\tto a larger number, as follows:\n"\
RED"\t\t# define  "PURPLE"MORE_SPACE\t\t"BLUE"4\n"RESET\
"\tAnd try it again.\n\n"

# define HOW_TO_USE        \
GREY\
"This is a file compressor. It works by passing any valid file (or files)\
with this executable.\nIt won't work if no argument\nis passed, if all \
the arguments are NULL or if none of the files passed exists.\n"\
RESET \
"\tencoder : usage: \n\t\t./encoder [an existing text file] [...] \
[extra text files]\n"

# define PINK                       "\033[0;350m"
# define BLACK				        "\033[0;30m"
# define RED				        "\033[0;31m"
# define GREEN				        "\033[0;32m"
# define YELLOW				        "\033[0;33m"
# define BLUE			    	    "\033[0;34m"
# define PURPLE				        "\033[0;35m"
# define CYAN				        "\033[0;36m"
# define WHITE				        "\033[0;37m"
# define GREY				        "\033[0;90m"
# define RESET				        "\033[0m"

#endif
