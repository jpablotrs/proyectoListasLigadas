#include <iostream>
using namespace std;

class Cancion{
	private:
		string titulo;
		string cantante;
		int duracion;
		Cancion* sig;
	public:
		cancion(){
			titulo = "";
			cantante = "";
			duracion = 0;
			sig = NULL;
		}
		cancion(string tit, string can, int dur, Cancion* s){
			titulo = tit;
			cantante = can;
			duracion = dur;
			sig = s;
		}
		void setTitulo(string tit){
			titulo = tit;
		}
		void setCantante(string can){
			cantante = can;
		}
		void setDuracion(int dur){
			duracion = dur;
		}
		void setSiguiente(Cancion* s){
			sig = s;
		}
		string getTitulo(){
			return titulo;
		}
		string getCantante(){
			return cantante;
		}
		int getDuracion(){
			return duracion;
		}
		Cancion* getSig(){
			return sig;
		}	
};

class ListaReproduccion{
	private:
		Cancion* cabeza;
	public:
		ListaReproduccion(){
			cabeza = NULL;
		}
		
		~ListaReproduccion(){
			Cancion* p = cabeza;
			while(p != NULL){
				cabeza = p->getSig();
				delete p;
				p = cabeza;
			}
		}
		
		void insertar(string tit,string can,int dur, int opc){
			Cancion* p = new Cancion();
			switch(opc){
				case 1:
					p->setTitulo(tit);
					p->setCantante(can);
					p->setDuracion(dur);
					break;
				case 2:
					p->setCantante(can);
					p->setTitulo(tit);
					p->setDuracion(dur);	
					break;
				case 3:
					p->setDuracion(dur);
					p->setTitulo(tit);
					p->setCantante(can);
					break;
			}
			p->setSig(cabeza);
			cabeza = p;
		}
		
		int estaVacia(){
			if(cabeza == NULL)
				return 1;
			else
				return 0;
		}
		
		void mostrar(){
			if(estaVacia()){
				cout<<"Error:::La lista de reproducción esta vacia";
				return;
			}
			Cancion* p = cabeza;
			while(p != NULL){
				
			}
		}
		
}


int main(){
	cout << "Hola mundo";
	
	return 0;
}
