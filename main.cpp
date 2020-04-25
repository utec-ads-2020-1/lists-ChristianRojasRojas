#include <iostream>
//#include "test/tester.h"
#include "structures/queue.h"
#include "structures/lists/forward.h"
#include "structures/lists/linked.h"
#include "structures/lists/circular.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    try{ //aqui se capturan las excepciones

       /* List<int>* lista1 = new ForwardList<int>(); //FORWARDLIST PRUEBA-------------------------------

        lista1->push_front(1);
        lista1->push_front(4);
        lista1->push_front(7);
        lista1->push_front(9);
        lista1->push_front(5);
        lista1->push_back(15);
        lista1->pop_back();
        lista1->reverse();
        lista1->sort();
        lista1->imprimir();

        int x = lista1->operator[](4);

        cout << "operator valor = " << x << endl;
        cout << "       front    =   " << lista1->front() << endl;
        cout << "       back   =    " << lista1->back() << endl;
        cout << "cantidad de elementos = " << lista1->size() << endl;
        lista1->clear();
        cout << "cantidad de elementos luego del clear = " << lista1->size() << endl;*/
//--------------------------------------------------------------------------------------------------------


        /*List<int>* lista2 = new LinkedList<int>(); //LINKEDLIST PRUEBA-----------------------------------

        lista2->push_front(5);
        lista2->push_front(4);
        lista2->push_front(7);
        lista2->push_front(9);
        lista2->push_front(11);
        lista2->push_back(15);
        lista2->pop_back();
        lista2->reverse();
        lista2->sort();
        lista2->imprimir();

        int y = lista2->operator[](4);

        cout << "operator valor = " << y << endl;
        cout << "       front    =   " << lista2->front() << endl;
        cout << "       back   =    " << lista2->back() << endl;
        cout << "cantidad de elementos = " << lista2->size() << endl;
        lista2->clear();
        cout << "cantidad de elementos luego del clear = " << lista2->size() << endl;*/
//--------------------------------------------------------------------------------------------------------


        /*List<int>* lista3 = new CircularLinkedList<int>(); //CIRCULARLINKEDLIST PRUEBA-------------------

        lista3->push_front(5);
        lista3->push_front(4);
        lista3->push_front(7);
        lista3->push_front(9);
        lista3->push_front(11);
        lista3->push_back(15);
        lista3->pop_back();
        lista3->reverse();
        lista3->sort();
        lista3->imprimir();

        int z = lista3->operator[](4);

        cout << "operator valor = " << z << endl;
        cout << "       front    =   " << lista3->front() << endl;
        cout << "       back   =    " << lista3->back() << endl;
        cout << "cantidad de elementos = " << lista3->size() << endl;
        lista3->clear();
        cout << "cantidad de elementos luego del clear = " << lista3->size() << endl;*/
//--------------------------------------------------------------------------------------------------------

    }catch (const char* dato){
        cout << dato << endl;
    }


    //Tester::execute();
    return EXIT_SUCCESS;
}
