#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int n;
struct Point{long long int x,y;};
Point points[1001];
Point operator -(Point a, Point b){
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
priority_queue<long long int> heap;
long long int triangles;
long long int sq(long long int x){ return x*x; }
long long int distance2(Point a){
	return sq(a.x) + sq(a.y);
}
int main(){
    while( scanf("%d\n",&n) > 0){
    	triangles = 0;
    	for( int i = 0; i < n; i++ ) scanf("%lld %lld\n",&points[i].x,&points[i].y);
    	for( int i = 0; i < n; i++ ){
    		for( int j = 0 ;j < n; j++ ){
    			if(j != i) heap.push(distance2(points[i]-points[j]));
    		}
    		long long int val = -1;
    		int counter = 0;
    		while( !heap.empty() ){
    			if( heap.top(); != val ){
    				triangles += (counter*(counter-1))/2;
    				counter = 1;
    				val = heap.top();
    				heap.pop();
    			}else{
    				counter++;
    				heap.pop();
    			}
    		}
    		triangles += (counter*(counter-1))/2;
    	}
    	if(n>0)printf("%lld\n",triangles);
    }
    return 0;
}
