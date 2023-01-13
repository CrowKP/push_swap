#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"


int *dostack(int argc, int *stack){
    stack = malloc((argc - 1) * sizeof *stack);
	return (stack);
}

int	main(int argc, char *argv[])
{
	int it;
	int	jt;
	int *a;
	int *b;

	it = 0;
	jt = 1;
	a = NULL;
	b = NULL;
	if(argc < 2){
		ft_printf("Error\n");
		return(0);
	}
	a = dostack(argc, a);
	b = dostack(argc, b);
	while (argc > jt){
		a[it] = ft_atoi(argv[jt]);
		ft_printf("%d\n", a[it]);
		it++;
		jt++;
	}
	ft_printf("Done\n");
	return (0);
}
