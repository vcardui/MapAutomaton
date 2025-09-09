/*
4 de septiembre de 2025
Vanessa Reteguín - 375533

Actividad 6.2: Práctica Estados y Transiciones

Universidad Aútonoma de Aguascalientes
Ingeniería en Computación Inteligente (ICI)
Semestre V

Grupo 5 - A
Autómatas I
Ángel Eduardo Villegas Ortíz

Instrucciones:
Implemente un código en C/C++ que permita realizar transiciones para los
ejercicios 1 y 3 de la Actividad 6 - AFD con base en una cadena dada

# --------------------- Ejercicio 1 --------------------- #

Requerimientos:
-Genere un mecanismo para contener la expresión en el lenguaje de programación
seleccionado para que el usuario ingrese el estado y la transición: δ(q, a) = q'

-Ofrezca en consola su nomenclatura de Estados y Transiciones:

Por ejemplo:
    Q: Conjunto de Estados Posibles: q0, q1, q2, q3
    Alfabeto: 0, 1
    Conjunto de transiciones δ: T(q0,1)=q1
    s: Estado Inicial: q0
    F: Conjunto de Estados finales: q1

-Implemente una función Transicion que reciba como parámetro del usuario el
Estado Actual (qn) y un valor de entrada (a) y retorne el estado que se adecúa a
la lógica del ejercicio. -En la función main muestre la transición solicitada
por el usuario en la notación más parecida posible y despliegue el estado
resultado, así como su clasificación. -La ejecución de la llamada Transición no
debe ser secuencial, es decir, para cada entrada debe existir una respuesta en
función de la Transición Ingresada (Ejemplos no válidos: Para mostrar en
pantalla el estado q3 no se tienen ingresar o mostrar los estados q1 o q2
anteriormente).

Ejemplos de entrada:  |  Ejemplo de salida:
---------------------------------------------
T(q1, 0)              | Estado Resultado: q3
                      | T(q1, 0)= q3
---------------------------------------------
T(q3, 0)              | Estado Resultado: q3
                      | T(q1, 0)= q3
---------------------------------------------
T(q0, “ “)            | Estado Resultado: q0
                      | T(q0, “ “)= q0

**Conjunto de Transición** 𝜹 **y Funciones de Transición**

$T:(q_{0}, 1) = q_{1}$

$T:(q_{1}, 0) = q_{3}$

$T:(q_{2}, 0) = q_{0}$

$T:(q_{3}, 1) = q_{2}$

$T:(q_{0}, 0) = q_{2}$

$T:(q_{1}, 1) = q_{0}$

$T:(q_{2}, 1) = q_{3}$

$T:(q_{3}, 0) = q_{1}$

# --------------------- Ejercicio 2 --------------------- #
Descripción: Genere un mismo código para representar el funcionamiento del
ejercicio 3. Ejercicio: Sea el alfabeto {0,1} el conjunto de cadenas que
empiecen o terminen (o ambas cosas) con 01.

**Descripción:** Diseñe el autómata que se ajuste a la siguiente expresión:

Sea el alfabeto {0,1} el conjunto de cadenas que empiecen o terminen (o ambas
cosas) con 01

*/

/* ------------ Resources / Documentation involved ------------- */
// Le copié a Pablo usar un mapa de pares, hace todo más sencillo

/* ------------------------- Libraries ------------------------- */
#include <iostream> /* cin/cout */
#include <map>
#include <string> /* stoi() */

using namespace std;

/* ------------------------- Functions ------------------------- */

void diplayMenu() {
    cout << endl
         << "\n.------------------."
            "\n||   -{ MENU }-   ||"
            "\n.------------------."
            "\n| [1] Ejercicio 1  |"
            "\n| [2] Ejercicio 2  |"
            "\n|       [3] Salir  |"
            "\n.------------------.\n";
}

void endTitle() {
    cout << "\n  ^~^  , * ------------- *"
            "\n ('Y') ) |  Hasta luego! | "
            "\n /   \\/  * ------------- *"
            "\n(\\|||/)        FIN      \n";
}

void automatonTitle1() {
    cout << "\n^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^"
            "\n||                     Autómata I                     ||"
            "\n|| A = (Q, Σ, δ, s, F)                                ||"
            "\n|| Conjunto de Estados Posibles  Q: {q0, q1, q2, q3}  ||"
            "\n|| Alfabeto                      Σ: {0, 1}            ||"
            "\n|| Estado Inicial                s: q0                ||"
            "\n|| Conjunto de Estados finales   F: q1                ||"
            "\nv-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v\n";
}

void automatonTitle2() {
    cout << "\n^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^"
            "\n||                     Autómata II                        ||"
            "\n|| A = (Q, Σ, δ, s, F)                                    ||"
            "\n|| Conjunto de Estados Posibles  Q: {q0, q1, q2, q3, q4}  ||"
            "\n|| Alfabeto                      Σ: {0, 1}                ||"
            "\n|| Estado Inicial                s: q0                    ||"
            "\n|| Conjunto de Estados finales   F: q2                    ||"
            "\nv-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v\n";
}

