typedef struct _cellule_t cellule_t;
struct _cellule_t{
	int donnee;
	cellule_t*suivant;
};

int Sommer(cellule_t *k, cellule_t *f) {
   return k->donnee+f->donnee;
}
int Soustraire(cellule_t *k, cellule_t *f) {
   return k->donnee-f->donnee;
}
