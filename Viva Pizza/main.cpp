// Proyecto de Laboratorio, *** Sistema de Ventas ***

#include <string> // Para poder hacer uso de cadenas de caracteres
#include <iostream>
using namespace std;

// Estructuras a Utilizar
    struct Address{
    string Col, munici, state;
    int nHouse;
};
    struct Order{ // Para pedidos a Domicilio
   	string name;
    Address address;
    int Telephone;
    string Main_Plate;
    string input;
    string Drink;
    int  Quantity;
    string Payment;
};



    struct Charge{ // Para enargos en el restaurante
   	string name;
    string Main_Plate;
    string input;
    string Drink;
    int  Quantity;
    string Payment;
};

// Funciones a Utilizar
int login();
void menuAdmin();
void menuEmploy();
void Add_Order(Order* Orders, int size);
void Add_Charge(Charge* Charges, int size);
void Home_delivery(Order* Orders, int size);
void Restaurant_Order(Charge* Charges, int size);
void Search();
void Total_Sale();




int main(){
    // Declarando Variables
    bool continue1 = true;
    bool continue3 = true;

    // Con un do while evaluamos la clave ingresada, al estar correcta desplega el menu de opciones
    login();
}

int login(){
    int user;
    bool continue1 =  true;
    do
    {
        cout << "\033[35m Bienvenido, digame que usuario es: " << endl ;
        cout << "1. Administrador " << endl << "2. Empleado" << endl << "3. Salir del sistema" << endl << "Digite su opcion: ";
        cin >> user;

        switch (user)
        {
        case 1:
            menuAdmin();
            break;
        case 2:
            menuEmploy();
            break;
        case 3: 
        cout << "El sistema se a cerrado exitosamente" << endl;
        return 0;
            break;
        default:
            break;
        }
    } while (continue1);
    
}

void menuAdmin(){
    string password;
    bool continue1 = true;
    bool continue2 = true;
    Order* add1;
    Charge* add2;
    int num1=0, num2=0;
    
    
    do
    {
        cout << "Digite la contraseña para poder ingresar al menu" << endl;
        cin >> password;
        if(password != "nullptr" && password != "NULLPTR"){
            cout << "Contraseña erronea " << endl;
        }else{
do {
		         int opcion = 0;
                 cout << " Usuario: Administrador " <<endl;
                 cout << "  ***Menu Viva Pizza***  " << endl;
		         cout << "Opciones disponibles: " << endl;
                 cout << "1) Agregar  pedido a Domicilio" << endl;
		         cout << "2) Agregar  encargo en Restaurante" << endl;
		         cout << "3) Ver pedidos a Domicilio" << endl;
                 cout << "4) Ver encargos en el restaurante" << endl;
                 cout << "5) Buscar orden segun nombre de persona" << endl;
                 cout << "6) Ver total de venta" << endl;
                 cout << "7) Borrar Orden" << endl;
                 cout << "8) Volver al administrador de usuarios" << endl;
		         cin >> opcion;
		         switch (opcion) {
		         case 1: 
                    
                    cout<<"¿Cuantos pedidos a Domicilio desea agregar?"<<endl;
                    cin>>num1; 
                    add1= new Order[num1]; 
                    Add_Order(add1, num1);
                    cout<<endl;
		            break;
		         case 2: 
                    cout<<"¿Cuantos encargos en restaurante desea agregar?"<<endl;
                    cin>>num2; 
                    add2= new Charge[num2];
                    Add_Charge(add2, num2);
			        break;
		         case 3: 
                    Home_delivery(add1, num1);
			        break;
		         case 4: 
                    Restaurant_Order(add2, num2);
			        break;
                 case 5:
                    Search();
                    break;
                 case 6: 
                    Total_Sale();
			        break;
                 case 7:
                    // funcion borrar
                    break;
                 case 8: 
                    login();
			        break;
		         default: cout << "Opcion erronea!" << endl;
			        break;
		        }
	} while (continue2);    
        }
    } while (continue1);  
    
}

void menuEmploy(){
    bool continue1 = true;
    Order* add1;
    Charge* add2;
    int num1=0, num2=0;
    
    do
    {
        int opcion = 0;
        cout << " Usuario: Empleado \\" << endl;
        cout << "  ***Menu Viva Pizza***  " << endl;
		cout << "Opciones disponibles: " << endl;
        cout << "1) Agregar  pedido a Domicilio" << endl;
		cout << "2) Agregar  encargo en Restaurante" << endl;
		cout << "3) Ver pedidos a Domicilio" << endl;
        cout << "4) Ver encargos en el restaurante" << endl;
        cout << "5) Buscar orden segun nombre de persona" << endl;
        cout << "6) Ver total de venta" << endl;
        cout << "7) Volver al administrador de usuarios" << endl;
		cin >> opcion;
		    switch (opcion) {
		        case 1: 
                    cout<<"¿Cuantos pedidos a Domicilio desea agregar?"<<endl;
                    cin>>num1; 
                    add1= new Order[num1]; 
                    Add_Order(add1, num1);
                    cout<<endl;
		            break;
		         case 2: 
                    cout<<"¿Cuantos encargos en restaurante desea agregar?"<<endl;
                    cin>>num2; 
                    add2= new Charge[num2];
                    Add_Charge(add2, num2);
			        break;
		         case 3: 
                    Home_delivery(add1, num1);
			        break;
		         case 4: 
                    Restaurant_Order(add2, num2);
			        break;
                 case 5:
                    Search();
                    break;
                 case 6: 
                    Total_Sale();
			        break;
                 case 7: 
                    login();
			        break;
		         default: cout << "Opcion erronea!" << endl;
			        break;
		        }
    } while (continue1);
    
}

