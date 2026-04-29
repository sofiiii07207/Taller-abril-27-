#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Jugador {
private:
    string nombre;
    int puntos;

public:
    Jugador(string n, int p) {
        nombre = n;
        puntos = p;
    }

    string getNombre() {
        return nombre;
    }

    int getPuntos() {
        return puntos;
    }

    void sumarPuntos(int carta) {
        puntos += carta;
    }

    void mostrar() {
        cout << "Puntos de " << nombre << ": " << puntos << endl;
    }
};

int mazo[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

int main() {
    srand(time(0));

    string nombre;
    cout << "Como te llamas: ";
    cin >> nombre;

    Jugador jugador(nombre, 0);

    int carta1 = mazo[rand() % 13];
    int carta2 = mazo[rand() % 13];

    jugador.sumarPuntos(carta1);
    jugador.sumarPuntos(carta2);

    cout << "Empieza el juego!" << endl;

    char opcion;
    bool jugando = true;

    while (jugando) {
        jugador.mostrar();

        if (jugador.getPuntos() > 21) {
            cout << "Perdiste, te pasaste de 21 :(" << endl;
            jugando = false;
        } else {
            cout << "Pedir carta (p) o Plantarse (s): ";
            cin >> opcion;

            if(opcion=='p'){
                int carta = mazo[rand() % 13];
                cout << "Nueva carta: " << carta << endl;
                jugador.sumarPuntos(carta);
            } else if(opcion=='s'){
                cout << "Te plantaste con " << jugador.getPuntos() << " puntos." << endl;
                jugando = false;
            } else {
                cout << "Ingresa p o s" << endl;
            }
        }

    return 0;
}
