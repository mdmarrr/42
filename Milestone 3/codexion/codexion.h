/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:04:16 by magomez-          #+#    #+#             */
/*   Updated: 2026/07/02 20:35:00 by magomez-         ###   ########.fr       */
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

typedef struct s_data		t_data;
typedef struct s_coder		t_coder;
typedef struct s_dongle		t_dongle;
typedef struct s_request	t_request;

typedef struct s_request
{
	t_coder	*coder;
	long	arrival;
	long	deadline;
}	t_request;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	long			cooldown_until;
	int				in_use;
	t_request		*queue;
	int				queue_size;
	int				queue_capacity;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	int				compiles;
	long			last_compile_start;
	pthread_mutex_t	state_mutex;
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
	int				stop;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print_mutex;
	t_dongle		*dongles;
	t_coder			*coders;
	pthread_t		monitor;
	int				dongles_initialized;
	int				coders_initialized;
	int				stop_mutex_initialized;
	int				print_mutex_initialized;
}	t_data;

int		parse_args(t_data *data, char **argv);
int		init_data(t_data *data, char **argv);
int		init_mutexes(t_data *data);
int		init_dongles(t_data *data);
int		init_coders(t_data *data);
int		init_arrays(t_data *data);
int		start_simulation(t_data *data);
void	clean_data(t_data *data);
int		take_dongles(t_coder *coder);
void	drop_dongles(t_coder *coder);
long	get_time_ms(void);
void	print_status(t_coder *coder, char *msg);
void	*coder_routine(void *arg);
void	*monitor_routine(void *arg);
int		get_stop(t_data *data);
void	set_stop(t_data *data, int value);
int		all_finished(t_data *data);
void	smart_sleep(t_data *data, long duration);
void	increment_compiles(t_coder *coder);
int		get_compiles(t_coder *coder);
void	set_last_compile(t_coder *coder, long time);
long	get_last_compile(t_coder *coder);
void	heap_push(t_dongle *dongle, t_request request, int scheduler);
t_request	heap_pop(t_dongle *dongle, int scheduler);

#endif