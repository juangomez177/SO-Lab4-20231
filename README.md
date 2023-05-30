# SO-Lab4-20231
Aplicación de Chat Básico Cliente-Servidor utilizando Sockets en C.  

## Descripción
Este proyecto es una implementación básica de un chat utilizando sockets en el lenguaje de programación C. El chat consta de dos componentes principales: un servidor y cliente. El servidor es responsable de aceptar conexiones del clientes para posteriormente entablar un canal de comunicación entre el cliente y servidor.  

## Ejecución
Para ejecutar use una terminal dividida, primero compile y ejecute el **servidor**:
```
gcc servidor.c -o servidor
./servidor
```
En la segunda terminal, compile y ejecute el **cliente**:
```
gcc cliente.c -o cliente
./cliente
```