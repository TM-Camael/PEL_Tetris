#include "tetris.h"


//******************************************
// Fonctions déjà écrites (ne pas modifier)
//******************************************

// Affiche un carre la position (x,y) de la grille
// la couleur du carre est alors la numero c
void affiche_carre(Tetris& tetris,int x,int y,int c){
  // Verifie que le numero de couleur est valide
  assert(0<=c and c<=7);

  // Defini la couleur de dessin 
  defini_couleur_dessin(tetris.couleurs[c]);

  int dx=tetris.dx;
  int dy=tetris.dy;
  int tc=tetris.taille_carre;
  
  // Dessine le carre
  rempli_rectangle(dx+tc*x+1,dy+tc*y+1,tc-2,tc-2);
}

// Ecrit la valeur v dans la case (x,y) de la grille du puits
void ecrire_position(Puits& puits,int x,int y,int v){
  assert(0<=x and x<puits.largeur and 0<=y and y<puits.hauteur and 0<=v and v<=7);
  puits.grille[x+y*puits.largeur]=v;
}

// Initialisation du tetris
void initialisation_tetris(Tetris& tetris){
  tetris.niveau=1;
  tetris.score=0;
  tetris.lignes_terminees=0;

  // Génère les premiers tetraminos
  nouveau_tetramino(tetris);
  nouveau_tetramino(tetris);


  // On remplis la grille de 0
  for(int i=0;i<tetris.puits.largeur*tetris.puits.hauteur;++i){
    tetris.puits.grille[i]=0;
  }
}

// Retourne le contenu de la case (x,y) de la grille
int lire_position(Puits& puits,int x,int y){
  assert(0<=x and x<puits.largeur and 0<=y and y<puits.hauteur);
  return puits.grille[x+y*puits.largeur];
}

//======================================================================
//                       Fonctions a finir
//======================================================================

//*******************
// Affiche tetramino
//*******************

void affiche_tetramino(Tetris& tetris,Tetramino& t){
  
  //========= Exercice 3 =========
  affiche_carre(tetris,t.x,t.y,1);
  affiche_carre(tetris,t.x1,t.y1,1);
  affiche_carre(tetris,t.x2,t.y2,1);
  affiche_carre(tetris,t.x3,t.y3,1);
  //==============================
  
}

//****************
// Affiche tetris
//****************

void affiche_tetris(Tetris& tetris){
  efface();

  // Selection la couleur blanche
  defini_couleur_dessin(blanc);

  // Affiche si le jeu est finie
  if(tetris.game_over){
    dessine_texte("Game over !!!",260,520);
  }
  
  // Affiche le nombre de lignes terminees
  dessine_texte("Lignes",260,475);
  dessine_texte(to_string(tetris.lignes_terminees),260,450);
  
  // Affiche le niveau
  dessine_texte("Niveau",260,400);
  dessine_texte(to_string(tetris.niveau),260,375);

  // Affiche le score
  dessine_texte("Score",260,325);
  dessine_texte(to_string(tetris.score),260,300);

  // Affiche le teramino suivant
  dessine_texte("Suivant",260,250);

   // Affiche quitter
  dessine_texte("(Q)uitter",260,25);

  int tc=tetris.taille_carre;
  int hp=tetris.puits.hauteur;
  int lp=tetris.puits.largeur;
  int dx=tetris.dx;
  int dy=tetris.dy;
  int lv=tetris.ligne_vie;
  
  
  //========= Exercice 1 =========
  
  dessine_ligne(0,0,0,hp*tc); // ligne à gauche
  dessine_ligne(lp*tc,0,lp*tc,hp*tc); // ligne à droite
  defini_couleur_dessin(gris);
  dessine_ligne(0,lv*tc,lp*tc,lv*tc);
  defini_couleur_dessin(blanc);
  //==============================

  //========= Exercice 3 =========
  // Decommenter puis commenter les ligne suivantes
  /*Tetramino t1,t2,t3,t4,t5,t6,t7;
  t1.x=t2.x=t3.x=t4.x=t5.x=t6.x=t7.x=4;
  t1.y=0;t2.y=4;t3.y=8;t4.y=12;t5.y=16;t6.y=20;t7.y=24;
  initialisation_tetramino(t1,1);
  initialisation_tetramino(t2,2);
  initialisation_tetramino(t3,3);
  initialisation_tetramino(t4,4);
  initialisation_tetramino(t5,5);
  initialisation_tetramino(t6,6);
  initialisation_tetramino(t7,7);
  affiche_tetramino(tetris,t1);
  affiche_tetramino(tetris,t2);
  affiche_tetramino(tetris,t3);
  affiche_tetramino(tetris,t4);
  affiche_tetramino(tetris,t5);
  affiche_tetramino(tetris,t6);
  affiche_tetramino(tetris,t4);*/
  //==============================

  //======== Exercice 12 =========
 
  //==============================
    
  if(not tetris.game_over){
    affiche_tetramino(tetris,tetris.prochain_tetramino);
    affiche_tetramino(tetris,tetris.tetramino_courant);
    deplace_tetramino(tetris.tetramino_courant, 0,-1);
  }
  // Rafraichi la fenêtre
  rafraichissement();
};

