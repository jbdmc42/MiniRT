#ifndef MINIRT_H
# define MINIRT_H

/* <===================================> */
// Macro Declarations
# define WIDTH 800		// Window/Image width
# define HEIGHT 600		// Window/Image height
# define E 1			// 'Error' return value
# define S 0			// 'Success' return value
# define U -1			// 'Undefined' return value (used for any type of special error that isn't defined)

/* <===================================> */
// Library Declarations

// Main Libraries
# include <unistd.h> 
# include <stdlib.h> 
# include <stdio.h> 
# include <errno.h> 
# include <fcntl.h>
# include <string.h> 
# include <math.h>
# include <sys/time.h>

// MiniLibX
# include "mlx.h"
# include "mlx_int.h"

// Libft
# include "libft.h"

// GetNextLine
# include "get_next_line.h"

/* <===================================> */
// Struct Declarations

// Vector Struct | Used to make vectors for positions, orientations, etc
typedef struct	s_vector 
{
	double	x;
	double	y;
	double	z;
}	t_vector;

// RGB Vector Struct | Used to make vectors for RGB color definition
typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

// MLX Struct | Contains the MLX data
typedef struct  s_mlx
{
    void    *mlxcon;
    void    *window;
    void    *image;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_mlx;

// Camera Struct | Contains the camera data defined by the argument
typedef struct	s_camera
{
    t_vector	position;
	t_vector	orientation;
	double		fov;
}	t_camera;

// Ambient Struct | Contains the ambient data defined by the argument
typedef struct	s_ambient
{
	double	ratio;
	t_rgb	color;	
}	t_ambient;

// Light Struct | Contains the light data defined by the argument
typedef struct	s_light
{
	t_vector	position;
	double		ratio;
	t_rgb		color;
}	t_light;

// Objects
// Sphere Struct | Contains the sphere data defined by the argument
typedef struct	s_sphere
{
	t_vector	center;
	double		diameter;
	t_rgb		color;
}	t_sphere;

// Plane Struct | Contains the plane data defined by the argument
typedef struct	s_plane
{
	t_vector	point;
	t_vector	normal;
	t_rgb		color;
}	t_plane;

// Cylinder Struct | Contains the cylinder data defined by the argument
typedef struct	s_cylinder
{
	t_vector	center;
	t_vector	normal;
	double		diameter;
	double		height;
	t_rgb		color;
}	t_cylinder;

// Scene Struct | Contains the scene data defined by the argument
typedef struct	s_scene
{
	t_ambient	ambient;
	t_light		light;
	t_camera	camera;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_scene;


// Main program struct | Contains all of the programs data
typedef struct	s_data
{
	t_mlx		mlx;
	t_scene		scene;
}	t_data;

/* <===================================> */
// Function Declarations


/* <======== input_validation =========> */
// extension.c:
int		input_validation(char *arg);


/* <======== parser ===================> */
// extract_objs.c:
int	extract_plane(t_data *data, char *line);
int	extract_sphere(t_data *data, char *line);
int	extract_cylinder(t_data *data, char *line);

// extract_scene.c:
int	extract_ambient(t_data *data, char *line);
int	extract_camera(t_data *data, char *line);
int	extract_light(t_data *data, char *line);

// scene_parser.c:
int		parse_scene(t_data *data, const char *scene);


/* <======== program_execution ========> */
// body.c:
int		program_execution(char *arg);

// initialization.c:
int		initialize_program(t_data *data);

// scene_renderer.c:
int		render_scene(t_data *data);


/* <======== tools ====================> */
// ft_def_atod.c:
double	ft_def_atod(char *line, int *i);

// ft_def_atoi.c:
int		ft_def_atoi(char *line, int *i);

/* Notes:
 => in this project, 'double' is used instead of 'int' in some occasions since it helps with 'float' type calculations.
*/
#endif