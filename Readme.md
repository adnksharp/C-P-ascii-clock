# Clock in C

```
.  . ##  #######     .  . ##  #######     #######  ####### 
.    ##  ##   ##  .  .    ##  ##   ##  .  .    ##  .    ## 
.  . ##  ## . ##     .  . ##  #######     #######  .  . ## 
.    ##  ##   ##  .  .    ##  .    ##  .  ##    .  .    ## 
.  . ##  #######     .  . ##  .  . ##     #######  .  . ##
```

Reloj en C usando caracteres ASCII.

### ```<Time>```
Uso de la libreria **time.h** para obtener la hora actual en [formato de cadena](https://docs.microsoft.com/en-us/dotnet/standard/base-types/custom-date-and-time-format-strings) ```%H:%M:%S```.

### ```<string>```
Uso de la libreria **string.h** para separar la hora en hora, minutos y segundos.

### ```Custom```
Uso de una libreria para imprimir la hora usando caracteres ASCII **.** y **#**.

### ```<sys/ioctl>```
Uso de la libreria **sys/ioctl.h**  y **unistd.h** para imprimir caracteres ASCII en una zona especifica de la terminal.