
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int		s;
	int		m;
	long	sol;

	s = 0;
	m = 1;
	sol = 0;
	while (str[s] && (str[s] == '\t' || str[s] == '\r' || str[s] == ' '
			||str[s] == '\f' || str[s] == '\v' || str[s] == '\n'))
		s++;
	if (str[s] == '+' || str[s] == '-')
	{
		if (str[s] == '-')
			m *= -1;
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9')
	{
		sol = (str[s] - '0') + (sol * 10);
		if ((sol * m < -2147483648) || (sol * m > 2147483648))
			return ((sol * m < -2147483648) - 1);
		s++;
	}
	return (sol * m);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
	{
		write(1, "Invalid arguments\n", 18);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
