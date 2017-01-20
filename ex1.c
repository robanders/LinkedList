#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
	struct point *next;
};

main(){
	int x, y, loop = 1;
	struct point *current;
	current = malloc(sizeof(struct point));
	
	struct point *root;
	root = malloc(sizeof(struct point));
	root -> x = -999999999; //used to identify root node

	while(loop == 1){
		scanf("%d%d", &x, &y);

		if(x == 0 && y == 0){
			loop = 0; //exit loop
			current -> next = NULL;
		} else {
			struct point *newPoint;
			newPoint = malloc(sizeof(struct point));

			newPoint-> x = x;
			newPoint -> y = y;

			if(root -> x == -999999999){
				root = newPoint;
				current = root;
			} else {
				current -> next = newPoint;
				current = newPoint;
			}
		}
	}

	struct point *newCurrent;
	newCurrent = malloc(sizeof(struct point));
	newCurrent = root;
	int loop2 = 1;

	while(loop2 == 1){		
		printf("%d\n", distance(newCurrent -> x, newCurrent -> y));
			
		if(newCurrent -> next == NULL){
			loop2 = 0;
		} else {
			newCurrent = newCurrent-> next;
		}
	}
}

int distance(int x, int y){//calculate squared distance from origin
	return ((x*x) + (y*y));
}
