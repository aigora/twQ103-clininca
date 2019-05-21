#include<stdio.h>
#include<stdlib.h> 
#include<windows.h>
#include<string.h>
#define SIZE 13


struct usuario
{	
	char user[SIZE];
	char contrasena[SIZE];
};

struct donacion
{
	char nombre[SIZE];
	int tarjeta;
	int cv;
	int caducidad;
	char n_identificacion[SIZE];
	float cantidad;
};


void inicio(int menu);
void usuario_registrado(struct usuario u,char nombreArchivo1[SIZE]);
void archivo_usuario_registrado(struct usuario u2,char nombreArchivo2[SIZE]);
void crear_usuario(struct usuario u3,char nombreArchivo3[SIZE],char escritura[]);
void lectura_repositorio(char lectura);
void elegir_donar(char nombreArchivodonacion[]);




void main() // FUNCION PRINCIPAL
{
	system("MODE 140,60");//TAMAÑO DE PANTALLA ( ANCHO Y ALTO)
	system("color 3E");//Color de fondo y de las letras
	int menu;
	printf("                                              BIENVENIDO A CLININCA, TU GUIA DE ONGS            \n");
	printf("\nPara iniciar sesion pulse 1\n");
	printf("Para registrarte pulsa 2 \n");
	printf("Para pasar como invitado pulse 3\n");
	printf("Para salir pulse 4 \n");
	inicio(menu);
	
};

void crear_usuario(struct usuario u3,char nombreArchivo3[SIZE],char escritura[])
{
	FILE *newuser,*newuser2;
	char lectura3;
	do
	{
	
		printf("\nIntroduce tu nombre de usuario que tenga como maximo 12 caracteres,que solo tenga numeros y/o - o _,y sin espacios\n");
		fflush( stdin );
		scanf("%s",u3.user);
		strcpy(nombreArchivo3,u3.user);
		newuser=fopen(nombreArchivo3,"r");
		
		if ( newuser==NULL)
		{
			printf("Introduce tu contrasenha que tenga como maximo 12 caracteres y sin espacios\n");
			fflush( stdin );
			scanf("%s",u3.contrasena);
			strcpy(nombreArchivo3,u3.user);
			newuser2=fopen(nombreArchivo3,"a");
			strcat(escritura,u3.user);
			fprintf(newuser2,"Usuario: %s",escritura);
			strcat(escritura,"\n");
			strcpy(escritura,u3.contrasena);
			fprintf(newuser2,"\nContraseña: %s\n",escritura);
			fclose(newuser2);
			printf("Cuenta creada sastisfactoriamente\n");
		}
			
		else if (strlen(u3.user)==0&&strlen(u3.contrasena)==0)
		{
			printf("Datos del usuario incompleto, por favor vuelva a introducir los datos.\n");
			
		}
		
		else
		{
			printf("\nUsuario registrado,introduzca nombre de usuario valido\n");
			crear_usuario(u3,nombreArchivo3,escritura);
			
		}
		
		
	}while(strlen(u3.user)==0&&strlen(u3.contrasena)==0);
	lectura_repositorio(lectura3);
	elegir_donar(nombreArchivo3);
	
};

void usuario_registrado(struct usuario u,char nombreArchivo1[SIZE])
{	
	int longitud;

	do
	{
		printf("Introduce tu nombre de usuario que tenga menos de 12 caracteres y que solo tenga numeros y - o _\n");
		scanf("%s",u.user);
		longitud=strlen(u.user);
		if(longitud!=0)
		{
			printf("\nUsuario %s, introducido satisfactoriamente! \n", u.user);
			strcpy(nombreArchivo1,u.user);
			archivo_usuario_registrado(u,nombreArchivo1);
			
		}
		else
		{
			printf("Datos del usuario incompleto, por favor vuelva a introducir los datos.\n");
			
		}
	}while(longitud==0);
	
};

