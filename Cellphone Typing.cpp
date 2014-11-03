#include <stdio.h>
#include <string.h>
#define FINP 26
#define COUNT 27
#define REST 28
int palabras;
int trie[30][1000005];
int actual;
int fin;
int total;

int main(){
    char c;
    while(scanf("%d\n",&palabras)>0){
        memset(trie,0,sizeof(trie));
        for( int i = 0; i < palabras; i++ ){
            actual = 0;
            while( (c = getchar()) != '\n'){
                if(c == EOF) break;
                if( trie[c-'a'][actual] == 0 ){
                    trie[c-'a'][actual] = ++fin;
                    trie[COUNT][actual]++;
                }
                actual = trie[c-'a'][actual];
            }
            trie[FINP][actual] = 1;
        }
        total = 0;
        for( int j = 0; j < 26; j++ ){
            if( trie[j][0] != 0 ){
                trie[REST][trie[j][0]] = 1;
            }
        }
        for( int i = 1; i <= fin; i++ ){
            for( int j = 0; j< 26; j++ ){
                if( trie[j][i] != 0 ){
                    if( trie[COUNT][i] == 1 ){
                        if( trie[FINP][i] == 1 ){
                            trie[REST][trie[j][i]] = trie[REST][i] + 1;
                        }else{
                            trie[REST][trie[j][i]] = trie[REST][i];
                        }
                    }else if( trie[COUNT][i] > 1 ){
                        trie[REST][trie[j][i]] = trie[REST][i] + 1;
                    }
                }

            }
            if( trie[FINP][i] == 1 ) total += trie[REST][i];

        }
        printf("%.2f\n",(total/(float)palabras));

    }
    return 0;
}
