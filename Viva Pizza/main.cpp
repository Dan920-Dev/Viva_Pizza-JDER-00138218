// Proyecto PED0319 *** Sistema de Ventas ***

#include <string> // Para poder hacer uso de cadenas de caracteres
#include <iostream> // Para entrada y salida de datos
#include <queue> // Libreria para colas
#include <vector> 
#include <stack> // Libreria para pilas
using namespace std;

#define PASSWORD "nullptr"

enum mainDish{pizza, pasta, lasagna};
enum drink{beer, soda, tea};
enum starter{garlicBread, pizzaRolls, cheeseSticks};
enum payment{cash, card};

// Estructuras a Utilizar
struct Address{
    string Col, munici, state;
    int nHouse, telephone;
};
struct Order{ 
   	string name;
    vector<mainDish> MainDish;
    vector<drink> PDrink;
    vector<starter> Starter;
    payment payM;
    int id;
    float wait;
    float total;
};

struct deli{ // Para pedidos a domicilio
    Order info;
    Address address;
};
typedef deli Delivery; 

struct House{ // para pedidos en restaurante
    Order info;
    int table;
};
typedef House Restaurant;

// Vectores, cola y pila a Utilizar
vector<Delivery> DeliveryOrder;
vector<House> HouseOrder;
queue<Delivery> Deliveryaux;
stack<House> Houseaux;

// Variables globales
bool admin = false;
int ID_ORDER = 1;
const float pricePizza = 13.99, pricePasta = 5.55, priceLasagna = 6.25;
const float priceSoda = 0.95, priceBeer = 1.99, priceIcedTea = 1.15;
const float priceGarlicBread = 3.99, pricePizzaRolls = 4.99, priceCheeseSticks = 3.75;

// Prototipo de Funciones a Utilizar
bool login();
void menu();
void Delivery_Order();





int main(){
    // Declarando Variables
    bool continue1 = true;
    int option = 0;

    if(login() == false){
        return 0;
    }

    do
    {
        menu(); cin >> option; cin.ignore();
        cout << endl;
        switch (option)
        {
        case 1:
            Delivery_Order();
            break;
        case 2:
            House_Order();
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        case 9:
            /* code */
            break;
        case 10:
            /* code */
            break;
        case 11:
            /* code */
            break;
        case 12:
            continue1 = false;
            break;  
        default:
            cout << "Opcion Invalida" << endl;
            break;
        }
    } while (continue1);
    
}

bool login(){

    int option;
    string password = "";
    bool continue1 =  true;
    do
    {
        cout << " Bienvenido, digame que usuario es: " << endl ;
        cout << "1. Administrador " << endl << "2. Empleado" << endl << "3. Salir del sistema" << endl << "Digite su opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            do
            {
                cout << "Digite la contraseña para poder ingresar al menu" << endl;
                cin >> password;
                if(password.compare(PASSWORD) == 0){
                admin = true;
                return true;
            }
            else{
                cout << endl << "La clave ingresada es incorrecta" << endl;
            }
            } while (continue1);
            break;
        case 2:
            admin = false;
            return true;
            break;
        case 3:
        cout << "El sistema se a cerrado exitosamente" << endl;
        return 0;
            break;
        default:
        cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue1);

    return false;
}


void menu(){
    
    cout << "  ***Menu Viva Pizza***  " << endl;
    cout << "Opciones disponibles: " << endl;
    cout << "1) Agregar  orden a Domicilio" << endl;
    cout << "2) Agregar  orden en Restaurante" << endl;
    cout << "3) Ver rdenes a Domicilio" << endl;
    cout << "4) Ver ordenes en  restaurante" << endl;
    cout << "5) Despachar ordenes a Domicilio" << endl;
    cout << "6) Despachar ordenes a restaurante" << endl;
    cout << "7) Ver tiempo promedio de espera a domicilio" << endl;
    cout << "8) Ver tiempo promedio de espera en restaurante" << endl;
    cout << "9) Cancelar orden(Domicilio o restaurante, solo Administrador)" << endl;
    cout << "10) Calcular total de ventas" << endl;
    cout << "11) Cambiar de usuario" << endl;
    cout << "12) Salir del sistema*" << endl;    
    cout << "Digite su opcion: ";
}



