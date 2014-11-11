#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void CrearArchivo(string nombre_archivo)
{
    ofstream out;
    out.open(nombre_archivo.c_str());
    out.close();
}

void ModificarArchivo(string nombre_archivo,string linea)
{
    ofstream out(nombre_archivo.c_str(),ios::in|ios::binary);
    out.write(linea.c_str(),100);
    out.close();
}

void VerArchivo(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());

    char linea[100];
    in.read(linea,100);
    cout<<linea<<endl;
}

void ListarArchivos()
{
    unsigned char isFile = 0x8;
    DIR* dir;
    dir = opendir("./");
    struct dirent *tipo = NULL;
    if(dir !=NULL)
    {
        while(tipo = readdir(dir))
        {
            //if(tipo->d_type == isFile) muestra solo los archivow pero se supone que solo funciona para linux por lo que investigue
            cout<<tipo->d_name<<endl;
        }
    }
}

void BorrarArchivo(string nombre_archivo)
{
    remove(nombre_archivo.c_str());
}

void CrearDirectorio(string nombre_directorio)
{
    mkdir(nombre_directorio.c_str());
}

void AbrirDirectorio(string nombre_directorio)
{
    chdir(nombre_directorio.c_str());
}

void CopiarArchivo(string nombre_archivo,string direccion, string destinatario)
{
    CopyFile(direccion.c_str(),string(destinatario+nombre_archivo).c_str(),TRUE);

}

void BorrarDirectorio(string nombre_directorio)
{
    rmdir(nombre_directorio.c_str());
}

void Ayuda()
{
    cout<<"********************** COMANDOS A UTILIZAR ***************************"<<endl;
    cout<<"********* Para Crear Archivo: creararchivo 'nombre del archivo' ******"<<endl;
    cout<<"****** Para Modificar Archivo: modificararchivo 'nombre del archivo' *"<<endl;
    cout<<"********** Para Ver Archivo: verarchivo 'nombre del archivo' *********"<<endl;
    cout<<"******** Para Borrar Archivo: borrararchivo 'nombre del archivo' *****"<<endl;
    cout<<"********* Para Crear Carpeta: crearcarpeta 'nombre de la carpeta' ****"<<endl;
    cout<<"****** Para Cambiar Carpeta: cambiarcarpeta 'nombre de la carpeta' ***"<<endl;
    cout<<"****** Para Copiar Archivo: copiararchivo 'nombre del archivo' *******"<<endl;
    cout<<"****************** Para Listar Archivos: listararchivos  *************"<<endl;
    cout<<"************************ Para Salir: salir  **************************"<<endl;
    cout<<"**********************************************************************"<<endl;
    //system("COLOR 0");
}

int main()
{
    system("COLOR 3");
    string nombre_archivo;
    string comando;

    cout<<"********** Para Mostrar Comandos de Ayuda Ingresa 'help'  *****"<<endl;

    while(comando != "salir")
    {
        cout<<"> ";
        cin>>comando;
         while((comando!="salir") && (comando != "listararchivos") && (comando != "help") && (comando!="verarchivo") && (comando!="creararchivo") && (comando!="modificararchivo") && (comando!="borrararchivo") && (comando!="crearcarpeta") && (comando!="cambiarcarpeta") && (comando!="copiararchivo") && (comando!="borrarcarpeta"))
            {
                cout<<"> ";
                cin>>comando;
            }
        if(comando == "salir")
            {break;}
        if(comando == "listararchivos")
            {ListarArchivos();}

        if(comando == "help")
            {Ayuda();}
       else if(comando != "listararchivos")
       {
           cin>>nombre_archivo;
            if(comando == "creararchivo")
                {   CrearArchivo(nombre_archivo);}
            if(comando == "modificararchivo")
                {   string linea;
                    cin.ignore();
                    getline(cin,linea);
                    ModificarArchivo(nombre_archivo,linea);
                }
            if(comando == "verarchivo")
                {   VerArchivo(nombre_archivo);}
            if(comando == "borrararchivo")
                {   BorrarArchivo(nombre_archivo);}
            if(comando == "crearcarpeta")
                {   CrearDirectorio(nombre_archivo);}
            if(comando == "cambiarcarpeta")
                {   AbrirDirectorio(nombre_archivo);}
            if(comando == "copiararchivo")
                {   string direccion = "C:\\Users\\usuario1\\Documents\\Ceutec\\Orga\\ExamenCasa\\hola.txt";
                    string destinatario = "C:\\Users\\usuario1\\Documents\\Ceutec\\Orga\\ExamenCasa\\mk\\";
                    //cout<<"Direccion del Archivo: ";
                    //cin>>direccion;
                    //cout<<"Destinatario del Archivo: ";
                    //cin>>destinatario;
                    CopiarArchivo(nombre_archivo,direccion,destinatario);}
            if(comando == "borrarcarpeta")
                {   BorrarDirectorio(nombre_archivo);}
       }
    }

    return 0;
}
