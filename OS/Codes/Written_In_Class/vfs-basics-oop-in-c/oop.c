#include <stdio.h>
#include <stdlib.h>
typedef struct animal {
	int x;
	void (*talk)(struct animal *);
	void (*me)(struct animal *);
	void (*nothing)();
}animal;
typedef struct tiger {
	animal a;
	int y;
	void (*eat)();
}tiger;
void a_talk(animal *a) {
	a->x = 20;
	printf("Animal Talking\n");
}
void a_me(animal *a) {
	printf("This is animal %d \n", a->x);
}
void a_nothing() {
	printf("Nothing in animal \n");
}
void t_talk(tiger *t) {
	t->a.x = 30;
	t->y = 100;
	printf("Tiger Rouring\n");
}
void t_me(tiger *t) {
	printf("This is tiger %d y = %d \n", t->a.x, t->y);
}
typedef struct cat {
	animal a;
	int z;
}cat;
void c_talk(cat *c) {
	c->a.x = 50;
	c->z = 200; 
	printf("Cat Muttering\n");
}
void c_me(cat *c) {
	printf("This is cat %d z = %d\n", c->a.x, c->z);
}
void animal_init(animal *a) {
	a->talk = a_talk;
	a->me = a_me;
	a->nothing = a_nothing;
}
void tiger_init(tiger *t) {
	t->a.talk = t_talk;
	t->a.me = t_me;
	t->a.nothing = a_nothing;
}
void cat_init(cat *c) {
	c->a.talk = c_talk;
	c->a.me = c_me;
	c->a.nothing = a_nothing;
}
int main() {
	animal *a = (struct animal *)malloc(sizeof(animal));
	tiger *t = (struct tiger *)malloc(sizeof(tiger));
	cat *c = (struct cat *)malloc(sizeof(cat));
	animal_init(a);
	tiger_init(t);
	cat_init(c);
	a->talk(a);
	t->a.talk(t);	
	c->a.talk(c);
	t->a.nothing();
	a = c;
	a->talk(a);
	a->me(a);
	a = t;
	a->talk(a);
	a->me(a);
}

/* 
typedef int youtint;
yourint x, y, z;
tyedef unsigned int uint;
uint p, q;
typedef struct xyz {int x, int y;}xyz;
*/
