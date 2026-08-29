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

static int	get_objects(t_data *data, const char *scene, int fd)
{
	char	*line;

	if (!line)
		return (E);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 's' && line[1] == 'p')
			data->scene.obj_count++;
		else if (line[0] == 'p' && line[1] == 'l')
			data->scene.obj_count++;
		else if (line[0] == 'c' && line[1] == 'y')
			data->scene.obj_count++;
		free(line);
		line = get_next_line(fd);
	}
	if (!line && data->scene.obj_count == 0)
		return (E);
	data->scene.objects = malloc(sizeof(t_objects) * data->scene.obj_count);
	if (!data->scene.objects)
		return (U);
	return (S);
}

int	parse_scene(t_data *data, const char *scene)
{
	int		fd;
	char	*line;

	fd = open(scene, O_RDONLY);
	if (fd < 0)
		return (printf("Error: file not found."), E);
	if (get_objects(data, scene, fd))
		return (printf("Error: couldn't retrieve objects from file."), E);
	else if (get_objects(data, scene, fd) == U)
		return (printf("Error: couldn't create object array."), E);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(data, line))
		{
			free(line);
			close(fd);
			return (printf("Error: couldn't retrieve line from file."), E);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (S);
}
