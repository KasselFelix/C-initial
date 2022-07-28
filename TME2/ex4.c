#include <cini.h>
#define MAX 800
int position(int a, int b, int x, int y){

	if(y > (a*x)+b){
		return 1;
	}else{
		if(y < (a*x)+b){
			return -1;
		}else{
			return 0;
		}
	}	
}

void affiche(int a, int b){
	int x,y;
	for(x=0;x<MAX;x++){
		for(y=0;y<MAX;y++){
			if (position(a,b,x,y)==1){
				CINI_draw_pixel(x,y,"red");
			}else{
				if(position(a,b,x,y)==-1){
					CINI_draw_pixel(x,y,"blue");
				}else{
					if(position(a,b,x,y)==0){
						CINI_draw_pixel(x,y,"black");
					}
				}
			}
		}
	}
}

int main(){
	int a=1,b=0;
	CINI_open_window(MAX,MAX,"ex4");
	affiche(a,b);
	CINI_loop();
	return 0;
}
