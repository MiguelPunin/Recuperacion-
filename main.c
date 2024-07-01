#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Producto productos[MAX_PRODUCTS] = {
        {"Vape Sabor Menta", 10, 10.0},   {"Vape Sabor Fresa", 10, 10.0},
        {"Vape Sabor Mango", 10, 10.0},   {"Vape Sabor Uva", 10, 10.0},
        {"Vape Sabor Sandia", 10, 10.0},  {"Vape Sabor Piña", 10, 10.0},
        {"Vape Sabor Limón", 10, 10.0},   {"Vape Sabor Coco", 10, 10.0},
        {"Vape Sabor Naranja", 10, 10.0}, {"Vape Sabor Plátano", 10, 10.0}
    };
    int numProductos = 10; // Número inicial de productos (los vapes)
    int opcion;

    do {
        printf("\nSistema de Inventarios\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Comprar productos\n");
        printf("6. Control de inventario\n");
        printf("7. Fusionar archivos\n");
        printf("8. Salir\n");
        printf("Seleccionar una opción: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                ingresarProducto(productos, &numProductos);
                break;
            case 2:
                editarProducto(productos, numProductos);
                break;
            case 3:
                eliminarProducto(productos, &numProductos);
                break;
            case 4:
                listarProductos(productos, numProductos);
                break;
            case 5:
                comprarProductos(productos, numProductos);
                break;
            case 6:
                controlDeInventario(productos, numProductos);
                break;
            case 7: {
                char archivoDestino[NAME_LENGTH];
                int numArchivos;
                printf("Ingresar nombre del archivo de destino: ");
                fgets(archivoDestino, NAME_LENGTH, stdin);
                archivoDestino[strcspn(archivoDestino, "\n")] = 0; // Eliminar el salto de línea

                printf("Ingresar número de archivos a fusionar: ");
                scanf("%d", &numArchivos);
                getchar();  // Limpiar el buffer de entrada

                const char *archivos[numArchivos];
                for (int i = 0; i < numArchivos; i++) {
                    archivos[i] = (char *)malloc(NAME_LENGTH * sizeof(char));
                    printf("Ingresar nombre del archivo %d: ", i + 1);
                    fgets((char *)archivos[i], NAME_LENGTH, stdin);
                    ((char *)archivos[i])[strcspn(archivos[i], "\n")] = 0; // Eliminar el salto de línea
                }

                fusionarArchivos(archivoDestino, archivos, numArchivos);

                for (int i = 0; i < numArchivos; i++) {
                    free((void *)archivos[i]);
                }
                break;
            }
            case 8:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 8);

    return 0;
}
