/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:29:52 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 16:00:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../srcs/Libft/libft.h"
# include "../minilibx-linux/mlx.h"

/*
** Key codes for X11 (Linux)
** ESC     : Escape key to exit the game
** KEY_W/Z : Move up (QWERTY/AZERTY)
** KEY_A/Q : Move left (QWERTY/AZERTY)
** KEY_S   : Move down
** KEY_D   : Move right
*/
# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define NAME "Soooooooooooooooooooooooooooooooooooooooooooo long"
# define TILE_SIZE 48
# define SPRITE_FLOOR "../sprites/grass.xpm"
# define SPRITE_WALL "../sprites/obstacle.xpm"
# define SPRITE_COLL "../sprites/collect.xpm"
# define SPRITE_EXIT "../sprites/end.xpm"
# define SPRITE_PLAYER_R "../sprites/player1.xpm"
# define SPRITE_PLAYER_L "../sprites/player2.xpm"

/*
** enum direction
** Used to track player's facing direction for sprite animation
** DOWN  (0) : Player facing down
** UP    (1) : Player facing up
** LEFT  (2) : Player facing left
** RIGHT (3) : Player facing right
*/
enum e_direction
{
	DOWN,
	UP,
	LEFT,
	RIGHT
};

/*
** t_img - Image structure for MLX sprites
** @w     : Width of the image in pixels
** @h     : Height of the image in pixels
** @path  : File path to the XPM image
** @img   : Pointer to MLX image object
*/
typedef struct s_img
{
	int		w;
	int		h;
	char	*path;
	void	*img;
}	t_img;

/*
** t_player - Player data structure
** @pos[2]     : Current position [y, x] on the map
** @coins      : Number of collectibles gathered
** @move_nbr   : Total number of moves made
** @dir        : Current facing direction (LEFT or RIGHT)
** @sprite_r   : Player sprite facing right
** @sprite_l   : Player sprite facing left
*/
typedef struct s_player_data
{
	int		pos[2];
	int		coins;
	int		move_nbr;
	int		dir;
	t_img	*sprite_r;
	t_img	*sprite_l;
}	t_player;

/*
** t_map - Map data structure
** @spawn[2]  : Player spawn position [x, y]
** @p_exit[2] : Exit position [x, y]
** @moves     : Move counter for display
** @collnb    : Total number of collectibles on map
** @width     : Map width in tiles
** @height    : Map height in tiles
** @map       : 2D array of map characters (0, 1, C, E, P)
** @wall      : Wall tile image (1)
** @coll      : Collectible tile image (C)
** @floor     : Floor tile image (0)
** @c_exit    : Closed exit image (E before all C collected)
** @o_exit    : Open exit image (E after all C collected)
*/
typedef struct s_map_data
{
	int		spawn[2];
	int		p_exit[2];
	int		moves;
	int		collnb;
	int		width;
	int		height;
	char	**map;
	t_img	*wall;
	t_img	*coll;
	t_img	*floor;
	t_img	*c_exit;
	t_img	*o_exit;
}	t_map;

/*
** t_data - Main game data structure
** @mlx    : Pointer to MLX connection
** @win    : Pointer to game window
** @map    : Pointer to map data structure
** @player : Pointer to player data structure
*/
typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
}	t_data;

/*
** data_init - Initializes all game data structures
** @data      : Double pointer to main data structure
** @file_name : Path to the map file
** @return    : 1 on success, 0 on failure
*/
int		data_init(t_data **data, char *file_name);

/*
** get_and_parse - Main parsing function, reads and validates the map
** @file_name : Path to the .ber map file
** @return    : 2D array of map on success, NULL on failure
** Validates:
** - File extension (.ber)
** - Map is rectangular
** - Map is surrounded by walls (1)
** - Contains exactly 1 player (P), 1 exit (E), at least 1 collectible (C)
** - Valid path exists from P to E passing through all C
*/
char	**get_and_parse(char *file_name);

