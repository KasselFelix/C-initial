#include <cini.h>
#include <stdio.h>

void diagonale(float x){
	int i;
	
	for(i=0;i<=x;i++){
		CINI_draw_pixel(i,i,"yellow");
	}
}

int main(){
	int x=200;
	CINI_open_window(400,400,"ex1");
	diagonale(x);
	CINI_loop
	return 0;
}
