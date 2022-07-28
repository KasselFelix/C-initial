#include <cini.h>
#include <math.h>

void triangles(int l, int h,int eps){
	int xa=0,xb=l-1,xc=l/2,ya=h-1,yb=h-1,yc=0;
	int xap=xa,yap=ya,xbp=xb,ybp=yb,xcp=xc,ycp=yc;
	int d=l-1;
	
	
	while(d>eps){
		CINI_draw_line(xap,yap,xbp,ybp,"red");
		CINI_draw_line(xap,yap,xcp,ycp,"blue");
		CINI_draw_line(xcp,ycp,xbp,ybp,"green");
		xap=(xb+9*xa)/10;
		yap=(yb+9*ya)/10;
		xbp=(xc+9*xb)/10;
		ybp=(yc+9*yb)/10;
		xcp=(xa+9*xc)/10;
		ycp=(ya+9*yc)/10;
		xa=xap+/*(2*pi/3);*/
		ya=yap;
		xb=xbp;
		yb=ybp;
		xc=xcp;
		yc=ycp;
		d=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
	}	

	
}

int main(){
	int l=1200,h=800,eps=1;
	
	CINI_open_window(l,h,"ex4");
	CINI_fill_window("white");
	triangles(l,h,eps);
	
	CINI_loop();
	return 0;
}
