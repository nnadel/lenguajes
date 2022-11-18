#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caract;
int DNI_ingresado;
int val_imp;

struct alumnos
{
    char nombre[15];
    char apellido[15];
    int edad;
    int dni;
    int prom_nota;
    struct alumnos *next;
};

struct cursos
{
    int grado;
    int cant_alumnos;
    struct alumnos *next;
    struct cursos *siguiente;
};

struct cursos *prim_curso = NULL;

struct alumnos *imp2;
struct cursos *imp;
struct cursos *p_curso;
struct alumnos *p_alum;
struct alumnos *control = NULL;
struct cursos *ctrl = NULL;
struct alumnos *aux_alumno;
struct cursos *aux_curso;

void crear_primer_curso_alumno ();
void crear_alum();
void UbicarAlum();
void UbicaCur();
void crear_cursos();
void Imp_alumnos(int);

int main()
{
    int buscar;
    while(buscar != 3)
    {
        if(prim_curso == NULL)
        {
            system("@cls||clear");
            printf("------------------------BIENVENIDO A ORGANIZAR------------------------\n\n");
            printf("Si desea crear, presione 1\n");
            printf("Si desea finalizar el programa, presione 3\n");
            scanf("%d", &buscar);
        }
        else
        {
            system("@cls||clear");
            printf("------------------------BIENVENIDO A ORGANIZAR------------------------\n\n");
            printf("Si desea crear, presione 1\n");
            printf("Si desea observar, presione 2\n");
            printf("Si desea finalizar el programa, presione 3\n");
            scanf("%d", &buscar);
        }
       
        switch(buscar)
        {
            case 1:
                system("@cls||clear");
                printf("Si desea crear un curso, presione 1\n");
                printf("Si desea crear alumno/os, presione 2\n");
                scanf("%d", &buscar);
               
                if(buscar == 1)
                {
                    crear_cursos();
                    UbicaCur();
                }
               
                if(buscar == 2)
                {
                    int alumnos;
                    system("@cls||clear");
                    printf("¿Cuantos alumnos desea crear?");
                    scanf("%d", &alumnos);
                    for(alumnos; alumnos--; alumnos<0)
                    {
                        crear_alum();
                        UbicarAlum();
                    }
                }
            break;
           
            case 2:
           
                system("@cls||clear");
                printf("Si desea observar los alumnos de un curso, ingrese 1\n");
                printf("Si desea observar los datos de un alumno, ingrese cualquier valor\n");
                scanf("%i",&val_imp);
               
                if(val_imp == 1)
                {
                    printf("¿Los alumnos de que curso desea observar?\n");
                    scanf("%d",&caract);
                    Imp_alumnos(caract);    
                    printf("\nApriete cualquier valor para volver al menu\n");
                    scanf("%d",&val_imp);
                }
                else
                {
                    printf("Ingrese el DNI del alumno que sea observar\n");
                    scanf("%d", &DNI_ingresado);
                }
            break;
        }
    }
}

//Creates a pupil who is pointed by p_alum

void crear_alum()
{
    aux_alumno = malloc(sizeof(struct alumnos));
    (aux_alumno->next) = NULL;
   
    printf("\nIngrese el nombre y apellido:");
    scanf("%s %s", aux_alumno->nombre, aux_alumno->apellido);
   
    printf("\nIngrese la edad y el DNI:");
    scanf("%d %d", &aux_alumno->edad, &aux_alumno->dni);
    printf("%x %x",aux_alumno->edad, aux_alumno->dni);
   
    do{
        printf("\nIngrese el promedio de sus notas:");
        scanf("%d", &aux_alumno->prom_nota);
        if(aux_alumno->prom_nota < 0 || aux_alumno->prom_nota > 10)
        {
            system("@cls||clear");
            printf("Nota mal ingresada\n");
            printf("Porfavor ingresar nuevamente\n");
            aux_alumno->prom_nota = -1;
        }
    }
    while(aux_alumno->prom_nota == -1);
}

//The first pupil was created by crear_alum is located
   
void UbicarAlum()
{
    int grado;
    int ctrl = 0;
    printf("En que grado quiere agregar este alumno:\n");
    scanf("%d", &grado);
    imp = prim_curso;
    p_alum = imp -> next;
   
    while(ctrl == 0)
    {
        //We look for the course
        if(grado == imp -> grado)
        {
            //Case which the first pupil is pointed
            if(imp -> next == NULL)
            {
                imp -> next = aux_alumno;
                ctrl = 1;
            }
           
            else
            {
                int i = strcmp(p_alum->apellido, aux_alumno->apellido);
               
                if(i<0)
                {
                    p_alum = p_alum -> next;
                    ctrl = 1;
                }
               
                else
                {
                    //Case which p_alum points to the last pupil
                    if(p_alum -> next == NULL)
                    {
                        p_alum->next = aux_alumno;
                        ctrl = 1;
                    }
                   
                    else
                    {
                        aux_alumno -> next = p_alum -> next;
                        p_alum -> next = aux_alumno;
                        ctrl = 1;
                    }
                }
            }
        }
       
        else
        {
            imp = imp -> siguiente;
        }
    }
}

