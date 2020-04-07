#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Point {
	int x;
	int y;

	char* name;
};
typedef struct Point Point;

struct Polygon {
	Point* points;
	int size;
	int capacity;
};
typedef struct Polygon Polygon;

void point_init(Point* p) {
	p->name = NULL;
}

void point_add_name(Point* p, char* name) {
	free(p->name);
	p->name = (char*)malloc(strlen(name));
	strcpy(p->name, name);
}

void polygon_init(Polygon* p) {
	p->size = 0;
	p->capacity = 8;
	p->points = (Point*)malloc(p->capacity * sizeof(Point));
}

void polygon_free(Polygon* p) {
	for (int i = 0; i < p->size; ++i) {
		free(p->points[i].name);
	}
	free(p->points);
	p->points = NULL; // we avoid double free
	p->size = 0;
}

void polygon_push_back(Polygon* pol, Point p) {
	if (pol->size >= pol->capacity) {
		Point* old = pol->points;
		pol->capacity = pol->capacity * 2;
		pol->points = (Point*)malloc(pol->capacity * sizeof(Point));
		for (int i = 0; i < pol->size; ++i) {
			pol->points[i] = old[i];
		}
		free(old);
	}

	// pol->points[pol->size] = p; // copy
	Point* newp = &pol->points[pol->size];
	newp->x = p.x;
	newp->y = p.y;
	// newp->name = p.name; // aliasing
	point_add_name(newp, p.name);
	++pol->size;
}

void polygon_push_back2(Polygon* pol, Point p) {
	if (pol->size >= pol->capacity) {
		pol->capacity = pol->capacity * 2;
		pol->points = (Point*)realloc(pol->points, pol->capacity * sizeof(Point));
	}

	Point* newp = &pol->points[pol->size];
	newp->x = p.x;
	newp->y = p.y;
	// newp->name = p.name; // aliasing
	point_add_name(newp, p.name);
	++pol->size;
}

int main() {
	Polygon pol;
	// pol.size; // refer member with dot, if it's a pointer, refer with ->
	polygon_init(&pol);
	Point p;
	point_init(&p);
	p.x = 1;
	p.y = 3;
	point_add_name(&p, "A");
	polygon_push_back(&pol, p);
	p.x = 8;
	p.y = 6;
	point_add_name(&p, "B");
	polygon_push_back2(&pol, p);
	polygon_push_back2(&pol, p);
	polygon_push_back2(&pol, p);
	free(p.name);


	for (int i = 0; i < pol.size; ++i) {
		printf("%d: (%d, %d): %s\n", i, pol.points[i].x, pol.points[i].y, pol.points[i].name);
	}

	polygon_free(&pol);
	polygon_free(&pol);

	return 0;
}
