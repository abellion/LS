/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_formater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 19:07:55 by abellion          #+#    #+#             */
/*   Updated: 2015/01/19 14:07:20 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../libft/includes/libft.h"
#include "../../../ft_ls.h"

int		nb_days(char *month)
{
	int		index;
	int		counter;
	int		nb_days;
	char	**m;
	char	**d;

	index = 0;
	counter = 0;
	nb_days = 0;
	m = ft_strsplit("Jan;Feb;Mar;Apr;May;Jun;Jul;Aug;Sep;Oct;Nov;Dec", ';');
	d = ft_strsplit("31;28;31;30;31;30;31;31;30;31;30;31", ';');
	while (ft_strcmp(month, m[index]))
		index++;
	while (counter < 6)
	{
		nb_days += ft_atoi(d[index]);
		index = (index + 1 >= 11) ? 0 : index + 1;
		counter++;
	}
	free(m);
	free(d);
	return (nb_days);
}

char	**format_date(time_t last_update)
{
	char	**split_date;
	char	**date_formated;
	char	*hour_year;
	int		diff_time;

	date_formated = (char **)malloc(sizeof(char **) * 4);
	split_date = ft_strsplit(ctime(&last_update), ' ');
	diff_time = absolute_value(time(NULL) - last_update);
	if (diff_time > ((nb_days(split_date[1]) - 1) * 24 * 3600))
		hour_year = ft_strsub(split_date[4], 0, 4);
	else
		hour_year = ft_strsub(split_date[3], 0, 5);
	date_formated[0] = split_date[2];
	date_formated[1] = split_date[1];
	date_formated[2] = hour_year;
	date_formated[3] = NULL;
	return (date_formated);
}
