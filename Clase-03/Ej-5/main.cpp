#include <iostream>

using namespace std;

int main()
{

    // crear un vector que contenga 5 frases string en cada uno de sus lugares
    string frases[5] = {"Ahogarse en un vaso de agua", "tomar el pelo ", "traer por la calle de la amargura", "dar gato por liebre", "Irse por las ramas"};

    // ordenar esas frases de manera alfabetica
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (frases[i] > frases[j])
            {
                string temp = frases[i];
                frases[i] = frases[j];
                frases[j] = temp;
            }
        }
    }

    // imprimir el vector ordenado
    for (int i = 0; i < 5; i++)
    {
        cout << frases[i] << endl;
    }

    return 0;
}
