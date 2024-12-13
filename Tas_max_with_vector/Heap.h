#pragma once
#include <vector>
#include <iostream>


template <typename T>
class Heap
{
private:
    std::vector<T> MonHeap; // Vecteur contenant les éléments du tas
    void heapMonant(int index); // Méthode pour réorganiser le tas en montant 
    void HeapDescendant(int index, int size); // Méthode pour réorganiser le tas en descendant
    bool rechercher(T value, int index); // Recherche d'une valeur dans le tas de manière récursive

public:
    Heap(int nbelem); // Constructeur
    void creerHeap(); // Crée un tas valide à partir des éléments du vecteur
    void chercheValue(T value); // Recherche une valeur et affiche si elle existe dans le tas
    void Tri(); // Trie les éléments du tas en ordre croissant
    void print(); // Affiche les éléments du tas
};

template<typename T>
inline void Heap<T>::heapMonant(int index)
{
    // Indices des enfants gauche et droit
    int leftfils = 2 * index + 1;
    int rightfils = 2 * index + 2;
    int greatest = index; // Initialiser le plus grand élément avec l'index actuel
    int size = MonHeap.size();

    // Vérifie si l'enfant gauche est plus grand que le parent
    if (leftfils < size && MonHeap[greatest] < MonHeap[leftfils])
    {
        greatest = leftfils;
    }

    // Vérifie si l'enfant droit est plus grand que le parent
    if (rightfils < size && MonHeap[greatest] < MonHeap[rightfils])
    {
        greatest = rightfils;
    }

    // Si le plus grand élément n'est pas le parent, on échange et on continue
    if (greatest != index)
    {
        std::swap(MonHeap[index], MonHeap[greatest]);
        heapMonant(greatest); // Répéter pour maintenir la propriété de tas
    }
}

template<typename T>
inline void Heap<T>::HeapDescendant(int index, int size)
{
    // Indices des enfants gauche et droit.
    int leftfils = 2 * index + 1;
    int rightfils = 2 * index + 2;
    int greatest = index; // Initialiser le plus grand élément avec l'index actuel

    // Vérifie si l'enfant gauche est dans les limites et plus grand que le parent
    if (leftfils < size && MonHeap[leftfils] > MonHeap[greatest])
    {
        greatest = leftfils;
    }

    // Vérifie si l'enfant droit est dans les limites et plus grand que le parent
    if (rightfils < size && MonHeap[rightfils] > MonHeap[greatest])
    {
        greatest = rightfils;
    }

    // Si le plus grand élément n'est pas le parent, on échange et on continue
    if (greatest != index)
    {
        std::swap(MonHeap[greatest], MonHeap[index]);
        HeapDescendant(greatest, size); // Répéter pour maintenir la propriété de tas
    }
}

template<typename T>
inline Heap<T>::Heap(int nbelem)
{
    srand(time(NULL));
    // Ajoute des nombres aléatoires au vecteur
    for (int i = 0; i < nbelem; i++)
        MonHeap.push_back(rand() % 100);
}

template<typename T>
inline void Heap<T>::creerHeap()
{
    // transforme l'arbre en tas
    int n = MonHeap.size() / 2;
    for (int i = n; i >= 0; i--)
    {
        heapMonant(i);
    }
}

template<typename T>
inline bool Heap<T>::rechercher(T value, int index)
{
  
    // Vérifie si l'index est en dehors des limites
    if (index >= MonHeap.size())
    {
        return false;
    }

    // Si la valeur de l'élément actuel est plus grande que la valeur recherchée, arrêtez
    if (MonHeap[index] < value)
    {
        return false;
    }

    // Si la valeur actuelle correspond à la valeur recherchée
    if (MonHeap[index] == value)
    { 
        return true;
    }
        

    // Recherche récursive dans les enfants gauche et droit
    if (!rechercher(value, 2 * index + 1))
    {
        return rechercher(value, 2 * index + 2);
    }
       

    return true;
}

template<typename T>
inline void Heap<T>::chercheValue(T value)
{
    // Appelle la méthode de recherche et affiche le résultat
    if (rechercher(value, 0))
        std::cout << "La valeur " << value << " existe dans le tas" << std::endl;
    else
        std::cout << "La valeur " << value << " n'existe pas dans le tas" << std::endl;
}

template<typename T>
inline void Heap<T>::Tri()
{
    // Trie les éléments en déplaçant le plus grand élément à la fin du tableau
    int size = MonHeap.size();
    for (int i = size - 1; i >= 0; i--)
    {
        std::swap(MonHeap[0], MonHeap[i]); // Place le plus grand élément en fin
        HeapDescendant(0, i); // Réorganise le tas pour les éléments restants
    }
}

template<typename T>
inline void Heap<T>::print()
{
    // Affiche tous les éléments du tas
    for (const auto& value : MonHeap)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
