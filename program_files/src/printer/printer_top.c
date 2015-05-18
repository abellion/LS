/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/21 18:28:02 by abellion          #+#    #+#             */
/*   Updated: 2015/01/05 19:06:47 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "../../ft_ls.h"

void	printer_top(t_args *args, t_files_infos *infos)
{
	static int	nb_times;
	static int	error;

	if (!nb_times)
		nb_times = 0;
	if (nb_times || (args && args->files))
		ft_putchar('\n');
	if (args && ((args->dirs->next || args->files) || error || nb_times))
	{
		ft_putstr(args->dirs->content);
		ft_putstr(":\n");
	}
	if (infos && infos->printer)
	{
		ft_putstr("total ");
		ft_putnbr(infos->printer->total_size);
		ft_putchar('\n');
	}
	if (!args && !infos)
		error = 1;
	else if ((ft_strchr(args->options, 'R') && infos)
			|| !ft_strchr(args->options, 'R'))
		nb_times++;
}
