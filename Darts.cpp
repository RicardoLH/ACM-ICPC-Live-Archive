#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int t;
int n;
int radios[11];
long long int puntaje;
int x;
int y;
int sq(int x){ return x*x; }
int opera( int x, int y ){
    int res = 0;
    for( int i = 10; i >= 1; i-- ){
        if( sq(x) + sq(y) <= radios[i] ){
            res = i;
            break;
        }
    }
    return res;
}
int main(){
    optimizar_io
    cin>>t;
    for( int i = 1;i <= 10; i++ ){
        radios[i] = sq(20*(11-i));
    }
    while(t--){
        cin>>n;
        puntaje = 0;
        for( int i = 0; i < n; i++ ){
            cin>>x;
            cin>>y;
            puntaje += opera(x,y);
        }
        cout<<puntaje<<endl;
    }
    return 0;
}
