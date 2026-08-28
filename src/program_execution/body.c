#include "minirt.h"

void	print_data(t_data *data)
{
	printf("\n\n======== SCENE ========\n\n");
	printf("Ambient:\n-> RATIO: %.1f\n-> R: %i G: %i B: %i", data->scene.ambient.ratio, data->scene.ambient.color.r, data->scene.ambient.color.g, data->scene.ambient.color.b);
	printf("\n\nCamera:\n-> POSITION: %.1f, %.1f, %.1f\n-> ORIENTATION: %.1f, %.1f, %.1f\n-> FOV: %i\n", data->scene.camera.position.x, data->scene.camera.position.y, data->scene.camera.position.z, data->scene.camera.orientation.x, data->scene.camera.orientation.y, data->scene.camera.orientation.z, data->scene.camera.fov);
	printf("\nLight:\n-> POSITION: %.1f, %.1f, %.1f\n-> RATIO: %.1f\n-> R: %i G: %i B: %i", data->scene.light.position.x, data->scene.light.position.y, data->scene.light.position.z, data->scene.light.ratio, data->scene.light.color.r, data->scene.light.color.g, data->scene.light.color.b);
	printf("\n\n======= OBJECTS =======\n\n");
	printf("Sphere:\n-> POSITION: %.1f, %.1f, %.1f\n-> DIAMETER: %.1f\n-> R: %i G: %i B: %i", data->scene.sphere.center.x, data->scene.sphere.center.y, data->scene.sphere.center.z, data->scene.sphere.diameter, data->scene.sphere.color.r, data->scene.sphere.color.g, data->scene.sphere.color.b);
	printf("\n\nPlane:\n-> POSITION: %.1f, %.1f, %.1f\n-> ORIENTATION: %.1f, %.1f, %.1f\n-> R: %i G: %i B: %i", data->scene.plane.point.x, data->scene.plane.point.y, data->scene.plane.point.z, data->scene.plane.normal.x, data->scene.plane.normal.y, data->scene.plane.normal.z, data->scene.plane.color.r, data->scene.plane.color.g, data->scene.plane.color.b);
	printf("\n\nCylinder:\n-> POSITION: %.1f, %.1f, %.1f\n-> ORIENTATION: %.1f, %.1f, %.1f\n-> DIAMETER: %.1f\n-> HEIGHT: %.1f\n-> R: %i G: %i B: %i", data->scene.cylinder.center.x, data->scene.cylinder.center.y, data->scene.cylinder.center.z, data->scene.cylinder.normal.x, data->scene.cylinder.normal.y, data->scene.cylinder.normal.z, data->scene.cylinder.diameter, data->scene.cylinder.height, data->scene.cylinder.color.r, data->scene.cylinder.color.g, data->scene.cylinder.color.b);
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
	return (S);
}