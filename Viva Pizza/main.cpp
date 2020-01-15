// Proyecto de Laboratorio, *** Sistema de Ventas ***

#include <string.h> // Para poder hacer uso de cadenas de caracteres
#include <iostream>
using namespace std;

// Estructuras a Utilizar
    struct Order{ // Para pedidos a Domicilio
   	char name[20];
    char address[20];
    int Telephone;
    char Main_Plate[20];
    char input[20];
    char Drink[20];
    int  Quantity;
    char Payment[20];
};

    struct Charge{ // Para enargos en el restaurante
   	char name[20];
    char Main_Plate[20];
    char input[20];
    char Drink[20];
    int  Quantity;
    char Payment[20];
};

// Funciones a Utilizar
void Add_Order(Order* Orders, int size);
void Add_Charge();
void Home_delivery(Order* Orders, int size);
void Restaurant_Order(Charge* Charges, int size);
void Total_Sale();




int main(){
    // Declarando Variables
    string password;
    bool continue1=true;
    bool continue2=true;
    Order* add1;
    Charge* add2;
    int num1=0, num2=0;

    // Con un do while evaluamos la clave ingresada, al estar correcta desplega el menu de opciones
    do
    {
      cout<<"Ingrese la clave de acceso: "<<endl;  
      cin>>password;
        if(password!="nullptr" && password!="NULLPTR"){
            cout<<"La clave ingresada es invalida"<<endl;
        }else{
            do {
		         int opcion = 0;
                 cout<<"  ***Menu Viva Pizza***  "<<endl;
		         cout << "Opciones disponibles: "<<endl;
                 cout<<"1) Agregar  pedido a Domicilio"<<endl;
		         cout<<"2) Agregar  encargo en Restaurante"<<endl;
		         cout<<"3) Ver pedidos a Domicilio"<<endl;
                 cout<<"4) Ver encargos en el restaurante"<<endl;
                 cout<<"5) Ver total de venta"<<endl;
                 cout<<"6) Salir del Menu"<<endl;
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
                    Total_Sale();
			        break;
                 case 6: continue2=false;
			        break;
		         default: cout << "Opcion erronea!" << endl;
			        break;
		        }
	} while (continue2);
            }
        } while (continue1);
    
    return 0;
}

void Add_Order(Order* Orders, int size){

for (int i = 0; i <size; i++){

    cout<< "Digite el nombre de quien realiza el pedido "<<": "<<endl;
	cin>>Orders[i].name;

    cout<< "Digite la direccion del pedido"<<endl;
    cin>>Orders[i].address;

    cout<< "Digite el numero de telefono del cliente: "<<endl;
    cin>>Orders[i].Telephone;

    cout<< "Digite el nombre del plato principal que desea: "<<endl;
    cout<< "1) Pizza"<<endl<< "2) Ensalada"<<endl<< "3) Pasta"<<endl;
    cin>>Orders[i].Main_Plate;

    cout<< "Digite el nombre de la entrada que desea: "<<endl;
    cout<< "1) Palitroques"<<endl<< "2) Alitas"<<endl;
    cin>>Orders[i].input;

     cout<< "Digite el nombre de la bebida que desea: "<<endl;
    cout<< "1) Gaseosa"<<endl<< "2) Te"<<endl;
    cin>>Orders[i].Drink;

    cout<< "Digite el monto a pagar"<<endl;
    cin>>Orders[i].Quantity;

    cout<< "Digite el tipo de pago"<<endl;
    cout<< "1) Tarjeta"<<endl<< "2) Efectivo"<<endl;
    cin>>Orders[i].Payment;

    cout<<endl;
}
cout<<"Pedido Agregado Exitosamente!!"<<endl;
}

void Add_Charge(Charge* Charges, int size){

for (int i = 0; i < 1; i++){

    cout<< "Digite el nombre de quien realiza el pedido "<<i+1<<": "<<endl;
	cin>>Charges[i].name;

    cout<< "Digite el nombre del plato principal que desea: "<<endl;
    cout<< "1) Pizza"<<endl<< "2) Ensalada"<<endl<< "3) Pasta"<<endl;
    cin>>Charges[i].Main_Plate;

    cout<< "Digite el nombre de la entrada que desea: "<<endl;
    cout<<" 1) Palitroques"<<endl<< "2) Alitas"<<endl;
    cin>>Charges[i].input;

     cout<< "Digite el nombre de la bebida que desea: "<<endl;
    cout<< "1) Gaseosa"<<endl<< "2) Te"<<endl;
    cin>>Charges[i].Drink;

    cout<< "Digite el monto a pagar"<<endl;
    cin>>Charges[i].Quantity;

    cout<< "Digite el tipo de pago"<<endl;
    cout<< "1) Tarjeta"<<endl<< "2) Efectivo"<<endl;
    cin>>Charges[i].Payment;

    cout<<endl;
}

cout<<"Orden Agregada Exitosamente!!"<<endl;
}

// Funcion que mostrara los pedidos a Domicilio
void Home_delivery(Order* Orders, int size){

    for(int i=0;i<size;i++){
        cout<<"1"<<endl;
        
	cout<<"Nombre: "<<Orders[i].name<<endl;
    cout<<"Direcion: "<<Orders[i].address<<endl;
    cout<<"Numero de Telefono: "<<Orders[i].Telephone<<endl;
    cout<<"Plato principal: "<<Orders[i].Main_Plate<<endl;
    cout<<"Entrada Solicitada: "<<Orders[i].input<<endl;
    cout<<"Bebida: "<<Orders[i].Drink<<endl;
    cout<<"Monto a pagar: "<<Orders[i].Quantity<<endl;
    cout<<"Tipo de pago: "<<Orders[i].Payment<<endl; 
    } 
    cout<<endl;
}

// Funcion que mostrara los encargos en restaurante
void Restaurant_Order(Charge* Charges, int size){
    for(int i=0;i<size;i++){
	cout<<"Nombre: "<<Charges[i].name<<endl;
    cout<<"Plato principal: "<<Charges[i].Main_Plate<<endl;
    cout<<"Entrada Solicitada: "<<Charges[i].input<<endl;
    cout<<"Bebida: "<<Charges[i].Drink<<endl;
    cout<<"Monto a pagar: "<<Charges[i].Quantity<<endl;
    cout<<"Tipo de pago: "<<Charges[i].Payment<<endl; 

    } 
    cout<<endl;
}

void Total_Sale(){
}
