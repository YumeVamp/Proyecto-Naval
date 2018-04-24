/**
*@Name: Jesús Alberto Vázquez Rioja Fatima
*@Date: Abril 11 '18
*[Description] Proyecto Final: Batalla Naval.
**/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define FILAS 10
#define COLUMNAS 10

/**-Guarda los barcos del usuario en un documento csv-
*@param tablero_jugador[][]
*
**/
void guardar_barcos_usuario(int tablero_jugador[][COLUMNAS]){

    FILE * archivo= fopen("barcos usuario.csv", "w");

    int i,j;
    for (i=0; i < FILAS; i++) {

        for (j=0; j < COLUMNAS; j++) {

            fprintf(archivo, "%i,", tablero_jugador[i][j]);
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);


}

void cargar_barcos_usuario(int tablero_jugador[][COLUMNAS]){

    FILE * archivo= fopen("barcos usuario.csv", "r");

    if(archivo==NULL){

        printf("No se encontro una partida guardada\n");
        exit(1);
    }

    int i;
    int j;
     for (i=0; i < FILAS; i++) {

        for (j=0; j < COLUMNAS; j++) {

            fscanf(archivo, "%i,", &tablero_jugador[i][j]);

        }
    }

    fclose(archivo);

}

void ubicar_barcos_usuario(char tablero_jugador[][8]){

    char row;
    scanf("%c", row);

     if (row >= 'a' && row <= 'z') {

            row = row - ('a' - 'A');

                }

                //tablero_jugador[row-'A'][collumn-1] = 1;



}

void inicializar_en_cero(int tablero_jugador[][COLUMNAS]){

    int i;
    int j;
    for(i=0;i<FILAS;i++){

        for(j=0;j<COLUMNAS;j++){

            tablero_jugador[i][j]=0;

        }

    }

}

char imprimir_char(int espacio){

    switch (espacio){

        case 0: return 176;//agua

        case 1: return 178;//barco
}

}

void imprimir_tablero(int tablero_jugador [] [COLUMNAS]) {
//contadores
    int i, j,k;
    system("COLOR 1A");//color

    int espacio;

//CONTADOR RENGLONES

    printf("        ");

    for(k=1;k<11;k++){

        printf("%i ", k);
    }

    printf("\n");

    //CONTADOR RENGLONES
    for (i=0; i<COLUMNAS; i++)
    {
        printf("       %c ", 'A'+i);

        //CONTADOR COLUMNAS
        for (j=0; j<FILAS; j++)
        {

            //IMPRIME LA MATRIZ

            espacio=tablero_jugador[i][j];
            printf("%c ", imprimir_char(espacio));

        }
        //IMPRIME SALTO DE LINEA
        printf("\n");
    }

}

int main(){

    int tablero_jugador[FILAS][COLUMNAS];

    inicializar_en_cero(tablero_jugador);

    cargar_barcos_usuario(tablero_jugador);

    imprimir_tablero(tablero_jugador);


    guardar_barcos_usuario(tablero_jugador);

}
