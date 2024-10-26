#include<iostream>
#include<string>

using namespace std;

 class button 
{
    public:
        virtual void press()
        {
            cout << "button press" << endl;
        }

        virtual void unpress() = 0; // Assign zero rather than an implementation to make it a pure virtual function.

};

class big_red_button : public button
{ 
    private: 
        big_red_button(); // private constructor 
        
        static big_red_button* instance;

    public:
        bool is_armed;
         
        static big_red_button* get_instance()
        { 
            if(instance == nullptr)
            {
                instance = new big_red_button();
            }
            return instance;
        }

        void press() override
        {
            cout << "Never press the little red button" << endl;
        }

        void unpress() override
        {
            cout << "It's too late, you already pressed it" << endl;
        }

        void do_cool_thing(void (*func)(void))
        {
            func();
        } 
};



int main() 
{
    big_red_button* brb = big_red_button::get_instance();

    brb->press();
    brb->unpress();
    brb->do_cool_thing([](){cout << "WHAOH";});

    return 0;
}