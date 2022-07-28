typedef struct cellule_t cellule_t;
struct cellule_t{
	int donnee;
	cellule_t *suivant;
};

int Sommer(cellule_t *k, cellule_t *f);
int Soustraire(cellule_t *k, cellule_t *f);

