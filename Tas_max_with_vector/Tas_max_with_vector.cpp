// Tas_max_with_vector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Heap.h"
#include <iostream>

int main()
{
    Heap<int> H(10);
    H.print();
    H.creerHeap();
    H.print();
    H.chercheValue(41);
    H.Tri();
    H.print();
}

