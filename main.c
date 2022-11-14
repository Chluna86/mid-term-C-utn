#include <stdio.h>
#include <stdlib.h>
#define ANIOS 6
#define MESES 13
#define DIAS 31

typedef struct {
    int tempMax;
    int tempMin;
    int senTerm;
}TempAnual;

void funcionCargarVector(TempAnual vector[][MESES][ANIOS]){
    int d, m, a;

    for(a=0;a<ANIOS;a++){
        for(m=0;m<MESES;m++){
            for(d=0;d<DIAS;d++){
                vector[d][m][a].senTerm=0;
                vector[d][m][a].tempMax=0;
                vector[d][m][a].tempMin=1000;
            }
        }
    }
}

void funcionIngreso(TempAnual vector[][MESES][ANIOS]){
    int auxMes, auxDia, auxAnio, control;
    int auxTempMax, auxTempMin,auxSenTerm;

    do{
        printf("Ingrese\nanio ");
        scanf("%d", &auxAnio);
        while(auxAnio<1||auxAnio>ANIOS){
            printf("\t***Anio no valido***\n");
            printf("anio: ");
            scanf("%d", &auxAnio);
        }

        printf("mes: ");
        scanf("%d", &auxMes);
        while(auxMes<1||auxMes>MESES){
            printf("\t***Mes no valido***\n");
            printf("mes: ");
            scanf("%d", &auxMes);
        }

        printf("dia: ");
        scanf("%d", &auxDia);
        while(auxDia<1||auxDia>DIAS){
            printf("\t***dia no valido***\n");
            printf("dia: ");
            scanf("%d", &auxDia);
        }


        printf("maxima: ");
        scanf("%d", &vector[auxDia][auxMes][auxAnio].tempMax);

        printf("minima: ");
        scanf("%d", &vector[auxDia][auxMes][auxAnio].tempMin);

        printf("termica: ");
        scanf("%d", &vector[auxDia][auxMes][auxAnio].senTerm);

        printf("\ningrese -1 para salir, 0 para continetuar ");
        scanf("%d", &control);
    }while(control!=-1);
}

int funcionTempMin(TempAnual vector[][MESES][ANIOS]){
    int setAnio, varMinAnio;

    printf("*** TEMPERATURA MINIMO DE UN ANIO DADO ***\n");
    printf("Ingrese el anio de busqueda: ");
    scanf("%d", &setAnio);

    varMinAnio=vector[1][1][setAnio].tempMin;
    for(int m=1;m<MESES;m++){
        for(int d=1;d<DIAS;d++){
            if(vector[d][m][setAnio].tempMin < varMinAnio){
                varMinAnio=vector[d][m][setAnio].tempMin;
            }
        }
    }
    return varMinAnio;
}

float funcionPromTerm(TempAnual vector[][MESES][ANIOS]){
    int setAnio, setMes;
    float acumSen;

    printf("*** PROMEDIO DE SENSACION TERMICA DE UN MES Y ANIO DADO ***\n");
    printf("Ingrese el anio de busqueda: ");
    scanf("%d", &setAnio);
    printf("Ingrese el mes de busqueda: ");
    scanf("%d", &setMes);

    for(int d=1;d<DIAS;d++){
        acumSen+=vector[d][setMes][setAnio].senTerm;
    }
    return acumSen/DIAS;
}

void funcionMostrar(TempAnual vector[][MESES][ANIOS]){
    int minAnio, a, m, d;

    printf("*** TEMPERATURA MINIMA DE CADA ANIO ***\n");

    /// de cada anio la temperatura minima
    /// el promedio de sensacion termica del mes de mayo de cada anio
    minAnio=vector[1][1][1].tempMin;
    for(a=1;a<ANIOS;a++){
        for(m=1;m<MESES;m++){
            for(d=1;d<DIAS;d++){
                if(vector[d][m][a].tempMin < minAnio){
                    minAnio=vector[d][m][a].tempMin;
                }
            }
        }
        printf("Anio %d la temperatura minima dentro del primer for es: %d\n", a, minAnio);
    }
    printf("Anio %d la temperatura minima fuera del for es: %d\n", a, minAnio);

    for(a=1;a<ANIOS;a++){
        for(d=1;d<DIAS;d++){

            for(d=1;d<DIAS;d++){

            }
        }
    }
}

int menu(){
    int opt;

    printf("*** Menu ***\n");
    printf("1- Cargar datos\n");
    printf("2- Temperatura minima de un anio\n");
    printf("3- Promedio sensacion termica de un mes y anio\n");
    printf("4- Mostrar minima de cada anio y promedio de sensacion termina de Mayo \n");
    printf("0- Salir\n");
    scanf("%d",&opt);
    return opt;
}

int main()
{
    int opcion, minAnio;
    float promSenTerm;
    TempAnual datos[DIAS][MESES][ANIOS];
    funcionCargarVector(datos);

    opcion=menu();

    while (opcion != 0){
        switch(opcion){
        case 1:
            funcionIngreso(datos);
            printf("\n\n");
            break;
        case 2:
            minAnio=funcionTempMin(datos);
            printf("La temperatura minima del anio es: %d",minAnio);
            printf("\n\n");
            break;
        case 3:
            printf("El promedio de sensacion termica del mes y anio es: %.2f\n", funcionPromTerm(datos));
            printf("\n\n");
            break;
        case 4:
            funcionMostrar(datos);;
            printf("\n\n");
            break;
        default:
            printf("*** OPCION INVALIDA ***\n");
        }
        opcion=menu();
    }


    /// mostrar vector cargado
    /*
    for(int a=1;a<ANIOS;a++){
        printf("\n");
        printf("Anio %d\n", a);
        for(int m=1;m<MESES;m++){
            printf("\nMes %d", m);
            printf("\t \tSenterm: TempMax: TempMin:\n");
            for(int d=1;d<DIAS;d++){
                printf("\n");
                printf("Dia %d\t", d);
                printf("\t|   %d \t |   %d\t |   %d   |", datos[d][m][a].senTerm, datos[d][m][a].tempMax, datos[d][m][a].tempMin);
            }
            printf("\n\n");
        }
    }*/

    printf("\n\nFin del programa!\n");
    return 0;
}
