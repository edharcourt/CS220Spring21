#include <stdio.h>

typedef struct {
    int x;
    int y; 
} Point;

void print_point(Point p) {
    printf("(%d,%d)\n", p.x, p.y);
}

int main() {

  Point p1;
  Point p2 = { 33, 44 };  
  p1.x = 50;
  p1.y = 90;
  print_point(p1);
  print_point(p2);
}
