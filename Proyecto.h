#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct i_nodo{

	char Nom[9];
	char Ext[4];
	char Tip[2];
	long int fmc;
	int sz;
	int r;
	int h;
	char cntd[256];
	i_nodo *pFA;
	i_nodo *pPA;
	i_nodo *pUL;
};

long int getFecha(){
	
	time_t fecha; time(&fecha);
	struct tm *fechita= localtime(&fecha);
	long int f;

	f=fechita->tm_year+1900; f=f*100;
	f=f+fechita->tm_mon+1; f=f*100;
	f=f+fechita->tm_mday;

	return f;
}

/*
1. Es para crear directorios

2. (**p) es el directorio donde se va a crear el nuevo directorio (si quieres crear un directorio en C entonces le pasas el puntero de C)

3. (nom) es el nombre que le quieres dar al directorio
*/

void crearD(i_nodo **p, char nom[8]){

	i_nodo *t, *px=*p;
	if (px){
		
		t= new i_nodo;
		strcpy(t->Nom, "D");
		strcpy(t->Tip, "D");
		t->fmc=getFecha();
		t->r=0;
		t->h=0;
		t->pFA=NULL;
		t->pPA=*p;
		t->pUL=(*p)->pFA;
		(*p)->pFA=t;
	}
}

/*
1. Es para buscar si exite un directorio usando su nombre

2. (**p) es el directorio donde quieres buscar 

3. (nom) es el nombre del directorio que estas buscando

4. Si el directorio existe devuelve [1] en caso contrario devuelve [0]
*/

int buscarD(i_nodo **p, char nom[8]){

	i_nodo *px=(*p)->pFA;

	while (px){

		if (!strcmp(nom, px->Nom)) return 1;
		else px=px->pUL;
	}
	return 0;
}

/*
1. Es para guardar el contenido de los directorios en un archivo.txt

2. (**p) es el primer directorio de la unidad 

3. (cont) es un contador que facilita saber que tan profundo estas en los directorios 
*/

void guardar(i_nodo **p, FILE *f, int cont){

	i_nodo *px=*p;
	i_nodo *pxx;

	if (strcmp("U", px->Tip)!=0){
		
		fprintf(f,"%i.%s.%s.%li.%i.%i\n",cont,px->Nom,px->Tip,px->fmc,px->r,px->h);
		if(px->pFA){

			pxx=px->pFA;
			guardar(&pxx,f,cont+1);
		}
		if(px->pUL){

			pxx=px->pUL;
			guardar(&pxx,f,cont);
		}
	}
	else{
	
		px=px->pFA;
		guardar(&px, f, cont);
	}
}

char *direcA(i_nodo **p){

	i_nodo *px=*p;
	char *d1= new char;
	char *dir= new char;

	if(px){
		
		if(!strcmp("C", px->Nom)){
			
			dir="C:/";
			return dir;
		}
		else{

			dir=direcA(&px->pPA);
			strcpy(d1, dir);
			strcat(d1,px->Nom);
			strcat(d1,"/");
			dir=d1;
			return dir;
		}
	}
}

void cambiarD(i_nodo **p, char* nom){

	i_nodo *px=(*p)->pFA;
	while (px){
	
		if (!strcmp(nom, px->Nom)){
			
			*p=px;
			break;
		}
		else{ 
			
			px=px->pUL;
		}
	}
	if (!px){
	
		printf("\tEse directorio no existe\n");
		printf("------------------------------------------------\n");
	}
}

void irPadre(i_nodo **p){

	i_nodo *px=*p;
	while (px->pPA){

		if (!strcmp("C", px->Nom)) break;
		else px=px->pPA;
	}
}