//Se creara un nuevo curso ingresando sus datos con los datos del primer alumno
void crear_cursos()
{
    aux_curso = malloc(sizeof(struct cursos));
    aux_curso -> siguiente = ctrl;
    printf("\nIngrese el grado del curso:");
    scanf("%d", &aux_curso->grado);
    aux_curso -> next = NULL;
}

//El curso creado por crear_cursos es ubicado
void UbicaCur()
{
    p_curso = prim_curso;
    if(prim_curso == NULL)
    {
        //si es el primer curso
        prim_curso = aux_curso;
        prim_curso->siguiente = NULL;
        prim_curso->next = NULL;
        printf("Se creo el primer curso\n");
    }
    else
    {
        //No es el primer curso, si se esta ubicando el segundo
        if(p_curso->siguiente == NULL)
        {
            if((p_curso->grado) > (aux_curso->grado))
            {
                printf("Se creo el segundo curso menor al primero\n");
                prim_curso = aux_curso;
                prim_curso->siguiente = p_curso;
                p_curso->siguiente = NULL;
                p_curso->next = NULL;
                aux_curso = p_curso;
                p_curso = prim_curso;
                //reacomodoamos los punteros y la organización
            }
           
            else
            {
                printf("Se creo el segundo curso\n");
                p_curso->siguiente = aux_curso;
                aux_curso->siguiente = NULL;
                aux_curso->next = NULL;
            }
        }
       
       
        //En esta parte de la funcion compara el grado de los cursos ciclicamente con el curso creado
        else
        {
            printf("Entro al else\n");
            int n;
            if(p_curso -> grado > aux_curso -> grado)//ERROR no entra a este if, termina por entrar al while(ctrl !=primcurso);
            {
                printf("Entro al if\n");
                prim_curso = aux_curso;
                prim_curso->siguiente = p_curso;
                aux_curso = p_curso;
                p_curso = prim_curso;
            }
            else
            {
                while(n != 1)
                {
                    printf("Entro al while\n");
                    if((p_curso->siguiente) == NULL||(p_curso -> siguiente)-> grado > (aux_curso -> grado))//ERROR SIGSEGV
                    {
                        printf("Entro al if");
                        struct cursos *save = (p_curso -> siguiente);
                        (p_curso -> siguiente) = aux_curso;
                        (aux_curso -> siguiente) = save;
                        n = 1;
                    }
                   
                    else
                    {
                        p_curso = (p_curso -> siguiente);
                    }
                }
            }
        }
    }
    p_curso = prim_curso;
}

void Imp_alumnos(int curso)
{
    if(prim_curso == NULL)
    {
        printf("No hay cursos creados\n");
    }
   
    else
    {
        int n;
        imp = prim_curso;
       
        do
        {
            if((imp -> grado) == curso)
            {
                imp2 = (imp -> next);
               
                if(imp2 == NULL)
                {
                    printf("No hay alumnos\n");
                    n = 1;
                }    
               
                else
                {
                    printf("Hay algun alumno\n");
                   
                    if((imp2 -> next) != NULL)
                    {
                        do
                        {
                            printf("\nNombre:%s",(imp2->nombre));
                            printf("\nApellido:%s",(imp2->apellido));
                            imp2 = imp2->next;
                        }
                        while(imp2 -> next != NULL);
                        n=1;
                    }
                    else
                    {
                        printf("\nNombre:%s",(imp2->nombre));
                        printf("\nApellido:%s",(imp2->apellido));
                        n=1;
                    }
                }    
            }
            else
            {
                printf("imp = imp->siguiente\n");
                imp = imp->siguiente;
            }
            printf("n tiene un valor de:%d\n",n);
        }
        while(n != 1);
    }
}




void Imp_dataAlum (int DNI_ingresado)
{
    imp = prim_curso;
   
    do
    {
        imp2 = imp -> next;
       
        if(imp2 != NULL)
        {
            do{
                if(imp2 -> dni == DNI_ingresado)
                {
                    printf("\nNombre: %s",imp2->nombre);
                    printf("\nApellido: %s",imp2->apellido);
                    printf("\nEdad: %d",imp2->edad);
                    printf("\nprom_nota: %d",imp2->prom_nota);
                    printf("\nDNI: %d",imp2->dni);
                }
                 
                else
                {
                    imp2 = imp2 -> next;
                }
            }
            while(imp2 -> next != NULL);
           
            imp = imp -> siguiente;
        }  
    }
    while(imp == NULL);
}