void archivo_usuario_registrado(struct usuario u2,char nombreArchivo2[SIZE])
{
	
	FILE *user,*user2;
	char usuario[SIZE],contrasena[SIZE],donacionesInvitados[]="DonacionesInvitados";
	int registro,opcion,i=0;
	char escritura2[]=" ",nuevoArchivo[SIZE],lectura;
	char leer2,comparar_contrasena[SIZE];
	struct usuario usuario2;
	
	user=fopen(nombreArchivo2,"r");
	
	if( user == NULL )
	{	
		fclose(user);
		printf("\nCuenta no existente\n\n");
		printf("¿Quiere registrarse?\n");
		printf("SI: 1 , NO: 2\n");
		
		do 
		{
			scanf("%d", &registro);
			
			switch(registro)
			{
			
				case 1:
					crear_usuario(usuario2,nuevoArchivo,escritura2);
					break;
			
				case 2:
					printf("¿Quiere acceder como invitado?, Pulse 1\n");
					printf("¿Quiere salir?,Pulse 2\n");
					fflush(stdin);
					scanf("%d",&opcion);
					
					if (opcion==1)
					{
						printf("Acceso como invitado");
						lectura_repositorio(leer2);
						elegir_donar(donacionesInvitados);
					}
					
					else if(opcion ==2)
					{
						printf("Ha salido de la guía de ONGS");
					}
					break;
				
				default:
			    printf("Caracter erroneo,repitelo\n");
			    fflush ( stdin );
				break;
				
			}		
						
		} while(registro!=1&&registro!=2);
	}

	else if ( user!= NULL )
	{	
		fclose(user);
		user2 = fopen(nombreArchivo2,"r");
		do
		{
			printf("Introduce tu contrasena\n");
			scanf("%s",u2.contrasena);
			while( !feof(user) && i==0)
			{	
				fscanf(user,"%s %s %s %s",usuario,u2.user,contrasena,comparar_contrasena);
				i++;
			}
			if ( strcmp(u2.contrasena,comparar_contrasena)==0 )
			{	
				printf("\nContrasena introducida correcta");	
			}
			else
			{
				printf("\n Contrasena incorrecta\n");
			}
			
		}while(strcmp(u2.contrasena,comparar_contrasena)!=0);
		fclose(user2);
		lectura_repositorio(lectura);
		elegir_donar(nombreArchivo2);
	}
	
	
};

void inicio(int menu)
{
	char donacionesInvitados[]="DonacionesInvitados";
	struct usuario usuario1;
	char leer;
	char nombreArchivo[SIZE],escritura[]="";
	int donacion;

	do{

		scanf("%d",&menu);
		switch (menu)
		{
        
			case 1:
				usuario_registrado(usuario1,nombreArchivo);
				break;

			case 2:
				crear_usuario(usuario1,nombreArchivo,escritura);
				break;

			case 3:
				printf("\nAcceso como invitado\n");
				lectura_repositorio(leer);
				elegir_donar(donacionesInvitados);
				break;
				
			case 4:
        	printf("\nHas salido del repositorio");
             break;

			default:
			    printf("Caracter erroneo,repitelo\n");
			    fflush( stdin );
				break;

		}
	}while( menu!=4&&menu!=1&&menu!=2&&menu!=3 );
};

void lectura_repositorio(char lectura)
{
	FILE *medioambiente1;
	FILE *proteccion1;
	FILE *ayuda1;
	int numero;
	char lectura2,ayudaLectura;
	int decision2;
	
	printf("\nPulse a/A para lectura de ongs medioambientales\n");
	printf("Pulse b/B para lectura de ongs de proteccion de animales");
	printf("\nPulse c/C para lectura de ongs de ayuda humanitaria\n");
	
	do
	{
		fflush(stdin);
		scanf("%c", &lectura);
		
		if ( lectura=='a' || lectura =='A')
		{
			medioambiente1=fopen("medioambiente.txt","r");
			
			if ( medioambiente1 ==NULL)
			{
				printf("Fichero no abierto");
			}
			else
			{
				while( !feof(medioambiente1) )
				{
					printf("%c",getc(medioambiente1));
				}
				fclose(medioambiente1);
			}
			
			printf("¿\n Quiere informacion de otro tipo de ongs?\n");
			printf("1: SI\n");
			printf("2: NO\n");
			fflush( stdin );
				do 
			{
				scanf("%d",&numero);
				switch(numero)
				{
					case 1:
						lectura_repositorio(lectura2);
						break;
					case 2:
						printf("\nGracias por su visita a la guia de ongs ");
						break;
					default:
						printf("\nNumero incorrecto\n");
						break;
				}
				
			}while(numero!=1&&numero!=2);
				
		}
		
		else if ( lectura=='b' || lectura=='B')
		{
			proteccion1=fopen("proteccion.txt","r");
			
			if ( proteccion1 ==NULL)
			{
				printf("Fichero no abierto");
			}
			else
			{
				while( !feof(proteccion1) )
				{
					printf("%c",getc(proteccion1));
				}
				fclose(proteccion1);	
			}
		
			printf("\n¿Quiere informacion de otro tipo de ongs?\n");
			printf("1: SI\n");
			printf("2: NO\n");
			fflush( stdin );
			
			do 
			{
				scanf("%d",&numero);
				switch(numero)
				{
					case 1:
						lectura_repositorio(lectura2);
						break;
					case 2:
						printf("\nGracias por su visita a la guia de ongs");
						break;
					default:
						printf("\nNumero incorrecto");
						break;
				}
				
			}while(numero!=1&&numero!=2);		
		}
		
	   
		else if( lectura =='c'|| lectura =='C')
		{
			ayuda1=fopen("ayuda.txt","r");
			
			if ( ayuda1 ==NULL)
			{
				printf("\nFichero no abierto\n");
			}
			
			else
			{
				while( !feof(ayuda1) )
				{	
					fscanf(ayuda1,"%c",&ayudaLectura);
					printf("%c",ayudaLectura);
				}
			 	fclose(ayuda1);
			}
			printf("\n¿Quiere informacion de otro tipo de ongs?\n");
			printf("1: SI\n");
			printf("2: NO\n");
			fflush( stdin );
			do 
			{
				scanf("%d",&numero);
				switch(numero)
				{
			
					case 1:
						lectura_repositorio(lectura2);
						break;
					case 2:
						printf("Gracias por la visita a la guia de ongs");
						break;
					default:
						printf("Numero incorrecto");
						break;
				}
				
			}while(numero!=1&&numero!=2);		
		}
		
		else
		{
			printf("Letra introducida incorrecta,pulse de nuevo\n");
		}
		
	}while( lectura!='a'&&lectura!='A'&&lectura!='b'&&lectura!='B'&&lectura!='c'&&lectura!='C' );
	
};

