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

int	parse_scene(t_data *data, const char *scene)
{
	int		fd;
	char	*line;

	fd = open(scene, O_RDONLY);
	if (fd < 0)
		return (printf("Error: file not found."), E);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		if (parse_line(data, line))
		{
			free(line);
			close(fd);
			return (printf("Error: could not retrieve line from file."), E);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (S);
}
