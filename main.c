/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrombez <ncrombez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:34:58 by ncrombez          #+#    #+#             */
/*   Updated: 2024/01/29 19:11:48 by ncrombez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	philosopher(t_philosopher *philo)
{
	while (1)
	{
		write(1, "a", 1);
		usleep(100);
	}
	return (1);
}

int	init_table(t_table *table)
{
	int	i;

	i = 0;
	printf("icit : %i\n", table->rules->nbr_philo);
	//table->forks = ft_calloc(table->rules.nbr_philo, sizeof(pthread_mutex_t));
	if (!table->forks)
		return (write(1, "Wrong calo\n", 11), 0);
	table->table = ft_calloc(table->rules->nbr_philo, sizeof(t_philosopher));
	if (!table->table)
		return (write(1, "Wrong calo2\n", 12), free(table->forks), 0);
	while (i < table->rules->nbr_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (write(1, "Wrong mute\n", 11), free(table->forks), free(table->table), 0);
		table->table[i].close_fork[1] = table->forks[i];
		if (i > 0)
			table->table[i].close_fork[0] = table->forks[i - 1];
		table->table[i].rules = table->rules;
		i++;//on peu le metttre en ++i dans le while
	}
	table->table[0].close_fork[0] = table->forks[i - 1];
	return (1);
}

int	atoi_verif(const char *str, int *error)
{
	int	ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10  + (*str++ - 48);
	if (*str != '\0')
		*error = 1;
	return (ret);
}

int	verif_n_use_args(int ac, char **av, t_rules *rules)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	if (!(ac == 5 || ac == 6))
		return (write(1, "Wrong args\n", 11), 0);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (write(1, "alloc fail\n", 11), 0);
	rules->nbr_philo = atoi_verif(av[i++], &error);
	rules->time_to_die = atoi_verif(av[i++], &error);
	rules->time_to_eat = atoi_verif(av[i++], &error);
	rules->time_to_sleep = atoi_verif(av[i++], &error);
	if (ac == 6)
		rules->number_to_eat = atoi_verif(av[i++], &error);
	if (error)
		return (0);
	printf("icit : %i\n", rules->nbr_philo);
	return (1);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (!verif_n_use_args(ac, av, table.rules))
		return (1);
	printf("icit : %i\n", table.rules->nbr_philo);
	if (!init_table(&table))
		return (write(1, "Init gone wrong\n", 16), 1);
	return (0);
}
