#include "philo.h"

uint64_t	timestamp_in_ms(void)
{
	static uint64_t	start = 0;

	if (start == 0)
		start = gettimeofday_ms();
	return (gettimeofday_ms() - start);
}

static void	eat(t_philo *philo)
{
	philo->eat_count++;
	philo->last_meal = timestamp_in_ms();
	usleep(input->time_to_eat);
}

static void	choose_forks(t_philo *philo, int *fork1, int *fork2)
{
	int	flag;
	t_input *input;

	if (philo->sit % 2)
	{
		if (input->number_of_philos % 2)
			flag = 0;
		else
			flag = 1;
	}
	else
	{
		if (input->number_of_philos % 2)
			flag = 1;
		else
			flag = 0;
	}
	if (flag)
	{
		*fork1 = (philo->sit + 1) % (input->number_of_philos);
		*fork2 = philo->sit;
		return ;
	}
	*fork1 = philo->sit;
	*fork2 = (philo->sit + 1) % (input->number_of_philos);
}

static void	pick_up_forks(t_philo *philo, t_input *input)
{
	int	fork1;
	int	fork2;

	choose_forks(philo, &fork1, &fork2);
	pthread_mutex_lock(philo->forks + fork1);
	pthread_mutex_lock(&philo->t1);
	p_take_1(t_philo *philo);
	pthread_mutex_unlock(&philo->t1);
	pthread_mutex_lock(philo->forks + fork2);
	pthread_mutex_lock(&philo->t1);
	p_take_2(t_philo *philo);
	pthread_mutex_unlock(&philo->t1);
}

static void	let_go_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->forks + ((philo->sit + 1)
			% input->number_of_philos));
	pthread_mutex_unlock(philo->forks + philo->sit);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	while (1)
	{
		pick_up_forks(philo);
		pthread_mutex_lock(&philo->t1);
		p_eat(t_philo *philo);
		pthread_mutex_unlock(&philo->t1);
		eat(philo);
		pthread_mutex_lock(&philo->t1);
		p_sleep(t_philo *philo);
		pthread_mutex_unlock(&philo->t1);
		let_go_forks(philo);
		usleep(philo->conf->t_sleep - 10);
		pthread_mutex_lock(&philo->t1);
		p_think(t_philo *philo);
		pthread_mutex_unlock(&philo->t1);
	}
	return (NULL);
}
