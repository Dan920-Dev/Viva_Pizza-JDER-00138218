#include <iostream>
#include <string>

// Declaracion de un define
#define PASSWORD "salu2"

using namespace std;



enum mainDish{pizza, pasta, lasagna};
enum drink{beer, soda ,tea};
enum starter{garlicBread, pizzaRolls, cheeseSticks};
enum paymentType{cash, card};

struct address{
    string settlement, municipality, departament;
    int houseNumber;
};

struct mainInfo{
    string name;
    mainDish pDish;
    drink pDrink;
    starter pStarter;
    paymentType pay;
    int order;
    float total;
};

struct delivery{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
};

struct houseOrder{
    int pTable;
    mainInfo houseInfo;
};

bool isAdmin = false;

bool loginUser();
void printMenu();

int main(){
    delivery* dArray = NULL;
    houseOrder* hArray = NULL;
    int option = 0;
    
    // Verificacion para inicio de sesion
    if(loginUser() == false)
    return 0;

    do
    {
        printMenu(); cin >> option;
        cin.ignore;

        switch(option){
            case 1:
                addOrder(dArray);
            break;
            case 2:
                addOrder(hArray);
            break;
            case 3:
                //
            break;
            case 4:
            break;
            case 0:
            //nada
            break;
            default:
        }
    } while (option != 0);
    

    return 0;
}

bool loginUser(){
    string enterPass = "";
    char option;
    cout << "INICIO DE SESION" << endl;
    cout << "A - Administrador" << endl;
    cout << "E - Empleado" <<  endl;
    cout << "Su opcion:\t" ; cin >> option;

    switch(option){
        case 'a':
        case 'A':
        break;
            cout << "Digite contyraseña: "; cin >> enterPass;

            if(enterPass.compare(PASSWORD) == 0){
            isAdmin = true;
            return true;
            }else{
                cout << "Contraseña incorrecta" << endl;
            }
        case 'e':
        case 'E':
            isAdmin = false;
            return true;
        break; 
    }
    return false;
}


void printMenu(){
    cout << "SISTEMA DE DESPACHO PIZZERIA " << endl;
    cout << "1. Agregar ordenes a domicilio" << endl;
    cout << "2. Agregar ordenes en restaurantes" << endl;
    cout << "3. Ver ordenes a domicilio" << endl;
    cout << "4. Ver ordenes en restaurante" << endl;
    cout << "Su opcion:\t";
}

void addOrder(delivery* array){
    int idOrder = 1;
    int size = 0, aux = 0;
    cout << "Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();

    array = new delivery[size];

    for(int i = 0; i < size; i++){
        cout << "NOmbre:\t"; getline(cin,array[i].deliveryInfo.name);
        cout << "Direccion:" << endl;
        cout << "Colonia:\t"; getline(cin, array[i].deliveryAddress.settlement);
        cout << "Municipio:\t"; getline(cin, array[i].deliveryAddress.municipality);
        cout << "Departamento:\t"; getline(cin, array[i].deliveryAddress.departament);
        cout << "No. Casa:\t"; cin >> array[i].deliveryAddress.houseNumber; cin.ignore();

        cout << "Entrada " << endl;
        cout << "1 - Pan con ajo" << endl;
        cout << "2 - Pizza rolls" << endl;
        cout << "3 - Palitos de queso" << endl;
        cout << "Su opcion:\t";
        cin.ignore();

        if(aux == 1)
        array[i].deliveryInfo.pStarter = garlicBread;
        else if(aux == 2)
        array[i].deliveryInfo.pStarter = pizzaRolls;
        else
        array[i].deliveryInfo.pStarter = cheeseSticks;

        cout << "Plato principal " << endl;
        cout << "1 - pizza" << endl;
        cout << "2 - pasta" << endl;
        cout << "3 - lasagna" << endl;
        cout << "Su opcion:\t";
        cin.ignore();

        if(aux == 1)
        array[i].deliveryInfo.pDish = pizza;
        else if(aux == 2)
        array[i].deliveryInfo.pDish = pasta;
        else
        array[i].deliveryInfo.pDish = lasagna;
        
        cout << "Bebida " << endl;
        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opcion:\t";
        cin.ignore();

        if(aux == 1)
        array[i].deliveryInfo.pDrink = beer;
        else if(aux == 2)
        array[i].deliveryInfo.pDrink = soda;
        else
        array[i].deliveryInfo.pDrink = tea;

        array[i].deliveryInfo.order = idOrder++;

        cout << "Bebida " << endl;
        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opcion:\t";
        cin.ignore();

        if(aux == 1)
           array[i].deliveryInfo.pay = card;
        else
           array[i].deliveryInfo.pay = cash;

        cout << "Monto: "; cin >> array[i].deliveryInfo.total;
        cin.ignore();
    }
}

void addOrder(houseOrder* array){
    int idOrder = 1;
    int size = 0, aux = 0;
    cout << "Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();

    array = new houseOrder[size];

    for(int i = 0; i < size; i++){
        cout << "NOmbre:\t"; getline(cin,array[i].houseInfo.name);
        cout << "Entrada " << endl;
        cout << "1 - Pan con ajo" << endl;
        cout << "2 - Pizza rolls" << endl;
        cout << "3 - Palitos de queso" << endl;
        cout << "Su opcion:\t";
        cin.ignore();

        if(aux == 1)
        array[i].houseInfo.pStarter = garlicBread;
        else if(aux == 2)
        array[i].houseInfo.pStarter = pizzaRolls;
        else
        array[i].houseInfo.pStarter = cheeseSticks;

        cout << "Plato principal " << endl;
        cout << "1 - pizza" << endl;
        cout << "2 - pasta" << endl;
        cout << "3 - lasagna" << endl;
        cout << "Su opcion:\t";
        cin.ignore();

        if(aux == 1)
        array[i].houseInfo.pDish = pizza;
        else if(aux == 2)
        array[i].houseInfo.pDish = pasta;
        else
        array[i].houseInfo.pDish = lasagna;
        
        cout << "Bebida " << endl;
        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opcion:\t";
        cin.ignore();

        if(aux == 1)
        array[i].houseInfo.pDrink = beer;
        else if(aux == 2)
        array[i].houseInfo.pDrink = soda;
        else
        array[i].houseInfo.pDrink = tea;

        array[i].houseInfo.order = idOrder++;

        cout << "Bebida " << endl;
        cout << "1 - Cerveza" << endl;
        cout << "2 - Soda" << endl;
        cout << "3 - Te helado" << endl;
        cout << "Su opcion:\t";
        cin.ignore();

        if(aux == 1)
           array[i].houseInfo.pay = card;
        else
           array[i].houseInfo.pay = cash;

        cout << "Monto: "; cin >> array[i].houseInfo.total;
        cin.ignore();
    }
}

void SearchByname(delivery* array, int size){
    bool userExits = false;
    string aux = "";
    cout << "Nombre a buscar: "; getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].deliveryInfo.name) == 0){
            // imprimir datos
            userExits == true;
    }
}

(!userExits) ? cout << "No existe el usuario" : cout << "";

}

void SearchByname(houseOrder* array, int size){
    bool userExits = false;
    string aux = "";
    cout << "Nombre a buscar: "; getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].houseInfo.name) == 0){
            // imprimir datos
            userExits == true;
    }
}

(!userExits) ? cout << "No existe el usuario" : cout << "";

}