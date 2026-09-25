
// COMSC-210 | Lab 14 | Jonvianney Maglasang

// Started September 24, 2026 at 11:01pm
// Finished September 24, 2026 at 

#include <iostream>
#include <iomanip>

using namespace std;

class Color
{
    private:
        int r;
        int g;
        int b;

        void fixColVals(int& colVal)
        {
            if(colVal < 0)
            {
                colVal = 0;
            }

            if(colVal > 255)
            {
                colVal = 255;
            }
        }
        
    
    public:
        void setRGB(int rVal, int gVal, int bVal)
        {
            fixColVals(rVal);
            fixColVals(gVal);
            fixColVals(bVal);

            r = rVal;
            g = gVal;
            b = bVal;
        }

        
};

int main()
{

    return 0;
}