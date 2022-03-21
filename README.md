<a>
    <img src="https://javier.rodriguez.org.mx/itesm/2014/tecnologico-de-monterrey-black.png" alt="ITESM" title="ITESM" align="right" height="60" />
</a>

# **Autómata Finito Determinista**

## **Propósito**

_Una de las aplicaciones de los autómatas finitos determinísticos es la implementación de reconocedores de tokens en un lenguaje de programación (conocido como Lexer en los compiladores)._

## **Reglas de formación de algunos tokens**

### **Variables:**

- _Deben empezar con una letra (mayúscula o minúscula)._
- _Sólo están formadas por letras, números y underscore (‘\_’)._

### **Números reales (de punto flotante):**

- _Pueden ser positivos o negativos_
- _Pueden o no tener parte decimal pero deben contener un punto (e.g. 10. o 10.0)_
- _Pueden usar notación exponencial con la letra E, mayúscula o minúscula, pero después de la letra E sólo puede ir un entero positivo o negativo (e.g. 2.3E3, 6.345e-5, -0.001E-3, .467E9)._

### **Comentarios**

- _Inician con // y todo lo que sigue hasta que termina el renglón es un comentario_

## Algoritmo

- **Variable:**
  _Inicia con una letra (mayúscula/minúscula), para después tener N cantidad de letras(mayúscula/minúscula), números o guiones bajos._
- **Numero:**
  _El numero puede iniciar con negativo o punto o que directamente inicie con un digito, después tener N cantidad de dígitos y si es entero, que acabe. Para los decimales tiene que estar seguidos por mas números, para las exponenciales puede iniciar con negativo y ser decimal._

https://github.com/Naiztu/AFD/blob/32c34980abc29aee66dfac574b36de953474abd5/DFA.drawio.png

## Manual de uso

_El programa está hecho con el lenguaje C++, por lo que se necesita del compilador MinGW para que este pueda ser ejecutado. En la consola se necita ejecutar los siguientes comandos en la terminal ubicada en el directorio de los archivos:_

1.- _Compilar el programa_

<pre>
<code>
 g++ main.cpp -o main
</code>
</pre>

2.- _Ejecutar el archivo resultado de la compilación_

<pre>
<code>
main.exe
</code>
</pre>

3.- _Escribir el nombre de del archivo de texto a utilizar, debe de estar en la misma carpeta que los archivos y tiene que terminar con la extensión .txt_

<pre>
<code>
Nombre del archivo (con extension .txt):  prueba.txt
</code>
</pre>

_La salida del programa será que por cada línea presentara el tipo de toquen y el resultado que es, un ejemplo seria el siguiente:_

<pre>
<code>
LINE 1
Variable : b
Asignacion : =
Entero : 7

LINE 3
Variable : a
Asignacion : =
Real : 32.4
Multiplicacion : *
Parentesis que abre : (
Real : -8.6
Resta : -
Variable : b
Parentesis que cierra : )
Division : /
Real : 6.1E-8

LINE 5
Variable : d
Asignacion : =
Variable : a
Potencia : ^
Variable : b
Comentario: // Esto es un comentario
</code>
</pre>

## **Integrantes**

- _Marco Antonio Camalich Pérez **-** A01351725_
- _José Ángel Rico Mendieta **-** A01707404_
