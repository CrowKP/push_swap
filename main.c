#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	main(int argc, char *argv[])
{
	if(argc!=2){
		ft_printf("Error\n");
		return(0);
	}
	ft_printf("Hola %s", argv[1]);
}