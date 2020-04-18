#include <iostream>
//#include "test/tester.h"
#include "structures/queue.h"
#include "structures/lists/forward.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    queue<int>* dato1;
    dato1->imprimir();

    ForwardList<int>* lista1;
    lista1->imprimir();
    //Tester::execute();
    return EXIT_SUCCESS;
}
