#include <stdio.h>

int alternative(int n1, int n2, int n3) {
	int res ;
	if (n1 > 8) {
		res = 3;
	} else {
		if (n3 == 20) {
			res = 2;
		} else {
			if ((n2 >= 10) && (n3 >= 10)) {
				res = 1;
			} else {
				res = 0;
			}
		}
	}
	
	return res;
}

int main(){
	printf("n1=7 n2=9 n3=10 \nres=%d\n",alternative(7,9,10));
	printf("n1=7 n2=15 n3=10 \nres=%d\n",alternative(7,15,10));
	printf("n1=7 n2=15 n3=20 \nres=%d\n",alternative(7,15,20));
	printf("n1=9 n2=15 n3=20 \nres=%d\n",alternative(9,15,20));
		
	
	return 0;
}
