#include "minirt.h"

int	extract_plane(t_data *data, char *line)
{
	int		i;
	int		j;
	t_plane	*plane;

	i = 2;
	j = 0;
	while (j < data->scene.obj_count && data->scene.objects[j].object)
		j++;
	if (j >= data->scene.obj_count)
		return (E);
	data->scene.objects[j].object = malloc(sizeof(t_plane));
	if (!data->scene.objects[j].object)
		return (U);
	plane = (t_plane *)data->scene.objects[j].object;
	plane->point.x = ft_def_atod(line, &i);
	plane->point.y = ft_def_atod(line, &i);
	plane->point.z = ft_def_atod(line, &i);
	plane->normal.x = ft_def_atod(line, &i);
	plane->normal.y = ft_def_atod(line, &i);
	plane->normal.z = ft_def_atod(line, &i);
	plane->color.r = ft_def_atoi(line, &i);
	plane->color.g = ft_def_atoi(line, &i);
	plane->color.b = ft_def_atoi(line, &i);
	data->scene.objects[j].type = 0;
	return (S);
}

int	extract_sphere(t_data *data, char *line)
{
	int			i;
	int			j;
	t_sphere	*sphere;

	i = 2;
	j = 0;
	while (j < data->scene.obj_count && data->scene.objects[j].object)
		j++;
	if (j >= data->scene.obj_count)
		return (E);
	data->scene.objects[j].object = malloc(sizeof(t_sphere));
	if (!data->scene.objects[j].object)
		return (U);
	sphere = (t_sphere *)data->scene.objects[j].object;
	sphere->center.x = ft_def_atod(line, &i);
	sphere->center.y = ft_def_atod(line, &i);
	sphere->center.z = ft_def_atod(line, &i);
	sphere->diameter = ft_def_atod(line, &i);
	sphere->color.r = ft_def_atoi(line, &i);
	sphere->color.g = ft_def_atoi(line, &i);
	sphere->color.b = ft_def_atoi(line, &i);
	data->scene.objects[j].type = 1;
	return (S);
}

int	extract_cylinder(t_data *data, char *line)
{
	int			i;
	int			j;
	t_cylinder	*cylinder;

	i = 2;
	j = 0;
	while (j < data->scene.obj_count && data->scene.objects[j].object)
		j++;
	if (j >= data->scene.obj_count)
		return (E);
	data->scene.objects[j].object = malloc(sizeof(t_cylinder));
	if (!data->scene.objects[j].object)
		return (U);
	cylinder = (t_cylinder *)data->scene.objects[j].object;
	cylinder->center.x = ft_def_atod(line, &i);
	cylinder->center.y = ft_def_atod(line, &i);
	cylinder->center.z = ft_def_atod(line, &i);
	cylinder->normal.x = ft_def_atod(line, &i);
	cylinder->normal.y = ft_def_atod(line, &i);
	cylinder->normal.z = ft_def_atod(line, &i);
	cylinder->diameter = ft_def_atod(line, &i);
	cylinder->height = ft_def_atod(line, &i);
	cylinder->color.r = ft_def_atoi(line, &i);
	cylinder->color.g = ft_def_atoi(line, &i);
	cylinder->color.b = ft_def_atoi(line, &i);
	data->scene.objects[j].type = 2;
	return (S);
}
