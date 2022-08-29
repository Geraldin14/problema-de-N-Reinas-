#include <stdio.h>
#include <stdlib.h>

int *creaArreglo(int);
int esValido(int*, int);
int reinas(int*, int, int);
void impTablero(int*, int);

int main (){
    int nReinas;
	printf("Numero de Reinas: ");
	scanf("%i", &nReinas);	
    int * solucion = creaArreglo(nReinas);
    if(reinas(solucion,nReinas, 0))
        impTablero(solucion, nReinas);
    else
        printf("\n\tNo se hallo solucion");
    getchar();
    return 0;
} 

int* creaArreglo(int nReinas){
    int* nuevoArreglo=NULL;
    if((nuevoArreglo=(int*)malloc(sizeof(int)*nReinas))==NULL){
        printf("Sin memoria suficiente\n");
        return NULL;
    }
    return nuevoArreglo;
}

int reinas(int* solucion, int nReinas, int etapa){
    int exito = 0;
    if (etapa < nReinas){
  	    solucion[etapa] = -1;
  	    while(solucion[etapa] < nReinas-1 && !exito){
                solucion[etapa] = solucion[etapa]+1;
                if (esValido(solucion, etapa)){
                    if (etapa < nReinas-1 ) 
                        exito = reinas(solucion, nReinas, etapa+1);
                    else
                        exito = 1;
                }
  	    }
  	    return exito;
	}
    return 0;
}

int esValido(int* solucion, int etapa){
    for (int i = 0; i < etapa; i++){
        if(solucion[i]==solucion[etapa] || abs(solucion[i]-solucion[etapa]) == abs(i-etapa)){
            return 0;
        }
    }
    return 1;
}

void impTablero(int* solucion, int nReinas){
    printf("\n\t**SOLUCION**\n");
    printf("\n  TABLERO:\n");
    for (int i = 0; i < nReinas; i++){
  	    for (int j = 0; j < nReinas; j++){
            if(solucion[j] == i)
                printf(" X");
            else
      	        printf(" =");
        }
  	    printf("\n");
    }

    printf("\n  COORDENADAS:\n");
        for(int i = 0; i < nReinas; i++)
    printf("[ %d, %d] ", i+1, solucion[i]+1 );
        return;
}