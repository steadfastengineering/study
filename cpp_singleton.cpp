#include <iostream>

using namespace std;


class Singleton
{ 
    public:
        static Singleton GetInstance(){
            if( instance == NULL){
                instance = new Singleton();
            }
             return instance;
        }

        ~Singleton(){}

    private:
        static Singleton* instance;
        Singleton(){} // Private constructor so that no objects can be created.
};

int main()
{
    Singleton s = Singleton::GetInstance();
     return 0;
}