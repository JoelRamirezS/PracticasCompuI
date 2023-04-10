/*
 * Autor: Joel Alejandro Ramírez Sandoval.
 * Fecha: 09/04/2023
 * Contacto: joalejandroramirezsa@gmail.com
 */
#include <iostream>
#include <array>

// Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz & miMatriz);

template <typename matriz>
void IntercambioRenglon(matriz & miMatriz);

int main()
{
    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 }; 

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la solución de la matriz
    ImprimirSolucion(miMatriz);
    

    return 0; // Indicamos que salimos del programa con éxito
}

/* 
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/

template <typename matriz>
void LlenarMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}
 

/* 
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz & miMatriz)
{
    
    //TODO

    int variables = miMatriz.size();

    ImprimirMatriz(miMatriz);

    cout << "\n";

    for( int i = 0; i < variables; i++ ){

        float var;

        var = miMatriz[i][variables] / miMatriz[i][i]; //dividiendo los resultados (cuarta columna) entre los pivotes (0,0 | 1,1 | 2,2), haciendo el despeje de los resultados

        cout << "x" << i << " = " << var << "\n";
    }

    for( int i = 0; i < variables; i++ ){
        for( int j = 0; j < variables; j++ ){
            if (miMatriz[2][0]==0 && miMatriz[2][1]==0 && miMatriz[2][2]==0 && miMatriz[2][3]==0){
                cout << "El sistema tiene infinitas soluciones" <<"\n";

            } else if(miMatriz[2][0]==0 && miMatriz[2][1]==0 && miMatriz[2][2]==0 && miMatriz[2][3]!=0){
                cout << "El sistema no tiene solucion" <<'\n';
            }
        }
    }



}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz)
{
    //TODO

    
    int variables = miMatriz.size();
    int columnas = variables + 1;
    float divPivote;

    if( miMatriz[0][0] == 0  ){ //verificar si primer numero es 0

        IntercambioRenglon(miMatriz);

    }

               
    for( int i = 0; i < variables; i++ ){ //selección del pivote

        for( int j = 0; j < variables; j++ ) { //selección de la fila-renglón  |||||||| i y j definen el espacio en el que se encontrarán los pivotes

            if( j != i ){ //evitando aplicación del procedimiento para puntos pivote ( números uno en la diagonal principal )

                divPivote = miMatriz[j][i]/miMatriz[i][i]; //se hace en este punto porque al realizar las operaciones se modificarán los valores en las ubicaciones dadas para j de i
                for( int k = 0; k < columnas; k++ ){ //recorriendo todo el renglón uno a uno

                  miMatriz[j][k] = miMatriz[j][k] - ( divPivote * miMatriz[i][k] ); //ejecutando operaciones de renglón

                }

            }

        }

    }

}

template <typename matriz>
void IntercambioRenglon( matriz & miMatriz ){

    int variables = miMatriz.size();

    for( int i = 1; i < variables; i++ ){

        if( miMatriz[i][0] != 0 ){

            for( int j = 0; j <= variables; j++ ){
                        
                swap( miMatriz[0][j], miMatriz[i][j] );

            }
        
            break;

        }

    }
  
}
