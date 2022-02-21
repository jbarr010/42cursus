
#include "push_swap.h"
#include <unistd.h>

t_list	*list_parm (char ** argv)
{
	char	**str;
	int	i;
	int	*A;
	t_list	*headA;

	str = ft_split(argv[1], 32);
	i = 0;
	while(str[i])
		i++;
	A = fill_parm(i, str);
	if (check_rep(i, A))
	{
		headA = ft_arrtoparm(i - 1, A);
		return (headA);
	}
	else
	{
		write (1, "Error\n", 6);
		exit(0);
	}
}

t_list	*list_simple(int n, char **argv)
{
	int	*A;
	t_list	*headA;
	
	A = fill_stack(n, argv);
	if(check_rep(n, A))
	{
		headA = ft_arrtolist(n, A);
		return (headA);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}