void Add_Order(Order* Orders, int size){

for (int i = 0; i <size; i++){
    
    cout << "Orden No. ORDDx" << i+1 << endl;
    cout<< "Digite el numero de telefono del cliente: " << endl;
    cin >> Orders[i].Telephone; cin.ignore();

    cout << "Digite el nombre de quien realiza el pedido " << ": " << endl;
    getline(cin,Orders[i].name); cin.ignore();

    cout<< "Digite la direccion del pedido"<<endl;
    cout << "No. de Casa: "; cin >> Orders[i].address.nHouse;
    cout << "Colonia: "; cin >> Orders[i].address.Col;
    cout << "Municipio: "; cin >> Orders[i].address.munici;
    cout << "Departamento: "; cin >> Orders[i].address.state;

    cout << "Digite el nombre del plato principal que desea: " << endl;
    cout << "1) Pizza" << endl << "2) Ensalada" << endl << "3) Pasta" << endl;
    cin >> Orders[i].Main_Plate;

    cout << "Digite el nombre de la entrada que desea: " << endl;
    cout << "1) Palitroques" << endl << "2) Alitas" << endl;
    cin >> Orders[i].input;

     cout << "Digite el nombre de la bebida que desea: " << endl;
    cout << "1) Gaseosa" << endl << "2) Te" << endl;
    cin >> Orders[i].Drink;

    cout << "Digite el monto a pagar" << endl;
    cin >> Orders[i].Quantity;

    cout << "Digite el tipo de pago" << endl;
    cout << "1) Tarjeta" << endl << "2) Efectivo" << endl;
    cin >> Orders[i].Payment;

    cout<<endl;
}
cout << "Pedido Agregado Exitosamente!!" << endl;
}

void Add_Charge(Charge* Charges, int size){

for (int i = 0; i < size; i++){
    cout << "Orden No. CHRx" << i+1 << endl;
    cin.ignore();
    cout << "Digite el nombre de quien realiza el pedido " << ": " << endl;
	getline(cin,Charges[i].name);

    cout << "Digite el nombre del plato principal que desea: " << endl;
    cout << "1) Pizza" << endl << "2) Ensalada" << endl << "3) Pasta" << endl;
    cin >> Charges[i].Main_Plate;

    cout << "Digite el nombre de la entrada que desea: " << endl;
    cout << " 1) Palitroques" << endl << "2) Alitas" << endl;
    cin >> Charges[i].input;

    cout << "Digite el nombre de la bebida que desea: " << endl;
    cout << "1) Gaseosa" << endl << "2) Te" << endl;
    cin >> Charges[i].Drink;

    cout << "Digite el monto a pagar" << endl;
    cin >> Charges[i].Quantity;

    cout << "Digite el tipo de pago" << endl;
    cout << "1) Tarjeta" << endl << "2) Efectivo" << endl;
    cin >> Charges[i].Payment;

    cout << endl;
}

cout << "Orden Agregada Exitosamente!!"<<endl;
}

// Funcion que mostrara los pedidos a Domicilio
void Home_delivery(Order* Orders, int size){

    for(int i=0;i<size;i++){
    cout << "Orden No. ORDDx" << i+1 << endl;
	cout << "Nombre: " << Orders[i].name << endl;
    cout << "Direcion: " << endl;
    cout << "No. De casa: " << Orders[i].address.nHouse << endl;
    cout << "Colonia: " << Orders[i].address.Col << endl;
    cout << "Municipio: " << Orders[i].address.munici << endl;
    cout << "Departamento: " << Orders[i].address.state << endl;

    cout << "Numero de Telefono: " << Orders[i].Telephone << endl;
    cout << "Plato principal: " << Orders[i].Main_Plate << endl;
    cout << "Entrada Solicitada: " << Orders[i].input << endl;
    cout << "Bebida: " << Orders[i].Drink << endl;
    cout << "Monto a pagar: " << Orders[i].Quantity << endl;
    cout << "Tipo de pago: " << Orders[i].Payment << endl; 
    cout << endl;
    } 
    cout << endl;
}

// Funcion que mostrara los encargos en restaurante
void Restaurant_Order(Charge* Charges, int size){

    for(int i=0;i<size;i++){
    cout << "Orden No. CHRx" << i+1 << endl;
	cout << "Nombre: " << Charges[i].name << endl;
    cout << "Plato principal: " << Charges[i].Main_Plate<<endl;
    cout << "Entrada Solicitada: " << Charges[i].input<<endl;
    cout << "Bebida: " << Charges[i].Drink << endl;
    cout << "Monto a pagar: " << Charges[i].Quantity << endl;
    cout << "Tipo de pago: " << Charges[i].Payment << endl; 
    cout << endl;
    } 
    cout << endl;
}

void Search(){
}

void Total_Sale(){
}
