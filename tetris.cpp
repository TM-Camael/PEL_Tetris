#include "tetris.h"

//******************************************
// Fonctions déjà écrites (ne pas modifier)
//******************************************

// Affiche un carre la position (x,y) de la grille
// la couleur du carre est alors la numero c
void affiche_carre(Tetris &tetris, int x, int y, int c)
{
	// Verifie que le numero de couleur est valide
	assert(0 <= c and c <= 7);

	// Defini la couleur de dessin
	defini_couleur_dessin(tetris.couleurs[c]);

	int dx = tetris.dx;
	int dy = tetris.dy;
	int tc = tetris.taille_carre;

	// Dessine le carre
	rempli_rectangle(dx + tc * x + 1, dy + tc * y + 1, tc - 2, tc - 2);
}

// Ecrit la valeur v dans la case (x,y) de la grille du puits
void ecrire_position(Puits &puits, int x, int y, int v)
{
	assert(0 <= x and x < puits.largeur and 0 <= y and y < puits.hauteur and 0 <= v and v <= 7);
	puits.grille[x + y * puits.largeur] = v;
}

// Initialisation du tetris
void initialisation_tetris(Tetris &tetris)
{
	tetris.niveau = 1;
	tetris.score = 0;
	tetris.lignes_terminees = 0;

	// Génère les premiers tetraminos
	nouveau_tetramino(tetris);
	nouveau_tetramino(tetris);

	// On remplis la grille de 0
	for (int i = 0; i < tetris.puits.largeur * tetris.puits.hauteur; ++i)
	{
		tetris.puits.grille[i] = 0;
	}
}

// Retourne le contenu de la case (x,y) de la grille
int lire_position(Puits &puits, int x, int y)
{
	assert(0 <= x and x < puits.largeur and 0 <= y and y < puits.hauteur);
	return puits.grille[x + y * puits.largeur];
}

//======================================================================
//                       Fonctions a finir
//======================================================================

//*******************
// Affiche tetramino
//*******************

void affiche_tetramino(Tetris &tetris, Tetramino &t)
{
	//========= Exercice 3 =========
	int x, y, x1, y1, x2, y2, x3, y3;
	x = t.x;
	x1 = x + t.x1;
	x2 = x + t.x2;
	x3 = x + t.x3;
	y = t.y;
	y1 = y + t.y1;
	y2 = y + t.y2;
	y3 = y + t.y3;
	affiche_carre(tetris, x, y, t.forme);
	affiche_carre(tetris, x1, y1, t.forme);
	affiche_carre(tetris, x2, y2, t.forme);
	affiche_carre(tetris, x3, y3, t.forme);
	//==============================
}

//****************
// Affiche tetris
//****************

void affiche_tetris(Tetris &tetris)
{
	efface();

	// Selection la couleur blanche
	defini_couleur_dessin(blanc);

	// Affiche si le jeu est finie
	if (tetris.game_over)
	{
		dessine_texte("Game over !!!", 260, 520);
	}

	// Affiche le nombre de lignes terminees
	dessine_texte("Lignes", 260, 475);
	dessine_texte(to_string(tetris.lignes_terminees), 260, 450);

	// Affiche le niveau
	dessine_texte("Niveau", 260, 400);
	dessine_texte(to_string(tetris.niveau), 260, 375);

	// Affiche le score
	dessine_texte("Score", 260, 325);
	dessine_texte(to_string(tetris.score), 260, 300);

	// Affiche le teramino suivant
	dessine_texte("Suivant", 260, 250);

	// Affiche quitter
	dessine_texte("(Q)uitter", 260, 25);

	int tc = tetris.taille_carre;
	int hp = tetris.puits.hauteur;
	int lp = tetris.puits.largeur;
	int dx = tetris.dx;
	int dy = tetris.dy;
	int lv = tetris.ligne_vie;

	//========= Exercice 1 =========

	dessine_ligne(dx + 0, dy + 0, dx + 0, dy + hp * tc);			 // ligne à gauche
	dessine_ligne(dx + lp * tc, dy + 0, dx + lp * tc, dy + hp * tc); // ligne à droite
	dessine_ligne(dx + 0, dy + 0, dx + lp * tc, dy + 0);			 //ligne du bas
	defini_couleur_dessin(gris);
	dessine_ligne(dx + 0, dy + lv * tc, dx + lp * tc, dy + lv * tc); //ligne de vie
	defini_couleur_dessin(blanc);
	//==============================

	//======== Exercice 12 =========
	for (int i = 0; i < hp; i++)
	{
		for (int j = 0; j < lp; j++)
		{
			cout<<i<<endl;
			cout<<j<<endl;
			if (lire_position(tetris.puits,j,i)!=0)
			{
				affiche_carre(tetris, j, i, lire_position(tetris.puits,j,i));
			}
		}
	}

	//==============================

	if (not tetris.game_over)
	{
		affiche_tetramino(tetris, tetris.prochain_tetramino);
		affiche_tetramino(tetris, tetris.tetramino_courant);
	}
	// Rafraichi la fenêtre
	rafraichissement();
};

