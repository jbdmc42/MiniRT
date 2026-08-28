#include "minirt.h"

int	ft_def_atoi(char *line, int *i)
{
	int	val;
	int	sig;

	val = 0;
	sig = 1;
	while (line[*i] == '\t' || line[*i] == ' ' || line[*i] == ',')
		(*i)++;
	while (line[*i] == '+' || line[*i] == '-')
	{
		if (line[*i] == '-')
			sig *= -1;
		(*i)++;
	}
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		val = line[*i] - '0' + val * 10;
		(*i)++;
	}
	return (val * sig);
}
