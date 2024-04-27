#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//======================= arreglo dado en el apartado ===================================
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
//=======================================================================================

//======================== Estructuras ==================================================
typedef struct {
    int ProductoID;        // Numerado en ciclo iterativo
    int Cantidad;          // entre 1 y 10
    char *TipoProducto;    // Algún valor del arreglo TiposProductos
    float PrecioUnitario;  // entre 10 - 100
} Producto;
typedef struct {
    int ClienteID;                // Numerado en el ciclo iterativo
    char *NombreCliente;          // Ingresado por usuario
    int CantidadProductosAPedir;  // (aleatorio entre 1 y 5)
    Producto *Productos;          // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
} Cliente;
//==========================================================================================

//======================= Funciones ========================================================
//----Funcion para cargar aleatoriamente los productos de un cliente
//--recibe el puntero productos que esta dentro de la estructura cliente
//--cant es la cantidad de productos a cargar en ese cliente
void cargarProductos(Producto *producto, int cant);
void cargarProductos(Producto *producto, int cant) {
    for (int i = 0; i < cant; i++) {
        producto[i].ProductoID = i;
        producto[i].Cantidad = rand() % 10 + 1;
        char aux[20];  // creo esta variable aux para guardar un tipo de prod
        // guardo un tipo del arreglo en la variable aux, elijo un indice aleatorio
        strcpy(aux, TiposProductos[rand() % 5]);
        // en base al tamaño de la palabra cargada, dimensiono el punutero del producto donde se guardará el tipo
        producto[i].TipoProducto = (char *)malloc(1 + strlen(aux) * sizeof(char));
        // guardo en la variable del producto
        strcpy(producto[i].TipoProducto, aux);
        producto[i].PrecioUnitario = rand() % 100 + 11;
    }
}

void cargarClientes(Cliente *cliente, int cant);
void cargarClientes(Cliente *cliente, int cant) {
    for (int i = 0; i < cant; i++)
    {
        cliente[i].ClienteID = i;
        char name[20];//creo una var aux para guardar momentaneamente el name del cliente
        printf("\n-Ingrese el nombre del cliente num %d: ", i+1);
        fflush(stdin);
        gets(name);
        //doy tama el puntero donde se guarda el name, sumando el espacio para el caracter nulo
        cliente[i].NombreCliente = (char*)malloc(strlen(name) * sizeof(char) + 1);
        //guardo el name
        strcpy(cliente[i].NombreCliente, name);
        cliente[i].CantidadProductosAPedir = rand() % 5 + 1;
        //en base a la cant de prod a pedir, dimensiono el puntero de tipo producto
        cliente[i].Productos = (Producto*)malloc(cliente[i].CantidadProductosAPedir * sizeof(Producto));
        //ahora uso la funcion para cargar productos random
        cargarProductos(cliente[i].Productos, cliente[i].CantidadProductosAPedir);
    }
}

float costoTotal(Producto producto);
float costoTotal(Producto producto){
    return producto.Cantidad * producto.PrecioUnitario;   
}

void mostrarTodo(Cliente *cliente, int cant);
void mostrarTodo(Cliente *cliente, int cant){
    printf(">>>>>> Clientes y Pedidos <<<<<<\n");
    printf("\n");
    for (int i = 0; i < cant; i++)
    {
        float total = 0;
        printf("----- Cliente %d -----\n", i+1);
        printf("-- ID cliente: %d\n", cliente[i].ClienteID);
        printf("-- Nombre: %s\n", cliente[i].NombreCliente);
        printf("-- Cant prod a pedeir: %d\n", cliente[i].CantidadProductosAPedir);
        //calculo el total
        for (int j = 0; j < cliente[i].CantidadProductosAPedir; j++)
        {
            total = total + costoTotal(cliente[i].Productos[j]);
        }
        printf("-- Total: $%.2f\n", total);
        printf("----------------------\n");
    }

}
//==========================================================================================
int main() {
    int cantClientes;  // aqui guardo la cantidad de clientes, max 5
    printf("\n>>Ingrese la cantidad de clientes a cargar: ");
    do {
        scanf("%d", &cantClientes);
    } while (cantClientes < 1 || cantClientes > 5);
    // creo el arreglo dinamico de clientes
    Cliente *clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente));
    cargarClientes(clientes, cantClientes);
    mostrarTodo(clientes, cantClientes);
    free(clientes);
    return 0;
}