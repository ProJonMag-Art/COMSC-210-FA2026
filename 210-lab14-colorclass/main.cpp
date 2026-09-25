
// COMSC-210 | Lab 14 | Jonvianney Maglasang

// Started September 24, 2026 at 11:01pm
// Finished September 24, 2026 at 11:57pm

#include <iostream>
#include <iomanip>
#include <vector>

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
            // If the index is out of the array range
            if(colIdx < 0 || colIdx > 2)
            {
                return -1;
            } else
            {
                fixColVal(colVal);
                rgb[colIdx] = colVal;
                return 1;
            }
        }

        // getCol() returns the color value at rgb[colIdx]
        int getCol(int colIdx)
        {
            // If the index is out of the array range
            if(colIdx < 0 || colIdx > 2)
            {
                return -1;
            } else
            {
                return rgb[colIdx];
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
    vector<Color> colors;
    for(int i = 0; i < 5; i++)
    {
        Color temp;
        colors.push_back(temp);
    }

    colors[0].setAllCols(256, -1, 30);
    colors[1].setAllCols(135, 200, 38);
    colors[2].setAllCols(56, 56, 72);
    colors[3].setAllCols(21, 9, 10);
    colors[4].setAllCols(66, 180, 230);

    // Getter function test should return 30
    cout << colors[0].getCol(2) << endl;
    colors[1].setCol(0, 30);

    cout << "All Color Data:" << endl;
    cout << "---------------" << endl;
    for(int i = 0; i < colors.size(); i++)
    {
        cout << "Color" << (i + 1) << " ";
        colors[i].printData();
    }

    return 0;
}