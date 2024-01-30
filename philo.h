/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrombez <ncrombez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:36:46 by ncrombez          #+#    #+#             */
/*   Updated: 2024/01/29 19:01:08 by ncrombez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libs/libft/libft.h"

typedef struct s_rules{
	int	nbr_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_to_eat;
}	t_rules;

typedef struct s_philosopher{
	pthread_t	*thread;
	pthread_mutex_t close_fork[2];
	int	time_last_eat;
	int	nbr_eaten;
	t_rules	*rules;	
}	t_philosopher;

typedef struct s_table{
	t_philosopher	*table;
	pthread_mutex_t *forks;
	t_rules *rules;
}	t_table;