// Añadir orden a Domicilio
void Delivery_Order(){
    bool continue1 = true, continue2 = true, continue3 = true, continue4 = true; // variables para validar menu
    float sumStarter = 0, sumMainDish = 0, sumDrink = 0; // variables para sumar el total de entradas, platos fuertes y bebidas

    Delivery orderInfo;
    orderInfo.info.id = ID_ORDER++;
    cout << "ID: " << orderInfo.info.id;
    cout << "Digite el nombre de quien realiza el pedido " << ": " << endl;
    getline(cin,orderInfo.info.name); 
    cout<< "Digite el numero de telefono del cliente: " << endl;
    cin >> orderInfo.address.telephone; cin.ignore();


    cout<< "Digite la direccion del pedido"<<endl;
    cout << "No. de Casa: "; cin >> orderInfo.address.nHouse; cin.ignore();
    cout << "Colonia: "; getline(cin, orderInfo.address.Col);
    cout << "Municipio: "; getline(cin, orderInfo.address.munici);
    cout << "Departamento: "; getline(cin, orderInfo.address.state);
  
    // Menu de entradas
    int option = 0 , garlicBread = 0, cheeseSticks = 0, pizzaRolls = 0;
    do
    {
        cout << "Entradas Disponibles" << endl;
        cout << "1) Orden de Pan con Ajo       ---- $"<< priceGarlicBread << endl;
        cout << "2) Orden de Palitos de queso  ---- $" << priceCheeseSticks << endl;
        cout << "3) Orden de Pizza rolls       ---- $" << pricePizzaRolls << endl;
        cout << "4) Salir del menu de entradas*" << endl;
        cout << "Digite su opcion: "; cin >> option;

        switch (option)
        {
        case 1:
            option--;
            orderInfo.info.Starter.push_back(starter(option));
            sumStarter++;
            garlicBread++;
            break;
        case 2:
            option--;
            orderInfo.info.Starter.push_back(starter(option));
            sumStarter++;
            cheeseSticks++;
            break;
        case 3:
            option--;
            orderInfo.info.Starter.push_back(starter(option));
            sumStarter++;
            pizzaRolls++;
            break;
        case 4:
            continue1 = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue1);
    
    // Menu de  plato principal
    int pizza = 0, pasta = 0, lasagna = 0;
    do
    {
        cout << "Platos fuertes Disponibles" << endl;
        cout << "1) Pizza    ---- $"<< pricePizza << endl;
        cout << "2) Pasta    ---- $" << pricePasta << endl;
        cout << "3) Lasagna  ---- $" << priceLasagna << endl;
        cout << "4) Salir del menu de Platos fuertes*" << endl;
        cout << "Digite su opcion: "; cin >> option;

        switch (option)
        {
        case 1:
            option--;
            orderInfo.info.MainDish.push_back(mainDish(option));
            sumMainDish++;
            pizza++;
            break;
        case 2:
            option--;
            orderInfo.info.MainDish.push_back(mainDish(option));
            sumMainDish++;
            pasta++;
            break;
        case 3:
            option--;
            orderInfo.info.MainDish.push_back(mainDish(option));
            sumMainDish++;
            lasagna++;
            break;
        case 4:
            continue2 = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue2);

    // Menu de bebidas
    int soda = 0, te = 0, beer = 0;
    do
    {
        cout << "Bebidas Disponibles" << endl;
        cout << "1) Soda       ---- $"<< priceSoda << endl;
        cout << "2) Te Helado  ---- $" << priceIcedTea << endl;
        cout << "3) Cerveza    ---- $" << priceBeer << endl;
        cout << "4) Salir del menu de Bebidas*" << endl;
        cout << "Digite su opcion: "; cin >> option;

        switch (option)
        {
        case 1:
            option--;
            orderInfo.info.PDrink.push_back(drink(option));
            sumDrink++;
            soda++;
            break;
        case 2:
            option--;
            orderInfo.info.PDrink.push_back(drink(option));
            sumDrink++;
            te++;
            break;
        case 3:
            option--;
            orderInfo.info.PDrink.push_back(drink(option));
            sumDrink++;
            beer++;
            break;
        case 4:
            continue3 = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue3);
    
    // tipo de pago

    do
    {
        cout << "Tipo de pago" << endl;
        cout << "1) Efectivo  "<< endl;
        cout << "2) Tarjeta  " << endl;
        cout << "Digite su opcion: "; cin >> option;

        switch (option)
        {
        case 1:
            option--;
            orderInfo.info.payM = cash;
            continue4 = false;
            break;
        case 2:
            option--;
            orderInfo.info.payM = card;
            continue4 = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue1);

    // Tiempo de espera 
    orderInfo.info.wait = ((sumStarter*1.10 + sumMainDish*1.5 +  sumDrink*1.35) + 15);
    cout << "El tiempo de espera es de: " << orderInfo.info.wait << "mn" << endl;

    // monto de la orden
    // calculos para el monto...
    float totalStarter = garlicBread*priceGarlicBread + cheeseSticks*priceCheeseSticks + pizzaRolls*pricePizzaRolls;
    float totalmainDish = pizza*pricePizza + pasta*pricePasta + lasagna*priceLasagna;
    float totalDrink = soda*priceSoda + beer*priceBeer + te*priceIcedTea;
    orderInfo.info.total = (totalStarter + totalmainDish + totalDrink);
    cout << "El monto total es de: " << orderInfo.info.total;

    DeliveryOrder.push_back(orderInfo);
cout << "Pedido Agregado Exitosamente!!" << endl;
}

// Añadir orden en Restaurante
void House_Order(){
    
    bool continue1 = true, continue2 = true, continue3 = true, continue4 = true; // variables para validar menu
    float sumStarter = 0, sumMainDish = 0, sumDrink = 0; // variables para sumar el total de entradas, platos fuertes y bebidas

    Restaurant orderInfo;
    orderInfo.info.id = ID_ORDER++;
    cout << "ID: " << orderInfo.info.id;
    cout << "Digite el nombre de quien realiza el pedido " << ": " << endl;
    getline(cin,orderInfo.info.name); 
    cout << "Digite el numero de personas en la mesa: "; cin >> orderInfo.table;
  
    // Menu de entradas
    int option = 0 , garlicBread = 0, cheeseSticks = 0, pizzaRolls = 0;
    do
    {
        cout << "Entradas Disponibles" << endl;
        cout << "1) Orden de Pan con Ajo       ---- $"<< priceGarlicBread << endl;
        cout << "2) Orden de Palitos de queso  ---- $" << priceCheeseSticks << endl;
        cout << "3) Orden de Pizza rolls       ---- $" << pricePizzaRolls << endl;
        cout << "4) Salir del menu de entradas*" << endl;
        cout << "Digite su opcion: "; cin >> option;

        switch (option)
        {
        case 1:
            option--;
            orderInfo.info.Starter.push_back(starter(option));
            sumStarter++;
            garlicBread++;
            break;
        case 2:
            option--;
            orderInfo.info.Starter.push_back(starter(option));
            sumStarter++;
            cheeseSticks++;
            break;
        case 3:
            option--;
            orderInfo.info.Starter.push_back(starter(option));
            sumStarter++;
            pizzaRolls++;
            break;
        case 4:
            continue1 = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue1);
    
    // Menu de  plato principal
    int pizza = 0, pasta = 0, lasagna = 0;
    do
    {
        cout << "Platos fuertes Disponibles" << endl;
        cout << "1) Pizza    ---- $"<< pricePizza << endl;
        cout << "2) Pasta    ---- $" << pricePasta << endl;
        cout << "3) Lasagna  ---- $" << priceLasagna << endl;
        cout << "4) Salir del menu de Platos fuertes*" << endl;
        cout << "Digite su opcion: "; cin >> option;

        switch (option)
        {
        case 1:
            option--;
            orderInfo.info.MainDish.push_back(mainDish(option));
            sumMainDish++;
            pizza++;
            break;
        case 2:
            option--;
            orderInfo.info.MainDish.push_back(mainDish(option));
            sumMainDish++;
            pasta++;
            break;
        case 3:
            option--;
            orderInfo.info.MainDish.push_back(mainDish(option));
            sumMainDish++;
            lasagna++;
            break;
        case 4:
            continue2 = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue2);

    // Menu de bebidas
    int soda = 0, te = 0, beer = 0;
    do
    {
        cout << "Bebidas Disponibles" << endl;
        cout << "1) Soda       ---- $"<< priceSoda << endl;
        cout << "2) Te Helado  ---- $" << priceIcedTea << endl;
        cout << "3) Cerveza    ---- $" << priceBeer << endl;
        cout << "4) Salir del menu de Bebidas*" << endl;
        cout << "Digite su opcion: "; cin >> option;

        switch (option)
        {
        case 1:
            option--;
            orderInfo.info.PDrink.push_back(drink(option));
            sumDrink++;
            soda++;
            break;
        case 2:
            option--;
            orderInfo.info.PDrink.push_back(drink(option));
            sumDrink++;
            te++;
            break;
        case 3:
            option--;
            orderInfo.info.PDrink.push_back(drink(option));
            sumDrink++;
            beer++;
            break;
        case 4:
            continue3 = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue3);
    
    // tipo de pago

    do
    {
        cout << "Tipo de pago" << endl;
        cout << "1) Efectivo  "<< endl;
        cout << "2) Tarjeta  " << endl;
        cout << "Digite su opcion: "; cin >> option;

        switch (option)
        {
        case 1:
            option--;
            orderInfo.info.payM = cash;
            continue4 = false;
            break;
        case 2:
            option--;
            orderInfo.info.payM = card;
            continue4 = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (continue1);

    // Tiempo de espera 
    orderInfo.info.wait = ((sumStarter*1.10 + sumMainDish*1.5 +  sumDrink*1.35) + 15);
    cout << "El tiempo de espera es de: " << orderInfo.info.wait << "mn" << endl;

    // monto de la orden
    // calculos para el monto...
    float totalStarter = garlicBread*priceGarlicBread + cheeseSticks*priceCheeseSticks + pizzaRolls*pricePizzaRolls;
    float totalmainDish = pizza*pricePizza + pasta*pricePasta + lasagna*priceLasagna;
    float totalDrink = soda*priceSoda + beer*priceBeer + te*priceIcedTea;
    orderInfo.info.total = (totalStarter + totalmainDish + totalDrink);
    cout << "El monto total es de: " << orderInfo.info.total;

    HouseOrder.push_back(orderInfo);
cout << "Pedido Agregado Exitosamente!!" << endl;
}

