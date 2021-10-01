//Jesús Huerta Aguilar, Javier de La Luz Ruiz, Ernesto Flores Cesareo
//Programación I - "Programa: Ordenamiento burbuja,inserción y selección"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
//PROTOTIPOS
void menu(int *);
void nom(int);
void size(int *,int);
void lect(int [],int,int);
void impr(int [],int);
void burbu(int [],int);
void indi(int [],int);
void direct(int [],int);
void casos(int ,int [],int);
void salida(char *,int);
//PRINCIPAL
int main(){
    int *a,tam,op;
    char des;
    do{
        //MENU
        menu(&op);
        //TAMAÑO
        if (op != 4){
            //nom(op);
            size(&tam,op);
            a = (int *)calloc(tam,sizeof(int));
            //LECTURA
            lect(a,tam,op);
            //CASOS
            casos(op,a,tam);
        }
        salida(&des,op);
    } while (des == 's' || des == 'S');
    getch();
    return 0;
}
//MENU
void menu(int *op){
    int error;
    do{
        error = 0;
        printf("\t\t- - - ALGORITMOS DE ORDENAMIENTO - - -\n");
        printf("\n\t\t\t   - || MENU || -");
        printf("\n\nSeleccione alguno de los siguientes m%ctodos de ordenamiento:",130);
        printf("\n\n\t[1]: Burbuja");
        printf("\n\t[2]: Inserci%cn directa",162);
        printf("\n\t[3]: Selecci%cn directa",162);
        printf("\n\t[4]: SALIR");
        printf("\n\n///// ");
        scanf("%d",op);
        if (*op < 1 || *op > 4){
            printf("\n[!] ERROR: Valores incorrectos [!]");
            error = 1;
            getch();
            system("cls");
        }
    } while (error == 1);
    system("cls");
}
//NOMBRE ACTUAL
void nom(int op){
    printf("\t\t- - - ALGORITMOS DE ORDENAMIENTO - - -\n");
    printf("\n///// M%cTODO DE ORDENAMIENTO: ",144);
    switch (op){
    case 1:
        printf("BURBUJA\n\n");       
        break;
    case 2:
        printf("INSERCI%cN DIRECTA\n\n",224);     
        break;
    case 3:
        printf("SELECCI%cN DIRECTA\n\n",224);        
        break;
    }
}
//TAMAÑO
void size(int *tam,int op){
    int error;
    do{
        nom(op);
        error = 0;
        printf("Indique el tama%co del arreglo: ",164);
        scanf("%d",tam);
        if (*tam <= 1){
            printf("\n[!] ERROR: Valores incorrectos [!]");
            error = 1;
            getch();
            system("cls");
        }
    } while (error == 1);
    printf("\n");
}
//LECTURA
void lect(int arreg[],int tam,int op){
    int i;
    system("cls");
    nom(op);
    printf("Arreglo tama%co: %d\n\n",164,tam);
    printf("Ingrese los valores del arreglo:\n\n");
    for (i = 0; i < tam; i++){
        printf("\t[%02d] %c ",i+1,26);
        scanf("%d",&arreg[i]);
    }
}
//IMPRECION
void impr(int arreg[],int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("\n\t[%02d] %c %d",i+1,26,arreg[i]);
    }
}
//BURBUJA O INTERCABIO DIRECTO
void burbu(int arreg[],int tam){
    int i,j,aux;
    for (i = 0; i < tam-1; i++){
        for (j = 0; j < tam-1; j++){
            if (arreg[j] > arreg[j + 1]){
                aux = arreg[j];
                arreg[j] = arreg[j + 1];
                arreg[j + 1] = aux;
            }
        }
    }
    impr(arreg,tam);
}
//INSERCION DIRECTA 
void indi(int arreg[],int tam){
    int i,act,aux;
    for (i = 0; i < tam; i++){
        act = i;
        while (act > 0 && arreg[act] < arreg[act - 1]){
            aux = arreg[act - 1];
            arreg[act - 1] = arreg[act];
            arreg[act] = aux;
            act = act - 1;
        }
    }
    impr(arreg,tam);
}
//SELECCION DIRECTA
void direct(int arreg[],int tam){
    int i,j,min,aux;
    for (i = 0; i < tam-1; i++){
        min = i;
        for (j = i + 1; j < tam; j++){
            if (arreg[j] < arreg[min]){
                min = j;
            }
        }
        aux = arreg[i];
        arreg[i] = arreg[min];
        arreg[min] = aux;
    }
    impr(arreg,tam);
}
//CASOS
void casos(int op,int arreg[],int tam){
    printf("\n///// ARREGLO ORDENADO:\n");
    switch (op){
    case 1:
        burbu(arreg,tam);
        break;
    case 2:
        indi(arreg,tam);
        break;
    case 3:
        direct(arreg,tam);
        break;
    }
}
//SALIDA
void salida(char *des,int op){
    int error;
    do{
        error = 0;
        if (op == 4){
            *des = 'N'; 
        }
        else{
            printf("\n\n%cDesea continuar? (S/N) >> ",168);
            scanf("%s",des);
        }
        if (*des == 's' || *des == 'S'){
            system("cls");
        }
        else{
            if (*des == 'n' || *des == 'N'){
                system("cls");
                printf("\n\n\tGRACIAS POR USAR NUESTROS SERVICIOS");
                printf("\n\n\t   Equipo 8\t-\tBUAP");
            }
            else{
                printf("\n[!] ERROR: Ingresa una opci%cn valida [!]",162);
                error = 1;
            }
        }
    } while (error == 1); 
}