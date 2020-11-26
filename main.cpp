#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector <int> czynniki;

void rozklad(int x)
{
    czynniki.clear();
    for(int i = 2; i*i <= x; i++)
    {
        while(x % i == 0)
        {
            czynniki.push_back(i);
            x /= i;
        }
    }
    if(x != 0)
        czynniki.push_back(x);
}

int zlicz()
{
    int ile = 0;
    for(int i = 0; i < czynniki.size(); i++)
    {
        if(i == 0 || czynniki[i] != czynniki[i-1])
        {
            if(czynniki[i]%2 == 1)
                ile++;
        }
    }
    return ile;
}

int main()
{
    ifstream plik("dane.txt");
    if (plik.good())
    {
        int x, ans = 0;
        while(plik >> x)
        {
            rozklad(x);
            if(zlicz() == 3)
                ans++;
        }
        cout << "Odpowiedz: " << ans;
    }
    return 0;
}
