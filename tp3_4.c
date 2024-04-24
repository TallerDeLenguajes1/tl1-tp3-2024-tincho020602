#include <stdio.h>
#include <stdlib.h>

char *TiposProductos[]={"Galletas","Snack",
                        "Cigarrillos","Caramelos",
                        "Bebidas"};
struct{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos;//El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;

int main(){
    Cliente *comprador;
    int cantCliente;
    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d",&cantCliente);
    fflush(stdin);
    comprador=(Cliente *)malloc(cantCliente* sizeof(Cliente));

    printf("\nIngrese el id de cada cliente: ");
    for (int i = 0; i < cantCliente; i++)
    {
        comprador[i].ClienteID=i+1;
        printf("\nIngrese el nombre del cliente %d: ",comprador[i].ClienteID);
        comprador[i].NombreCliente=(char*)malloc(sizeof(char)*100);
        gets(comprador[i].NombreCliente);
        fflush(stdin);
    }

    for (int i = 0; i < cantCliente; i++)
    {
        printf("\nNombre del cliente %d: %s",comprador[i].ClienteID,comprador[i].NombreCliente);
    }

    

    return 0;
}