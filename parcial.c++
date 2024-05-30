#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef struct
{
    int codigo, dni;
    string apellido, nombre; 

}tSolicitud;

const int limite = 100;
typedef tSolicitud tArray[limite];
 
typedef struct 
{
    tArray elemento;
    int contador = 0;

}tLista;

void menu();
void cargarDatos(tLista& lista);
void guardarDatos(tLista lista);
void altaSolicitud(tLista& lista);
void bajaSolicitud(tLista& lista);
void modificarSolicitud(tLista& lista);
void buscarSolicitud(tLista lista);
void mostrarLista(tLista lista);
void mostrarDatos(tLista lista, int posicion);
int buscarPosicion(tLista lista);

void clearConsole()
{
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN32)
        system("cls");
    #endif defined
}

void pauseConsole()
{
    cin.ignore();
    cin.get();
}

int main()
{
    menu();

    return 0;
}
void menu()
{
    int opcion = 0;
    tLista lista;

    cargarDatos(lista);

    do
    {
        clearConsole();

        cout << "\t\t\nOpciones de Solicitud\n\n";
        cout << "1. Dar de alta un Solicitud\n";
        cout << "2. Dar de baja un Solicitud\n";
        cout << "3. Modificar un Solicitud\n";
        cout << "4. Buscar un Solicitud\n";
        cout << "5. Mostra lista de Solicitudes\n";
        cout << "6. Cerrar Programa!\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                altaSolicitud(lista);
                break;
            case 2:
                bajaSolicitud(lista);
                break;
            case 3:
                modificarSolicitud(lista);
                break;
            case 4:
                buscarSolicitud(lista);
                break;
            case 5:
                mostrarLista(lista);
                break;
            case 6:
                cout << "Programa Finalizado!";
                break;
            default:
                cout << "Opcion Incorrecta";
                break;
        }
    }while(opcion != 6);

    guardarDatos(lista);

}
void cargarDatos(tLista& lista)
{
    ifstream archivo;
    lista.contador = 0;

    archivo.open("solicitudes.csv");

    if(archivo.is_open())
    {
        string linea;

        while (getline(archivo, linea)) 
        {
            if(lista.contador >= limite)
            {
                return;
            }

            istringstream iss(linea);
            string campo;
            
            getline(iss, campo, ',');
            lista.elemento[lista.contador].codigo = stoi(campo);

            getline(iss, campo, ',');
            lista.elemento[lista.contador].apellido = campo;

            getline(iss, campo, ',');
            lista.elemento[lista.contador].nombre = campo;

            getline(iss, campo, ',');
            lista.elemento[lista.contador].dni = stoi(campo);

            lista.contador++;
        }

        archivo.close();
    }
    else
    {
        cout << "No se encontro el archivo!";
    }
}
void altaSolicitud(tLista& lista)
{
    tSolicitud solicitud;

    clearConsole();

    cout << "\n\t\t~~~Dar de alta Solicitud~~~\n\n";

    if(lista.contador >= limite)
    {
        cout << "No se puede agregar mas clientes!\n";
        return;
    }

    solicitud.codigo = lista.contador + 100;

    if(solicitud.codigo == lista.elemento[lista.contador - 1].codigo)
    {
        solicitud.codigo++;
    }

    cout << "Ingrese apellido del cliente que realiza la solicitud: ";
    cin.ignore();
    getline(cin, solicitud.apellido);
    cout << "Ingrese nombre del cliente que realiza la solicitud: ";
    getline(cin, solicitud.nombre);
    cout << "Ingrese DNI del cliente que realiza la solicitud: ";
    cin >> solicitud.dni;
    cout << "El codigo de solicitud es: " << solicitud.codigo << endl;
    cout << "\nSolicitud agregada correctamente!\n";

    lista.elemento[lista.contador] = solicitud;
    lista.contador++;

    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();

}
void bajaSolicitud(tLista& lista)
{
    clearConsole();

    cout << "\n\t\t~~~Dar de Baja un Solicitud~~~\n\n";

    int posicion = buscarPosicion(lista);

    if(posicion != -1)
    {
        bool opcion;
        
        mostrarDatos(lista, posicion);
        
        cout << "Es la Solicitud que quiere dar de Baja?\n";
        cout << "Para si ingrese '1'\n";
        cout << "Para no ingrese '0'\n";
        cout << "opcion: ";
        cin >> opcion;

        if(opcion)
        {
            for(int i = posicion; i < lista.contador - 1; i++)
            {
                lista.elemento[i] = lista.elemento[i + 1];
            }
            lista.contador--;
            cout << "Solicitud eliminada correctamente!\n";
        }
        else
        {
            cout << "No se dio de Baja la Solicitud!\n";
        }
    }
    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
}
void modificarSolicitud(tLista& lista)
{
    clearConsole();

    cout << "\n\t\t~~~Modificar Solicitud~~~\n\n";
    int posicion = buscarPosicion(lista);

    if(posicion != -1)
    {
        bool opcion;
        
        mostrarDatos(lista, posicion);

        cout << "Es la Solicitud que quiere Modificar?\n";
        cout << "Para si ingrese '1'\n";
        cout << "Para no ingrese '0'\n";
        cout << "opcion: ";
        cin >> opcion;

        if(opcion)
        {
            cout << "Ingrese el nuevo Apelllido: ";
            cin.ignore();
            getline(cin, lista.elemento[posicion].apellido);
            cout << "Ingrese el nuevo Nombre: ";
            getline(cin, lista.elemento[posicion].nombre);
            cout << "Ingrese el nuevo DNI: ";
            cin >> lista.elemento[posicion].dni;
            cout << "Solicitud modificada correctamente!\n";
        }
        else
        {
            cout << "No se Modifico la Solicitud!\n";
        }
    }
    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
}
void buscarSolicitud(tLista lista)
{
    clearConsole();

    cout << "\n\t\t~~~Buscar Solicitud~~~\n\n";

    int posicion = buscarPosicion(lista);

    if(posicion != -1)
    {
        mostrarDatos(lista, posicion);
    }
    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
}
void mostrarLista(tLista lista)
{
    clearConsole();

    cout << "\n\t\t~~~Lista de Solicitudes~~~\n\n";
    cout << setw(6) << " Codigo";
    cout << setw(16) << "Apellido/s" << setw(4);
    cout << setw(20) << "Nombre/s" << setw(5);
    cout << setw(14) << "DNI\n";

    for (int i = 0; i < lista.contador; i++)
    {
        cout << setw(6) << lista.elemento[i].codigo << " "; 
        cout << setw(20) << lista.elemento[i].apellido << " ";
        cout << setw(20) << lista.elemento[i].nombre << " ";
        cout << setw(9) << lista.elemento[i].dni << endl;
    }


    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
    
}
void mostrarDatos(tLista lista, int posicion)
{
    cout << "Codigo de Solicitud: " << lista.elemento[posicion].codigo << endl;
    cout << "Apellido: " << lista.elemento[posicion].apellido << endl;
    cout << "Nombre: " << lista.elemento[posicion].nombre << endl;
    cout << "DNI: " << lista.elemento[posicion].dni << endl;
}
int buscarPosicion(tLista lista)
{
    int posicion = -1, codigo = 0;

    cout << "Ingrese el codigo de Solicitud: ";
    cin >> codigo;

    
    for (int i = 0; i < lista.contador; i++) 
    {
        if(codigo == lista.elemento[i].codigo)
        {
            posicion = i;
            break;
        }
    }
    if(posicion != -1)
    {
        return posicion;
    }
    else
    {
        cout << "Solicitud no encontrada!\n";
        return -1;
    }
}
void guardarDatos(tLista lista)
{
    ofstream archivo;

    archivo.open("solicitudes.csv");

    if(archivo.is_open())
    {
        for(int i = 0; i < lista.contador; i++)
        {
            archivo << lista.elemento[i].codigo << "," << lista.elemento[i].apellido << "," 
            << lista.elemento[i].nombre << "," << lista.elemento[i].dni << endl;
        }

        archivo.close();
    }
}