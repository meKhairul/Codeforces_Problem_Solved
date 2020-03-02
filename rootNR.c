#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) ((x)*(x)*(x)-4*(x)-8.93)
#define fp(x) (3*(x)*(x)-4)
#define EPS 1.0e-9

int main() {
	double a = 2, root;
	int count = 0;
	while(1) {
		count++;
		root = a - (f(a)/fp(a));
		if(fabs(f(root))<EPS) {
			printf("%lf\n",root);
			printf("%d\n",count);
			exit(0);
		}
		a = root;
	}
	return 0;	
}
