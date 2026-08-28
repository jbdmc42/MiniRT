#include "minirt.h"

int	extract_ambient(t_data *data, char *line)
{	
	int	i;

	i = 1;
	data->scene.ambient.ratio = ft_def_atod(line, &i);
	data->scene.ambient.color.r = ft_def_atoi(line, &i);
	data->scene.ambient.color.g = ft_def_atoi(line, &i);
	data->scene.ambient.color.b = ft_def_atoi(line, &i);
	if (!data->scene.ambient.ratio || !data->scene.ambient.color.r
		|| !data->scene.ambient.color.g || !data->scene.ambient.color.b)
		return (printf("Error\n"), E);
	return (S);
}

int	extract_camera(t_data *data, char *line)
{
	(void)data;
	(void)line;
	return (S);
}

int	extract_light(t_data *data, char *line)
{
	(void)data;
	(void)line;
	return (S);
}
