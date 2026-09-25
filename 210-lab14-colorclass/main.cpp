
// COMSC-210 | Lab 14 | Jonvianney Maglasang

// Started September 24, 2026 at 11:01pm
// Finished September 24, 2026 at 

#include <iostream>
#include <iomanip>

using namespace std;

class Color
{
    private:
        // [0] = r, [1] = g, [2] = b
        int rgb[3] = { 0, 0, 0 };

        // Turns a color value into 0 or 255 if it is less than 0 or greater than 255
        void fixColVal(int& colVal)
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
        // setCol() saves colVal at rgb[colIdx]
        int setCol(int colIdx, int colVal)
        {
            if(colIdx < 0 || colIdx > 2)
            {
                fixColVal(colVal);
                rgb[colIdx] = colVal;
                return 1;
            } else
            {
                return -1;
            }
        }

        // getCol() returns the color value at rgb[colIdx]
        int getCol(int colIdx)
        {
            if(colIdx < 0 || colIdx > 2)
            {
                return rgb[colIdx];
            } else
            {
                return -1;
            }
        }

        // setAllCols() uses setCol() in a loop
        void setAllCols(int rVal = 0, int gVal = 0, int bVal = 0)
        {
            int inputtedVals[3] = { rVal, gVal, bVal };

            for(int i = 0; i < 3; i++)
            {
                setCol(i, inputtedVals[i]);
            }
        }

        void printData()
        {
            cout << "R: " << rgb[0] << " G: " << rgb[1] << " B: " << rgb[2] << endl;
        }
};

int main()
{
    
    return 0;
}