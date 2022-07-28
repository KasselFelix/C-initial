# include <stdio.h>

float prixEntree(int nb_ad,int nb_eam5,int nb_se){
	int famille;
	float som=0.0;
	
	while((nb_ad + nb_se)>=2  && nb_eam5>=2){
		if(nb_ad>=2){
			nb_ad-=2;
			if(nb_eam5>=3){
				nb_eam5-=3;
			}else{
				nb_eam5-=2;
			}
			som=57.80;
			famille++;
		}else{
			if(nb_ad + nb_se >= 2 && nb_ad >= 1){
				nb_ad-=1;
				nb_se-=1;
				if(nb_eam5>=3){
					nb_eam5-=3;
				}else{
					nb_eam5-=2;
				}
				som=57.80;
				famille++;
			}else{	
				if(nb_se>=2 && nb_eam5>=3){
					nb_se-=2;
					nb_eam5-=3;
					som=57.80;
					famille++;
				}	
			}
		}
	}	
	som= famille*57.80;
	printf("%d\n",famille );
	return som+nb_ad * 22.7 + nb_eam5* 10.75 + nb_se*17.7;
}

int main(){
	int nb_ad=10,nb_eam5=15, nb_se=2;
	printf("meilleur tarif = %.2f£\n",prixEntree(nb_ad,nb_eam5,nb_se));
	return 0;
}

