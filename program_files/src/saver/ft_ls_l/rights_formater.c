/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights_formater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 20:38:30 by abellion          #+#    #+#             */
/*   Updated: 2014/12/29 18:10:34 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../libft/includes/libft.h"
#include "../../../ft_ls.h"

char			first_right(mode_t st_mode)
{
	char	right;

	right = '-';
	right = (S_ISDIR(st_mode)) ? 'd' : right;
	right = (S_ISCHR(st_mode)) ? 'c' : right;
	right = (S_ISBLK(st_mode)) ? 'b' : right;
	right = (S_ISFIFO(st_mode)) ? 'p' : right;
	right = (S_ISLNK(st_mode)) ? 'l' : right;
	return (right);
}

char			*format_rights(mode_t st_mode)
{
	char	*rights;
	int		chmod;

	chmod = st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
	rights = ft_strnew(11);
	rights = ft_memset(rights, '-', 10);
	rights[0] = first_right(st_mode);
	rights[1] = (st_mode & S_IRUSR) ? 'r' : rights[1];
	rights[2] = (st_mode & S_IWUSR) ? 'w' : rights[2];
	rights[3] = (st_mode & S_IXUSR) ? 'x' : rights[3];
	rights[3] = (st_mode & S_ISUID) ? 's' : rights[3];
	rights[3] = (st_mode & S_ISUID && !chmod) ? 'S' : rights[3];
	rights[4] = (st_mode & S_IRGRP) ? 'r' : rights[4];
	rights[5] = (st_mode & S_IWGRP) ? 'w' : rights[5];
	rights[6] = (st_mode & S_IXGRP) ? 'x' : rights[6];
	rights[6] = (st_mode & S_ISGID) ? 's' : rights[6];
	rights[6] = (st_mode & S_ISGID && !chmod) ? 'S' : rights[6];
	rights[7] = (st_mode & S_IROTH) ? 'r' : rights[7];
	rights[8] = (st_mode & S_IWOTH) ? 'w' : rights[8];
	rights[9] = (st_mode & S_IXOTH) ? 'x' : rights[9];
	rights[9] = (st_mode & S_ISVTX) ? 't' : rights[9];
	rights[9] = (st_mode & S_ISVTX && !chmod) ? 'T' : rights[9];
	return (rights);
}
