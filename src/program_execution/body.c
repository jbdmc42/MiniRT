#include "minirt.h"

void	print_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	printf("\n\n======== SCENE ========\n\n");
	printf("Ambient:\n-> RATIO: %.1f\n-> R: %i G: %i B: %i",
		data->scene.ambient.ratio, data->scene.ambient.color.r,
		data->scene.ambient.color.g, data->scene.ambient.color.b);
	printf("\n\nCamera:\n-> POSITION: %.1f, %.1f, %.1f\n-> ORIENTATION: %.1f, %.1f, %.1f\n-> FOV: %i\n",
		data->scene.camera.position.x, data->scene.camera.position.y,
		data->scene.camera.position.z, data->scene.camera.orientation.x,
		data->scene.camera.orientation.y, data->scene.camera.orientation.z,
		data->scene.camera.fov);
	printf("\nLight:\n-> POSITION: %.1f, %.1f, %.1f\n-> RATIO: %.1f\n-> R: %i G: %i B: %i",
		data->scene.light.position.x, data->scene.light.position.y,
		data->scene.light.position.z, data->scene.light.ratio,
		data->scene.light.color.r, data->scene.light.color.g,
		data->scene.light.color.b);
	printf("\n\n======= OBJECTS =======\n");
	if (!data->scene.objects)
	{
		printf("No objects allocated (NULL array).\n");
		return ;
	}
	i = 0;
	while (i < data->scene.obj_count)
	{
		if (!data->scene.objects[i].object)
		{
			printf("\nObject %i | NULL Pointer\n", i);
			i++;
			continue ;
		}
		if (data->scene.objects[i].type == 0)
		{
			t_plane *plane = (t_plane *)data->scene.objects[i].object;
			printf("\nObject %i | Plane\n-> POSITION: %.1f, %.1f, %.1f\n-> ORIENTATION: %.1f, %.1f, %.1f\n-> R: %i G: %i B: %i\n",
				i, plane->point.x, plane->point.y, plane->point.z,
				plane->normal.x, plane->normal.y, plane->normal.z,
				plane->color.r, plane->color.g, plane->color.b);
		}
		else if (data->scene.objects[i].type == 1)
		{
			t_sphere *sphere = (t_sphere *)data->scene.objects[i].object;
			printf("\nObject %i | Sphere\n-> POSITION: %.1f, %.1f, %.1f\n-> DIAMETER: %.1f\n-> R: %i G: %i B: %i\n",
				i, sphere->center.x, sphere->center.y, sphere->center.z,
				sphere->diameter, sphere->color.r, sphere->color.g, sphere->color.b);
		}
		else if (data->scene.objects[i].type == 2)
		{
			t_cylinder *cylinder = (t_cylinder *)data->scene.objects[i].object;
			printf("\nObject %i | Cylinder\n-> POSITION: %.1f, %.1f, %.1f\n-> ORIENTATION: %.1f, %.1f, %.1f\n-> DIAMETER: %.1f\n-> HEIGHT: %.1f\n-> R: %i G: %i B: %i\n",
				i, cylinder->center.x, cylinder->center.y, cylinder->center.z,
				cylinder->normal.x, cylinder->normal.y, cylinder->normal.z,
				cylinder->diameter, cylinder->height,
				cylinder->color.r, cylinder->color.g, cylinder->color.b);
		}
		i++;
	}
}

static int	start_event_loop(t_data *data)
{
	(void)data;
	return (S);
}

int		program_execution(char *scene)
{
	t_data	data;

    if (initialize_program(&data))
		return (printf("\n──┬──\n  └─── failed initialization.\n"), E);
	if (parse_scene(&data, scene))
		return (printf("\n──┬──\n  └─── failed to parse the scene.\n"), 1);
	print_data(&data);	// debug purposes only
	if (render_scene(&data))
		return (printf("Error: failed to render the scene.\n"), 1);
	if (start_event_loop(&data))
		return (printf("Error: failed to start event loop.\n"), 1);
	free_objects(&data);
	return (S);
}