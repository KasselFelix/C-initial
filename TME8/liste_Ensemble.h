
cellule_t* liste_vers_ensemble(cellule_t* liste);
int Est_un_ensemble_it(cellule_t *liste);
int Est_un_ensemble_rec(cellule_t *liste);

cellule_t* union_E_rec(cellule_t *l1, cellule_t *l2);
cellule_t* union_E_it(cellule_t *l1, cellule_t *l2);

cellule_t* inter_E_rec(cellule_t* l1, cellule_t* l2);
cellule_t* inter_E_it(cellule_t* l1, cellule_t* l2);

cellule_t* soustraction_E(cellule_t* l1, cellule_t* l2);
cellule_t* soustraction_E_it_efficace(cellule_t* l1, cellule_t* l2);
cellule_t* soustraction_E_rec(cellule_t* l1, cellule_t* l2);

cellule_t* xor_E(cellule_t* l1, cellule_t* l2);
cellule_t* xor_E_efficace_it(cellule_t* l1, cellule_t* l2);
cellule_t* xor_E_efficace_rec(cellule_t* l1, cellule_t* l2);

int inclusion_E(cellule_t* l1, cellule_t* l2);
int inclusion_E_efficace_it(cellule_t* l1, cellule_t* l2);
int inclusion_E_rec(cellule_t* l1, cellule_t* l2);

int identique_E(cellule_t* l1, cellule_t* l2);


