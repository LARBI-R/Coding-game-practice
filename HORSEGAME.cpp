/* CODING GAME 03/04/2021 */


//- -------------- GAME 2 HORSE GAME --------------- //

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
    vector<int> pi;
    vector<int> totalP;

    int N, min;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        pi.push_back(Pi);
    }

    sort(pi.begin(), pi.begin()+pi.size());
    cerr<<"after sort"<<endl;
    cerr<<pi[0];
    
    min = std::abs ( pi[1] - pi[0] ) ;

    for ( int i = 0; i < N; ++i)
    {
        if ( std::abs( pi[i] - pi[i-1] ) < min )
        {
            min = std::abs( pi[i] - pi[i-1] );
        }

    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << min << endl;
}
