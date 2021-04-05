/* CODING GAME 03/04/2021 */



// GAME 8 TRIFORCE-----------------------------------------------------------


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
    int N;
    cin >> N; cin.ignore();
    vector<string> tab; 

    string temp;

    int i = 0;
    int oldsize, fixpos, fixloop = (2*N - 1); 

    temp.push_back('.');

    for ( int j = 0; j < 2*N ; ++j)
    {
        if ( j == N )
        {
            fixloop = (tab[j-1].length() );
        }
        while ( i < fixloop )
        {
            if ( (j == 0) && (i == 0 ) )
            {
            }
            else 
            {
                temp.push_back(' ');
            }
            i++;
        }

        if ( j < N )
        {
            temp.push_back('*');
            for (int f = 0 ; f < j ; f++ )
            {
                temp.push_back('*');
            } 
            if ( j == 0 )
            {
                fixpos = (temp.length() - 1);
            }
            else 
            {
                for ( int h = 1 ; h < (j+1) ; ++h)
                {
                    temp[fixpos - h] = '*';
                }
            }
        }
        else 
        {
            temp.push_back('*');
            for (int f = N ; f < j ; f++ )
            {
                temp.push_back('*');
            } 
            if ( j == N )
            {
                fixpos = (temp.length() - 1);
            }
            else 
            {
                for ( int h = N+1 ; h < (j + 1) ; ++h)
                {
                    temp[fixpos -(h-N)] = '*';
                }
            }
        }
        
        tab.push_back(temp);
        i = 0;
        temp.clear();
    }

    for (int i = N; i < 2*N; i++)
    {
        (tab[i])[fixpos-(2*N)] = '*';
        if ( i == N)
        {
            // rien
        }
        else 
        {
            // i = N  // i-N = 0 

            for (int f = 0; f < (i-N); f++ )
            {
                (tab[i])[(fixpos-(2*N))-(f+1)] = '*';
                (tab[i])[(fixpos-(2*N))-(f+1)] = '*';

                (tab[i])[(fixpos-(2*N))+(f+1)] = '*';
                (tab[i])[(fixpos-(2*N))+(f+1)] = '*';
            }

        }
    }


    for (string k : tab)
    {
        cout<<k<<endl;
    }


    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}
