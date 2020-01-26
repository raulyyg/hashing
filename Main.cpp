/*******************************************************************
 Raul Garcia
 CPSC 131
 Homwork 3: Hashing Problem
 Date Due: Oct. 28, 2015
 Visual Studios 2012
 Hash Function that operates on the following strings that returns
 the fewest collisions using the dictionary.txt file.
 *******************************************************************/

#include "Hash.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = new Item;
    head -> next = NULL;
    length = 0;
}

void LinkedList::insertItem( Item * newItem )
{
    if (!head -> next)
    {
        head -> next = newItem;
        length++;
        return;
    }
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newItem;
    newItem -> next = NULL;
    length++;
}


Item * LinkedList::getItem( string itemKey )
{
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> key == itemKey))
            return p;
        q = p -> next;
    }
    return NULL;
}

void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n";
        return;
    }
    
    cout <<"\t\t\t\t\t ";
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p -> key;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "\n";
}

int LinkedList::getLength()
{
    return length;
}

LinkedList::~LinkedList()
{
    Item * p = head;
    Item * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}


HashTable::HashTable( int tableLength )
{
    if (tableLength <= 0) tableLength = 151;
    array = new LinkedList[ tableLength ];
    length = tableLength;
}

int HashTable::hash( string itemKey )
{
    int value = 0;
    for ( int i = 0; i < itemKey.length(); i++ )
        value += itemKey[i];
    return (value * itemKey.length() ) % length;
}

void HashTable::insertItem( Item * newItem )
{
    int index = hash( newItem -> key );
    array[ index ].insertItem( newItem );
}


Item * HashTable::getItemByKey( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].getItem( itemKey );
}

void HashTable::printTable()
{
    cout << "\n\nHash Value: \t\t String: \n"<< endl;
    for ( int i = 0; i < length; i++ )
    {
        cout << "" << i + 1 << ": ";
        array[i].printList();
    }
}

void HashTable::printCollisions()
{
    
    cout << "\n\nHash Table Value: \t\t Number of Collisions:\n " <<endl;
    
    
    for ( int i = 0; i < length; i++ )
    {
        int collisionCounter = 0;
        cout << "Hash value: " << i + 1 << ":\t\t\t";
        for ( int j = 0; j < array[i].getLength(); j++ )
            collisionCounter += 1;
        cout << " " << collisionCounter;
        cout << "\n";
    }
}


HashTable::~HashTable()
{
    delete [] array;
}

