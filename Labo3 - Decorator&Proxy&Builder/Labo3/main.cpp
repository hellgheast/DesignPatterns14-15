#include <iostream>

using namespace std;

int main()
{
    Order o;
    o.nextState();
    o.nextState();
    o.nextState();

    cout << endl << "Done.";
    std::cin.get();
    return 0;
}
