#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int t;
int a;
int b;
int memo[10000000];
int llena(int num){
    if( memo[num] == 0 ){
        if( num % 2 == 0 ){
            memo[num] = max( llena(num/2), num );
        }else{
            memo[num] = max( llena((num*3)+1), num );
        }
    }
    return memo[num];
}
int main(){
    optimizar_io
    cin>>t;
    int temp = 1;
    while( temp <= 300001 ){
      memo[temp] = temp;
      temp = temp << 1;
    }
    while( t-- ){
        cin>>a;
        cin>>b;
        cout<<a << " "<<llena(b)<<endl;
    }
    return 0;
}
