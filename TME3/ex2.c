#include <math.h>
#include <stdio.h>
#include <time.h>
#include <time.h>
#include <stdlib.h>
int nb_racines(float a, float b, float c){
	
	float delta=b*b-(4*a*c);
	if(delta>0){
		return 2;
	}
	if (delta==0){
		return 1;
	}
	return 0;
}	

int nb_racines_delta(float a, float b, float c,float *disc){
	*disc=b*b-(4*a*c);
	
	if(*disc>0){
		return 2;
	}
	if (*disc==0){
		return 1;
	}
	return 0;
}

int racines(float a, float b, float c,float *disc,float *x1,float *x2, float *x0){
	if (nb_racines_delta(a,b,c,disc)==2){
		*x1=-b-sqrt(*disc)/(2*a);
		*x2=-b+sqrt(*disc)/(2*a);
		return 2;
	}
	if (nb_racines_delta(a,b,c,disc)==0){
		*x0=-b/(2*a);
		return 1;
	}
	return 0;
}

void generation_polynome(){
	int a=-10+rand()%20,b=-10+rand()%21,c=-10+rand()%21;
	if(a>=0){
		a++;
	}
	float disc=0.0;
	float x1=0.0;
	float x2=0.0;
	float x0=0.0;
	printf("%d*x*x + (%d)*x +(%d)\n",a,b,c);
	printf("%d\n",nb_racines(a,b,c));
	racines(a,b,c,&disc,&x1,&x2,&x0);
	printf("x1 %.2f\nx2 %.2f\nx0 %.2f\n",x1,x2,x0);
	
}


int main(){
	srand(time(NULL));
	generation_polynome();
	return 0;
}
