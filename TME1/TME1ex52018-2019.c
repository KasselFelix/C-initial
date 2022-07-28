#include <stdio.h>
#include <math.h>
#include <assert.h>

int discriminant(int a, int b, int c){
    int res;
    res=b*b-4*a*c;

    return res;
}

int afficheRacines(int a, int b, int c){
	
	int delta=discriminant(a,b,c);
	printf("%dx^2 + %dx + %d\n",a,b,c);
    	printf("delta = %d\n",discriminant(a,b,c));
	
	if (delta>0){		
            printf("x1 = %f\n",(-b - sqrt(delta))/(2.0*a));
            printf("x2 = %f\n",(-b + sqrt(delta))/(2.0*a));
            return 0;
  
	}
	else{
		if(delta==0){

			printf("x0= %f\n",-b/(2.0*a));
			return 1;
		}
		else{
			if(delta<0){
		
				printf("pas de solution reelle\n");
				return 2;
			}
		}
	}
	return -1;
}


int main(){
	assert(afficheRacines(4,2,-2)==0);
	assert(afficheRacines(1,2,1)==1);
	assert(afficheRacines(2,2,2)==2);
	return 0;
}


