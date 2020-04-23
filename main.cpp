#include <iostream>
//#include "test/tester.h"
#include "structures/queue.h"
#include "structures/lists/forward.h"
#include "structures/lists/linked.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    List<int>* lista1 = new LinkedList<int>();

    lista1->push_front(5);
    lista1->push_front(4);
    lista1->push_front(7);
    lista1->push_front(9);
    lista1->pop_back();
    lista1->reverse();

    int x = lista1->operator[](0);

    cout << "position Numero 1 = " << x << endl;
    cout << "              " << lista1->back() << endl;
    cout << "              " << lista1->front() << endl;
    cout << "cantidad de elementos = " << lista1->size() << endl;


    //Tester::execute();
    return EXIT_SUCCESS;
}
