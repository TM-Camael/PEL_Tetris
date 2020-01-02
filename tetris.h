#ifndef TETRIS_HPP
#define TETRIS_HPP

#include <cassert>
#include "interface.h"

//**************
//* Structures *
//**************

//-------
// Puits
//-------

struct Puits{
  // Hauteur du puits
  static const int hauteur=28;

  // Largeur du puits
  static const int largeur=10;

  // Grille décrivant le contenu du puits
  // 0 pour pas de pièce
  // un entier de [1,7] pour le tetramino correspondant
  int grille[hauteur*largeur];
};

//-----------
// Tetramino
//-----------

struct Tetramino{
  // Forme du tetramino
  // 1 pour I, 2 pour J, 3 pour L, 4 pour O
  // 5 pour S, 6 pour T, 7 pour Z
  int forme=0;

  // Rotation du tetramino
  // 0 pour 0°, 1 pour 90°, 2 pour 180°, 3 pour 270°
  int rotation=0; //0->0, 1->90, 2->180, 3->270

  // Position du centre tetramino sur la grille du puits
  int x=0;
  int y=0;
  
  // Position realtive des trois autres carres du tetramino
  int x1=0;
  int y1=0;
  int x2=0;
  int y2=0;
  int x3=0;
  int y3=0;
};

//--------
// Tetris
//--------

struct Tetris{
  // Couleur des tetraminos
  // l'indice 0 correspond à l'absence de tetramino
  const Couleur couleurs[8]={noir,cyan,bleu,orange,jaune,vert,violet,rouge};
  
  // Puits du jeu
  Puits puits;

  // Tetramino en jeu
  Tetramino tetramino_courant;

  // Prochain tetramino en jeu
  Tetramino prochain_tetramino;

  // Decalage x et y pour l'affichage 
  const int dx=10;
  const int dy=10;
  
  // Taille des carrés des tetraminos;
  const int taille_carre=20;
  
  // Ligne de vie du puits
  // Si un teramino est entièrement placée au delà
  // de cette ligne, la partie est perdue
  const int ligne_vie=22;
 
  // Nombre de lignes terminées
  int lignes_terminees;
  
  // Niveau du joueur
  int niveau;

  // Score du joueur
  int score;

  // Partie finie ?
  bool game_over=false;
};

//****************************
// Declaration des fonctions *
//****************************

void affiche_carre(Tetris& tetris,int x,int y,int c);
void affiche_tetramino(Tetris& tetris,Tetramino& t);
void affiche_tetris(Tetris& tetris);
Tetramino deplace_tetramino(Tetramino& t,int mx,int my);
void ecrire_position(Puits& puits,int x,int y,int v);
bool evenement_chute(Tetris& tetris);
void evenement_deplacement(Tetris& tetris,int direction);
void evenement_rotation(Tetris& tetris);
void initialisation_tetris(Tetris& tetris);
void initialisation_tetramino(Tetramino& t,int forme);
int lire_position(Puits& puits,int x,int y);
void nouveau_tetramino(Tetris& tetris);
bool teste_position(Tetris& tertris,int x,int y);
bool teste_tetramino(Tetris& tetris,Tetramino& t);
Tetramino tourne_tetramino(Tetramino& t);
void verouillage_tetramino(Tetris& tetris);

#endif
