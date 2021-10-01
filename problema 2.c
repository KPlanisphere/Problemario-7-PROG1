/*2.Algoritmos de busqueda lineal y binaria*/

//cargar librerias
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Prototipos
void menu(int *);
void nombre(int);
void dimension(int *,int);
void valores (int [],int,int);
void impresion(int [],int);
void metodo(int,int [],int,int);
void soli (int*);
void lineal(int,int [],int);
void binaria(int [],int,int);
void final(char *,int);
	
//Principal
int main (){
	int x,op,longi,*arreglo;
	char op2;
	do{
		menu(&op);
		if (op!=3){
			dimension(&longi,op);
			arreglo=(int *)calloc(longi,sizeof(int));
			valores(arreglo,longi,op);
			soli(&x);
			metodo(op,arreglo,longi,x);
		}
		final(&op2,op);
	}while(op2=='s' || op2=='S');
	
	printf("\n");
	getch();
	return 0;
}

//funcion de tipo void para menu
void menu(int *op){
	int error;
	do{
		error=0;
		printf ("\t\t%c\t\t     %c\n",201,187);
		printf ("\t\t%c Men%c de Algoritmos %c",186,163,186);
		printf ("\n\t\t%c\t\t     %c\n",200,188);
		printf ("\n%c Seleccione el m%ctodo de b%csqueda con el que desea operar:\n",219,130,163);
		printf ("\n\t%c[1] B%csqueda lineal.",175,163);
		printf ("\n\t%c[2] B%csqueda binaria.",175,163);
		printf ("\n\t%c[3] Salir.",175);
		printf ("\n\n=");
		scanf ("%d",op);
		if (*op<1 || *op>3){
			printf ("\n[!] ERROR: Opci%cn no v%clida [!]",162,160);
			error=1;
			system("pause");
			system("cls");
		}
	}while(error!=0);
}

//funcion de tipo void para indicar el metodo seleccionado
void nombre(int op){
    printf("\n\t\t%c ALGORITMOS DE B%CSQUEDA %c\n",186,233,186);
    printf("\n\tM%cTODO DE B%CSQUEDA: ",144,233);
    switch (op){
    case 1:
        printf("LINEAL\n");       
        break;
    case 2:
        printf("BINARIO\n",224);     
        break;
	}
}

//funcion de tipo void para dimensionar el arreglo
void dimension (int *longi,int op){
    int error;
    do{
    	nombre(op);
    	system ("cls");
        error = 0;
        printf("\n%c%cIndique el tama%co del Arreglo: ",175,175,164);
        scanf("%d",longi);
        if (*longi == 1 || *longi == 0){
            printf("\n[!] ERROR: Tama%co del Arreglo menor que 2 [!]",164);
            error=1;
            getch();
            system("cls");
        }else if (*longi < 0 ){
        	printf ("\n[!] ERROR: Tama%co del Arreglo inexistente [!]",164);
        	error=1;
        	getch();
        	system ("cls");
		}
    } while (error!=0);
    printf("\n");
}

//funcion de tipo void para ingresar valores al arreglo
void valores(int A[],int longi,int op){
    int i;
    system("cls");
    nombre(op);
    printf("\n%cTama%co del Arreglo: %d\n\n",175,164,longi);
    printf("%c%cProceda a ingresar los valores en el Arreglo%c%c\n\n",175,175,174,174);
    for (i = 0; i < longi; i++){
        printf("\t%cValor %c%d en el Arreglo: ",219,35,i+1);
        scanf("%d",&A[i]);
    }
}

//funcion de tipo void para imprimir los valores dentro del arreglo
void impresion(int A[],int longi){
    int i;
    printf ("Arreglo:\n");
    for (i = 0; i < longi; i++){
        printf("[%d]",A[i]);
    }	
}

//funcion de tipo void para solicitar el valor a buscar dentro del arreglo
void soli (int *x){
	system ("cls");
	printf ("\n%c%cIngrese el valor x a buscar dentro del Arreglo: ",175,175);
	scanf ("%d",x);
}

//funcion de tipo void para metodo lineal
void lineal(int longi,int A[],int x){
	int i,buscador;
	printf("\n");
	impresion(A,longi);
	for (i=0;i<=longi;i++){
		if(A[i]==x){
			buscador=i;
			break;
		}else{
			buscador=-1;
		}
	}
	if (buscador==-1){
		printf("\n\nNumero no encontrado\n");
	}else{
		printf("\n\nNumero %d encontrado en la posicion {%d}\n",x,i);
	}
}
//funcion de tipo void para metodo binario
void binaria(int A[],int longi,int x){
    int i,j,aux,mitad;
    int a=0,contadorA=0,contadorB=0;
    for (i = 0; i < longi; i++){
        for (j = i + 1; j < longi; j++){
            if (A[j] < A[i]){
                aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        }
    }
    printf("\n");
    impresion(A,longi);	

	while (a <= longi){
    	contadorA++;
    	mitad = (a + longi) / 2;
    	if(x > 200){
			printf("\n\nNumero no encontrado\n");
			break;
    	}
    	if(x == A[mitad]){
			printf("\n\nNumero %d encontrado en posicion {%d}\n", A[mitad], mitad);
			break;
    	}else if(x < A[mitad]){
			longi = mitad -1;
    	}else{
			a = mitad + 1;
    	}
		contadorB++;
	}	
	if(contadorA == contadorB){
	  printf("\n\nNumero no encontrado\n");
	}
}

//funcion de tipo void para seleccion de metodo
void metodo(int op,int A[],int longi,int x){

    switch (op){
    case 1:
        lineal(longi,A,x);
        break;
    case 2:
        binaria(A,longi,x);
        break;
	}
}

//funcion de tipo void para mostrar mensaje al usuario
void final(char *op2,int op){
    int error;
    do{
        error = 0;
        if (op == 3){
            *op2 = 'N'; 
        }
        else{
            printf("\n%cContinuar ejecuci%cn? (s/n) %c ",168,162,175);
            scanf("%s",op2);
        }
        if (*op2 == 's' || *op2 == 'S'){
            system("cls");
        }
        else{
            if (*op2 == 'n' || *op2 == 'N'){
                system("cls");
                printf("\n\n\tGRACIAS POR USAR NUESTROS SERVICIOS");
                printf("\n\n\t   Equipo 8\t-\tBUAP");
            }
            else{
                printf("\n[!] ERROR: Ingresa una opci%cn valida [!]",162);
                error = 1;
            }
        }
    } while (error!=0); 
}
