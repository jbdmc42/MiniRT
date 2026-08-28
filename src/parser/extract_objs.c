#include "minirt.h"

int	extract_plane(t_data *data, char *line)
{
	int	i;

	i = 2;
	data->scene.plane.point.x = ft_def_atod(line, &i);
	data->scene.plane.point.y = ft_def_atod(line, &i);
	data->scene.plane.point.z = ft_def_atod(line, &i);
	data->scene.plane.normal.x = ft_def_atod(line, &i);
	data->scene.plane.normal.y = ft_def_atod(line, &i);
	data->scene.plane.normal.z = ft_def_atod(line, &i);
	data->scene.plane.color.r = ft_def_atoi(line, &i);
	data->scene.plane.color.g = ft_def_atoi(line, &i);
	data->scene.plane.color.b = ft_def_atoi(line, &i);
	return (S);
}

int	extract_sphere(t_data *data, char *line)
{
	int	i;

	i = 2;
	data->scene.sphere.center.x = ft_def_atod(line, &i);
	data->scene.sphere.center.y = ft_def_atod(line, &i);
	data->scene.sphere.center.z = ft_def_atod(line, &i);
	data->scene.sphere.diameter = ft_def_atod(line, &i);
	data->scene.sphere.color.r = ft_def_atoi(line, &i);
	data->scene.sphere.color.g = ft_def_atoi(line, &i);
	data->scene.sphere.color.b = ft_def_atoi(line, &i);
	return (S);
}

int	extract_cylinder(t_data *data, char *line)
{
	int	i;

	i = 2;
	data->scene.cylinder.center.x = ft_def_atod(line, &i);
	data->scene.cylinder.center.y = ft_def_atod(line, &i);
	data->scene.cylinder.center.z = ft_def_atod(line, &i);
	data->scene.cylinder.normal.x = ft_def_atod(line, &i);
	data->scene.cylinder.normal.y = ft_def_atod(line, &i);
	data->scene.cylinder.normal.z = ft_def_atod(line, &i);
	data->scene.cylinder.diameter = ft_def_atod(line, &i);
	data->scene.cylinder.height = ft_def_atod(line, &i);
	data->scene.cylinder.color.r = ft_def_atoi(line, &i);
	data->scene.cylinder.color.g = ft_def_atoi(line, &i);
	data->scene.cylinder.color.b = ft_def_atoi(line, &i);
	return (S);
}
