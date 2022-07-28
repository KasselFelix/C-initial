#include <cini.h>
#include <stdlib.h>
#include <time.h>
/*#include <SDL/SDL.h>*/
#define HAUTEUR 22
#define LARGEUR 10
#define VIDE -1
#define TAILLE_CASE 20

/* (a completer) */
typedef struct Case{
	int colonne;
	int ligne;
}Case;


typedef struct piece {
	int positionligne;
	int positioncolone;
	Case relativ[4];
	int couleur;
}piece;
	


/*-------------   INSERER ICI LES DEFINITIONS DE TYPES   --------------*/

void afficher_plateau(int plateau[HAUTEUR][LARGEUR],char* color[]){
	CINI_fill_window("black");
	int i,j;
	int l,c,couleur;
	for(i=0;i<HAUTEUR;i++){
		for(j=0;j<LARGEUR;j++){
			if(plateau[i][j]!=VIDE){
				l=i*TAILLE_CASE;
				c=j*TAILLE_CASE;
				couleur=plateau[l][c];
				CINI_fill_rect(l,c,TAILLE_CASE,TAILLE_CASE,color[couleur]);
			}
		}
	}
}



/*-------------------   INSERER ICI LES FONCTIONS   -------------------*/

void initialiser(piece* tetromino,Case tab[4], int indice){
	int i;
	tetromino->positionligne=0;
	tetromino->positioncolone=LARGEUR/2;
	for(i=0;i<4;i++){
		tetromino->relativ[i]=tab[i];
	}
	tetromino->couleur=indice;

}

void afficher_piece(piece tetromino,char* color[]){
	int i;
	int l;
	int c;
	for(i=0;i<4;i++){
		l=(tetromino.positionligne)*TAILLE_CASE;
		c=(tetromino.positioncolone)*TAILLE_CASE;
		CINI_fill_rect();
	}
	
}


/*---------------------------------------------------------------------*/

int main() {
   
   /*---------------------   les declarations   ---------------------*/
   
   int indice;    /* l'indice (type) de la piece jouee */
   int touche;   /* identifie la frappe du joueur */  
   
   piece tetromino; /*piece jouee */
   
	char* color[7]={"green","blue","orange","purple","red","yellow","grey"}; /*couleur indice tetromino*/
	
	
	Case tab_pieces[7][4]={
			{{0, 0}, {0, 1}, {1, 0}, {1, 1}},//O
			{{0, 0}, {0, 1}, {0, 2}, {0, 3}},//I
			{{0, 0}, {0, 1}, {0, 2}, {1, 2}},//L
			{{0, 0}, {1, 0}, {2, 0}, {1, 1}},//T
			{{0, 0}, {1, 0}, {0, 1}, {0, 2}},//J
			{{0, 0}, {1, 0}, {1, 1}, {2, 1}},//Z
			{{0, 0}, {0, 1}, {1, 1}, {1, 2}},//S
			};
	
	int plateau[HAUTEUR][LARGEUR];
	int i,j;
	for(i=0;i<HAUTEUR;i++){
		for(j=0;j<LARGEUR;j++){
			plateau[i][j]=VIDE;
		}
	}
	
	srand(time(NULL));
	indice=rand()%7;
	initialiser(&tetromino,tab_pieces[indice],indice);
	
	
	
	
	CINI_open_window(LARGEUR*TAILLE_CASE,HAUTEUR*TAILLE_CASE,"Plateau");
	afficher_plateau(plateau,color);



   
   CINI_loop();
      
   return 0;
}
