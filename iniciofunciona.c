#include<stdio.h>
#include<stdlib.h> 
#include<windows.h>
#include<string.h>
#define SIZE 25	

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
void releer(char relectura);
void elegir_donar(char nombreArchivodonacion[]);


void main() // FUNCION PRINCIPAL
{
	system("MODE 140,60");//TAMA—O DE PANTALLA ( ANCHO Y ALTO)
	system("color 3E");//Color de fondo y de las letras
	int menu;
	printf("BIENVENIDO A CLININCA, TU GUIA DE ONGS \n");
	printf("Para iniciar sesion pulse 1\n");
	printf("Para registrarte pulsa 2 \n");
	printf("Para pasar como invitado pulse 3\n");
	printf("Para salir pulse 4 \n");
	inicio(menu);
	
};


void inicio(struct usuario u )
{
	
	void crear_usuario(struct usuario u3,char nombreArchivo3[SIZE],char escritura[])
{
	FILE *newuser,*newuser2;
	do
	{
	
		printf("Introduce tu nombre de usuario que tenga menos de 25 caracteres,que solo tenga numeros y/o - o _,y sin espacios\n");
		fflush( stdin );
		scanf("%s",u3.user);
		strcpy(nombreArchivo3,u3.user);
		newuser=fopen(nombreArchivo3,"r");
		
		if ( newuser==NULL)
		{
			printf("Introduce tu contrasenha que tenga menos de 25 caracteres y sin espacios\n");
			fflush( stdin );
			scanf("%s",u3.contrasena);
			strcpy(nombreArchivo3,u3.user);
			newuser2=fopen(nombreArchivo3,"a");
			strcat(escritura,u3.user);
			strcat(escritura,"-");
			strcat(escritura,u3.contrasena);
			fprintf(newuser2,"Nombre de usuario-ContraseÒa: %s\n",escritura);
			fclose(newuser2);
			printf("Cuenta creada sastisfactoriamente");
		}
			
		else if (strlen(u3.user)==0&&strlen(u3.contrasena)==0)
		{
			printf("Datos del usuario incompleto, por favor vuelva a introducir los datos.\n");
			
		}
		
		else
		{
			printf("Usuario registrado,introduzca nombre de usuario valido\n");
			crear_usuario(u3,nombreArchivo3,escritura);
			
		}
		
		
	}while(strlen(u3.user)==0&&strlen(u3.contrasena)==0);
};

void usuario_registrado(struct usuario u,char nombreArchivo1[SIZE])
{	

	do
	{
		printf("Introduce tu nombre de usuario que tenga menos de 25 caracteres y que solo tenga numeros y - o _\n");
		scanf("%s",u.user);
		printf("Introduce tu contrasenha que tenga menos de 25 caracteres y sin espacios\n");
		scanf("%s",u.contrasena);
		if(strlen(u.user) != 0 && strlen(u.contrasena) !=0)
		{
			printf("\nUsuario %s, introducido satisfactoriamente! \n", u.user);
			strcpy(nombreArchivo1,u.user);
			archivo_usuario_registrado(u,nombreArchivo1);
			
		}
		else
		{
			printf("Datos del usuario incompleto, por favor vuelva a introducir los datos.\n");
			
		}
	}while(strlen(u.user)==0&&strlen(u.contrasena)==0);
	
};

void archivo_usuario_registrado(struct usuario u2,char nombreArchivo2[SIZE])
{
	
	FILE *user,*user2;
	char donacionesInvitados[]="donacionesInvitados";
	int registro,opcion;
	char escritura2[]=" ",nuevoArchivo[SIZE],lectura,opcion2;
	char leer2;
	struct usuario usuario2;
	
	user = fopen(nombreArchivo2,"r");
	if( user == NULL )
	{
		printf("\nCuenta no existente\n\n");
		printf("øQuiere registrarse?\n");
		printf("SI: 1 , NO: 2\n");
		
		do 
		{
			scanf("%d", &registro);
			
			switch(registro)
			{
			
				case 1:
					crear_usuario(usuario2,nuevoArchivo,escritura2);
					lectura_repositorio(leer2);
					elegir_donar(nuevoArchivo);
					break;
			
				case 2:
					printf("øQuiere acceder como invitado?, Pulse 1\n");
					printf("øQuiere salir?,Pulse 2\n");
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
						printf("Ha salido de la guÌa de ONGS");
					}
					break;
				
				default:
			    printf("Caracter erroneo,repitelo\n");
			    fflush ( stdin );
				break;
				
			}		
						
		} while(registro!=1&&registro!=2);
	}
		
		
	else
	{
		printf("\nCuenta existente");
		lectura_repositorio(lectura);
		elegir_donar(nombreArchivo2);
	}
	
};

void inicio(int menu)
{
	char donacionesInvitados[]="donacionesInvitados";
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
				lectura_repositorio(leer);
				printf("%c",nombreArchivo);
				elegir_donar(nombreArchivo);
				break;

			case 3:
				printf("\nAcceso como invitado\n");
				//Se abre fichero de lectura de las ongs
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
			
			printf("ø\n Quiere informacion de otro tipo de ongs?\n");
			printf("1: SI\n");
			printf("2: NO\n");
			fflush( stdin );
				do 
			{
				scanf("%d",&numero);
				switch(numero)
				{
					case 1:
						releer(lectura2);
						break;
					case 2:
						printf("Gracias por su visita a la guia de ongs ");
						break;
					default:
						printf("Numero incorrecto\n");
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
		
			printf("øQuiere informacion de otro tipo de ongs?\n");
			printf("1: SI\n");
			printf("2: NO\n");
			fflush( stdin );
			
			do 
			{
				scanf("%d",&numero);
				switch(numero)
				{
					case 1:
						releer(lectura2);
						break;
					case 2:
						printf("Gracias por su visita a la guia de ongs");
						break;
					default:
						printf("Numero incorrecto");
						break;
				}
				
			}while(numero!=1&&numero!=2);		
		}
		
	   
		else if( lectura=='c' || lectura=='C')
		{
			ayuda1=fopen("ayudas.txt","r");
			
			if ( ayuda1 ==NULL)
			{
				printf("Fichero no abierto");
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
			
			printf("øQuiere informacion de otro tipo de ongs?\n");
			printf("1: SI\n");
			printf("2: NO\n");
			fflush( stdin );
			do 
			{
				switch(numero)
				{
					scanf("%d",&numero);
			
					case 1:
						releer(lectura2);
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

void releer(char relectura)
{
	int i=1;
	lectura_repositorio(relectura);
	switch(i)
	{
		case 1 :
			break;
	}
};
}
