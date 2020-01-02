#include "interface.h"


void initialise_interface(int l,int h){
  // Initialise la SDL
  if(SDL_Init(SDL_INIT_VIDEO)<0){
    cout << "Erreur lors du chargement de la SDL : "<<SDL_GetError()<<endl;
    SDL_Quit();
    return;
  }

  // Specifie la hauteur et la largeur
  largeur=l;
  hauteur=h;

  // Crée la fenêtre et l'afficheur associé
  if(SDL_CreateWindowAndRenderer(l, h, 0, &fenetre, &afficheur)<0){
    cout <<"Erreur lors de la creation de la fenetre SDL : "<<SDL_GetError()<<endl;
    SDL_Quit();
    return;
  }

  // Initialise SDL_TTF pour le rendu de police en TTF
  if(TTF_Init() == -1){
    cout<<"Erreur d'initialisation de SDL_TTF : "<<TTF_GetError()<<endl;
    SDL_Quit();
      return;
  }

  // Spécifie la police
  police=TTF_OpenFont("VeraMono.ttf",20);

  // Efface la fenêtre
  efface();
  rafraichissement();
}

void defini_couleur_dessin(SDL_Colour c){
  couleur_dessin=c;
  SDL_SetRenderDrawColor(afficheur,c.r,c.g,c.b,SDL_ALPHA_OPAQUE);
}

void dessine_ligne(int x1,int y1,int x2,int y2){
  SDL_RenderDrawLine(afficheur,x1,hauteur-y1,x2,hauteur-y2);
}

void dessine_rectangle(int x,int y,int l,int h){
  SDL_Rect rect;
  rect.x=x;
  rect.y=hauteur-y-h;
  rect.w=l;
  rect.h=h;
  SDL_RenderDrawRect(afficheur,&rect);
}

void dessine_texte(string texte,int x,int y){
  // Crée une surface du texte
  SDL_Surface* surface=TTF_RenderText_Shaded(police,texte.c_str(),couleur_dessin,couleur_fond);

  // Affiche erreur si surface non créée
  if(surface==NULL){
    cout<<"Inpossible d'afficher la surface : "<<TTF_GetError()<<endl;
    return;
  }

  // Recupere la heuteur et la largeur de la surface
  int h=surface->h;
  int l=surface->w;
  
  // Crée une texture de la surface
  SDL_Texture* texture = SDL_CreateTextureFromSurface(afficheur,surface);

  // Libère la surface
  SDL_FreeSurface(surface);
  
  // Affiche erreur si texture non créée
  if(texture == NULL){
    cout<<"Inpossible de créer la texture : "<<SDL_GetError()<<endl;
    return;
  }

  // Déterment le rectandle de rendu de la texture
  SDL_Rect dst;
  dst.x=x;
  dst.y=hauteur-y-h;
  dst.w=l;
  dst.h=h;

  // Affiche la texture
  SDL_RenderCopy(afficheur,texture,NULL,&dst);

  // Libère la texture
  SDL_DestroyTexture(texture);
}

void efface(){
  // Choisie la couleur de fond
   SDL_SetRenderDrawColor(afficheur,couleur_fond.r,couleur_fond.g,couleur_fond.b,SDL_ALPHA_OPAQUE);

   // Rempli toute la fenetre
   SDL_RenderClear(afficheur);

   // Choisie la couleur de dessin
   SDL_SetRenderDrawColor(afficheur,couleur_dessin.r,couleur_dessin.g,couleur_dessin.b,SDL_ALPHA_OPAQUE);
}

void ferme_interface(){
  if(afficheur){
    SDL_DestroyRenderer(afficheur);
  }
  if(fenetre){
    SDL_DestroyWindow(fenetre);
  }
  TTF_CloseFont(police);
  TTF_Quit();
  SDL_Quit();
}

void rafraichissement(){
  SDL_RenderPresent(afficheur);
}

void rempli_rectangle(int x,int y,int l,int h){
  SDL_Rect rect;
  rect.x=x;
  rect.y=hauteur-y-h;
  rect.w=l;
  rect.h=h;
  SDL_RenderFillRect(afficheur, &rect);
}






