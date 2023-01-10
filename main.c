#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	main(int argc, char *argv[])
{
	int it;

	it = 1;
	if(argc < 2){
		ft_printf("Error\n");
		return(0);
	}
	while (it < argc){
		ft_printf("Hola %s\n", argv[it]);
		it++;
	}
	ft_printf("Done\n");
	return (0);
}