#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "empleados.h"
#include"equipo.h"
#include"alquileres.h"



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void indiceAlquiler(eAlquiler alquiler[], int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
    strcpy(alquiler[i].status, "LIBRE");
     }

    alquiler[0].idCliente =10;
    alquiler[1].idCliente =10;
    alquiler[2].idCliente =10;

    alquiler[0].idEquipo =40;
    alquiler[1].idEquipo =41;
    alquiler[2].idEquipo  =42;

    alquiler[0].idOperador =21;
    alquiler[1].idOperador  =21;
    alquiler[2].idOperador   =21;

    alquiler[0].tiempoAlquiler=7;
    alquiler[1].tiempoAlquiler=29;
    alquiler[2].tiempoAlquiler =2;

    for (i=0 ; i<3;i++)
    {
    alquiler[i].idAlquiler=i+1;
    strcpy(alquiler[i].status, "ALQUILADO");
   }

}





/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void alquilarEquipo(eAlquiler alquiler[], eClientes cliente[],eEmpleados operador[] ,eEquipo equipo[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos)
 {
     int i;
     int j;
     int k;
     int l;
     int m;
     int n;
     int idClienteAux;
     int idOperadorAux;
     int idEquipoAux;

    listadoDeClientes(cliente, CantClientes);
    printf("\n\nIngrese el id de cliente que desea alquilar un equipo :");
    scanf("%d", &idClienteAux);

for (i=0; i <CantAlquileres; i++)
{
    if (strcmp(alquiler[i].status,"LIBRE")==0) // busco el indice disponible en las relaciones de alquiler
    {
       strcpy(alquiler[i].status,"ALQUILADO");
       alquiler [i].idAlquiler=i+1;
       for (j=0; j<CantClientes; j++) // recorro
        {
           if (idClienteAux== cliente[j].idCliente)
                {
                alquiler [i].idCliente=idClienteAux;
                listadoDeEquipos(equipo, CantEquipos);
                printf("\n\nIngrese el id de equipo que desea alquilar un equipo :");
                scanf("%d", &idEquipoAux);
                for (k=0; k<CantEquipos; k++)
                {
                    if (idEquipoAux== equipo[k].idEquipo)
                    {
                        alquiler [i].idEquipo=idEquipoAux;

                        listadoDeEmpleados(operador, CantOperadores);
                        printf("\n\nIngrese el id del operario :");
                        scanf("%d", &idOperadorAux);

                        for(l=0; l<CantOperadores; l++)
                        {
                            if(idOperadorAux==operador[l].idEmpleado)
                            {
                                alquiler[i].idOperador=idOperadorAux;

                                printf("\n\nIngrese cuantos dias que estara alquilado el equipo :");
                                scanf("%d", &alquiler[i].tiempoAlquiler);
                                break;
                            }
                        }
                        break;
                    }
                }
            break;
                }

        }
        break;

    }

    }
       printf("\n================================================");
        printf("\nCliente:");
        showOneClient(cliente[j]);
        printf("\n");
        printf("\nEquipo:");
        showOneEquip(equipo[k]);
        printf("\n");
        printf("\nSera Operado por:");
        showOneEmploye(operador[l]);
        printf("\n");
        printf("\nEstara alquilado por %d Dias", alquiler[i].tiempoAlquiler);

    printf("\n\n=========== ALQUILER INGRESADO ==============");

 }

 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

  void devolucionEquipo(eAlquiler alquiler[], eClientes cliente[],eEmpleados operador[] ,eEquipo equipo[],int CantAlquileres, int CantClientes,int CantOperadores,int CantEquipos)
 {
     int i;
     int j;
     int k;
     int l;
     int m;
     int idAlquilerAux;
     int idClienteAux;
     int idOperadorAux;
     int idEquipoAux;
     int auxTiempo;
     char seguir;
     int flag=0;

    listadoDeClientes(cliente, CantClientes);
    printf("\n\nIngrese el id de cliente que desea devolver un equipo :");
    scanf("%d", &idClienteAux);


       for (j=0; j<CantClientes; j++) // recorro los clientes
        {
           if (idClienteAux== cliente[j].idCliente) // si el cliente es igual al que busco
                {
           for (i=0; i <CantAlquileres; i++) // recorro los alquileres realizados
                {
                if (cliente[j].idCliente==alquiler[i].idCliente && strcmp(alquiler[i].status,"ALQUILADO")==0 ) // busci los alquilere que realizo ese cliente
                    {
                        printf("\n-----Transacion %d -- Estado %s------",alquiler[i].idAlquiler, alquiler[i].status); // que cleinte es

                       for (k=0; k<CantEquipos; k++) // recorro lo equipo
                        {
                            if (alquiler[i].idEquipo== equipo[k].idEquipo) //i si el equipo del alquiler coincide con la base
                            {
                                flag=1;
                            showOneEquip(equipo[k]); // muestro una linea de equipo
                            break;
                            }
                        }

                    }
                }
                break;
                }

        }




     if (flag==0)
         {
             printf("\n\n=========== No existe el usuario ==============\n");
         }
    else
         {
             printf("\n\nIngrese el id de transaccion que desea devolver el equipo :");
            scanf("%d", &idAlquilerAux);

             int flagTrans=0;
             for (m=0; m<CantAlquileres; m++)
             {
                 if(idAlquilerAux==alquiler[m].idAlquiler)
                 {
                     flagTrans=1;
                     printf("\t \t Esta seguro que desea borrar la transaccion  S-N\t");
                     fflush(stdin);
                     seguir=tolower(getche());
                    seguir = ValidacionSiNo(seguir,"\n Respuesta Incorrecta - desea borrar la transaccion ? S-N");
                     if (seguir=='s')
                     {
                        strcpy(alquiler[m].status,"FINALIZADO");
                        printf("\n\n=========== DEVOLUCION INGRESADA ==============\n");
                        break;
                     }
                     else
                    {
                        printf("\n\n=========== OPERACION CANCELADA ==============\n");
                    }

                 }
             }

             if(flagTrans==0 )
                {
                        printf("\n\n=========== la transaccion ingresado no existe ==============\n");
                    }


    }





}


   /*    printf("\n================================================");
       printf("\nCliente:");
       showOneClient(cliente[j]);
        printf("\n");
        printf("\nEquipo:");
        showOneEquip(equipo[k]);
        printf("\n");
        printf("\n");
        printf("\nEstara alquilado por %d Dias", alquiler[i].tiempoAlquiler);*/


