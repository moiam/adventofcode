#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath> 

using namespace std;

int main() {
    ifstream file("input2.txt");
    if (!file) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    ofstream output("output.txt");
    if (!output) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    string line;
    int num;
    int unsafeCounter = 0; 
    int safeCounter = 0;   

   
    while (getline(file, line)) {
        output << "Línea: " << line << endl;

       
        istringstream stream(line);
        vector<int> numbers;

      
        while (stream >> num) {
            numbers.push_back(num);
        }

        bool isUnsafe = false; 
        bool isCrescent = true, isDecrescent = true;

        
        for (size_t i = 1; i < numbers.size(); ++i) {
            int diff = numbers[i] - numbers[i - 1];

            // Verificar si hay un cambio de patrón
            if (diff > 0) {
                isDecrescent = false; 
            } else if (diff < 0) {
                isCrescent = false; 
            } else {
                isUnsafe = true; //Números iguales
                break;
            }

           
            if (abs(diff) > 3) {
                isUnsafe = true; 
                break;
            }
        }

        // En caso de cambiar el patrón
        if (!isCrescent && !isDecrescent) {
            isUnsafe = true;
        }

        if (isUnsafe) {
            unsafeCounter++;
            output << "Línea marcada como UNSAFE." << endl;
        } else {
            safeCounter++;
            output << "Línea marcada como SAFE." << endl;
        }

        output << endl; 
    }

    output << "Total de líneas SAFE: " << safeCounter << endl;
    output << "Total de líneas UNSAFE: " << unsafeCounter << endl;

    file.close();
    output.close();

    cout << "Escrito output.txt" << endl;
    return 0;
}
