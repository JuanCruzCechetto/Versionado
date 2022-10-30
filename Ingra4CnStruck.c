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
                    
                    cargarProd();
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
void cargarProd()
{
    printf("--Ingres%c los datos del Producto--\n", 138);

    for(int i = 0; i < tam; i++)

    {
        printf("C%cdigo del producto: ",162); 
        scanf("%i", &lista_producto[i].codigodeP);
        fflush (stdin); 
        printf("Ingrese la descripci%cn: ",162);
        printf("\n");
        scanf("%[^\n]", &lista_producto[i].descripcion);
        
        
        printf("Ingrese la cantidad: ");
        printf("\n");
        scanf("%i", &lista_producto[i].cantidad);
        
    }
}
void modificarStockdeProductos()
{
    int codB = 0, cant = 0;
    int encontrado = 0;
    
    printf("Ingrese el C%cdigo del producto para modificar su stock: ", 162); 
    scanf("%i", &codB);

    for(int i = 0; i < tam; i++) 

    {
     
        if(codB == lista_producto[i].codigodeP)
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
void mostrarProductossinStock()
{  
    printf("Lista de electrodomesticos sin stock\n");
           
            for (int i = 0; i < tam ; i++)
            {
                
                if(lista_producto[i].cantidad ==0) 
                {
                    printf("Codigo del producto sin stock es: %i \n", lista_producto[i].codigodeP);
                    
                }
                
            }                                    
        
}         
void listadoProductos() 
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