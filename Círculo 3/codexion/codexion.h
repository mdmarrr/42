/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/06/24 18:58:55 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	long			cooldown_until;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	int				compiles;
	long			last_compile_start;
	pthread_t		thread;
	t_dongle		*left;
	t_dongle		*right;
	struct s_data	*data;
}	t_coder;

typedef struct s_data
{
	int				number_of_coders;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;
	long			time_to_refactor;
	int				number_of_compiles_required;
	long			dongle_cooldown;
	int				scheduler;
	long			start_time;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print_mutex;
	t_dongle		*dongles;
	t_coder			*coders;
}	t_data;

int		init_data(t_data *data, char **argv);
int		init_mutexes(t_data *data);
int		start_simulation(t_data *data);
void	clean_data(t_data *data);
long	get_time_ms(void);
void	print_status(t_coder *coder, char *msg);
int		init_dongles(t_data *data);
int		init_coders(t_data *data);

#endif