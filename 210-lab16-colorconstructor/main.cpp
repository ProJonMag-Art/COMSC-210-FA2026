
// COMSC-210 | Lab 16 | Jonvianney Maglasang

// Started September 30, 2026 at 9:25pm
// Finished September 30, 2026 at 

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
        // Parameter Constructor
        Color(int rInput, int gInput, int bInput)
        {
            fixColVal(rInput);
            fixColVal(gInput);
            fixColVal(bInput);
            rgb[0] = rInput;
            rgb[1] = gInput;
            rgb[2] = gInput;
        }

        // Partial Constructor
        Color(int rInput)
        {
            fixColVal(rInput);
            rgb[0] = rInput;
            rgb[1] = 0;
            rgb[2] = 0;
        }

        // Default Constructor
        Color()
        {
            for(int i = 0; i < 3; i++)
            {
                rgb[i] = 0;
            }
        }
        
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
    for(int i = 0; i < 2; i++)
    {
        Color temp1 = Color();
        Color temp2 = Color(10 * i, 10 * i, 10 * 1);
        Color temp3 = Color(i * 50);
        colors.push_back(temp1);
        colors.push_back(temp2);
        colors.push_back(temp3);
    }

     //Getter function test should return 30
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