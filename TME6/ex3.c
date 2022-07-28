#include <cini.h>
#include <SDL/SDL.h>

#define TAILLE_CASE 20
#define LARGEUR 800 
#define HAUTEUR 800
#define VIDE -1 
/*-------------   INSERER ICI LES DEFINITIONS DE TYPES   --------------*/

typedef struct Case{
	int colonne;
	int ligne;
}Case;


typedef struct Piece{
	Case position;
	int tab[4][2];
	char *couleurs;
}Piece;


/*-------------------   INSERER ICI LES FONCTIONS   -------------------*/
void afficher_plateau(int LARGEUR, int HAUTEUR, char* couleurs[]){
	CINI_fill_window("black");
	
	int i,j;
	Case c; 
	
	for(i=0;i<=LARGEUR-TAILLE_CASE;i+=TAILLE_CASE){
		for(j=0;j<=HAUTEUR-TAILLE_CASE,j+=TAILLE_CASE){
			
			c.ligne=i;
			c.colonne=j;

			if(i=position){
				CINI_draw_pixel(i,j,position.*couleurs);
			}else{
				CINI_draw_pixel(i,j,"black");
			}
			
		}
	}

}



/*---------------------------------------------------------------------*/

int main() {
   
   char* couleurs[7]={"grey","blue","purple","green","pink","orange","yellow"};
   Case tab_pieces[7][4]={
			{{0,0}, {0, 1}, {1, 0}, {1, 1}},//O
			{{0, 0}, {0, 1}, {0, 2}, {0, 3}},//I
			{{0, 0}, {0, 1}, {0, 2}, {1, 2}},//L
			{{0, 0}, {1, 0}, {2, 0}, {1, 1}},//T
			{{0, 0}, {1, 0}, {0, 1}, {0, 2}},//J
			{{0, 0}, {1, 0}, {1, 1}, {2, 1}},//Z
			{{0, 0}, {0, 1}, {1, 1}, {1, 2}},//S
			};

   
   
   int indice;    /* l'indice (type) de la piece jouee */
   int touche;   /* identifie la frappe du joueur */  
	
   /* (a completer) */
   
   /*--------------------  les initialisations  ---------------------*/
   CINI_open_window(LARGEUR,HAUTEUR);
	CINI_fill_window("black");		
   
   srand(time(NULL));
   
   /* (a completer) */

   /*----------------------  ouverture de la fenêtre graphique -------*/

   /* (a completer) */
   
   /*----------------------  la boucle de jeu  ----------------------*/

   do {
      /* afficher_plateau( );*/
      indice = rand()%7;
      /* initialiser( ); */
      /* afficher_piece( ); */
            
      do {
         touche = CINI_loop_until_keyup();
         /* afficher_piece( ); */              /* "efface" la piece en l'affichant en noir ... */
         /* descendre( ); */  
         switch (touche) {
            case SDLK_LEFT:
               /* decaler_gauche( ); */
               break;
            case SDLK_RIGHT:
               /* decaler_droite( ); */
               break;
            case SDLK_d:
               /* rotation_gauche( ); */
               break;
            case SDLK_g:
               /* rotation_droite( ); */
               break;
            /*case SDLK_g:
               hard_drop( ); 
               break; */
            default:
               break;
         }
         /* afficher_piece( ); */   /* ... avant de la reafficher
                                                                  apres modification */
      } while ( (touche != SDLK_DOWN) && (touche != SDLK_ESCAPE) ) ;
            
      /* on supprime les lignes completes si elles existent */
      /* supprimer_lignes( ); */

   } while (touche != SDLK_ESCAPE) ;
   
   CINI_loop();
      
   return 0;
}
