#include <iostream>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    
    for (char c : s)
        cout << static_cast<char>(c > 96 ? c - 32 : c + 32);
    
    return 0;
}