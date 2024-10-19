#pragma once
// Circle definition
template <class T> 
class circle
{
    public:
        void setRadius(T radius);
        T getArea();
        circle();
        ~circle();
    
    private:
     T radius;
};