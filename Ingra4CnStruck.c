/*
Se desea realizar un programa que gestione el stock de un negocio de venta de 
electrodomésticos. Como máximo se permitirán cargar 100 electrodomésticos. De cada 
electrodoméstico se conoce su código de barras, su descripción y una cantidad en stock. 
Se deberá presentar un menú con las siguientes opciones:
1. Cargar productos.
2. Modificar stock.
3. Mostrar productos sin stock.
4. Listar productos.
5. Salir.
Donde, la opción 1 permite cargar los 100 electrodomésticos ingresando para cada uno: código 
de barras, descripción y cantidad.
La opción 2 debe pedir el código de barras del electrodoméstico al cual se desea cambiar el 
stock y la nueva cantidad. Si el código de barras ingresado no existe, informar la situación con 
un mensaje “Electrodoméstico inexistente”, si el código de barras si se encuentra modificar su 
stock con la cantidad ingresada.
La opción 3 debe mostrar en la consola los datos de aquellos electrodomésticos con cantidad 
igual a cero.
La opción 4 debe mostrar en la consola el listado de electrodomésticos.
SOLO se saldrá de la aplicación si se selecciona la opción 5
 
Juan Cruz Cechetto
Sara Guala
Valentin Gimenez
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct producto
{
    int codigodeP;
    char descripcion[50];
    int cantidad;
};
struct producto lista_producto [100];

const int tam = 2;

void cargarProd();
void modificarStockdeProductos();
void mostrarProductossinStock();
void listadoProductos();

void main()
{
    int opcion = 0;
    int des = 0;

    do
    {
        printf("\n1- Cargar productos.");
        printf("\n2- Modificar Stock del Producto.");
        printf("\n3- Mostrar Productos sin stock.");
        printf("\n4- Listar Productos.");
        printf("\n5- Salir.\n\n");
        scanf("%d", &opcion);

          if(opcion != 5)
          {
            switch(opcion)
            {
                case 1: 
                    
                    cargarProd(); //sub proceso
                    break;
                case 2: 
                    
                    modificarStockdeProductos();
                    break;
                case 3: 
                    
                    mostrarProductossinStock();
                    break;
                case 4: 
                 
                    listadoProductos();
                    break;
                     
                default:
                    printf("La opci%cn ingresada es inv%clida\n", 162, 160);
            }  
        }

    } while (opcion != 5);


}
void cargarProd() //Subproceso=Pide datos y va guardando en c/arreglo // For se mueve hasta la cantidad de productos que tenga/quieras cargar
{
    printf("--Ingres%c los datos del Producto--\n", 138);

    for(int i = 0; i < tam; i++)

    {
        printf("C%cdigo del producto: ",162); 
        scanf("%i", &lista_producto[i].codigodeP);
        fflush (stdin); //Limpia la consola
        printf("Ingrese la descripci%cn: ",162);
        printf("\n");
        scanf("%[^\n]"/*Deja ingresar palabras con espacio*/, &lista_producto[i].descripcion);
        
        
        printf("Ingrese la cantidad: ");
        printf("\n");
        scanf("%i", &lista_producto[i].cantidad);
        
    }
}
void modificarStockdeProductos() // Pide un Cdebarra se fija si esta en la lista de codigos.
{
    int codB = 0, cant = 0;
    int encontrado = 0;
    
    printf("Ingrese el C%cdigo del producto para modificar su stock: ", 162); 
    scanf("%i", &codB);

    for(int i = 0; i < tam; i++) //recorre todos los productos y nos permite modificar el stock cuando encuentra el mismo codigo de barra

    {
     
        if(codB == lista_producto[i].codigodeP) // Si el Cod esta en la lista pide que ingrese nuevo stock
        {
            printf("\n1- Ingrese nuevo stock: \n", lista_producto[i].codigodeP);
            printf("\n");
            scanf("%i", &cant);
            lista_producto[i].cantidad = cant;  
            encontrado = 1; 
            printf("Stock actualizado");
        }
    }

    if (encontrado == 0)
    {
        printf("El electrodom%cstico es inexistente...\n", 138);  
    }
}
void mostrarProductossinStock() //Recorre los productos y si alguno es igual a 0 (sin stock) se muestra
{  
    printf("Lista de electrodomesticos sin stock\n");
           
            for (int i = 0; i < tam ; i++)
            {
                
                if(lista_producto[i].cantidad ==0) //controla si producto tiene stock 0  
                {
                    printf("Codigo del producto sin stock es: %i \n", lista_producto[i].codigodeP);
                    
                }
                //Mejora: hacer un IF fuera del for pára la variable encontrada
            }                                    
        
}         
void listadoProductos() //recorre todo el arreglo y muestra toda la informacion de todos los produco
{
    printf("Listado de productos: \n");

    for(int i = 0; i < tam; i++)
    {
        
        
        printf("Codigo de Barra: %d\t ", lista_producto[i].codigodeP);
        printf("Descripcion: %s\t ", lista_producto[i].descripcion);
        printf("Stock: %d \t", lista_producto[i].cantidad);  
        printf("\n");
    }
}