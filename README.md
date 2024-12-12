
# **Proyecto Cazador:**


El presente proyecto fue realizado en el editor Visual Estudio Code y se utilizaron como complemento las librerias Msys2 y SMFL.

![Presa Vs Cazador demo.](Portada.png)


## Como ejecutar el juego:


Para ejecutar sera necesario estar en la root del archivo y teclear *make* para que compile y haga un ejecutable, despues pondra en terminal el nombre del archivo main con la siguiente sintaxis: 
"*make runmain*", esto sera suficiente para correr el juego.



## Los programas que se utilizaron son:
Visual Estudio Code

Libreria SFML

Mysis2 de windows.

GitHub Desktop.

---
## Visual Studio Code
![VSCODE](VSCODE.png)

Instale VSCODE desde el siguiente link.

[Boton de enlace.](https://code.visualstudio.com/docs/editor/vscode-web)

---
## SFML
![SFML](SFML.png)
---
A continiacion se muestra un enlace a la pagina oficial de SFML.


[Boton de enlace.](https://packages.msys2.org/package/mingw-w64-x86_64-sfml)

este comando es para instalar SFML desde la terminal.

    pacman -S mingw-w64-x86_64-sfml
---
### MSYS2 (Windows)

![MSYS2](MSYS2.png)
---
Instalelo con el enlace presente. 

[Boton de enlace.](https://objects.githubusercontent.com/github-production-release-asset-2e65be/80988227/19da371e-6ab9-4858-9b44-b504631c4c5f?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=releaseassetproduction%2F20240702%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240702T032413Z&X-Amz-Expires=300&X-Amz-Signature=e6f83ee9e4f7431edf9eeb97db49a5d3bb460c25d629d06828d8f613dc987182&X-Amz-SignedHeaders=host&actor_id=160084874&key_id=0&repo_id=80988227&response-content-disposition=attachment%3B%20filename%3Dmsys2-x86_64-20230526.exe&response-content-type=application%2Foctet-stream)

No modifiques nada a la hora de la instalacion, puede que no corra el ejecutable.

Una vez instalado es necesario agregar los siguientes directorios al path de windows y reiniciar.

Para cambiar los paths de windows  sigue el siguiente video que te explica como se hace paso a paso.

[Boton de enlace.](https://www.youtube.com/watch?v=ql7V-wgZU1U)

Solo agregue los ya mencionados, no modifiques las que ya tenias por deffault.

    C:\msys64\mingw64\bin

    C:\msys64\usr\bin


---
## Github Desktop
![GitHubDESKTOP](DESKTOP.png)
--
Github ha sido utilizado para la publicacion del mismo, puedes obtnerlo a traves del siguiente link.

[Boton de enlace.](https://docs.github.com/en/desktop/installing-and-authenticating-to-github-desktop/installing-github-desktop)

---
## Librerias en utilizadas (Msys2)

Ejecutar los siguientes comandos en la terminal de msys2 para instalar las dependencias necesarias
DevTools

instalados las depedencias anteriores puede usar estos comandos en la termninal para descargar las librerias necesarias para la compilacion.

[Boton de enlace.](https://code.visualstudio.com/docs/cpp/config-mingw)

    pacman -S --needed base-devel mingw-w64-x86_64-toolchain

---

## Mods Implementados en la ultima revision

Se crearon difrentes estados del juego mediante el uso de condicionantes de tipo boleana con el fin de dar los siguientes estados
---
###Victoria
Se agrego una fase en donde se tiene un objetivo clave el cual es recabar los sufientes puntos sin ser atrapado con el fin de ganar el juego, siendo este seateado a 500 unicamente con la finalidad de demostrar su funcionamiento, se le agrego musica particular y mensajes personalizados para el estado victoria.
![Imagenvictoria](victoriaportada.png)
###GameOver
Se agrego una fase game over que esta optimizada con sonido y imagen propia, con el fin de demostar el gameover de forma efectiva, se usaron archivos de audio y tipo Png, asi como mensajes para dar a entender el game over.
![ImagenGameOver](GameOverpantalla.png)

###Reincio y inico del Juego
Ya existia este apartado, solo se le agragaron elementos que lo hacen mas diferenciable de su version anterior.
![Imageninicio](Iniciopantalla.png)

##Implementacion de los metodos:
En esta Version el codigo se optimizo generando las instancias como variables globales para que fueran accesibles por los elementos del codigo, ya que son pocos estados no resulta incomodo y no es tan necesario encapsularlos tanto.
