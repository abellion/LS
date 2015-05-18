/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_lst_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/21 19:52:35 by abellion          #+#    #+#             */
/*   Updated: 2014/12/29 17:55:42 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

t_printer		*initialize_printer(void)
{
	t_printer	*printer;

	if (!(printer = (t_printer *)malloc(sizeof(*printer))))
		return (0);
	printer->total_size = 0;
	printer->nb_links = 0;
	printer->user_name = 0;
	printer->user_group = 0;
	printer->size = 0;
	printer->dev_values = (unsigned int *)malloc(sizeof(unsigned int *) * 2);
	printer->dev_values[0] = 0;
	printer->dev_values[1] = 0;
	printer->date_day = 0;
	return (printer);
}

void			delete_printer(t_printer **printer)
{
	if (printer)
	{
		if (*printer && (*printer)->dev_values)
			free((*printer)->dev_values);
		free(*printer);
	}
}
