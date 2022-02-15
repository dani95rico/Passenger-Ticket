/*
 * billete.c
 *
 *  Created on: 26/11/2014
 *  EXAMPLE OF A PASSANGER TICKET BY DANI95RICO
 */
#include <stdio.h>
#include <string.h>

#define MAX_nom 20+1
#define MAX_ape 40+1
#define MAX_dni 9+1
#define MAX_fecha 10+1
#define MAX_plazas 100

typedef char tNombre[MAX_nom];
typedef char tApellidos[MAX_ape];
typedef char tDNI[MAX_dni];
typedef char tFecha[MAX_fecha];

typedef struct{
	int tarifa;
	tFecha fechaVenta;
} tBillete;

typedef struct{
	tNombre nombre;
	tApellidos apellidos;
	tDNI dni;
	tBillete billete;
} tPasajero;

typedef struct{
	tPasajero pasajero;
	int ocupado;
} tRegistro;

typedef tRegistro tListaPasajeros[MAX_plazas];

/*PROTOTIPOS*/
void inicioListaPasajeros(tListaPasajeros lista);      /*Lista es parÃ¡metro de salida pero es array*/
void leerCadena(char *cadena,int tam);                 /*En vez de poner [] se pone char "*" */
int menu();
int haySitio(const tListaPasajeros lista,int *hueco);  /*Hueco parÃ¡metro de salida->por referencia*/
int buscarPasajeroEnLista(const tDNI dni,const tListaPasajeros lista,int *pos);
void _listaPasajeros(const tListaPasajeros lista);
int borrarPasajero(const tDNI dni,tListaPasajeros lista);
int plazasLibres(const tListaPasajeros lista);

int main(void)
{
	tListaPasajeros listaPasajeros;
	tPasajero pasajero;
	tDNI dni;
	int opcion;                       /*Opcion del menu*/
	int sitio;
	int posicion;

	inicioListaPasajeros(listaPasajeros);
	do
	{
	opcion=menu();
	switch (opcion)
	{
		case 1:
				if(haySitio(listaPasajeros,&sitio))
				{
					printf("DNI: ");
					fflush(stdout);
					leerCadena(pasajero.dni,MAX_dni);
					if(buscarPasajeroEnLista(pasajero.dni,listaPasajeros,&posicion)==1)
					{
						printf("El pasajero ya tiene billete.\n");
						fflush(stdout);
					}
					else
						printf("Nombre: ");
						fflush(stdout);
						leerCadena(pasajero.nombre,MAX_nom);
						printf("Apellidos: ");
						fflush(stdout);
						leerCadena(pasajero.apellidos,MAX_ape);
						printf("Tarifa: ");
						fflush(stdout);
						scanf("%d",&pasajero.billete.tarifa);
						fflush(stdin);
						printf("Fecha: ");
						fflush(stdout);
						leerCadena(pasajero.billete.fechaVenta,MAX_fecha);
				}
				else
					printf("Tren lleno.");
					fflush(stdout);
			break;

		case 2:
				_listaPasajeros(listaPasajeros);
			break;

		case 3:
				printf("DNI pasajero a borrar: ");
				leerCadena(dni,MAX_dni);
				if(borrarPasajero(dni,listaPasajeros))
				{
					printf("Se ha borrado el pasajero de DNI: %s\n",dni);
					fflush(stdout);
				}
				else
					printf("El pasajero no tiene reserva.");
			break;

		case 4:
				printf("Hay %d plazas libres.\n",plazasLibres(listaPasajeros));
				fflush(stdout);
			break;

		case 5:
				printf("Un besito guapo.\n");
				fflush(stdout);
			break;

		default:
				printf("ERROR.\n");
				fflush(stdout);
			break;

	}
} while(opcion!=5);

return 0;
}

void inicioListaPasajeros(tListaPasajeros lista)
{
	int i;
	for(i=0;i<MAX_plazas;i++)
	{
		lista[i].ocupado=0;
	}
}

void leerCadena(char *cadena,int tam)
{
	fgets(cadena,tam,stdin);
	if(cadena[strlen(cadena)-1]=='\n')
	{
		cadena[strlen(cadena)-1]='\0';
	}
}

int menu()
{

}

int haySitio(const tListaPasajeros lista,int *hueco)
{
	int i;
	int encontrado;
	encontrado=0;
	for(i=0;(i<MAX_plazas) && !encontrado;i++)
	{
		if(lista[i].ocupado==0)
		{
			encontrado=1;
			*hueco=i;
		}
	}
	return encontrado;
}

int buscarPasajeroEnLista(const tDNI dni,const tListaPasajeros lista,int *pos)
{
	int i;
	int encontrado;
	encontrado=0;
	for(i=0;(i<MAX_plazas)&& !encontrado;i++)
	{
		if(lista[i].ocupado)
		{
			if(!strcmp(dni,lista[i].pasajero.dni))
			{
				encontrado=1;
				*pos=i;
			}
		}
	}
	return encontrado;
}

void _listaPasajeros(const tListaPasajeros lista)
{
	int i;
	for(i=0;i<MAX_plazas;i++)
	{
		if(lista[i].ocupado)
		{
			printf("%s %s %d %d %s\n",lista[i].pasajero.nombre,lista[i].pasajero.apellidos,lista[i].pasajero.dni,lista[i].pasajero.billete.tarifa,lista[i].pasajero.billete.fechaVenta);
			fflush(stdout);
		}
	}
}

int borrarPasajero(const tDNI dni,tListaPasajeros lista)
{
	int posicion;
	int encontrado;
	encontrado=buscarPasajeroEnLista(dni,lista,&posicion);
	if(encontrado)
	{
		lista[posicion].ocupado=0;
	}
	return encontrado;
}

int plazasLibres(const tListaPasajeros lista)
{

}
