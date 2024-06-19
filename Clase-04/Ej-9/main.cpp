#include <iostream>

// Función genérica de impresión y ordenamiento por inserción
template <class T>
void imprimir(T* v, int cantidad, bool mayor_a_menor) {
    // Ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i) {
        T key = v[i];
        int j = i - 1;

        // Ordenar en orden creciente o decreciente según el parámetro mayor_a_menor
        if (mayor_a_menor) {
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
        } else {
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
        }
        v[j + 1] = key;
    }

    // Imprimir los elementos del array
    for (int i = 0; i < cantidad; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Prueba con un array de enteros
    int arrInt[] = {5, 2, 9, 1, 5, 6};
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);

    std::cout << "Array de enteros ordenado de mayor a menor: ";
    imprimir(arrInt, sizeInt, true);

    std::cout << "Array de enteros ordenado de menor a mayor: ";
    imprimir(arrInt, sizeInt, false);

    // Prueba con un array de floats
    float arrFloat[] = {3.2, 1.4, 2.5, 5.1};
    int sizeFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);

    std::cout << "Array de floats ordenado de mayor a menor: ";
    imprimir(arrFloat, sizeFloat, true);

    std::cout << "Array de floats ordenado de menor a mayor: ";
    imprimir(arrFloat, sizeFloat, false);

    return 0;
}
