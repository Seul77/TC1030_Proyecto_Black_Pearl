# TC1030_Proyecto_Black_Pearl
Este proyecto simula el funcionamiento de un antro llamado Black Pearl. Tu rol es el de supervisor, eres el "ojo de dios" del lugar. Puedes controlar a los empleados para que hagan su función y a los clientes para que interactúen con el antro. Cada objeto tiene distintos atributos que interactúan de forma diferente entre sí.

## Funcionalidad
El programa tiene distintas funcionalidades:
- Los cadeneros pueden revisar a los clientes y decidir si los expulsan o no dependiendo de sus atributos
- Los DJS pueden cambiar la musica, enseñarte la lista de géneros musicales que tienen, pueden agregar algun género que declares en el input
- Los clientes pueden pedir bebidas dependiendo del dinero que tengan
- Se puede ver la informacion de todas las personas dentro del antro
- Los clientes tienen un contador de bebidas tomadas, si supera 4 bebidas, se consideran como ebrios
- Los cadeneros pueden expulsar a los clientes ebrios o menores de edad

## Clases
- Bebida: Representa una bebida con nombre, precio, grado de alcohol
- Cliente: Representa un nombre con nombre, edad, dinero, estado de embriaguez
- Empleado: Es la clase abstracta para los empleados
- DJ: Empleado que controla la musica
- Cadenero: Empleado que revisa y expulsa clientes
- Bartender: Muestra su informacion
- BlackPearl: Clase principal que administra a los empleados, clientes y bebidas

## Consideraciones
compilar con: "g++ Bebida.h Cliente.h Empleado.h BlackPearl.h Main.cpp"

correr en linux: "/a.out"

correr en windows: "a.exe"

## Casos donde no funciona
En el archivo main.cpp, 
Si se escribe "abc" en los inputs en lugar de un número, falla y el while se vuelve infinito
Al controlar un cliente o al revisar clientes con el cadenero, si ya se expulsó a alguien, el programa intenta acceder a memoria eliminada y crashea ya que los loops usan el 4 fijo.
agregaGenero en DJ no acepta nombres con espacios
