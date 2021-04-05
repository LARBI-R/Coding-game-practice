/* CODING GAME 03/04/2021 */


/* GAME 6 SODUKO ---------------------------- */

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

    int tab[9][9];
    string result = "true";
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int n;
            cin >> n; cin.ignore();
            tab[i][j] = n;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cerr<<tab[i][j]<<" ";
        }
        cerr<<endl;
    }


    // subgrid err

    for ( int i = 0 ; i < 9; i = (i+3) )
    {
        for ( int j = 0; j < 9; j = (j+3))
        {
            for ( int k = i; k < 3; k++)
            {
              for ( int h = j ; h < 3; h++)
              {
                for ( int u = i; u < 3; u++)
                {
                    for ( int z = j ; z < 3; z++)
                    {           
                        if ( (k == u ) && ( h == z ) )
                        {
                            // rien
                        }
                        else 
                        {
                            if ( tab[k][h] == tab[u][z] )
                            {
                                result = "false";
                            }
                        } 
                    }
                }
              }
      
            }
            
        }

    }
   
    // all test


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // row test 
            if ( i != 0 )
            {
                for ( int k = i - 1 ; k >= 0; k--)
                {
                    if (tab[k][j] == tab[i][j])
                    {
                        result = "false";
                    }  
                }
            }
            if ( i != 9 )
            {
                for ( int k = i + 1 ; k < 9; k++)
                {
                    if (tab[k][j] == tab[i][j])
                    {
                        result = "false";
                    }  
                }
            }   
            // colomn test
            if ( j != 0 )
            {
                for ( int k = j - 1 ; k >= 0; k--)
                {
                    if (tab[i][k] == tab[i][j])
                    {
                        result = "false";
                    }  
                }
            }
            if ( j != 9 )
            {
                for ( int k = j + 1 ; k < 9; k++)
                {
                    if (tab[i][k] == tab[i][j])
                    {
                        result = "false";
                    }  
                }
            }  
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << result << endl;
}