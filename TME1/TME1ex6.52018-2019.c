#include <stdio.h>

#define TNORMAL 11.4
#define TMOINS14 4.5
#define TMOINS26S 4.9
#define TMOINS26WE 7.90
#define TMATIN 7.10 

float prixPlace(int age, int jour, float heure){
	if (age<14){
		return TMOINS14;
	}else{
		if(age<26 && jour <=5){
			return TMOINS26S;
		}else{
			if (heure<11 && heure>8){
				return TMATIN;
			}else{
				if (age<26){
					return TMOINS26WE;
				}else{
					return TNORMAL;
				}	
			}
		}
	}
}

int main(){
	int age=20;
	int jour=5;
	int heure=19;
	printf("le tarif le plus avantageux est de %f$\n",prixPlace(age,jour,heure));
	return 0;
}
