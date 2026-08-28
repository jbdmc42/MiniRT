#include "minirt.h"

int	extract_ambient(t_data *data, char *line)
{	
	int	i;

	i = 1;
	data->scene.ambient.ratio = ft_def_atod(line, &i);
	data->scene.ambient.color.r = ft_def_atoi(line, &i);
	data->scene.ambient.color.g = ft_def_atoi(line, &i);
	data->scene.ambient.color.b = ft_def_atoi(line, &i);
	return (S);
}

int	extract_camera(t_data *data, char *line)
{
	int	i;

	i = 1;
	data->scene.camera.position.x = ft_def_atod(line, &i);
	data->scene.camera.position.y = ft_def_atod(line, &i);
	data->scene.camera.position.z = ft_def_atod(line, &i);
	data->scene.camera.orientation.x = ft_def_atod(line, &i);
	data->scene.camera.orientation.y = ft_def_atod(line, &i);
	data->scene.camera.orientation.z = ft_def_atod(line, &i);
	data->scene.camera.fov = ft_def_atoi(line, &i);
	return (S);
}

int	extract_light(t_data *data, char *line)
{
	int	i;

	i = 1;
	data->scene.light.position.x = ft_def_atod(line, &i);
	data->scene.light.position.y = ft_def_atod(line, &i);
	data->scene.light.position.z = ft_def_atod(line, &i);
	data->scene.light.ratio = ft_def_atod(line, &i);
	data->scene.light.color.r = ft_def_atoi(line, &i);
	data->scene.light.color.g = ft_def_atoi(line, &i);
	data->scene.light.color.b = ft_def_atoi(line, &i);
	return (S);
}
