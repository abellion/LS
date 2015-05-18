/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:44:07 by abellion          #+#    #+#             */
/*   Updated: 2015/01/19 14:07:01 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

void			printer_special(t_files_infos *infos, t_printer *printer)
{
	if (!printer->dev_values[0] && !printer->dev_values[1])
	{
		spaces(printer->size - nbrlen(infos->size));
		ft_putnbr(infos->size);
	}
	else if (!infos->dev_values)
	{
		spaces(printer->dev_values[0] + 3);
		spaces(printer->dev_values[1] - nbrlen(infos->size));
		ft_putnbr(infos->size);
	}
	else
	{
		spaces(printer->dev_values[0] - nbrlen(infos->dev_values[0]));
		ft_putnbr(infos->dev_values[0]);
		ft_putstr(", ");
		spaces(printer->dev_values[1] - nbrlen(infos->dev_values[1]));
		ft_putnbr(infos->dev_values[1]);
	}
}

void			printer_ls_l(t_files_infos *infos, t_printer *printer)
{
	ft_putstr(infos->rights);
	spaces(printer->nb_links - nbrlen(infos->nb_links) + 2);
	ft_putnbr(infos->nb_links);
	spaces(1);
	ft_putstr(infos->user_name);
	spaces(printer->user_name - ft_strlen(infos->user_name) + 2);
	ft_putstr(infos->user_group);
	spaces(printer->user_group - ft_strlen(infos->user_group) + 2);
	printer_special(infos, printer);
	spaces(1);
	ft_putstr(infos->date[1]);
	if (ft_strlen(infos->date[0]) == 1 && printer->date_day == 1)
		spaces(2);
	else
		spaces(printer->date_day - ft_strlen(infos->date[0]) + 1);
	ft_putstr(infos->date[0]);
	if (ft_strlen(infos->date[2]) == 5)
		spaces(1);
	else
		spaces(2);
	ft_putstr(infos->date[2]);
	spaces(1);
}

void			printer_controller(t_files_infos *infos, t_args *arguments)
{
	t_printer		*printer;
	t_error			error;

	if (!infos)
	{
		error.number = -1;
		error.details = arguments->dirs->content;
		saver_errors_printer(error);
		return ;
	}
	printer = infos->printer;
	while (infos)
	{
		if (ft_strrchr(arguments->options, 'l'))
			printer_ls_l(infos, printer);
		ft_putstr(infos->name);
		if (ft_strlen(infos->linked_name))
		{
			ft_putstr(" -> ");
			ft_putstr(infos->linked_name);
		}
		ft_putchar('\n');
		infos = infos->next;
	}
}
