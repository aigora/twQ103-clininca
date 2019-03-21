
#include<stdio.h>

int main ()
{
    int acceso;
	char user[100] ;
	char contrasena[100];

	printf("BIENVENIDO A CLININCA, TUS GUIAS DE ONGS \n");

	printf("Para iniciar sesion pulse 1\n");
	printf("Para registrarte pulsa 2 \n");
	printf("Para pasar como invitado pulse 3\n");
	printf("Para salir pulse 0 \n");

	do{
	scanf("%d",&acceso);



		switch (acceso)
		{
            case 0:
                 return 0;
                 break;
			case 1:
				printf("Username o e-mail\n");
				scanf("%s",user);
				printf("Contrasena\n");
				scanf("%s",contrasena);
			break;

			case 2:
				printf("Introduzca su Usenarme o e-mail\n");
				scanf("%s",user);
				printf("Introduzca su contrasena\n");
				scanf("%s",contrasena);
			break;

			case 3:
				// Se abre fichero para la lectura de las ongs
				printf("Introduzca su Usenarme o e-mail\n");
				scanf("%s",user);
				printf("Introduzca su contrasena\n");
				scanf("%s",contrasena);
			break;

			default:
			    printf("numero erroneo,repitelo\n");
				break;

		}
	}while(acceso!=0&&acceso!=1&&acceso!=2&&acceso!=3);






	return 0;
}
