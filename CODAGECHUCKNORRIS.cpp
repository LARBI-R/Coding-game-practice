/* CODING GAME 03/04/2021 */


/* GAME 1 */ 

// CODAGE CHUCK NORRIS


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    unsigned char x;

    string MESSAGE;
    getline(cin, MESSAGE);

    vector <string> resultfinal;
    vector <int> binary;
    
    for (int j = 0; j < MESSAGE.length(); ++j)
    {
        for (int i = 6; i >= 0; --i)
        {
            binary.push_back( (MESSAGE[j] & (1 << i) ) ? 1 : 0 ); 
        }
    }


    string result , sum = "";
    int i = 0, cnt1 = 0, cnt0 = 0;

    while ( i < 7*MESSAGE.length() )
    {
        if (binary[i] == 0)
        {
            if (i == 0)
            {
                result = "00 0";
            }
            else
            {
                result = " 00 0";
            }
            while(binary[++i] != 1)
            {
                if (i > (7*MESSAGE.length() - 1))
                {
                    break;
                }
                else
                {
                    sum += "0";
                }
            }
            resultfinal.push_back(result + sum);
            sum = "";
        }
        else
        {
            if (i == 0)
            {
                result = "0 0";
            }
            else
            {
                result = " 0 0";
            }
            while(binary[++i] != 0)
            {
                if (i > (7*MESSAGE.length() - 1))
                {
                    break;
                }
                else
                {
                    sum += "0";
                }
                
            }
            resultfinal.push_back(result + sum);
            sum = "";
        }
    }

    for (string l : resultfinal)
    {
        cout<<l;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;





}