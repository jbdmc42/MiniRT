#include "minirt.h"

void	free_objects(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->scene.obj_count)
	{
		free(data->scene.objects[i].object);
		i++;
	}
	free(data->scene.objects);
}