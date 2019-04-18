#include<stdio.h>
#include<stdlib.h> 
struct usuario
{	
	int accesso;
	char user[100];
	char contrasena[100];
};

void inicio(struct usuario u);

void main()
{
	system("color 3E");//Color de fondo y de las letras
	;struct usuario usuario1;
	inicio(usuario1);
}

void inicio(struct usuario u )
{
	
	FILE *newusers;
	FILE *ongs;
	//FILE *password;
	printf("BIENVENIDO A CLININCA, TUS GUIAS DE ONGS \n");
	printf("Para iniciar sesion pulse 1\n");
	printf("Para registrarte pulsa 2 \n");
	printf("Para pasar como invitado pulse 3\n");
	printf("Para salir pulse 0 \n");
	
	do{
	scanf("%d",&u.accesso);

		switch (u.accesso)
		{
            case 0:
                 break;
			case 1:
				printf("Inicio de sesion\n");
				printf("Username o e-mail\n");
				scanf("%s",u.user);
				fflush( stdin );
				// Se abre fichero que guarda el usuario 
				newusers=fopen("usuarios.txt","a");
				//Se escribe sobre el fichero del usuario
				fprintf (newusers, "%s- ",u.user);
				printf("Contrasena\n");
				scanf("%s",u.contrasena);
				//Se escribe sobre el fichero del usuario donde se ha guardado el nombre del usuario y se escribe la contraseña
				fprintf(newusers, "%s\n", u.contrasena);
				//Se cierra el fichero
				fclose(newusers);
			break;

			case 2:
				printf("Registro\n");
				printf("Introduzca su Usenarme o e-mail\n");
				scanf("%s",u.user);
				fflush( stdin);
				//Se abre fichero que guarda el usuario creado 
				newusers=fopen("usuarios.txt","a");
				//Se escribe sobre el fichero del usuario
				fprintf (newusers, "%s-",u.user);
				printf("Introduzca su contrasena\n");
				scanf("%s",u.contrasena);
				//Se escribe sobre el fichero del usuario donde se ha guardado el nombre del usuario y se escribe la contraseña
				fprintf (newusers, "%s\n", u.contrasena);
				//Se escribe el fichero
				fclose(newusers);
				//Se abre fichero de lectura de las ongs
				ongs=fopen("ongs.txt","r");
				//Se cierra fichero de lectura de las ongs
				fclose(ongs);
				
			break;

			case 3:
				printf("Acceso como invitado");
				//Se abre fichero de lectura de las ongs
				ongs=fopen("ongs.txt","r");
				//Se cierra fichero de lectura de las ongs
				fclose(ongs);
				break;

			default:
			    printf("Numero erroneo,repitelo\n");
			    scanf("%s",u.accesso);
				break;

		}
	}while( u.accesso!=0&&u.accesso!=1&&u.accesso!=2&&u.accesso!=3 );
}
