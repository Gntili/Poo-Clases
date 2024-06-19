#include <iostream>
#include <QString>

using namespace std;

// Clase Persona
class Persona {
public:
    Persona(const QString& nombre) : nombre(nombre) {}

    QString getNombre() const {
        return nombre;
    }

private:
    QString nombre;
};

// Clase Poste
class Poste {
public:
    Poste(double altura, double diametro) : altura(altura), diametro(diametro) {}

    double getAltura() const {
        return altura;
    }

    double getDiametro() const {
        return diametro;
    }

private:
    double altura;
    double diametro;
};



// Sobrecarga de la función para objetos de tipo Persona
void mostrardescripcionespecifica(const Persona& persona) {
    cout << "Persona con nombre " << persona.getNombre().toStdString() << endl;
}

// Sobrecarga de la función para objetos de tipo Poste
void mostrardescripcionespecifica(const Poste& poste) {
    cout << "Poste con altura de " << poste.getAltura() << " metros y " << poste.getDiametro() << " cm de diametro"<< endl;
}

int main() {
    // Crear objetos de prueba
    Persona persona1("Agostina");
    Persona persona2("Santiago");

    Poste poste1(8.0, 15.0);
    Poste poste2(10.5, 20.0);

    // Probar la función genérica de impresión
    mostrardescripcionespecifica(persona1);
    mostrardescripcionespecifica(persona2);
    mostrardescripcionespecifica(poste1);
    mostrardescripcionespecifica(poste2);

    return 0;
}
