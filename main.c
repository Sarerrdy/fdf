/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:46:15 by eina              #+#    #+#             */
/*   Updated: 2026/02/11 13:43:29 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Usuage: ./program <map_file>\n");
        return ;
    } 
    
    if (argv[1] != NULL)
        parse_map(argv[1]);
    else
        ft_printf("Error!: Map cannot be empty\n");
}
