#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Proyecto.h"

void op1(i_nodo **p, char **dir){

	int op=2;
	char nom[8]="";

	while (op!=0){

		*dir=direcA(p);
		printf("\tManejo Virtual de Archivos (MVA)\n");
		printf("\t[1. Crear directorio (MKD)]\n");
		printf("------------------------------------------------\n\n");
		printf("\tDirectorio actual -> [%s]\n\n", *dir);
		printf("\t1. Nombre del directorio a crear\n");
		printf("\t0. Salir\n\n");
		printf("\tSu opcion [0-1]: ");

		scanf("%i",&op);

		printf("------------------------------------------------\n");


		switch (op){
		
			case 1:	printf("\tNombre del directorio = ");
					scanf("%s",&nom);
					if(strlen(nom)<=9){
		
						if (!(buscarD(p,nom))){
				
							crearD(p,nom);
						}
						else{
				
							printf("------------------------------------------------\n");
							printf("\tEl directorio no pudo ser creado\n");
							printf("\tYa existe un directiorio con ese nombre\n\n\t");
							system("pause");
						}
					}
					else{
						printf("------------------------------------------------\n");
						printf("\tEl nombre no puede tener mas de 9 caracteres\n");
					}
					printf("------------------------------------------------\n");
					break;

			case 0:	break;

			default:printf("\tNo existe esa opcion\n");
					printf("\tSeleccione una de las opciones disponibles\n\n\t");
					system("pause");
					printf("------------------------------------------------\n");
					break;
		}
	}
	printf("\t");
	system("pause");
}

void op2(i_nodo **p, char **dir){

	int op=1;
	char nom[8];

	while (op!=0){
	
		*dir=direcA(p);
		printf("\tManejo Virtual de Archivos (MVA)\n");
		printf("\t[2. Cambiar directorio (CHD)]\n");
		printf("------------------------------------------------\n");
		printf("\tDirectorio actual -> [%s]\n\n", *dir);
		printf("\t1. Subir a directorio padre\n");
		printf("\t2. Bajar a un subdirectorio\n");
		printf("\t0. Volver a pantalla principal\n\n");
		printf("\tSu opcion [0-2]: ");

		scanf("%i",&op);

		printf("------------------------------------------------\n");

		switch(op){
		
			case 1:	(*p)=(*p)->pPA;
					break;

			case 2:	printf("\tIntroduzca el nombre: ");
					scanf("%s",&nom);
					printf("------------------------------------------------\n");
					cambiarD(p,nom);
					break;

			case 0:	break;
		}
	}
	system("pause");
}

void op5(i_nodo **p, char **dir){

	int op=1;

	printf("\tManejo Virtual de Archivos (MVA)\n");
	printf("\t[4. Mover directorio (MVD)]\n");
	printf("------------------------------------------------\n");
	printf("\tDirectorio actual -> [%s]\n\n", dir);
	printf("\t1. Nombre del directorio destino:\n");
	printf("\t0. Volver a pantalla principal\n\n");
	printf("\tSu opcion [0-1]:\n");
	printf("------------------------------------------------\n");
	system("pause");
}

void op0(i_nodo **p){

	FILE *f=NULL;
	irPadre(p);
	f=fopen("Guardado","w");
	fprintf(f,"Unidad logica C\n");
	guardar(p,f,1);
	fclose(f);
}

void main(){

// Inicio del disco C
	i_nodo *c;
	c=new i_nodo;
	strcpy(c->Nom, "C");
	strcpy(c->Tip, "U");
	c->pFA=NULL;
	c->pPA=c;
	c->pUL=NULL;
	char *dir= new char;

	int op=1;

	while (op!=0){

		dir=direcA(&c);
		printf("------------------------------------------------\n\n");
		printf("\tManejo Virtual de Archivos (MVA)\n\n");
		printf("------------------------------------------------\n\n");
		printf("\tDirectorio actual -> [%s]\n\n", dir);
		printf("\t1. Crear directorio (MKD)\n");
		printf("\t2. Cambiar de directorio (CHD)\n");
		printf("\t3. Borrar directorio (RMD)\n");
		printf("\t4. Copiar directorio (CPD)\n");
		printf("\t5. Mover directorio (MVD)\n");
		printf("\t6. Modificar directorio (MDD)\n");
		printf("\t7. Mostrar contenido (SHD)\n");
		printf("\t0. Salir y guardar datos.\n\n");
		printf("\tSu opcion [0-7]: ");

		scanf("%i",&op);

		printf("\n------------------------------------------------\n");

		switch(op){
	
			case 1:	op1(&c, &dir);
					break;
			case 2: op2(&c, &dir);
					break;
			case 5: op5(&c, &dir);
					break;
			case 0: op0(&c);
					system ("pause");
					break;
		}
	}
}
