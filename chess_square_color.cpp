#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a' + 1;
        int y = coordinates[1] - '1' + 1;

        // if even x, starting color from bottom is white, if odd, black
        bool x_color = (x % 2 == 0);
        bool y_color = (y % 2 == 0);

        // if the start (bottom) x color is white, flip the corresponding y
        // color
        bool color = x_color ? !y_color : y_color;
        return color;
    }

    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        bool white1 = squareIsWhite(coordinate1);
        bool white2 = squareIsWhite(coordinate2);
        return white1 && white2 || !white1 && !white2;
    }
};

int main()
{
    // TODO 
    return 0;
}