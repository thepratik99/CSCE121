#include <iostream>
#include <stdexcept>
#include "BasicTree.h"
#include "Node.h"
using namespace std;

int main()
try
{
    BasicTree bt;
    cout << bt << endl;
    bt.insert(10);
    bt.insert(5);
    bt.insert(13);
    bt.insert(3);
    bt.insert(4);
    //int p = bt.find(14);
    cout << bt << endl;

    return 0;
} catch (runtime_error& e)
{
    cerr << e.what() << '\n';
    return 1;
} catch (...)
{
    cerr << "exception\n";
    return 2;
}