int main()
{
    
    Item * A = new Item {"air condiotner", NULL};
    Item * A2 = new Item {"alternator bearing", NULL};
    Item * A3 = new Item {"antenna assembly", NULL};
    Item * A4 = new Item {"assist", NULL};
    Item * A5 = new Item {"automobile", NULL};
    Item * B = new Item {"ball bearing", NULL};
    Item * B1 = new Item {"ball joint", NULL};
    Item * B2 = new Item {"battery", NULL};
    Item * B3 = new Item {"bias ply tires", NULL};
    Item * B4 = new Item {"blanket", NULL};
    Item * B5 = new Item {"blower fan", NULL};
    Item * B6 = new Item {"BMW 120", NULL};
    Item * B7 = new Item {"BMW 320", NULL};
    Item * B8 = new Item {"BMW 328", NULL};
    Item * B9 = new Item {"BMW 530", NULL};
    Item * B10 = new Item {"BMW 535", NULL};
    Item * B11 = new Item {"BMW M1", NULL};
    Item * B12 = new Item {"BMW M3", NULL};
    Item * B13 = new Item {"BMW M5", NULL};
    Item * B14 = new Item {"BMW M6", NULL};
    Item * B15 = new Item {"bonnet latch", NULL};
    Item * B16 = new Item {"boot", NULL};
    Item * B17 = new Item {"brake fluid DOT 4", NULL};
    Item * B18 = new Item {"brake fluid DOT 5", NULL};
    Item * B19 = new Item {"brake line", NULL};
    Item * B20 = new Item {"brake pad", NULL};
    Item * B21 = new Item {"brake rotor corss-drilled", NULL};
    Item * B22 = new Item {"brake rotor slotted", NULL};
    Item * B23 = new Item {"brake rotor vented", NULL};
    Item * B24 = new Item {"bumper", NULL};
    Item * C = new Item {"camshaft position sensor", NULL};
    Item * C1 = new Item {"camshaft seal", NULL};
    Item * C2 = new Item {"car seat", NULL};
    Item * C3 = new Item {"carbon brakes", NULL};
    Item * C4 = new Item {"carbon rotors", NULL};
    Item * C5 = new Item {"carburator", NULL};
    Item * C6 = new Item {"carriage", NULL};
    Item * C7 = new Item {"clutch", NULL};
    Item * C8 = new Item {"clutch pack", NULL};
    Item * C9 = new Item {"coil on plug", NULL};
    Item * C10 = new Item {"connecting rod", NULL};
    Item * C11 = new Item {"coolant temperature sensor", NULL};
    Item * C12 = new Item {"control arm", NULL};
    Item * C13 = new Item {"cradle", NULL};
    Item * C14 = new Item {"crankshaft", NULL};
    Item * C15 = new Item {"crankshaft position sensor", NULL};
    Item * D = new Item {"differential", NULL};
    Item * D1 = new Item {"diffuser", NULL};
    Item * D2 = new Item {"dog door", NULL};
    Item * D3 = new Item {"doggy", NULL};
    Item * D4 = new Item {"door handle", NULL};
    Item * D5 = new Item {"door latch", NULL};
    Item * D6 = new Item {"drive shaft", NULL};
    Item * D7 = new Item {"dual clutch transmission", NULL};
    Item * D8 = new Item {"dual overhead cam", NULL};
    Item * E = new Item { "electroc power steering", NULL};
    Item * E1 = new Item { "exhaust manifold", NULL};
    Item * F = new Item {"", NULL};
    Item * F1 = new Item {"Ferrari 308", NULL};
    Item * F2 = new Item {"Ferrari 355", NULL};
    Item * F3 = new Item {"Ferrari 458", NULL};
    Item * F4 = new Item {"Ferrari 488", NULL};
    Item * F5 = new Item {"fuel injection", NULL};
    Item * F6 = new Item {"fuel line", NULL};
    Item * F7 = new Item {"fuel pressure", NULL};
    Item * F8 = new Item {"fuel pump standard pressure", NULL};
    Item * F9 = new Item {"file pump high pressure", NULL};
    Item * H = new Item {"halogen headlights", NULL};
    Item * H1= new Item {"headlight", NULL};
    Item * H2 = new Item {"head gasket", NULL};
    Item * H3 = new Item {"hood", NULL};
    Item * H4 = new Item {"hood latch", NULL};
    Item * H5 = new Item {"high chair", NULL};
    Item * H6 = new Item {"hydraulic power steering", NULL};
    Item * I = new Item {"inline 4", NULL};
    Item * I1 = new Item {"inline 6", NULL};
    Item * I2 = new Item {"inline 8", NULL};
    Item * I3 = new Item {"intercooler", NULL};
    Item * K = new Item {"Knock sensor", NULL};
    Item * L = new Item {"Lamborghini Aventador", NULL};
    Item * L1 = new Item {"Lamborghini Countach", NULL};
    Item * L2 = new Item {"Lamborghini Diablo", NULL};
    Item * L3 = new Item {"LamborghiniGallardo", NULL};
    Item * L4 = new Item {"Lamborghini Miura", NULL};
    Item * L5 = new Item {"Lamborghini Murcielago", NULL};
    Item * L6 = new Item {"LASER Headlight", NULL};
    Item * L7 = new Item {"LED Headlights", NULL};
    Item * L8 = new Item {"limited slip", NULL};
    Item * M = new Item {"Maserati", NULL};
    Item * M1 = new Item {"McPherson strut suspension", NULL};
    Item * M2 = new Item {"multilink suspension", NULL};
    Item * O = new Item {"overhead valve", NULL};
    Item * P = new Item {"Packard", NULL};
    Item * P1 = new Item {"paint color", NULL};
    Item * P2 = new Item {"piston playpen", NULL};
    Item * P3 = new Item {"Porsche 356", NULL};
    Item * P4 = new Item {"Porsche 911", NULL};
    Item * P5 = new Item {"Porsche 924", NULL};
    Item * P6 = new Item {"Porsche 928", NULL};
    Item * P7 = new Item {"Porsche 944", NULL};
    Item * P8 = new Item {"Pullrod suspension", NULL};
    Item * P9 = new Item {"Pushrod suspension", NULL};
    Item * R = new Item {"rack and pinion", NULL};
    Item * R1 = new Item {"radial tires", NULL};
    Item * R2 = new Item {"rear wing", NULL};
    Item * R3 = new Item {"rocker arms", NULL};
    Item * R4 = new Item {"roll bar", NULL};
    Item * R5 = new Item {"roll cage", NULL};
    Item * R6 = new Item {"roller bearing", NULL};
    Item * R7 = new Item {"roots blower", NULL};
    Item * R8 = new Item {"rubber ducky", NULL};
    Item * S = new Item {"seat belt", NULL};
    Item * S1 = new Item {"single overhead cam", NULL};
    Item * S2 = new Item {"spark plugs", NULL};
    Item * S3 = new Item {"starter", NULL};
    Item * S4 = new Item {"struts", NULL};
    Item * S5 = new Item {"sunroof", NULL};
    Item * S6 = new Item {"super charger", NULL};
    Item * S7 = new Item {"suspension", NULL};
    Item * T = new Item {"thermostat", NULL};
    Item * T1 = new Item {"timing belt", NULL};
    Item * T2 = new Item {"timing gear", NULL};
    Item * T3 = new Item {"tires H rated", NULL};
    Item * T4 = new Item {"tires V rated", NULL};
    Item * T5 = new Item {"tires w rated", NULL};
    Item * T6 = new Item {"tires Y rated", NULL};
    Item * T7 = new Item {"tire warmer", NULL};
    Item * T8 = new Item {"torsion beam suspension", NULL};
    Item * T9 = new Item {"trailing arm", NULL};
    Item * T10 = new Item {"transmission", NULL};
    Item * T11 = new Item {"trunk", NULL};
    Item * T12 = new Item {"turbo charger", NULL};
    Item * V = new Item {"V6", NULL};
    Item * V1 = new Item {"V8", NULL};
    Item * V2 = new Item {"valve cover", NULL};
    Item * V3 = new Item {"valve housing", NULL};
    Item * V4 = new Item {"valve spring", NULL};
    Item * V5 = new Item {"valve stem", NULL};
    Item * V6 = new Item {"volkswagen Beetle", NULL};
    Item * V7 = new Item {"volkswagen Golf", NULL};
    Item * V8 = new Item {"volkswagen GTI", NULL};
    Item * V9 = new Item {"volkswagen Passat", NULL};
    Item * W = new Item {"walker", NULL};
    Item * W1 = new Item {"water pump", NULL};
    Item * W2 = new Item {"windshield", NULL};
    Item * W3 = new Item {"windshield seal", NULL};
    Item * W4 = new Item {"windshield wiper", NULL};
    Item * W5 = new Item {"wiper motor", NULL};
    Item * W6 = new Item {"wishbone suspension", NULL};
    Item * X = new Item {"xenon headlights", NULL};

    HashTable table;
    
    table.insertItem(A);
    table.insertItem(A2);
    table.insertItem(A3);
    table.insertItem(A4);
    table.insertItem(A5);
    table.insertItem(B);
    table.insertItem(B1);
    table.insertItem(B2);
    table.insertItem(B3);
    table.insertItem(B4);
    table.insertItem(B5);
    table.insertItem(B6);
    table.insertItem(B7);
    table.insertItem(B8);
    table.insertItem(B9);
    table.insertItem(B10);
    table.insertItem(B11);
    table.insertItem(B12);
    table.insertItem(B13);
    table.insertItem(B14);
    table.insertItem(B15);
    table.insertItem(B16);
    table.insertItem(B17);
    table.insertItem(B18);
    table.insertItem(B19);
    table.insertItem(B20);
    table.insertItem(B21);
    table.insertItem(B22);
    table.insertItem(B23);
    table.insertItem(B24);
    table.insertItem(C);
    table.insertItem(C1);
    table.insertItem(C2);
    table.insertItem(C3);
    table.insertItem(C4);
    table.insertItem(C5);
    table.insertItem(C6);
    table.insertItem(C7);
    table.insertItem(C8);
    table.insertItem(C9);
    table.insertItem(C10);
    table.insertItem(C11);
    table.insertItem(C12);
    table.insertItem(C13);
    table.insertItem(C14);
    table.insertItem(C15);
    table.insertItem(D);
    table.insertItem(D1);
    table.insertItem(D2);
    table.insertItem(D3);
    table.insertItem(D4);
    table.insertItem(D5);
    table.insertItem(D6);
    table.insertItem(D7);
    table.insertItem(D8);
    table.insertItem(E);
    table.insertItem(E1);
    table.insertItem(F);
    table.insertItem(F1);
    table.insertItem(F2);
    table.insertItem(F3);
    table.insertItem(F4);
    table.insertItem(F5);
    table.insertItem(F6);
    table.insertItem(F7);
    table.insertItem(F8);
    table.insertItem(F9);
    table.insertItem(H);
    table.insertItem(H1);
    table.insertItem(H2);
    table.insertItem(H3);
    table.insertItem(H4);
    table.insertItem(H5);
    table.insertItem(H6);
    table.insertItem(I);
    table.insertItem(I1);
    table.insertItem(I2);
    table.insertItem(I3);
    table.insertItem(K);
    table.insertItem(L);
    table.insertItem(L1);
    table.insertItem(L2);
    table.insertItem(L3);
    table.insertItem(L4);
    table.insertItem(L5);
    table.insertItem(L6);
    table.insertItem(L7);
    table.insertItem(L8);
    table.insertItem(M);
    table.insertItem(M1);
    table.insertItem(M2);
    table.insertItem(O);
    table.insertItem(P);
    table.insertItem(P1);
    table.insertItem(P2);
    table.insertItem(P3);
    table.insertItem(P4);
    table.insertItem(P5);
    table.insertItem(P6);
    table.insertItem(P7);
    table.insertItem(P8);
    table.insertItem(P9);
    table.insertItem(R);
    table.insertItem(R1);
    table.insertItem(R2);
    table.insertItem(R3);
    table.insertItem(R4);
    table.insertItem(R5);
    table.insertItem(R6);
    table.insertItem(R7);
    table.insertItem(R8);
    table.insertItem(S);
    table.insertItem(S1);
    table.insertItem(S2);
    table.insertItem(S3);
    table.insertItem(S4);
    table.insertItem(S5);
    table.insertItem(S6);
    table.insertItem(S7);
    table.insertItem(T);
    table.insertItem(T1);
    table.insertItem(T2);
    table.insertItem(T3);
    table.insertItem(T4);
    table.insertItem(T5);
    table.insertItem(T6);
    table.insertItem(T7);
    table.insertItem(T8);
    table.insertItem(T9);
    table.insertItem(T10);
    table.insertItem(T11);
    table.insertItem(T12);
    table.insertItem(V);
    table.insertItem(V1);
    table.insertItem(V2);
    table.insertItem(V3);
    table.insertItem(V4);
    table.insertItem(V5);
    table.insertItem(V6);
    table.insertItem(V7);
    table.insertItem(V8);
    table.insertItem(V9);
    table.insertItem(W);
    table.insertItem(W1);
    table.insertItem(W2);
    table.insertItem(W3);
    table.insertItem(W4);
    table.insertItem(W5);
    table.insertItem(W6);
    table.insertItem(X);
    
    cout << "Part 1: " << endl;
    table.printTable();
    cout << "\n\n\n";
    
    cout << "Part 2: " << endl;
    table.printCollisions();
    cout << "\n";

    system("pause");
    return 0;
}