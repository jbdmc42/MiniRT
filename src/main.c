#include "minirt.h"

int		main(int argc, char **argv) 
{
	if (argc != 2)
		return(printf("Invalid argument count. Usage: ./minirt <scene>\n"), E);
	if (!input_validation(argv[1]))
		return (printf("Invalid argument type. Expected 'scene.rt'.\n"), E);
	return (program_execution(argv[1]));
}