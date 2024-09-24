#include <iostream>
#include <string>

using namespace std;

// Función que simula el autómata
bool automata(const string &palabra) {
    int estado = 0;  // Estado inicial q0

    // Recorremos cada símbolo de la palabra
    for (char simbolo : palabra) {
        switch (estado) {
            case 0: // Estado q0
                if (simbolo == 'a') {
                    estado = 1;  // Transición a q1 con 'a'
                } else if (simbolo == 'b') {
                    estado = 2;  // Transición a q2 con 'b'
                } else {
                    return false;  // Símbolo no válido
                }
                break;

            case 1: // Estado q1
                if (simbolo == 'a' || simbolo == 'b') {
                    estado = 1;  // Bucles en q1 con 'a' o 'b'
                }
                break;

            case 2: // Estado q2
                if (simbolo == 'a' || simbolo == 'b') {
                    estado = 2;  // Bucles en q2 con 'a' o 'b'
                }
                break;

            default:
                return false;  // Estado no válido
        }
    }

    // Verificar si el estado final es de aceptación (q1 o q2)
    return (estado == 1 || estado == 2);  // q1 y q2 son estados de aceptación
}

int main() {
    string palabra;
    cout << "Ingresa una palabra: ";
    cin >> palabra;

    if (automata(palabra)) {
        cout << "La palabra es aceptada." << endl;
    } else {
        cout << "La palabra no es aceptada." << endl;
    }

    return 0;
}
