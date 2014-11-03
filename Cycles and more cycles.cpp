#include <stdio.h>
#include <string.h>
int t, n, k;
long long int memo[1<<16][16];
long long int cubeta;
int nodos[17];
int matriz[17][17];
int busca(int nodo, int estado, int actual ){
    if( memo[estado][nodo] == 0 ){
		long long int suma = 0;
		for( int i = 0; i < n; i++ ){
		    if( ( matriz[i][nodo] > 0 && (estado&(1<<i)) == 0) ){
		        int bit = cubeta & (1<<i);
				if( bit == 0 ){
					suma += busca(i,estado | (1<<i), actual) % 98765431;
					suma %= 98765431;
				}else if( nodos[actual] == i && actual <k){
					suma += busca(i,estado | (1<<i), actual+1) % 98765431;
					suma %= 98765431;
				}
		    }
		}
		memo[estado][nodo] = suma;
    }
    return memo[estado][nodo];
}

int main(){
    scanf("%d\n",&t);
    while( t-- ){
        memset(memo,0,sizeof(memo));
        memset(matriz,0,sizeof(matriz));
        memset(nodos,0,sizeof(nodos));
        cubeta = 0;
        scanf("%d\n",&n);
        
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                scanf("%d ",&matriz[i][j]);
            }
            scanf("\n");
        }
        scanf("%d\n",&k);
        for( int i = 0; i < k; i++ ){
            scanf("%d",&nodos[i]);
            cubeta |= (1<<(nodos[i]));
        }
        scanf("\n");
        for( int i = 0; i < 16; i++ ){
        	if( matriz[i][nodos[0]] == 1 ){
        		memo[(1<<n)-1][i] = 1;
        	}
        	
        }
        printf("%d\n",busca(nodos[0], (1<<nodos[0]), 1));
    }
    return 0;
}
