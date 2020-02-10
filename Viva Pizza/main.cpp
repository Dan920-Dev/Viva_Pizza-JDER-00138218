// Proyecto PED0319 *** Sistema de Ventas ***

#include <string> // Para poder hacer uso de cadenas de caracteres
#include <iostream> // Para entrada y salida de datos
#include <vector> 

using namespace std;

#define PASSWORD "nullptr"

// Enumeraciones  de Plato Principal/ Entradas/ Bebidas/ Tipo de pago
enum mainDish{pizza, pasta, lasagna};
enum drink{beer, soda, tea};
enum starter{garlicBread, pizzaRolls, cheeseSticks};
enum payment{cash, card};

// Estructuras a Utilizar
struct Address{
    string Col, munici, state;
    int nHouse, telephone;
};

// campos de una Orden
struct Order{ 
   	string name;
    vector<mainDish> MainDish;
    vector<drink> PDrink;
    vector<starter> Starter;
    payment payM;
    int id;
    int wait;
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

// Vectores a Utilizar
vector<Delivery> DeliveryOrder, ListDelivery;
vector<House> HouseOrder, ListHouse;

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
void House_Order();
void print(vector<Delivery> DeliveryOrder);
void print(vector<House> HouseOrder);
void dispatch(vector<Delivery> DeliveryOrder);
void dispatch(vector<House> HouseOrder);
int averageTimeDelivery(int aux);
int averageTimeHouse(int aux);
bool VerifyId(vector<Delivery> DeliveryOrder,int Id);
bool VerifyId(vector<House> HouseOrder,int Id);
void cancelOrder(int Id);
float totalSales(vector<Delivery> ListDelivery, int pos);
float totalSales(vector<House> ListHouse, int pos);



int main(){
    // Declarando Variables
    bool continue1 = true;
    int option = 0, option2 = 0 , promDelivery = 0, promHouse = 0, id;
    float totalSa = 0;

    if(login() == false){
        return 0;
    }

    do
    {
        menu(); cin >> option; cin.ignore();
        cout << endl << endl;
        switch (option)
        {
        case 1:
            Delivery_Order();
            cout << endl << endl;
            break;
        case 2:
            House_Order();
            cout << endl << endl;
            break;
        case 3:
            if(DeliveryOrder.empty()){
                cout << "No hay ordenes para mostrar" << endl << endl;
            }else{
            print(DeliveryOrder);
            cout << endl << endl;
            }
            break;
        case 4:
            if(HouseOrder.empty()){
                cout << "No hay ordenes para mostrar" << endl << endl;
            }else{
            print(HouseOrder);
            cout << endl << endl;
            }
            break;
        case 5:
            dispatch(DeliveryOrder);
            cout << endl << endl;
            break;
        case 6:
            dispatch(HouseOrder);
            cout << endl << endl;
            break;
        case 7:
            if (DeliveryOrder.empty()){
                cout << "No hay Ordenes agregadas aun, por lo cual no se puede mostrar el promedio de tiempo de espera" << endl << endl;
            }else{
                promDelivery = averageTimeDelivery(0) / DeliveryOrder.size();
                cout << "El tiempo promedio de espera es: " << promDelivery << "minutos" << endl << endl;
            }
            break;
        case 8:
            if (HouseOrder.empty()){
                cout << "No hay Ordenes agregadas aun, por lo cual no se puede mostrar el promedio de tiempo de espera" << endl << endl;
            }else{
                promHouse = averageTimeHouse(0) / HouseOrder.size();
                cout << "El tiempo promedio de espera es: " << promHouse << "minutos" << endl << endl;    
            }
            break;
        case 9:
            if(admin == false){
                cout << "Solo el Administrador tiene acceso a esta opcion del menu" << endl << endl;
            }

            if(admin == true){
                cout << "digite el ID de la orden a eliminar: "; cin >> id;
                if(VerifyId(DeliveryOrder,id) == true or VerifyId(HouseOrder,id) == true){
                    cancelOrder(id);
                    cout << "La orden " << id << " a sido cancelada existosamente" << endl << endl;
                }else{
                    cout << "No existe orden con ID: " << id << endl << endl;
                }
            }
            break;
        case 10:
            totalSa = totalSales(ListDelivery, 0) + totalSales(ListHouse, 0);
            cout << "El total de ventas es: $" << totalSa;
            cout << endl << endl;
            break;
        case 11:
            if(login() == false){
                return 0;
            }
            cout << endl << endl;
            break;
        case 12:
            continue1 = false;
            break;  
        default:
            cout << "Opcion Invalida" << endl << endl;
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
        // Se pregunta que usuario es
        cout << " Bienvenido, digame que usuario es: " << endl ;
        cout << "1. Administrador " << endl << "2. Empleado" << endl << "3. Salir del sistema" << endl << "Digite su opcion: ";
        cin >> option;
        
        switch (option)
        {
        case 1:
            do
            {
                // Si es Administrador se pide la contraseña para acceder al sistema
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
        case 2: // si es empleado no pide acceso 
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

    // Se piden los datos de la orden
    Delivery orderInfo;
    orderInfo.info.id = ID_ORDER++;
    cout << endl;
    cout << "ID: " << orderInfo.info.id << endl;
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
    cout << "El tiempo de espera es de: " << orderInfo.info.wait << "minutos" << endl;

    // monto de la orden
    // calculos para el monto...
    float totalStarter = garlicBread*priceGarlicBread + cheeseSticks*priceCheeseSticks + pizzaRolls*pricePizzaRolls;
    float totalmainDish = pizza*pricePizza + pasta*pricePasta + lasagna*priceLasagna;
    float totalDrink = soda*priceSoda + beer*priceBeer + te*priceIcedTea;
    orderInfo.info.total = (totalStarter + totalmainDish + totalDrink);
    cout << "El subtotal es: $" << orderInfo.info.total;

    DeliveryOrder.push_back(orderInfo);
cout << "Pedido Agregado Exitosamente!!" << endl;
}

// Añadir orden en Restaurante
void House_Order(){
    
    bool continue1 = true, continue2 = true, continue3 = true, continue4 = true; // variables para validar menu
    float sumStarter = 0, sumMainDish = 0, sumDrink = 0; // variables para sumar el total de entradas, platos fuertes y bebidas

    // Se piden los datos de la orden
    Restaurant orderInfo;
    orderInfo.info.id = ID_ORDER++;
    cout << "ID: " << orderInfo.info.id << endl;
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
    cout << "El tiempo de espera es de: " << orderInfo.info.wait << " minutos" << endl;

    // monto de la orden
    // calculos para el monto...
    float totalStarter = garlicBread*priceGarlicBread + cheeseSticks*priceCheeseSticks + pizzaRolls*pricePizzaRolls;
    float totalmainDish = pizza*pricePizza + pasta*pricePasta + lasagna*priceLasagna;
    float totalDrink = soda*priceSoda + beer*priceBeer + te*priceIcedTea;
    orderInfo.info.total = (totalStarter + totalmainDish + totalDrink);
    cout << "El subtotal es: $" << orderInfo.info.total << endl;

    HouseOrder.push_back(orderInfo);
cout << "Orden Agregada Exitosamente!!" << endl;
}

// Muestra las ordenes a Domicilio
void print(vector<Delivery> DeliveryOrder){

    // Se muestran los datos de la orden
    for(int i = 0; i < DeliveryOrder.size(); i++){
     cout << "----------------------------------------------------------------------------" << endl;
        cout << "ID de orden: " << DeliveryOrder[i].info.id << endl;
        cout << "Nombre de la persona que Ordeno: " << DeliveryOrder[i].info.name << endl;
        cout << "No. de Telefono: " << DeliveryOrder[i].address.telephone << endl;
        cout << "Direccion: ";
        cout << "Casa No." << DeliveryOrder[i].address.nHouse;
        cout << ", Colonia " << DeliveryOrder[i].address.Col;
        cout << ", Municipio " << DeliveryOrder[i].address.munici;
        cout << ", Departamento " << DeliveryOrder[i].address.state << endl;
        
        // Se muestran entradas
        cout << "Entradas: " << endl;
       
        for(int s = 0; s < DeliveryOrder[i].info.Starter.size(); s++){

            switch (DeliveryOrder[i].info.Starter[s])
            {
            case garlicBread:
                cout << "1 Orden de Pan con ajo" <<endl;
                break;
            case pizzaRolls:
                cout << "1 Orden de pizza Rolls" << endl;
                break;
            case cheeseSticks:
                cout << "1 Orden de palitos de queso" << endl;
                break;
            }

        }
        
        // Se muestran Plato principal
        cout << "Plato Principal: " << endl;
        for(int m = 0; m < DeliveryOrder[i].info.MainDish.size(); m++){
           switch (DeliveryOrder[i].info.Starter[m])
            {
            case pizza:
                cout << "1 Pizza" <<endl;
                break;
            case pasta:
                cout << "1 Pasta" << endl;
                break;
            case lasagna:
                cout << "1 Lasagna" << endl;
                break;
            }
        }

        // Se muestran Bebidas
        cout << "Bebidas: " << endl;
        for(int d = 0; d < DeliveryOrder[i].info.PDrink.size(); d++){
            switch (DeliveryOrder[i].info.Starter[d])
            {
            case beer:
                cout << "1 Cerveza" <<endl;
                break;
            case soda:
                cout << "1 soda" << endl;
                break;
            case tea:
                cout << "1 Te helado" << endl;
                break;
            }
        }

        // Se muestra los demas datos de la orden
        if(DeliveryOrder[i].info.payM = cash){
        cout << "Tipo de pago: Efectivo"<< endl;
        }
        if(DeliveryOrder[i].info.payM = card){
            cout << "Tipo de pago: Tarjeta"<< endl;
        }
        cout << "Tiempo de espera: " << DeliveryOrder[i].info.wait << " minutos" << endl;
        cout << "Monto a pagar: $" << DeliveryOrder[i].info.total << endl;
      cout << "----------------------------------------------------------------------------" << endl;
    } 

}

// Muestra las ordenes en el Restaurante
void print(vector<House> HouseOrder){

 for(int i = 0; i < HouseOrder.size(); i++){
    cout << "----------------------------------------------------------------------------" << endl;
        cout << "ID de orden: " << HouseOrder[i].info.id << endl;
        cout << "Nombre de la persona que Ordeno: " << HouseOrder[i].info.name << endl;
        
        cout << "Entradas: " << endl;
       
        for(int s = 0; s < HouseOrder[i].info.Starter.size(); s++){

            switch (HouseOrder[i].info.Starter[s])
            {
            case garlicBread:
                cout << "1 Orden de Pan con ajo" <<endl;
                break;
            case pizzaRolls:
                cout << "1 Orden de pizza Rolls" << endl;
                break;
            case cheeseSticks:
                cout << "1 Orden de palitos de queso" << endl;
                break;
            }

        }
        
        cout << "Plato Principal: " << endl;
        for(int m = 0; m < HouseOrder[i].info.MainDish.size(); m++){
           switch (HouseOrder[i].info.Starter[m])
            {
            case pizza:
                cout << "1 Pizza" <<endl;
                break;
            case pasta:
                cout << "1 Pasta" << endl;
                break;
            case lasagna:
                cout << "1 Lasagna" << endl;
                break;
            }
        }
        cout << "Bebidas: " << endl;
        for(int d = 0; d < HouseOrder[i].info.PDrink.size(); d++){
            switch (HouseOrder[i].info.Starter[d])
            {
            case beer:
                cout << "1 Cerveza" <<endl;
                break;
            case soda:
                cout << "1 soda" << endl;
                break;
            case tea:
                cout << "1 Te Helado" << endl;
                break;
            }
        }

        if(HouseOrder[i].info.payM = cash){
        cout << "Tipo de pago: Efectivo"<< endl;
        }
        if(HouseOrder[i].info.payM = card){
            cout << "Tipo de pago: Tarjeta"<< endl;
        }
        cout << "Tiempo de espera: " << HouseOrder[i].info.wait << " minutos" << endl;
        cout << "Monto a pagar: $" << HouseOrder[i].info.total << endl;

    cout << "----------------------------------------------------------------------------" << endl;
    } 
}

// Despacha Las ordenes a Domicilio
void dispatch(vector<Delivery> DeliveryOrder){
    // Primero se verifica si la lista esta vacia
    if(DeliveryOrder.empty()){
        cout << "No hay ordenes para despachar" << endl;
    }else{
    
    // Se despacha la primera orden y se envia  a una lista auxiliar 
    Delivery orderDispatch = DeliveryOrder.back();
    ListDelivery.push_back(orderDispatch);
    cout << "-----------------------------------" << endl;
    cout << "           DELIVERY" << endl;
    cout << "      Orden a Despachar" << endl;
    cout << "Cliente: "<< orderDispatch.info.name << endl; 
    cout << "Total: $" << orderDispatch.info.total << endl;
    cout << "Orden Despachada Exitosamente" << endl;
    cout << "-----------------------------------" << endl;
    DeliveryOrder.pop_back();
    }

}

// Despacha Las ordenes en el Restaurante
void dispatch(vector<House> HouseOrder){
    if(HouseOrder.empty()){
        cout << "No hay ordenes para despachar" << endl;
    }else{
    Restaurant orderDispatch = HouseOrder.back();
    ListHouse.push_back(orderDispatch);
    cout << "-----------------------------------" << endl;
    cout << "         RESTAURANTE" << endl;
    cout << "      Orden a Despachar" << endl;
    cout << "Cliente: "<< orderDispatch.info.name << endl; 
    cout << "Total: $" << orderDispatch.info.total << endl;
    cout << "Orden Despachada Exitosamente" << endl;
    cout << "-----------------------------------" << endl;
    HouseOrder.pop_back();
    }
}

// Calcula la suma de todos los tiempos a Domicilio con recursividad
int averageTimeDelivery(int aux){

    if(aux == DeliveryOrder.size()){
        return 0;
    }else{
        return DeliveryOrder[aux].info.wait + averageTimeDelivery(aux + 1);
    }
}

// Calcula la suma de todos los tiempos en Restaurante con recursividad
int averageTimeHouse(int aux){
    if(aux == HouseOrder.size()){
        return 0;
    }else{
        return HouseOrder[aux].info.wait + averageTimeHouse(aux + 1);
    }
}

// Cancela la Orden y la elimina de la Lista
void cancelOrder(int Id){ 
   
   // Recorre la lista desde el inicio hasta el final y si se encuentra el id elimina esa orden
    for(auto iter = DeliveryOrder.begin(); iter != DeliveryOrder.end(); iter++){
        if(iter->info.id == Id){ 
        iter = DeliveryOrder.erase(iter);
        break;
        }
    } 

    for(auto iter = HouseOrder.begin(); iter != HouseOrder.end(); iter++){
        if(iter->info.id == Id){
            iter = HouseOrder.erase(iter);
            break;
        }
        
    }
}

// Verifica si la orden a eliminar esta en lista a Domicilio
bool VerifyId(vector<Delivery> DeliveryOrder,int Id){
    // verifica que el elemento, en este caso el id se encuentre en la lista 
        for(Delivery element : DeliveryOrder){
        if(element.info.id == Id){
            return true;
        }else{
            return false;
        }
    }
}

// Verifica si la orden a eliminar esta en lista en Restaurante
bool VerifyId(vector<House> HouseOrder, int Id){
    for(Restaurant element : HouseOrder){
        if(element.info.id == Id){
            return true;
        }else{
            return false;
        }
    }
}

// Calcula el total de ventas a Domicilio
float totalSales(vector<Delivery> ListDelivery, int pos){
    // Con recursividad se verifica cada orden y se extrae el total y se va sumando
    if(pos == ListDelivery.size()){
        return 0;
    }else{
        return ListDelivery[pos].info.total + totalSales(ListDelivery, pos + 1);
    }
}

// Calcula el total de ventas en el Restaurante
float totalSales(vector<House> ListHouse, int pos){
    if(pos == ListHouse.size()){
        return 0;
    }else{
        return ListHouse[pos].info.total + totalSales(ListHouse, pos + 1);
    }
}


