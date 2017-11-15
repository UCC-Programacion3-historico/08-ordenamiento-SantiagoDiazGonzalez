#ifndef INTERSORT_H
#define INTERSORT_H


template <class T>
void interSort(T *vect, unsigned long tamanio){

    int i, j;
    T aux;
    for (i=1; i < tamanio; i++) {
        j = i;
        aux = vect[i];
        while (j > 0 && aux < vect[j-1]) {
            vect[j] = vect[j-1];
            j--;
        }
        vect[j] = aux;
    }
}

#endif //IINTERSORT_H