string getNextState1(string initialState, int transitionInput) {
    map<pair<string, int>, string> transitionMap = {
        {{"q0", 1}, "q1"}, {{"q1", 0}, "q3"}, {{"q2", 0}, "q0"},
        {{"q3", 1}, "q2"}, {{"q0", 0}, "q2"}, {{"q1", 1}, "q0"},
        {{"q2", 1}, "q3"}, {{"q3", 0}, "q1"}};

    auto it = transitionMap.find({initialState, transitionInput});

    if (it != transitionMap.end()) {
        cout << endl << "Estado Resultado: " << it->second << endl;
        cout << "T(" << initialState << ", " << transitionInput
             << ") = " << it->second << endl;
    } else {
        cout << endl << "[!] Transición no válida" << endl;
    }

    return it->second;
}

string getNextState2(string initialState, int transitionInput) {
    map<pair<string, int>, string> transitionMap = {
        {{"q0", 0}, "q1"}, {{"q1", 1}, "q2"}, {{"q2", 0}, "q3"},
        {{"q2", 1}, "q4"}, {{"q3", 0}, "q3"}, {{"q3", 1}, "q2"},
        {{"q4", 0}, "q3"}, {{"q4", 1}, "q4"}};

    auto it = transitionMap.find({initialState, transitionInput});

    if (it != transitionMap.end()) {
        cout << endl << "Estado Resultado: " << it->second << endl;
        cout << "T(" << initialState << ", " << transitionInput
             << ") = " << it->second << endl;
    } else {
        cout << endl << "[!] Transición no válida" << endl;
    }

    return it->second;
}

int main() {
    /* ------------------------- Variables ------------------------- */
    /* - Menu - */
    int userChoice;
    bool run = true;
    bool validString = false;

    /* - Auxiliaries - */
    int i;

    string initialState;
    int transitionInput;

    string automatonInput;
    string nextState;
    string currentByte;

    /* --------------------------- Code ---------------------------- */
    while (run == true) {
        diplayMenu();
        while (!((cin >> userChoice) && (userChoice >= 1 && userChoice <= 3))) {
            cin.clear();
            cin.ignore();
        }

        switch (userChoice) {
            case 1:
                automatonTitle1();
                while (validString == false) {
                    cout << "Ingrese una cadena: ";
                    cin >> automatonInput;

                    for (int i = 0; i < automatonInput.length(); i++) {
                        if ((automatonInput[i] == '0') ||
                            (automatonInput[i] == '1')) {
                            validString = true;
                        } else {
                            cout << endl
                                 << "    [!] Cadena no válida\n"
                                 << endl;
                            validString = false;
                            break;
                        }
                    }
                }

                cout << endl << "[*] Cadena válida" << endl;
                nextState = "q0";

                cout << endl << "[*] Estado inicial: " << nextState << endl;

                for (i = 0; i < automatonInput.length(); i++) {
                    currentByte = automatonInput[i];
                    // cout << endl << "[" << currentByte << "]";
                    nextState = getNextState1(nextState, stoi(currentByte));
                }

                cout << endl << "[*] Estado final: " << nextState << endl;

                if (nextState == "q0") {
                    cout << endl << "[*] Estado final: " << nextState << endl;
                } else {
                    cout << endl
                         << "[!] Estado final no válido: " << nextState << endl
                         << "[!] Cadena no válida";
                }

                break;

            case 2:
                automatonTitle2();
                while (validString == false) {
                    cout << "Ingrese una cadena: ";
                    cin >> automatonInput;

                    for (int i = 0; i < automatonInput.length(); i++) {
                        if ((automatonInput[i] == '0') ||
                            (automatonInput[i] == '1')) {
                            validString = true;
                        } else {
                            cout << endl
                                 << "    [!] Cadena no válida\n"
                                 << endl;
                            validString = false;
                            break;
                        }
                    }
                }

                cout << endl << "[*] Cadena válida" << endl;
                nextState = "q0";

                cout << endl << "[*] Estado inicial: " << nextState << endl;

                for (i = 0; i < automatonInput.length(); i++) {
                    currentByte = automatonInput[i];
                    // cout << endl << "[" << currentByte << "]";
                    nextState = getNextState2(nextState, stoi(currentByte));
                }

                if (nextState == "q2s") {
                    cout << endl << "[*] Estado final: " << nextState << endl;
                } else {
                    cout << endl
                         << "[!] Estado final no válido: " << nextState << endl
                         << "[!] Cadena no válida";
                }
                break;

            case 3:
                endTitle();
                run = false;
                break;
        }
    }

    return 0;
}
