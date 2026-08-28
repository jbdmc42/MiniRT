#include "minirt.h"

void	print_data(t_data *data)
{
	printf("Ambient:\n-> RATIO: %f\n-> R: %i\n-> G: %i\n-> B: %i\n",
		data->scene.ambient.ratio, data->scene.ambient.color.r,
		data->scene.ambient.color.g, data->scene.ambient.color.b);
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
	(void)scene;
	if (parse_scene(&data, scene))
		return (printf("\n──┬──\n  └─── failed to parse the scene.\n"), 1);
	print_data(&data);	// debug purposes only
	if (render_scene(&data))
		return (printf("Error: failed to render the scene.\n"), 1);
	if (start_event_loop(&data))
		return (printf("Error: failed to start event loop.\n"), 1);
	return (S);
}