//Alumno: Messa Mandujano, Fabricio Arian

#include <iostream>
#include <time.h> // profe, quería utilizar la libreria <cmath> pero en google vi que se usa tambien <time.h>

char matriz[3][3]; //coloqué una matriz afuera de todo para que sea universal

char opcion(){ //declalo la función para elegir la ficha, pero el detalle que no pude era el de la ficha 'O'. Con la ficha 'X' si sirve

    char ficha; // dentro de la funcion declaro la variable char para que se almacene la ficha

    do //así como expliqué en el anterior trabajo, uso do while para ese bucle hasta que coloque lo indicado
    {
        std::cout << "Elije la ficha 'X' o la ficha 'O' para empezar: ";
        std::cin >> ficha;
    } while (ficha != 'X' && ficha != 'O');
    
    if (ficha == 'X')
    {
        std::cout << "Escojiste ser la ficha " << ficha << "\n";
    }
    if (ficha == 'O')
    {
        std::cout << "Escojiste ser la ficha " << ficha << "\n";
    }
    
}


void tablero(char tabla[3][3]){ // aquí contruyo la matriz y de oaso relleno los espacios vacios

    int x = 0, y = 0; // x son las filas y y las columnas para recorrer la matriz

    for (int i = 0; i < 6; i++) //así como expliqué la otra vez, mi matriz es de 5x3, ya que los palitos tmb cuentan como espacio, y para rellenar un hueco tendría que
    {                           //reemplazar un palo
        for (int j = 0; j < 3; j++)
        {
            if (i < 5 && i % 2 == 1) //aquí imprime los palos si es una posición impar
            {
                std::cout << "___";
            }
            else
            {
                if (i < 5)
                {
                    std::cout << " " << tabla[x][y] << " "; //aquí relleno ese espació con valores del 1 al 9
                    y++; //este y++ sirve para que recorra al siguiente casillero hasta que termine el bucle
                }
                else
                {
                    std::cout << "   ";
                }
            }
            if (j < 2)
            {
                std::cout << "|";
            }            
        }
    y = 0; //aquí se vuele a recetear
    if (i % 2 == 0) //y aquí es el turno de la x++ para que rellena las demás filas, pongo la condición para que sea pan, ya que las casillas vacias están en una posicion par
    {
        x++;
    }
    std::cout << "\n";    
    }

}

void colocar(int posicion, char option){ //ahora sigue la funcion colora, pongo 2 valores, uno tipo entero y otro tipo char

    if (option == 'X') // si la función opcion() es igual a 'X' entonces se realiza lo de abajo
    {
        do //con este do while lo que hago es hacer que el usuario solo digite numero entre el 1 al 9
        {
            std::cout << "Elija una posicion: ";
            std::cin >> posicion;// alamaceno esa numero en la variable 'posicion'
        } while (posicion < 1 || posicion > 9);

        switch (posicion) //con un switch realizo los posibles casos dependiendo lo que digitó el usuario
        {
        case 1: //si colocó el numero 1, entonces que impima en la matriz creada anteriormente el valor de 'X'
            matriz[0][0] = {'X'};
            tablero(matriz); //así con el resto
            break;

        case 2:
            matriz[0][1] = {'X'};
            tablero(matriz);
            break;

        case 3:
            matriz[0][2] = {'X'};
            tablero(matriz);
            break;

        case 4:
            matriz[1][0] = {'X'};
            tablero(matriz);
            break;

        case 5:
            matriz[1][1] = {'X'};
            tablero(matriz);
            break;

        case 6:
            matriz[1][2] = {'X'};
            tablero(matriz);
            break;

        case 7:
            matriz[2][0] = {'X'};
            tablero(matriz);
            break;

        case 8:
            matriz[2][1] = {'X'};
            tablero(matriz);
            break;

        case 9:
            matriz[2][2] = {'X'};
            tablero(matriz);
            break;

        default:
            break;
        }
        
    }

}

void ia(){ //aquí es las fichas de la IA

    int numero; //coloco dentro una variable tipo entera

    srand(time(NULL)); //gracias a la libería de antes ejecuto esto

    numero = 1 + rand() % 9; //y hago que genere un numero aleatorio entre el 1 y 9

    switch (numero) //lo mismo que el otro caso, con ayuda de un switch coloco la ficha de la IA en la poscion que generó ese numero aleatorio
    {               //el unico problema, es que no pude hacer la función para ver si la casilla está llena o no, y aveces rellena el mismo espacio :"""c
    case 1:
        matriz[0][0] = 'O';
        tablero(matriz);
        break;

    case 2:
        matriz[0][1] = 'O';
        tablero(matriz);
        break;

    case 3:
        matriz[0][2] = 'O';
        tablero(matriz);
        break;

    case 4:
        matriz[1][0] = 'O';
        tablero(matriz);
        break;

    case 5:
        matriz[1][1] = 'O';
        tablero(matriz);
        break;

    case 6:
        matriz[1][2] = 'O';
        tablero(matriz);
        break;

    case 7:
        matriz[2][0] = 'O';
        tablero(matriz);
        break;

    case 8:
        matriz[2][1] = 'O';
        tablero(matriz);
        break;

    case 9:
        matriz[2][2] = 'O';
        tablero(matriz);
        break;

    default:
        break;
    }
    

}

int main(){ //aqui ya coloco las funciones y akgunos otros valores

    char option; //como la opcion 
    int posicion; //y la posicion

    matriz[0][0] = {'1'}; //esto de aqui es para imprimir los numero del 1 al 9 que vio en el princio
    matriz[0][1] = {'2'};
    matriz[0][2] = {'3'};
    matriz[1][0] = {'4'};
    matriz[1][1] = {'5'};
    matriz[1][2] = {'6'};
    matriz[2][0] = {'7'};
    matriz[2][1] = {'8'};
    matriz[2][2] = {'9'};

    tablero(matriz); //aquí imprimo la matriz ya con las casillas rellenadas
 
    option = opcion(); // coloco la funcion opcion() en una variable para que se ejecute en otra funcion

    colocar(posicion, option); //apartir de aqui coloco en forma intercalda el turno de la IA y mi turno :c, está chafa, disculpe, todavia no manejo al 100% funciones
    ia();
    colocar(posicion, option);
    ia();
    colocar(posicion, option);
    ia();
    colocar(posicion, option);
    ia();
    colocar(posicion, option);
    ia();
    colocar(posicion, option);
    ia();
    colocar(posicion, option);
    ia();
    colocar(posicion, option);
    ia();
    colocar(posicion, option);
    ia();
    colocar(posicion, option);


    system("pause");
    return 0;

}