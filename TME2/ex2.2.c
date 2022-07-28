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

void carres_d(int l, int x, int y){
	
	while(x+l<MAX && y+l<MAX ){
		carre(l,x,y);
		x+=20;
		y+=20;
	}
}
	
	


int main(){

	CINI_open_window(MAX,MAX,"ex2");
	CINI_fill_window("white");
	carres_d(100,MAX/2,MAX/2);
	CINI_loop();
	return 0;
}
