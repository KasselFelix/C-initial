typedef struct cellule_t cellule_t;
struct cellule_t{
	int donnee;
	cellule_t *suivant;
};

void Afficher_liste_int(cellule_t *liste);
int len(cellule_t* liste);
int Existe(cellule_t *liste,int val);

cellule_t *Creer_cellule(int d);
cellule_t *Inserer_tete(int d, cellule_t *liste);
cellule_t *Inserer_fin_it( int d, cellule_t *liste);
cellule_t *Inserer_en_pos(int d, int pos , cellule_t *liste);
cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2);
cellule_t *Dupliquer_liste(cellule_t *liste);//
cellule_t* Retourner_dernier_element(cellule_t* liste);
cellule_t* Retourner_element_debut(int val, cellule_t *liste);
cellule_t* Retourner_element_fin(int val, cellule_t *liste);
void Modifier_element(int val, int pos,cellule_t* liste);
cellule_t* Liberer_liste(cellule_t* liste);
cellule_t *Supprimer_element_it(int val, cellule_t *liste);
cellule_t *Supprimer_en_pos_it(int pos,cellule_t *liste);//
cellule_t *maximum(cellule_t *liste);
int nb_occurences(int val, cellule_t *liste);
int tous_plus_grand(int val, cellule_t *liste);
int nb_maximum(cellule_t *liste);
int Retourner_val_element_pos(int pos, cellule_t *liste);

cellule_t *Trier_liste_selection( cellule_t *liste);
cellule_t *Eliminer_doublons( cellule_t *liste);
cellule_t *Creer_liste_alea(int val_max, int nb_val );
int listes_identiques(cellule_t *l1, cellule_t *l2);

