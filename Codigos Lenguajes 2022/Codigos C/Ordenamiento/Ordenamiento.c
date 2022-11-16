#include <stdio.h>
#include <string.h>

int main()
{
    /*Declaro todas las variables */  
    int i = 1,j,k,n,aux;
    char saux[10];

     /*El usuario ingresa cuantos tipos de fruta */
    printf("¿Cuantas tipos de fruta quiere ingresar? :");
    scanf("%d", &n);
   
     /* En la estructura tengo las variables 
     del nombre de la fruta y su cantidad*/
    struct verduleria{
        char nombre[10];
        int cantidad;
    }
    frutas[n];
   
    /*Aca el usuario ingresa el nombre y la cantidad de frutas*/
    for(k = 0; k < n; k = k+1)
    {
        printf("Ingrese el nombre de la fruta %d: ",i);
        scanf("%s", frutas[k].nombre);
        printf("Ingrese la cantidad de %s: ",frutas[k].nombre);
        scanf("%d",&frutas[k].cantidad);
        i++;
    }
   /* Aca ordeno primero las cantidades de fruta */
    /* Despues ordeno con strcpy los nombres en funcion de las cantidades*/
   for(k=0; k < n; k = k+1)
    {
        for(j=0; j < n; j = j+1)
        {
            if(frutas[k].cantidad < frutas[j].cantidad)
            {
                aux = frutas[k].cantidad;
                frutas[k].cantidad = frutas[j].cantidad;
                frutas[j].cantidad = aux;
               
               
                strcpy(saux, frutas[k].nombre);
                strcpy(frutas[k].nombre, frutas[j].nombre);
                strcpy(frutas[j].nombre, saux);
            }
        }
    }
   
     /* Se imprime las frutas ordenadas segun su cantidad*/
   
    printf("Las frutas ordenadas por cantidad son: \n");
    for(k = 0; k< n; k = k +1)
    {
        printf("%s: %d \n", frutas[k].nombre, frutas[k].cantidad);
    }
   
    return 0;
}
