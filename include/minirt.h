#ifndef MINIRT_H
# define MINIRT_H

// Main Libraries
# include <unistd.h> 
# include <stdlib.h> 
# include <stdio.h> 
# include <errno.h> 
# include <fcntl.h>
# include <string.h> 
# include <math.h>
# include <sys/time.h>

// MiniLibX
# include "mlx.h"
# include "mlx_int.h"

// Libft
# include "libft.h"

// Struct Declarations

// Function Declarations

// input_validation
// extension.c:
int     input_validation(char *arg);

// program_execution
// window.c:
void    program_execution(char *arg)

#endif