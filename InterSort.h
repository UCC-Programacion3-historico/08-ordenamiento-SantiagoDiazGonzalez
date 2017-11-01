#ifndef INTERSORT_H
#define INTERSORT_H


template<class T>
void ord_intercalacion(T *A, T *tmp, int izq, int der);
/* Función recursiva, A es el array de datos. tmp debe ser un
array de tamaño mayor o igual a A. izq y der son los extremos
del subarreglo sobre el cual trabajaremos en esta
recursión. */

template<class T>
void intercalar(T *A, T *tmp, int izq, int centro, int der);
/* lo que hace esta rutina es intercalar las particiones
[A[izq], ..., A[centro-1] ] y [ A[centro], ..., A[der] ]
(que deberían estar ya ordenadas) en el subarray
[ tmp[izq], ..., tmp[der] ] y luego copiar los elementos
nuevamente a A, en el subarray [ A[izq], ..., A[der] ] */

template<class T>
void interSort(T *A, int N) {
    T *tmp = new T [N];
    ord_intercalacion(A, tmp, 0, N - 1);
}

template<class T>
void ord_intercalacion(T *A, T *tmp, int izq, int der) {
    if (izq < der)
    {
        int centro = (izq + der) / 2;

        ord_intercalacion(A, tmp, izq, centro);
        ord_intercalacion(A, tmp, centro + 1, der);

        intercalar(A, tmp, izq, centro + 1, der);
    }
}

template<class T>
void intercalar(T *A, T *tmp, int izq, int centro, int der) {
/* mis particiones serán [izq,...,centro-1] y
[centro,...,der] */
/* contadores para la primera mitad, la segunda y para la
intercalacion respectivamente. */
    int ap = izq, bp = centro, cp = izq;
    while ((ap < centro) && (bp <= der)) {
        if (A[ap] <= A[bp]) {
            tmp[cp] = A[ap];
            ap++;
        } else {
            tmp[cp] = A[bp];
            bp++;
        }
        cp++;
    }

/* terminamos de intercalar, ahora metemos los elementos
restantes de la lista que aún no ha terminado de ser
procesada. */
    while (ap < centro) {
        tmp[cp] = A[ap];
        cp++;
        ap++;
    }
    while (bp <= der) {
        tmp[cp] = A[bp];
        cp++;
        bp++;
    }
/* ahora que tenemos la intercalación finalizada en tmp, la
pasamos a A */
    for (ap = izq; ap <= der; ap++)
        A[ap] = tmp[ap];
}

#endif //IINTERSORT_H
