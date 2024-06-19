#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <string>

class Jugador {
private:
    int velocidad;
    int fuerza;
    std::string nombre;

public:
    // Constructor
    Jugador(int vel = 0, int fue = 0, std::string nom = "sin nombre")
        : velocidad(vel), fuerza(fue), nombre(nom) {}

    // Destructor
    ~Jugador() {}

    // Setters
    void setVelocidad(int vel) { velocidad = vel; }
    void setFuerza(int fue) { fuerza = fue; }
    void setNombre(std::string nom) { nombre = nom; }

    // Getters
    int getVelocidad() const { return velocidad; }
    int getFuerza() const { return fuerza; }
    std::string getNombre() const { return nombre; }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    std::vector<Jugador> jugadores;

    // Insertar 10 jugadores con nombres generados automáticamente
    for (int i = 1; i <= 10; ++i) {
        std::string nombre = "Jugador " + std::to_string(i);
        jugadores.push_back(Jugador(i * 5 + 5, i * 10 + 10, nombre));
    }

    // Publicar los datos de cada jugador usando qDebug
    for (const auto& jugador : jugadores) {
        qDebug() << "Nombre:" << QString::fromStdString(jugador.getNombre())
                 << ", Velocidad:" << jugador.getVelocidad()
                 << ", Fuerza:" << jugador.getFuerza();
    }

    return 0;
}
