#ifndef BUBBLESORT_H
#define BUBBLESORT_H


template <class T>
void bubbleSort(T *vect, unsigned long tamanio){
    unsigned long i;
    int flag;
    T aux;
    do{
        flag=0;
        for(i=0; i<tamanio-1; i++)
            if(vect[i]>vect[i+1]){
                aux=vect[i];
                vect[i]=vect[i+1];
                vect[i+1]=aux;
                flag=1;
            }
    }while(flag==1);
}


#endif //BUBBLESORT_H
