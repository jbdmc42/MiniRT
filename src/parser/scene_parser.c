#include "minirt.h"

static int	parse_line(t_data *data, char *line)
{
	if (!line)
		return (E);
	if (line[0] == 'A')
		return (extract_ambient(data, line));
	else if (line[0] == 'C')
		return (extract_camera(data, line));
	else if (line[0] == 'L')
		return (extract_light(data, line));
	else if (line[0] == 'p' && line[1] == 'l')
		return (extract_plane(data, line));
	else if (line[0] == 's' && line[1] == 'p')
		return (extract_sphere(data, line));
	else if (line[0] == 'c' && line[1] == 'y')
		return (extract_cylinder(data, line));
	return (E);
}

static int	get_objects(t_data *data, const char *scene)
{
	char	*line;
	int		fd;

	fd = open(scene, O_RDONLY);
	if (fd < 0)
		return (E);
	while ((line = get_next_line(fd)))
	{
		if (line[0] == 's' && line[1] == 'p')
			data->scene.obj_count++;
		else if (line[0] == 'p' && line[1] == 'l')
			data->scene.obj_count++;
		else if (line[0] == 'c' && line[1] == 'y')
			data->scene.obj_count++;
		free(line);
	}
	if (data->scene.obj_count == 0)
		return (close(fd), S);
	data->scene.objects = malloc(sizeof(t_objects) * data->scene.obj_count);
	if (!data->scene.objects)
		return (close(fd), U);
	ft_memset(data->scene.objects, 0, 
		sizeof(t_objects) * data->scene.obj_count);
	return (close(fd), S);
}

int	parse_scene(t_data *data, const char *scene)
{
	int		fd;
	char	*line;
	int		err;

	err = get_objects(data, scene);
	if (err == E)
		return (printf("Error: couldn't retrieve objects from file."), E);
	else if (err == U)
		return (printf("Error: couldn't create object array."), E);
	fd = open(scene, O_RDONLY);
	if (fd < 0)
		return (printf("Error: file not found."), E);
	while ((line = get_next_line(fd)))
	{
		err = parse_line(data, line);
		if (err == E)
			return (free(line), close(fd), 
				printf("Error: couldn't retrieve line from file."), E);
		else if (err == U)
			return (free(line), close(fd), printf("Error: malloc error."), E);
		free(line);
	}
	return (close(fd), S);
}
