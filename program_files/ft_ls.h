/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 20:46:54 by abellion          #+#    #+#             */
/*   Updated: 2015/01/19 14:07:41 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

/*
**Declarations de structures
*/
typedef struct	s_error
{
	int						number;
	char					*details;
}				t_error;

typedef struct	s_args
{
	char					*options;
	t_list					*files;
	t_list					*dirs;
}				t_args;

typedef struct	s_printer
{
	unsigned int			total_size;
	unsigned int			nb_links;
	unsigned int			user_name;
	unsigned int			user_group;
	unsigned int			size;
	unsigned int			*dev_values;
	unsigned int			date_day;
}				t_printer;

typedef struct	s_files_infos
{
	char					*path;
	char					*name;
	char					*linked_name;
	char					*rights;
	int						nb_links;
	char					*user_name;
	char					*user_group;
	long long int			size;
	int						*dev_values;
	char					**date;
	t_printer				*printer;
	struct s_files_infos	*next;
}				t_files_infos;
/*
**Declarations de typedef
*/
typedef t_list	*(*t_insert_type)(t_list *elem, t_list *part);

/*
**Prototypes gestion arguments
*/
int				is_option(char *str);
char			*options_saver(char **args);
t_list			*files_dirs_saver(char **args);
t_error			options_checker(char *options);
int				file_checker(char *path, char *options);
int				dir_checker(char *path, char *options);
t_error			file_dir_checker(char *path, char *options);
void			options_errors_printer(t_error error);
void			files_errors_printer(t_error error);
t_list			*files_dirs_traitment(t_list *files_dirs, char *options);
t_args			*final_args_saver(t_list *files_dirs, char *options);
t_args			*args_controller(char **args);
t_args			*initialize_args(void);
void			delete_args(t_args **args);

/*
**Prototypes algo de tri
*/
t_list			*merge(t_list *part1, t_list *part2, t_insert_type insert);
int				count_links(t_list *lst);
t_list			*merge_sort(t_list *sequence, t_insert_type insert);
t_list			*insert_ascii(t_list *elem, t_list *sequence);
t_list			*sort_by_ascii(t_list *sequence);
t_list			*insert_date(t_list *elem, t_list *sequence);
t_list			*sort_by_date(t_list *sequence);
t_list			*sort_reverse(t_list *sequence);

/*
**Prototypes controlleur
*/
t_files_infos	*saver_lst_new(void);
void			saver_lst_del(t_files_infos **lst);
t_files_infos	*create_files_infos(t_list *lst, char type);
t_files_infos	*dirs_controller(t_args *args);
t_files_infos	*files_controller(t_list **files_name, char *options);
t_list			*sort_options(t_list *files_name, char *options);
t_files_infos	*print_options(t_files_infos *infos, char *options, char type);

/*
**Prototypes saver
*/
t_list			*files_name_saver(char *curent_dir);
void			saver_errors_printer(t_error error);
t_files_infos	*ft_ls_l(t_files_infos *files_infos);
char			*format_rights(mode_t st_mode);
char			**format_date(time_t last_update);
int				nb_days(char *month);
t_files_infos	*ft_ls_a(t_files_infos *files_infos);
void			explorer(t_args *args, char *path);
void			printer(t_list *files_name, t_args *args, char *path);
void			ft_ls_r(t_args *args);

/*
**Prototypes printer
*/
void			printer_controller(t_files_infos *infos, t_args *arguments);
void			spaces(int nb_spaces);
void			printer_ls_l(t_files_infos *infos, t_printer *printer);
unsigned int	nbrlen(int nbr);
void			printer_special(t_files_infos *infos, t_printer *printer);
void			printer_top(t_args *args, t_files_infos *infos);
t_printer		*initialize_printer(void);
void			delete_printer(t_printer **printer);

#endif
