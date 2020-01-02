#include "tetris.h"

int main()
{
	// Amorce du generateur pseudo-aléatoire
	srand(time(NULL));

	// Creation d'une interface graphique de 450x580
	initialise_interface(450, 580);

	// Creation et initialisation du jeu
	Tetris tetris;
	initialisation_tetris(tetris);

	// Quitter vaudra true si l'utilisateur demande à quitter
	bool quitter = false;

	// Evenement de l'interface
	SDL_Event evenement;

	// Nombre de boucles avant chute
	int nombre_boucles_pour_chute;

	// Nombre de boucles depuis dernière chute
	int nombre_boucles = 0;

	// Teste si la chute du tetramino a ete faite
	bool chute_effectuee = true;

	// Memorise si la vitesse de chute est acceleree
	bool vitesse_chute_acceleree = false;

	// Boucle gérant les événements et l'écoulement du temps

	while (not quitter)
	{
		// On affiche le jeu
		affiche_tetris(tetris);

		nombre_boucles_pour_chute = (21 - tetris.niveau) * 2;
		// Détection d'un événement
		while (SDL_PollEvent(&evenement) != 0)
		{

			// Appuie sur le bouton 'fermer fenêtre'
			if (evenement.type == SDL_QUIT)
			{
				quitter = true;
			}

			// Appuie sur une touche du clavier
			else if (evenement.type == SDL_KEYDOWN)
			{
				// Recuperation des informations sur la touche enfoncée
				SDL_KeyboardEvent evenement_clavier = evenement.key;

				// Detection de la touche enfoncée
				switch (evenement_clavier.keysym.sym)
				{
					// Flêche du haut
				case SDLK_UP:
					if (not tetris.game_over)
					{
						evenement_rotation(tetris);
					}
					break;

					// Flêche de gauche
				case SDLK_LEFT:
					if (not tetris.game_over)
					{
						evenement_deplacement(tetris, -1);
					}
					break;

					// Flêche de droite
				case SDLK_RIGHT:
					if (not tetris.game_over)
					{
						evenement_deplacement(tetris, 1);
					}
					break;

					// Flêche du bas
				case SDLK_DOWN:
					if (not tetris.game_over)
					{
						vitesse_chute_acceleree = true;
					}
					break;

					// Touche Q
				case SDLK_q:
					quitter = true;
					break;

				default:
					break;
				}
			}

			// Relachement d'une touche du clavier
			else if (evenement.type == SDL_KEYUP)
			{
				// Recuperation des informations sur la touche enfoncée
				SDL_KeyboardEvent evenement_clavier = evenement.key;
				switch (evenement_clavier.keysym.sym)
				{
					// Flêche du bas
				case SDLK_DOWN:
					if (not tetris.game_over)
					{
						vitesse_chute_acceleree = false;
					}
					break;
				default:
					break;
				}
			}
		}
		// Declenchement evenement automatique

		if (not tetris.game_over)
		{
			if (chute_effectuee)
			{
				// Le tetramino est entrain de tomber
				if (nombre_boucles >= nombre_boucles_pour_chute or vitesse_chute_acceleree)
				{
					nombre_boucles = 0;
					chute_effectuee = evenement_chute(tetris);
				}
				else
				{
					++nombre_boucles;
					chute_effectuee = evenement_chute(tetris);

				}
			}
			else
			{
				// Le tetramino a fini de tomber
				// On laisse le temps d'une chute/2 avant verouillage

				if (2 * nombre_boucles >= nombre_boucles_pour_chute)
				{
					nombre_boucles = 0;

					// On verouille le tetramino
					verouillage_tetramino(tetris);
					chute_effectuee = true;

					// On supprime l'acceleration de la chute
					vitesse_chute_acceleree = false;
				}
				else
				{
					++nombre_boucles;
				}
			}

			// On attent 20ms avant de recommencer la boucle
			SDL_Delay(100);
		}
		else
		{
			// On attent 10ms avant de recommencer la boucle si game_over
			SDL_Delay(100);
		}
	}
	ferme_interface();
}
