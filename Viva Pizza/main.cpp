// Proyecto de Laboratorio, *** Sistema de Ventas ***

#include <string.h>
#include <iostream>
using namespace std;

// Funciones a Utilizar
void Menu();
void Add_Order();
void Add_Charge();
void Home_delivery();
void Restaurant_Order();
void Total_Sale();

int main(){
    // Declarando Variables
    string password;
    bool continue1=true;
    
    do
    {
      cout<<"Ingrese la clave de acceso: "<<endl;  
      cin>>password;
        if(password!="nullptr"){
            cout<<"La clave ingresada es invalida"<<endl;
        }else{
            continue1=true;
            Menu();
        }
    } while (continue1);
    
    return 0;
}

void Menu(){
    bool continue2=true;
	do {
		int opcion = 0;
        cout<<"   ***Viva Pizza***  "<<endl;
		cout << "Opciones disponibles: "<<endl;
        
		cout<<"1) Agregar pedido a Domicilio"<<endl;
		cout<<"2) Agregar 1 encargo en Restaurante"<<endl;
		cout<<"3) Ver pedidos a Domicilio"<<endl;
        cout<<"4) Ver encargos en el restaurante"<<endl;
        cout<<"5) Ver total de venta"<<endl;
        cout<<"6) Salir del Menu"<<endl;


		cin >> opcion;
		switch (opcion) {
		case 1: Add_Order();
			break;
		case 2: Add_Charge();
			break;
		case 3: Home_delivery();
			break;
		case 4: Restaurant_Order();
			break;
        case 5: Total_Sale();
			break;
        case 6: continue2=false;
			break;
		default: cout << "Opcion erronea!" << endl;
			break;
		}
	} while (continue2);

}

void Add_Order(){
}

void Add_Charge(){
}

void Home_delivery(){
}

void Restaurant_Order(){
}

void Total_Sale(){
}
