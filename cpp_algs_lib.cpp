#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;



int main() 
{
    map<string, double> m;
    m["asdf"] = 69.6;
    m["derp"] = 44;
    
    
     if(m.find("derp") != m.end())
     {
        cout << "Found!" << endl;
    }
    else{
        cout << "Not found!" << endl;
    }
   
    #if 1
    cout << "The value of derp is: " << m["derp"] << endl;
    auto iter = m.find("derp");
    m.erase(iter);
    cout << "The value of asdf is: " << m["asdf"] << endl;
    cout << "The value of derp is: " << m["derp"] << endl;

    #endif

    return 0;
}