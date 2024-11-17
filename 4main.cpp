#include <iostream>
#include "LinkedList.h"

using namespace std;

int somma_rec(LinkedList ll, int pos){
    int d = ll.get_data(pos);
    if(d == INT_MIN)
        return 0;
    return d + somma_rec(ll, pos+1);
}

int main(){
    LinkedList ll;
    int valore;
    cout << "Inserisci un valore: ";
    cin >> valore;
    while(valore!=0){
        ll.insert_back(valore);
        cout << "Inserisci un valore: ";
        cin >> valore;
    }
    cout << "Inserisci il numero per eliminare i suoi multipli dalla lista: ";
    cin >> valore;

    ll.removeMult(valore);
    ll.print();

}