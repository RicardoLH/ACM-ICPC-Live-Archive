#include <stdio.h>
#include <bits/stdc++.h>
#define lld long long int
using namespace std;
struct Point{long long int x,y;};
int n;
int triangles;
Point points[1001];
set<lld> distances[1001];
Point operator -( Point a, Point b){
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
lld sq( lld x ){ return x*x; }
lld distance( Point a){
	printf("El punto es: %d %d\n", a.x,a.y);
	return sq(a.x) + sq(a.y);
}
int main() {
	while( scanf("%d\n", &n) > 0 ){
		triangles = 0;
		for( int i = 0; i < n; i++ ){
			scanf("%d %d\n",&points[i].x, &points[i].y);
		}
		for( int i = 0; i < n; i++ ){
			for( int j = i+1; j < n; j++ ){
				printf("distancia: %d\n",distance(points[i]-points[j]));
				distances[i].insert(distance(points[i]-points[j]));
			}
			/*lld val = -5;
			int counter = 0;
			set<lld>::iterator it;
			for ( it = distances[i].begin(); it != distances[i].end(); it++) {
				printf("El valor es: %d\n",*it);
				if( *it != val ){
					triangles = (counter)*(counter-1)/2;
					val = *it;
					counter = 1;
				}else counter++;
			}*/
			
		}
		if( n > 0 ) printf("%d\n",triangles);
	}
	return 0;
}
