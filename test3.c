#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

# define ESC 27

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	draw_pixels(t_data img, void *mlx, void *mlx_win, int x, int y)
{
	int		bit_x;
	int		bit_y;

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
		return (4);
	bit_y = 0;
	while (bit_y <= 150)
	{
		bit_x = bit_y;
		while (bit_x <= 150)
		{
			my_mlx_pixel_put(&img, bit_x, bit_y, 0x0000FF00);
			bit_x++;
		}
		bit_y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if(!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 900, 600, "so_long");
	if(!vars.win)
		return (2);
	img.img = mlx_new_image(vars.mlx, 900, 600);
	if(!img.img)
		return (3);
	draw_pixels(img, vars.mlx, vars.win, 450, 300);
	mlx_loop(vars.mlx);	
	return (0);
}
