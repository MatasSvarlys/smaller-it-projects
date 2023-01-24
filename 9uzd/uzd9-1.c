#include <stdio.h>
#include <math.h>

struct Point{
    double x, y;
};

typedef struct Point Point;

void printPoint(Point p){
    printf("(%.2f, %.2f) ", p.x, p.y);
}

Point createPoint(double x, double y){
    Point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

double getDistance(Point a, Point b){
    double x, y;
    double distance;
    
    x = a.x - b.x;
    y = a.y - b.y;

    distance = sqrt(pow(x, 2) + pow(y, 2));

    printf("%.2f\n", distance);

    return distance;

}

int main(){
    Point p1, p2;
    // p1.x = 2;
    // p1.y = -3;
    // p2.x = -4;
    // p2.y = 5;

    p1 = createPoint(2, -3);
    p2 = createPoint(-4, 5);

    printPoint(p1);
    printPoint(p2);

    getDistance(createPoint(2, -3), createPoint(-4, 5));
}