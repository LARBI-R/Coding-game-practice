/* CODING GAME 03/04/2021 */



//---------------------------- GAME 4 CREDIT CARD----------------------------//

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
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string card;
        getline(cin, card);
        vector<char> result;
        char temp[20];
        string result2 = "";
        
        card.erase(remove(card.begin(), card.end(), ' '), card.end());

        cerr<<card<<endl;

        int k = card.length() - 2 ;

        while ( k >= 0)
        {
            sprintf(temp, "%d", 2*(card[k] - 48));
            result2 += temp;
            result2 += " ";
            k -= 2;
        }

        cerr<<result2<<endl;

        k = 0;
        string result3 = "";

        int som = 0;
        vector<int> resulta3v;

        for ( int k = 0 ; k < result2.length(); k++)
        {
            
            if ( result2[k] == ' ')
            {
                resulta3v.push_back(som);
                som = 0;
            }
            else 
            {
                som += (result2[k] - 48);
            }

        }

        som = 0;

        for ( int j : resulta3v)
        {
            som += j;
        }
        int som3 = 0;

        k = (card.length()-1);

        while ( k >= 0 )
        {
            som3 += (card[k] - 48);
            //result.push_back(); 
            k = (k-2);
        }

        cerr<<som<<endl;
        cerr<<som3<<endl;

        cerr<<result3<<endl;

        if ( ( (som3+som ) % 10 ) == 0)
        {
            cout<<"YES"<<endl;
        }
        else 
        {
            cout<<"NO"<<endl;
        }


    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "YES or NO" << endl;
}
