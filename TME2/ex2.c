#include <cini.h>
#define MAX 800


void carre(int l, int x, int y){
	int i;
	
	for(i=0;i<=l;i++){
		CINI_draw_pixel(i+x,y,"blue");
		CINI_draw_pixel(i+x,y+l,"green");
		CINI_draw_pixel(x,i+y,"red");
		CINI_draw_pixel(l+x,i+y,"black");
		
	}
}

void carres_remontant(int l, int x, int y){
	
	while(x>0 && y>0){
		carre(l,x,y);
		x-=20;
		y-=20;
	}
}
	
	


int main(){
	int d=400;
	CINI_open_window(MAX,MAX,"ex2");
	CINI_fill_window("white");
	carres_remontant(d,MAX/2-d/2,MAX/2-d/2);
	CINI_loop();
	return 0;
}
