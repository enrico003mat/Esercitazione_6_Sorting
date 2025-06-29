#include <vector>


namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();

    for(unsigned int i = 0; i <= n - 2; i++)
    {
        
        for(unsigned int j = i + 1; j <= n-1; j++)
        {
            if(v[j] < v[i])
			{
                // swap:
				T tmp = v[j];
				v[j] = v[i];
				v[i] = tmp;
			}

        }
    }
}
template<Sortable T>
void SelectionSort(std::vector<T>& v)
{
    const unsigned int n = v.size();

    for(unsigned int i = 0; i < n - 1; i++)
    {
        unsigned int min_index = i;
        for(unsigned int j = i + 1; j < n; j++)
        {
            if(v[j] < v[min_index])
                min_index = j;
        }

        // swap:
        T tmp = v[i];
        v[i] = v[min_index];
        v[min_index] = tmp;
    }
}

template<Sortable T>
void InsertionSort(std::vector<T>& v)
{

    const unsigned int n = v.size();

    for(unsigned int i = 1; i < n; i++)
    {
        unsigned int j = i;
        while(j > 0 && v[j] < v[j - 1])
        {
            // swap:
            T tmp = v[j];
            v[j] = v[j - 1];
            v[j - 1] = tmp;

            j--;
        }


    }

}
//funzione che costruisce heap
template<Sortable T>
void subf(std::vector<T>& v,int n,int i)
{
	int largest = i;
	//figlio sx
    int l = 2 * i + 1; 
	//figlio dx
    int r = 2 * i + 2; 
	//imposto as larger figlio più grande del nodo corrente
    if (l < n && v[l] > v[largest])
        largest = l;

    if (r < n && v[r] > v[largest])
        largest = r;
	// se un figlio è più grande swap e applico ricorsivamente
    if (largest != i) {
        std::swap(v[i], v[largest]);
        subf(v, n, largest);
    }
	
	
}
template<Sortable T>
void HeapSort(std::vector<T>& v)
{

   int n = v.size();
	//parto da fondo albero e sistemo sotto albero
	//subf controlla se soddisfo prop heap
    for (int i = n / 2 - 1; i >= 0; i--)
        subf(v, n, i);

    //voglio mettere elt massimo in fondo a vettore
    for (int i = n - 1; i > 0; i--) {
        std::swap(v[0], v[i]);
	    //ristabilisco propr heap
        subf(v, i, 0);        
    }
}

}



