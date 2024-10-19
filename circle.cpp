#include "circle.h"
  
template <class T>
circle<T>::circle(){  
    radius = 0;  
}

template <class T>
circle<T>::~circle(){}

template <class T>
void circle<T>::setRadius(T r){
    radius = (T)r;
}

template <class T>
T circle<T>::getArea(){
        return (T)(3.14 * radius * radius);
}