//*******************
// Deplace tetramino
//*******************
Tetramino deplace_tetramino(Tetramino &t, int mx, int my)
{

	//========= Exercice 5 =========
	t.x = t.x + mx;
	t.y = t.y + my;
	//==============================
}

//*****************
// Evenement chute
//*****************
bool evenement_chute(Tetris &tetris)
{

	//========= Exercice 9 =========
	Tetramino temp = tetris.tetramino_courant;
	deplace_tetramino(temp, 0, -1);
	if (teste_tetramino(tetris, temp))
	{
		tetris.tetramino_courant = temp;
		return true;
	}
	else
		return false;
	//==============================
}

//***********************
// Evenement deplacement
//***********************
void evenement_deplacement(Tetris &tetris, int direction)
{

	//========= Exercice 8 =========
	Tetramino temp = tetris.tetramino_courant;
	deplace_tetramino(temp, direction, 0);
	if (teste_tetramino(tetris, temp))
	{
		tetris.tetramino_courant = temp;
	}

	//==============================
}

//********************
// Evenement rotation
//********************
void evenement_rotation(Tetris &tetris)
{

	//========= Exercice 11 =========

	Tetramino temp = tetris.tetramino_courant;
	//initialisation_tetramino(temp, tetris.tetramino_courant.forme);
	temp = tourne_tetramino(temp);
	if (teste_tetramino(tetris, temp))
	{
		tetris.tetramino_courant = temp;
	}
	//==============================
}

//**************************
// Initialisation tetramino
//**************************
void initialisation_tetramino(Tetramino &t, int f)
{
	//========= Exercice 2 =========
	if (f == 1)
	{
		t.x1 = -1;
		t.y1 = 0;
		t.x2 = 1;
		t.y2 = 0;
		t.x3 = 2;
		t.y3 = 0;
	}
	else if (f == 2)
	{
		t.x1 = -1;
		t.y1 = 0;
		t.x2 = 1;
		t.y2 = 0;
		t.x3 = 1;
		t.y3 = -1;
	}
	else if (f == 3)
	{
		t.x1 = -1;
		t.y1 = -1;
		t.x2 = -1;
		t.y2 = 0;
		t.x3 = +1;
		t.y3 = 0;
	}
	else if (f == 4)
	{
		t.x1 = -1;
		t.y1 = 0;
		t.x2 = -1;
		t.y2 = 1;
		t.x3 = 0;
		t.y3 = 1;
	}
	else if (f == 5)
	{
		t.x1 = -1;
		t.y1 = -1;
		t.x2 = 0;
		t.y2 = -1;
		t.x3 = 1;
		t.y3 = 0;
	}
	else if (f == 6)
	{
		t.x1 = -1;
		t.y1 = 0;
		t.x2 = 0;
		t.y2 = -1;
		t.x3 = +1;
		t.y3 = 0;
	}
	else if (f == 7)
	{
		t.x1 = -1;
		t.y1 = 0;
		t.x2 = 0;
		t.y2 = -1;
		t.x3 = 1;
		t.y3 = -1;
	}
	else
	{ // error
	}

	//==============================
}

