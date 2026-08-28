#include "minirt.h"

static int	parse_line(t_data *data, char *line)
{
	int	errflag;

	errflag = S;
	if (!line)
		return (E);
	if (line[0] == 'A' && !errflag)
		errflag = extract_ambient(data, line);
	else if (line[0] == 'C' && !errflag)
		errflag = extract_camera(data, line);
	else if (line[0] == 'L' && !errflag)
		errflag = extract_light(data, line);
	else if (line[0] == 'p' && line[1] == 'l' && !errflag)
		errflag = extract_plane(data, line);
	else if (line[0] == 's' && line[1] == 'p' && !errflag)
		errflag = extract_sphere(data, line);
	else if (line[0] == 'c' && line[1] == 'y' && !errflag)
		errflag = extract_cylinder(data, line);
	else
		return (printf("Error\n"), E);
	/*define_nulls(data);*/
	return (S);
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
