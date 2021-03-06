

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

 #include "funciones.h"
#include "propietarios.h"
#include "ingresoEgresos.h"



/** \brief ALTA DE CLIENTE
 *
 * \param array de estrcutrad de socio
 * \param tama�o del array
 * \return numero de index
 *
 */
int  altaCliente (ePropietario propietario[], int tamanio)
{
    int flag=0;
    int seguir='s';
    int index;
    while (seguir == 's')
        {
            index=searchIndexpropietario(propietario, tamanio);
            if (index != -1)
                {
                printf("\n\n---PRUEBA DE INDEX %d \t STATUS %d\n\n",index, propietario[index].status);

                propietario[index].idPropietario =index+100;
                printf("\n \nel ID del Propietarios es %d \n", propietario[index].idPropietario);

                printf("Ingrese el nombre y apellido:\t");
                fflush(stdin);
                gets(propietario[index].nombreyApellido);

                //////////////////ARMAR FUNCION QUE RECORRE EL ARRAY
                 /*   while (!(isalpha(propietario[index].nombreyApellido)))
                    {
                    printf("No ingreso un caracter valido - Ingrese el nombre y apellido:\t");
                    fflush(stdin);
                    gets(propietario[index].nombreyApellido);
                    }
*/
                printf("Ingrese el direccion:\t");
                fflush(stdin);
                gets(propietario[index].direccion);

                printf("Ingrese nro de tarjeta de credito:\t");
                fflush(stdin);
                gets(propietario[index].tarjetaCredito);
            /*    while (isalpha(propietario[index].tarjetaCredito))
                    {
                    printf("No ingreso un caracter valido - Ingrese nro de tarjeta de credito:\t");
                    fflush(stdin);
                    gets(propietario[index].nombreyApellido);
                    }
*/
                propietario[index].status=1;
                flag=1;

                seguir= preguntarSiNo( "\t \t Cargar otro propietario?\t");
                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE PROPIETARIOS LLENO\n===========================\n");
                break;
                }
        }
        return flag;

}

/** \brief buscar el primer index vacion en la usuarios/cliente/socio
 *
 * \param array de estrcutrad de socio
 * \param tama�o del array
 * \return numero de index
 *
 */
int searchIndexpropietario ( ePropietario status[], int tamanio)
{
    int index=-1;
    int i;
    for (i=0 ; i<tamanio ; i++)
            {
                if (status[i].status==0)
                {
                   index = i;
                   break;
                }
            }
    return index;
}


/** \brief lleva a CERO todo el indice de status de  la estrcutura usuario/cliente/socio
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
void indicePropietario(ePropietario usuarios[], int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
    usuarios[i].status=0;
     }
}
/** \brief Carga de Datos Inicial para poder operar
 *
 * \param estructura de usuarios/cliente/socio
 * \param tamanio total del array de usuarios/cliente/socio
 * \return
 *
 */
int cargarPropietario(ePropietario propietarios[], int tamanio)
{
    int i;
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

  for(i=0;i<tamanio;i++)
    {
    propietarios[i].idPropietario=id[i];
    strcpy(propietarios[i].nombreyApellido, nombre[i]);
    strcpy(propietarios[i].direccion, direccion[i]);
    strcpy(propietarios[i].tarjetaCredito, tarjeta[i]);
    propietarios[i].status=1;

    }
    return 1;

}


/** \brief mostrar 1 datos de 1 usuario/socio/cliente
 *
 * \param  un punto de la estrcutura de usuario/socio/cliente
 * \return
 *
 */


  void showOneClient (ePropietario usuarios)
{
 printf("\nidProp %d  Nom y Ap: %8s   Direccion %8s   Tarjeta :%5s   e:%d"  , usuarios.idPropietario , usuarios.nombreyApellido , usuarios.direccion,usuarios.tarjetaCredito, usuarios.status);
}

/** \brief mostrar listado de usuario/socio/cliente
 *
 * \param  array estrcutura de usuario/socio/cliente
 * \param  cantidad maxima de usuario/socio/cliente
 * \return
 *
 */
  void listadoDePropietario (ePropietario users [], int tamanio, int flag)
 {
      int i;
            if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY PROPIETARIOS CARGADOS\n======================\n");
            }
            else
            {
                printf("\n\n\n========================\n PROPIETARIOS CARGADOS\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (users[i].status==1)
                    {
                        showOneClient(users[i]);
                    }

                }
            }
 }



/** \brief modificacion de usuario/socio/cliente
 *
* \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 * \return
 *
 */

 void modificarPropietario (ePropietario users[], int tamanio, int flag)
 {
     int i;
     int idAux;
     int confirm;
     int flagchange=0;
     int opcion;

              if(flag!=0)
               {
               listadoDePropietario(users, tamanio, flag);
               printf("\n============================================================================\n");
               printf("\n\n Ingrese el Id del PROPIETARIO que desea Modificar:\t");
               scanf("%d", &idAux);
               cleanScreen();
               for (i=0; i<tamanio;i++)
                            {
                                if (users[i].idPropietario== idAux)
                                    {
                                    flagchange=1;
                                    printf("\n----------------------------");
                                    printf("\nEl cliente a modificar es\n");
                                    showOneClient(users[i]);
                                    printf("\n-------------------------------------------------------------------------\n");
                                    confirm =preguntarSiNo("\nSeguro que desea modificar el propietario:\t");
                                    if( confirm == 's')
                                    {

                                    do {
                                    printf("\n\n\n  == OPCIONES DE DATOS A MODIFICAR == \n\n 1- Nombre y Apellido \n 2- Direccion \n 3- Tarjeta de Credito \n \t \t Que dato desea modificar?\t");
                                    scanf ("%d", &opcion);
                                    switch(opcion)
                                        {
                                        case 1:
                                             printf("Ingrese el NUEVO nombre y apellido:\t");
                                            fflush(stdin);
                                            gets(users[i].nombreyApellido);
                                             break;
                                        case 2:
                                             printf("Ingrese LA NUEVA direccion:\t");
                                            fflush(stdin);
                                            gets(users[i].direccion);
                                             break;
                                        case 3:
                                            printf("Ingrese nro de tarjeta de credito:\t");
                                            fflush(stdin);
                                            gets(users[i].tarjetaCredito);
                                            break;
                                        default:

                                            fflush(stdin);
                                            printf("\n -------- No ingreso una opcion valida -----------");
                                            opcion=0;
                                             break;

                                           }
                                    }while (opcion ==0);

                                        printf("\n\n\n======================\n Propietario modificado\n======================\n");

                                        break;
                                    }// fin IF PREGUNTA S N
                                    else
                                    {
                                    printf("\n\n=====================================\n");
                                    printf("OPERACION CANCELADA");
                                    printf("\n=====================================\n");
                                    }

                                    break;
                                    } //FIN IF SI
                            } //FIN FOR

               if (flagchange==0)
                         {

                            printf("\n\n=====================================\n");
                            printf("PROPIETARIO NO EXISTE");
                            printf("\n=====================================\n");

                         }
               }// FIN FLAG !=0

                else
                {
                printf("\n\n=====================================\n");
                printf("NO HAY PROPIETARIOS CARGADOS");
                printf("\n=====================================\n");
                }


 }