//*******************
// Deplace tetramino
//*******************
Tetramino deplace_tetramino(Tetramino& t,int mx,int my){
  
  //========= Exercice 5 =========
  t.x = t.x + mx;
  t.y = t.y + my;
  initialisation_tetramino(t, t.forme);
  //==============================
}

//*****************
// Evenement chute
//*****************
bool evenement_chute(Tetris& tetris){
  
  //========= Exercice 9 =========
 
  //==============================
  
}

//***********************
// Evenement deplacement
//***********************
void evenement_deplacement(Tetris& tetris,int direction){

  //========= Exercice 8 =========
 
  //==============================

}

//********************
// Evenement rotation
//********************
void evenement_rotation(Tetris& tetris){

  //========= Exercice 11 =========
 
  //==============================

}


//**************************
// Initialisation tetramino
//**************************
void initialisation_tetramino(Tetramino& t,int f){
  //========= Exercice 2 =========
  if(f == 1){
    t.x1=t.x-1;
    t.y1=t.y;
    t.x2=t.x+1;
    t.y2=t.y;
    t.x3=t.x+2;
    t.y3=t.y;
  } else if(f == 2){
    t.x1=t.x-1;
    t.y1=t.y;
    t.x2=t.x+1;
    t.y2=t.y;
    t.x3=t.x+1;
    t.y3=t.y-1;
  } else if(f == 3){
    t.x1=t.x-1;
    t.y1=t.y-1;
    t.x2=t.x-1;
    t.y2=t.y;
    t.x3=t.x+1;
    t.y3=t.y;
  } else if(f == 4){
    t.x1=t.x-1;
    t.y1=t.y;
    t.x2=t.x-1;
    t.y2=t.y-1;
    t.x3=t.x;
    t.y3=t.y+1;
  } else if(f == 5){
    t.x1=t.x-1;
    t.y1=t.y-1;
    t.x2=t.x;
    t.y2=t.y-1;
    t.x3=t.x+1;
    t.y3=t.y;
  } else if(f == 6){
    t.x1=t.x-1;
    t.y1=t.y;
    t.x2=t.x;
    t.y2=t.y-1;
    t.x3=t.x+1;
    t.y3=t.y;
  } else if( f == 7){
    t.x1=t.x-1;
    t.y1=t.y;
    t.x2=t.x;
    t.y2=t.y-1;
    t.x3=t.x+1;
    t.y3=t.y-1;
  } else { // error

  }

  //==============================
  
}


//*******************
// Nouveau tetramino
//*******************
void nouveau_tetramino(Tetris& tetris){
  // On tire une forme au hasard
  int f=rand()%7+1;
  Tetramino prochain;
  prochain.forme = f;

  //========= Exercice 4 =========
  tetris.tetramino_courant = tetris.prochain_tetramino;
  tetris.prochain_tetramino = prochain;

  tetris.tetramino_courant.y = tetris.puits.hauteur-1;
  tetris.tetramino_courant.x = tetris.puits.largeur/2-1;
  initialisation_tetramino(tetris.tetramino_courant, tetris.tetramino_courant.forme);

  tetris.prochain_tetramino.x = (int)(280/tetris.taille_carre);
  tetris.prochain_tetramino.y = (int)(190/tetris.taille_carre);
  initialisation_tetramino(tetris.prochain_tetramino, tetris.prochain_tetramino.forme);
  cout<<tetris.tetramino_courant.forme<<endl;
  cout<<tetris.prochain_tetramino.forme<<endl;

  //==============================
  
}

//*****************
// Teste position
//*****************
bool teste_position(Tetris& tetris,int x,int y){

  //========= Exercice 6 =========
 
  //==============================

}


//*****************
// Teste tetramino
//*****************
bool teste_tetramino(Tetris& tetris,Tetramino& t){
  int x,y,x1,y1,x2,y2,x3,y3;
  x=t.x;
  x1=x+t.x1;
  x2=x+t.x2;
  x3=x+t.x3;
  y=t.y;
  y1=y+t.y1;
  y2=y+t.y2;
  y3=y+t.y3;
  
  //========= Exercice 7 =========
 
  //==============================

}

//******************
// Tourne tetramino
//******************
Tetramino tourne_tetramino(Tetramino& t){

  //========= Exercice 10 =========
 
  //===============================
}


//***********************
// Verouillage tetramino 
//***********************
void verouillage_tetramino(Tetris& tetris){
  Tetramino& t=tetris.tetramino_courant;
  int c=t.forme;
  int x,y,x1,y1,x2,y2,x3,y3;
  x=t.x;
  x1=x+t.x1;
  x2=x+t.x2;
  x3=x+t.x3;
  y=t.y;
  y1=y+t.y1;
  y2=y+t.y2;
  y3=y+t.y3;
  
  //========= Exercice 11 =========
  
  //===============================

  //========= Exercice 12 =========

  //===============================

  // Plus petite ordonnée d'un carré du tetramino courant
  int ymin;

  //========= Exercice 13 =========
 
  //===============================

  int nombre_lignes_finies=0;
    
  //========= Exercice 14 =========
 
  //===============================
}
