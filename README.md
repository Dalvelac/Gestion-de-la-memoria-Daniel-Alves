https://github.com/Dalvelac/Gestion-de-la-memoria-Daniel-Alves/

# Descripción del Programa

Este programa demuestra el uso de memoria compartida para la comunicación entre un proceso principal y un proceso hijo en Windows, utilizando la API de Windows. El proceso principal crea un segmento de memoria compartida y escribe un mensaje para el proceso hijo. Luego, el proceso hijo lee este mensaje desde la memoria compartida. La comunicación se logra utilizando un archivo de memoria mapeada (memory-mapped file).
Componentes Principales

    Memoria compartida: Utiliza CreateFileMapping y MapViewOfFile para crear y mapear un segmento de memoria compartida en el espacio de direcciones del proceso.
    Creación de proceso hijo: Se utiliza CreateProcess para iniciar un proceso hijo que puede acceder al segmento de memoria compartida.
    Sincronización: El proceso principal espera a que el proceso hijo termine usando WaitForSingleObject.

## Requisitos

Windows con soporte para la API de Windows.
Compilador C compatible con Windows, como GCC (MinGW) o Microsoft Visual Studio.

## Instrucciones para Compilar y Ejecutar

A continuación, se proporcionan dos métodos para compilar y ejecutar el programa: usando Google Cloud Shell y usando una máquina virtual de Ubuntu.

# Método 1: Google Cloud Shell

Acceder a Google Cloud Shell: Ve a Google Cloud Shell e inicia una sesión.

Instalar el compilador MinGW: Google Cloud Shell está basado en Linux, así que necesitarás instalar MinGW para compilar código de Windows. Ejecuta lo siguiente:
```
sudo apt-get update
sudo apt-get install mingw-w64
``` 

## Compilar el programa: Copia el código fuente del programa a un archivo, por ejemplo shared_memory.c, y luego compílalo usando el compilador MinGW:

    x86_64-w64-mingw32-gcc shared_memory.c -o shared_memory.exe

Transferir el ejecutable a Windows: Una vez compilado, necesitarás descargar shared_memory.exe a tu máquina Windows para ejecutarlo, ya que está construido para ese entorno.

# Método 2: Compilar en una Máquina Virtual de Ubuntu

Configurar la VM de Ubuntu: Puedes usar VirtualBox o cualquier proveedor de servicios en la nube para configurar una VM con Ubuntu.

Instalar el compilador MinGW: Para compilar el código de Windows en Ubuntu, instala MinGW ejecutando:

```
sudo apt-get update
sudo apt-get install mingw-w64
```

Copiar el Código Fuente: Crea un archivo llamado shared_memory.c y pégale el código proporcionado.

Compilar el Programa: Utiliza MinGW para compilar el archivo en un ejecutable de Windows:

    x86_64-w64-mingw32-gcc shared_memory.c -o shared_memory.exe

Transferir el Ejecutable a Windows: Descarga el archivo shared_memory.exe a tu máquina Windows para ejecutarlo.

Ejecución del Programa en Windows

Una vez que tengas el ejecutable (shared_memory.exe) en tu máquina Windows, sigue estos pasos:

Abrir el Command Prompt: Pulsa Win + R, escribe cmd y presiona Enter.

Ejecutar el Programa: Navega al directorio donde está el archivo shared_memory.exe y ejecútalo escribiendo:

    shared_memory.exe

Esto ejecutará el programa principal, que a su vez creará un proceso hijo para demostrar la comunicación usando memoria compartida.