/*
** check_empty_line_split - Splits raw map and checks for empty lines
** @raw_map : Raw map string read from file
** @return  : 2D array of map lines, NULL if empty line detected
*/
char	**check_empty_line_split(char *raw_map);

/*
** continue_parsing - Helper to continue reading lines from file
** @line    : Pointer to current line buffer
** @fd      : File descriptor
** @raw_map : Pointer to raw map string being built
*/
void	continue_parsing(char **line, int fd, char **raw_map);

/*
** clone_map - Creates a deep copy of the map for flood fill
** @map    : Original map to clone
** @return : New allocated copy of the map
*/
char	**clone_map(char **map);

/*
** flood_fill - Recursive flood fill algorithm for path validation
** @map : Map to flood fill (modified in place)
** @x   : Starting X coordinate
** @y   : Starting Y coordinate
*/
void	flood_fill(char **map, int x, int y);

/*
** is_border_tile - Checks if a tile is on the border of the map
** @map : 2D map array
** @i   : Row index
** @j   : Column index
** @return : 1 if border, 0 otherwise
*/
int		is_border_tile(char **map, int i, int j);

/*
** find_firstof - Finds first occurrence of a character in map
** @map     : 2D map array
** @to_find : Character to search for
** @pos     : Output array [x, y] to store position
*/
void	find_firstof(char **map, char to_find, int *pos);

/*
** map_width - Calculates the width of the map
** @map    : 2D map array
** @return : Width in tiles (length of first line without newline)
*/
int		map_width(char **map);

/*
** map_height - Calculates the height of the map
** @map    : 2D map array
** @return : Height in tiles (number of lines)
*/
int		map_height(char **map);

/*
** number_of - Counts occurrences of a character in the map
** @map    : 2D map array
** @c      : Character to count
** @return : Number of occurrences
*/
int		number_of(char **map, char c);

/*
** register_move - Registers a player movement
** @data : Main data structure
** @x    : X direction delta (-1, 0, or 1)
** @y    : Y direction delta (-1, 0, or 1)
** Updates player position, handles collectible pickup,
** checks win condition, and increments move counter
*/
void	register_move(t_data *data, int x, int y);

/*
** display_map_elem - Displays a single map element at position
** @data   : Main data structure
** @i      : Row index (Y)
** @j      : Column index (X)
** @player : Whether to draw player sprite (1) or not (0)
*/
void	display_map_elem(t_data *data, int i, int j, int player);

/*
** free_all - Frees all allocated memory in data structure
** @data : Main data structure to free
** Frees map, player, images, MLX resources
*/
void	free_all(t_data *data);

/*
** big_big_free - Frees a 2D char array (map)
** @map : 2D array to free
*/
void	big_big_free(char **map);

/*
** kill_prog - Clean exit handler for the game
** @data   : Main data structure
** @return : 0 (used as MLX hook return value)
** Called on window close or ESC key, frees everything and exits
*/
int		kill_prog(t_data *data);

/*
** put_err - Prints error message and exits program
** @err_mess : Error message to display
** @data     : Data structure to free (can be NULL)
** Prints "Error\n" followed by the message to stderr
** Frees data if not NULL, then exits with status 1
*/
void	put_err(char *err_mess, t_data *data);

/*
** load_sprites - Loads all XPM sprites into memory
** @data : Main data structure
** Loads floor, wall, collectible, exit and player sprites
** Exits with error if any sprite fails to load
*/
void	load_sprites(t_data *data);

/*
** render_map - Renders the entire map to the window
** @data : Main data structure
** Draws all tiles including floor, walls, collectibles,
** exit, and player at their respective positions
*/
void	render_map(t_data *data);

/*
** move_player - Moves the player in the specified direction
** @data : Main data structure
** @dy   : Y direction delta (-1 up, 0 none, 1 down)
** @dx   : X direction delta (-1 left, 0 none, 1 right)
** Checks for walls, collects items, updates position and re-renders
*/
void	move_player(t_data *data, int dy, int dx);

#endif