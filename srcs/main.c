/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:29:52 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 13:29:56 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "./libft/includes/libft.h"

#define ESC 65307 // C'est le keycode d'ECHAP / ESC. Important pour quitter le programme avec ce dernier.
#define NAME "\112\157\151\156\040\124\150\145\040\120\
\171\164\150\157\156\040\123\151\144\145\041"

typedef struct s_img
{
	int		w; // width
	int		h; // height
	char	*path; // Ici le path de l'image en .xpm (rien d'autre)
	void	*img; // Ce qui va stocker l'adresse de l'image par la mlx
}	t_img;

typedef struct s_data
{
	void	*mlx; // Le pointeur de la mlx
	void	*win; // Le pointeur de la fenêtre
	t_img	*sprite; // Ici d'est la structure d'une image avec le moins de données possibles.
}	t_data;

int	kill_prog(t_data *data)
{
	if (data->sprite) // Si un sprite à été créé, on destroy l'image (leaks) et on free son pointeur
	{
		mlx_destroy_image(data->mlx, data->sprite->img); // Important pour les leaks
		free(data->sprite);
	}
	if (data->win) // Si une fenêtre à été créé, on free
	{
		mlx_destroy_window(data->mlx, data->win); // Détruit la fenêtre (leaks)
		mlx_destroy_display(data->mlx); // Détruit le contenu du pointeur de la mlx
	}
	if (data->mlx)
		free(data->mlx); // free le pointeur de la mlx
	free(data);
	exit (0); // Quitte le programme. Ici il va falloir mettre une variable pour savoir
	// s'il y a eu une erreur ou non, donc 0 sans erreur, 1 si erreur.
	// Vous pouvez vous faire chier à faire un code d'erreur par erreur.
	// Pensez à rajouter un print en cas d'erreur pour dire ce qu'il s'est passé.
}

int	input(int key, t_data *data)
{
	if (key == ESC) // key est envoyé par le key_hook, et on compare key à la touche souhaitée, ici ESC
		kill_prog(data);
	return (1);
}

int	main(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	data->sprite = NULL; // Définition à NULL, important pour le free
	data->mlx = NULL; // Définition à NULL, important pour le free
	data->win = NULL; // Définition à NULL, important pour le free
	data->mlx = mlx_init(); // Fonction pour créer le pointeur de la mlx qui permet tous le reste
	if (!data->mlx)
		return (1);

	data->win = mlx_new_window(data->mlx, 256, 256, NAME); // Crée la fenêtre et la stocke dans la structure.
	// On donne le pointeur de la mlx, ses dimensions, et le nom de la fenêtre.

	data->sprite = ft_calloc(sizeof(t_img), 1);
	data->sprite->path = "./sprites/help.xpm"; // Le path est en brut, pas besoin de le prendre autrement
	data->sprite->img = mlx_xpm_file_to_image(\
		data->mlx, "./sprites/help.xpm", &data->sprite->w, &data->sprite->w); // Cette LONGUE fonction va convertir une image en .xpm
		// vers un format utilisable par la mlx. On donne le pointeur de la mlx, et l'adresse des INTs de sa taille pour qu'il la stocke.

	mlx_put_image_to_window(data->mlx, data->win, data->sprite->img, 64, 64); // Cette fonction va afficher une image.
	// On donne la mlx, la fenêtre, l'image créé par la fonction précédente, et ses coordonnées en partant d'en haut à gauche.

	mlx_key_hook(data->win, &input, data); // Key hook c'est le hook qui va permettre la reconnaissance des keys donc du clavier/souris.
	// input c'est la fonction plus haut qui termine le programme

	mlx_hook(data->win, 17, 1L << 17, &kill_prog, data); // Ici, 17 correspond à DestroyNotify, c'est l'action à faire
	// Et 1L << 17 correspond à StructureNotifyMask qui est la croix en haut à droite
	// kill_prog est ce qui va être exécuté si la croix est cliquée

	mlx_loop(data->mlx); // C'est le hook de base, celui qui va permettre de loop dans tous les hooks précédents
}
