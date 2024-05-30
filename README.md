# AyED1_Primer_Parcial

1. Gestionar las Solicitudes
a. Dar de alta la Solicitud (el código de la Solicitud es la ubicación en el array x 100).
b. Dar de Baja las Solicitudes x código de Solicitud.
c. Modificar las Solicitudes, ingresar el código, mostrarlo y editarlo.
2. Listar las solicitudes.
a. Listar todas las Solicitudes.
b. Buscar unas Solicitud x código y mostrarla (imprimir cartel de no encontrado).
3. Todo esto mediante un Menú, Modularizando en Funciones, utilizando Archivos, arreglos y
estructuras.

# Sistema de Gestión de Solicitudes

Este proyecto es un programa en C++ para la gestión de solicitudes. El objetivo del programa es permitir la carga, modificación, búsqueda, eliminación y visualización de solicitudes realizadas por clientes.

## Descripción

El programa utiliza estructuras y arreglos para manejar las solicitudes, cada una de las cuales contiene información del cliente y un código único. La información se guarda y carga desde un archivo CSV.

### Funcionalidades

1. **Cargar Solicitudes**: Lee las solicitudes de un archivo CSV y las carga en memoria.
2. **Guardar Solicitudes**: Guarda las solicitudes en memoria en un archivo CSV.
3. **Dar de Alta una Solicitud**: Permite agregar una nueva solicitud.
4. **Dar de Baja una Solicitud**: Permite eliminar una solicitud existente.
5. **Modificar una Solicitud**: Permite modificar los datos de una solicitud existente.
6. **Buscar una Solicitud**: Permite buscar una solicitud por su código.
7. **Mostrar Lista de Solicitudes**: Muestra todas las solicitudes en la consola.

### Estructura del Proyecto

- `main.cpp`: Contiene la función principal del programa y el menú de opciones.
- `solicitudes.csv`: Archivo CSV utilizado para almacenar las solicitudes.