//*******************
// Nouveau tetramino
//*******************
void nouveau_tetramino(Tetris &tetris)
{
	// On tire une forme au hasard
	int f = rand() % 7 + 1;
	Tetramino prochain;
	prochain.forme = f;

	//========= Exercice 4 =========
	tetris.tetramino_courant = tetris.prochain_tetramino;
	tetris.prochain_tetramino = prochain;

	tetris.tetramino_courant.y = tetris.puits.hauteur - 1;
	tetris.tetramino_courant.x = tetris.puits.largeur / 2 - 1;
	initialisation_tetramino(tetris.tetramino_courant, tetris.tetramino_courant.forme);

	tetris.prochain_tetramino.x = (int)(280 / tetris.taille_carre);
	tetris.prochain_tetramino.y = (int)(190 / tetris.taille_carre);
	initialisation_tetramino(tetris.prochain_tetramino, tetris.prochain_tetramino.forme);

	//==============================
}

//*****************
// Teste position
//*****************
bool teste_position(Tetris &tetris, int x, int y)
{

	//========= Exercice 6 =========
	if (0 <= x and x < tetris.puits.largeur and 0 <= y and y < tetris.puits.hauteur and tetris.puits.grille[x + y * tetris.puits.largeur] == 0)
	{
		return true;
	}
	else
		return false;

	//==============================
}

//*****************
// Teste tetramino
//*****************
bool teste_tetramino(Tetris &tetris, Tetramino &t)
{
	int x, y, x1, y1, x2, y2, x3, y3;
	x = t.x;
	x1 = x + t.x1;
	x2 = x + t.x2;
	x3 = x + t.x3;
	y = t.y;
	y1 = y + t.y1;
	y2 = y + t.y2;
	y3 = y + t.y3;

	//========= Exercice 7 =========
	return teste_position(tetris, x, y) and teste_position(tetris, x1, y1) and teste_position(tetris, x2, y2) and teste_position(tetris, x3, y3);
	//==============================
}

//******************
// Tourne tetramino
//******************
Tetramino tourne_tetramino(Tetramino &t)
{
	//========= Exercice 10 =========
	Tetramino temp = t;
	double angle = 90 * M_PI / 180;
	if (temp.forme != 1 or temp.forme != 4)
	{
		if (temp.rotation < 3)
		{
			temp.rotation++;
		}
		else
			temp.rotation = 0;

		int cosval;
		cosval = cos(angle);
		int sinval;
		sinval = sin(angle);

		temp.x1 = t.x1 * cosval - t.y1 * sinval;
		temp.y1 = t.x1 * sinval + t.y1 * cosval;

		temp.x2 = t.x2 * cosval - t.y2 * sinval;
		temp.y2 = t.x2 * sinval + t.y2 * cosval;

		temp.x3 = t.x3 * cosval - t.y3 * sinval;
		temp.y3 = t.y3 * cosval + t.x3 * sinval;
	}
	else if (temp.forme == 1)
	{
		if (temp.rotation == 0 or temp.rotation == 2)
		{
			temp.x1 == 0;
			temp.y1 == -1;
			temp.x2 == 0;
			temp.y2 == 1;
			temp.x3 == 0;
			temp.y3 == 2;
		}
		else
			initialisation_tetramino(temp, temp.forme);
	}

	return temp;
	//===============================
}

//***********************
// Verouillage tetramino
//***********************
void verouillage_tetramino(Tetris &tetris)
{
	Tetramino &t = tetris.tetramino_courant;
	int c = t.forme;
	int x, y, x1, y1, x2, y2, x3, y3;
	x = t.x;
	x1 = x + t.x1;
	x2 = x + t.x2;
	x3 = x + t.x3;
	y = t.y;
	y1 = y + t.y1;
	y2 = y + t.y2;
	y3 = y + t.y3;

	//========= Exercice 12 =========
	ecrire_position(tetris.puits,x,y,t.forme);
	ecrire_position(tetris.puits,x1,y1,t.forme);
	ecrire_position(tetris.puits,x2,y2,t.forme);
	ecrire_position(tetris.puits,x3,y3,t.forme);

	//===============================

	// Plus petite ordonnée d'un carré du tetramino courant
	int ymin=INT32_MAX;

	//========= Exercice 13 =========
	if(y<ymin){
		ymin=y;
	}
	if (y1<ymin)
	{
		ymin=y1;
	}
	if (y2<ymin){
		ymin=y2;
	}
	if (y3<ymin){
		ymin=y3;
	}

	if (ymin>=tetris.ligne_vie){
		tetris.game_over=true;
	}
	else nouveau_tetramino(tetris);

	

	//===============================

	int nombre_lignes_finies = 0;

	//========= Exercice 14 =========

	//===============================
}