void elegir_donar(char nombreArchivodonacion[])
{
	FILE *donaciones;
	struct donacion donacion_ongs[9];
	char donacion_ongs3[]=" ";
	int donacionTarjeta;
	float cantidadDonacion;
	int i,j,eleccion;
	
	printf("\n\nQuieres donar?, 1:SI ,2: NO\n");
	scanf("%d",&eleccion);
	
	
	if(eleccion == 1)
	{
		
		do
		{
			printf("\nIntroduce el numero de ongs que quieres donar, el numero maximo es nueve\n");
			scanf("%d",&j);
				
			if(j>0  && j<10)
			{
				for(i=1 ; i<=j ; i++)
				{
					fflush( stdin );
					printf("\nNombre de la ong\n");
					scanf("%s",&donacion_ongs[i].nombre);
					fflush( stdin );
					printf("Introduce nombre del titular de la tarjeta\n");
					gets(donacion_ongs[i].n_identificacion);
					fflush( stdin );
					printf("Introduce la cantidad a donar en euros\n");
					scanf("%f",&donacion_ongs[i].cantidad);
					fflush( stdin );
					printf("Numero de tarjeta bancaria\n");
					scanf("%d",&donacion_ongs[i].tarjeta);
					fflush( stdin );
					printf("Fecha de vencimiento mesanho\n");
					scanf("%d",&donacion_ongs[i].caducidad);
					fflush( stdin );
					printf("Introduce codigo de seguridad\n");
					scanf("%d",&donacion_ongs[i].cv);
				}
				
				
				for(i=1 ; i<=j ; i++)
				{
					donaciones=fopen(nombreArchivodonacion,"a");
					
					if(donaciones==NULL)
					{
						printf("FICHERO NO ABIERTO\n");
					}
					
					else
					{
						fprintf(donaciones,"\nDONACION %i: ",i);
						strcpy(donacion_ongs3,donacion_ongs[i].nombre);
						strcat(donacion_ongs3,",");
						strcat(donacion_ongs3,donacion_ongs[i].n_identificacion);
						strcat(donacion_ongs3,",");
						donacionTarjeta=donacion_ongs[i].tarjeta;
						cantidadDonacion=donacion_ongs[i].cantidad;
						fprintf(donaciones," \nNombre de la Asociacion, Nombre del Titular de la Tarjeta, Numero de Tarjeta de debito/credito, Cantidad donada (€): ");
						fprintf(donaciones," %s %d, %f\n",donacion_ongs3,donacionTarjeta,cantidadDonacion);
						fclose(donaciones);
					}
				
			    }
			    printf("\nMuchas gracias por la donacion y  su visita a la guia de ongs\n");
					
			}
		
				
		}while(j<=0 || j>9);
			
	}
				
	else
	{
		printf("\n\nGracias por haber visitado la guia de ONGS\n");
	}	
	
};


