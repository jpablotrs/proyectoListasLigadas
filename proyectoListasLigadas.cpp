#include <iostream>
using namespace std;


class Cancion{
	private:
		string titulo;
		string cantante;
		int duracion;
		Cancion* sig;
	public:
		Cancion(){
			titulo = "";
			cantante = "";
			duracion = 0;
			sig = NULL;
		}
		Cancion(string tit, string can, int dur, Cancion* s){
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
		void setSig(Cancion* s){
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
		int prioridad;
		//tres variables auxiliares para pedir los daos
		string tituloAux;
		string cantanteAux;
		int duracionAux;
	public:
		ListaReproduccion(int prio){
			cabeza = NULL;
			prioridad = prio;
		}
		
		~ListaReproduccion(){
			Cancion* p = cabeza;
			while(p != NULL){
				cabeza = p->getSig();
				delete p;
				p = cabeza;
			}
		}
		
		//metodo para pedir datos de acuerdo a la prioridad
		void pedirDatos(){
			switch(prioridad){
				case 1:
					cin.ignore();
					do{					
						cout<<"Titulo: ";
						getline (cin, tituloAux);
					}while(tituloAux=="");
					do{
						cout<<"Cantante: ";
						getline (cin, cantanteAux);
					}while(cantanteAux=="");
					do{
						cout<<"Duracion: ";
						cin >> duracionAux;
					}while(duracionAux<=0);
					cout << endl << endl;
					break;
				case 2:
					
					cin.ignore();
					do{
						cout<<"Cantante: ";
						getline (cin, cantanteAux);
					}while(cantanteAux=="");
					do{					
						cout<<"Titulo: ";
						getline (cin, tituloAux);
					}while(tituloAux=="");
					do{
						cout<<"Duracion: ";
						cin >> duracionAux;
					}while(duracionAux<=0);
					cout << endl << endl;
					break;
				case 3:
					
					do{
						cout<<"Duracion: ";
						cin >> duracionAux;
					}while(duracionAux<=0);
					cin.ignore();
					do{					
						cout<<"Titulo: ";
						getline (cin, tituloAux);
					}while(tituloAux=="");
					do{
						cout<<"Cantante: ";
						getline (cin, cantanteAux);
					}while(cantanteAux=="");
					cout << endl << endl;
					break;
			}
			
		}
		
		void insertar(){
			Cancion *p = new Cancion();
			p->setTitulo(tituloAux);
			p->setCantante(cantanteAux);
			p->setDuracion(duracionAux);
			//Insertar cuando la lista esta vacia
			
			if(estaVacia()){
				p->setSig(NULL);
				cabeza = p;
				return;
			}
			
			//recorrer la lista para ver donde meter el dato de acuerdo a la prioridad
			Cancion* aux;
			Cancion* ant;
			ant = NULL;
			aux = cabeza;
			while(aux!=NULL){
				switch(prioridad){
					case 1:
						if(p->getTitulo() < aux->getTitulo()){
							if(ant==NULL){
								//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
								p->setSig(aux);
								cabeza = p;
								return;
							}
							//se inserta en cualquier otra posicion
							p->setSig(aux);
							ant-> setSig(p);
							return;
						}
						if(p->getTitulo() == aux->getTitulo()){
							//SE REVISAN LOS DEMAS PARAMETROS
							if(p->getCantante() < aux->getCantante()){
								if(ant==NULL){
									//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
									p->setSig(aux);
									cabeza = p;
									return;
								}
								//se inserta en cualquier otra posicion
								p->setSig(aux);
								ant->setSig(p);
								return;
							}
							if(p->getCantante() == aux->getCantante()){
							//SE REVISA el ultimo parametro
							if(p->getDuracion() <= aux->getDuracion()){
								if(ant==NULL){
									//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
									p->setSig(aux);
									cabeza = p;
									return;
								}
								//se inserta en cualquier otra posicion
								p->setSig(aux);
								ant->setSig(p);
								return;
							}
							if (p->getDuracion()>aux->getDuracion() && aux->getSig()==NULL){
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
							}
							
							}
							if(p->getCantante()>aux->getCantante() && aux->getSig()==NULL){
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
							}
						}
						if((p->getTitulo() > aux->getTitulo()) && (aux->getSig() == NULL)){
							p->setSig(aux->getSig());
							aux->setSig(p);
							return;
						}
						break;
					case 2:
						if(p->getCantante()<aux->getCantante()){
							if(ant==NULL){
								//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
								p->setSig(aux);
								cabeza = p;
								return;
							}
							//se inserta en cualquier otra posicion
							p->setSig(aux);
							ant->setSig(p);
							return;
						}
						if(p->getCantante() == aux->getCantante()){
							//SE REVISAN LOS DEMAS PARAMETROS
							if(p->getTitulo()<aux->getTitulo()){
								if(ant==NULL){
									//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
									p->setSig(aux);
									cabeza = p;
									return;
								}
								//se inserta en cualquier otra posicion
								p->setSig(aux);
								ant->setSig(p);
								return;
							}
							if(p->getTitulo() == aux->getTitulo()){
							//SE REVISA el ultimo parametro
								if(p->getDuracion() <= aux->getDuracion()){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								//se inserta despues del aux
								if (p->getDuracion()>aux->getDuracion() && aux->getSig()==NULL){
									p->setSig(aux->getSig());
									aux->setSig(p);
									return;
								}
						    	}
						    	if((p->getTitulo() > aux->getTitulo()) && (aux->getSig() == NULL)){
									p->setSig(aux->getSig());
									aux->setSig(p);
									return;
								}
							}
							if((p->getCantante() > aux->getCantante()) && (aux->getSig() == NULL)){
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
							}
							break;
					case 3:
							if(p->getDuracion() < aux->getDuracion()){
								if(ant==NULL){
									//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
									p->setSig(aux);
									cabeza = p;
									return;
								}
								//se inserta en cualquier otra posicion
								p->setSig(aux);
								ant->setSig(p);
								return;
							}
							if(p->getDuracion() == aux->getDuracion()){
								//SE REVISAN LOS DEMAS PARAMETROS
								if(p->getTitulo()<aux->getTitulo()){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								if(p->getTitulo() == aux->getTitulo()){
								//SE REVISA el ultimo parametro
								if(p->getCantante()<aux->getCantante()){
									if(ant==NULL){
										//SE INSERTA EN LA PRIMER POSICION Y SE ACTUALIZA CABEZA
										p->setSig(aux);
										cabeza = p;
										return;
									}
									//se inserta en cualquier otra posicion
									p->setSig(aux);
									ant->setSig(p);
									return;
								}
								//se inserta despues del aux si cantante es mayor y no hay mas datos despues
								if((p->getCantante() > aux->getCantante()) && (aux->getSig() == NULL)){
									p->setSig(aux->getSig());
									aux->setSig(p);
									return;
								}
								}
								if((p->getTitulo() > aux->getTitulo()) && (aux->getSig() == NULL)){
									p->setSig(aux->getSig());
									aux->setSig(p);
									return;
								}
							}
							if (p->getDuracion()>aux->getDuracion() && aux->getSig()==NULL){
								p->setSig(aux->getSig());
								aux->setSig(p);
								return;
							}
							break;
				}
				ant = aux;
				aux = aux->getSig();
			}
		}
		
		int estaVacia(){
			if(cabeza == NULL)
				return 1;
			else
			
				return 0;
		}

		
		void mostrar(){
			if(estaVacia()){
				cout<<"Error, La lista de reproduccion esta vacia"<<endl;
				return;
			}
			Cancion* p = cabeza;
			int cont = 1;
			switch(prioridad){
				case 1:
					while(p != NULL){
						cout << "\n<-----Cancion "<<cont<<"----->";
						cout <<"\nTitulo: "<<p->getTitulo()<<endl;
						cout <<"\nCantante: "<< p->getCantante()<<endl;
						cout <<"\nDuracion: "<< p->getDuracion()<<endl;
						cout << '\n' << '\n';
						p = p->getSig();
						cont ++;
					}
					break;
				case 2:
					while(p != NULL){
						cout << "\n<-----Cancion "<<cont<<"----->";
						cout <<"\nCantante: "<< p->getCantante()<<endl;
						cout <<"\nTitulo: "<< p->getTitulo()<<endl;
						cout <<"\nDuracion: "<< p->getDuracion()<<endl;
						cout << '\n' << '\n';
						p = p->getSig();
						cont ++;
					}
					break;
				case 3:
					while(p != NULL){
						cout << "\n<-----Cancion "<<cont<<"----->";
						cout <<"\nDuracion: "<< p->getDuracion()<<endl;
						cout <<"\nTitulo: "<< p->getTitulo()<<endl;
						cout <<"\nCantante: "<< p->getCantante()<<endl;
						cout << '\n' << '\n';
						p = p->getSig();
						cont ++;
					}
					break;
			}
		}
		
		void eliminarCancionTitulo(string tit){
			if(estaVacia()){
				cout << "ERROR, no hay canciones en la lista de reproduccion."<<endl;
			}
			Cancion* p = cabeza;
			Cancion* aux = NULL;
			
			while(p != NULL){
				if(aux==NULL && (p->getTitulo() == tit)){
					cabeza = p->getSig();
					delete p;
					cout<<endl<<"Cancion eliminada\n";
					return;
				}else if(p->getTitulo() == tit){
					aux->setSig(p->getSig());
					delete p;
					return;
				}
				aux = p;
				p = p->getSig();
			}
			cout<<endl<<"Cancion no encontrada\n";
		}
		
		void eliminarCancionCantante(string can){
			if(estaVacia()){
				cout << "ERROR, no hay canciones en la lista de reproduccion."<<endl;
			}
			Cancion* p = cabeza;
			Cancion* aux = NULL;
			
			while(p != NULL){
				if(aux==NULL && (p->getCantante() == can)){
					cabeza = p->getSig();
					delete p;
					cout<<endl<<"Cancion eliminada\n";
					return;
				}else if(p->getCantante() == can){
					aux->setSig(p->getSig());
					delete p;
					return;
				}
				aux = p;
				p = p->getSig();
			}
			cout<<endl<<"Cancion no encontrada\n";
		}
		
		void eliminarCancionDuracion(int dur){
			if(estaVacia()){
				cout << "ERROR, no hay canciones en la lista de reproduccion."<<endl;
			}
			Cancion* p = cabeza;
			Cancion* aux = NULL;
			
			while(p != NULL){
				if(aux==NULL && (p->getDuracion() == dur)){
					cabeza = p->getSig();
					delete p;
					cout<<endl<<"Cancion eliminada\n";
					return;
				}else if(p->getDuracion() == dur){
					aux->setSig(p->getSig());
					delete p;
					return;
				}
				aux = p;
				p = p->getSig();
			}
			cout<<endl<<"Cancion no encontrada\n";
		}
		
		
};

void menu(ListaReproduccion* li){
	int opc = 1;
	string busqueda;
	int busquedaInt;
	while(opc!=6){
		cout << "1. Insertar cancion."<<'\n'<<"2. Mostrar lista."<<'\n'<<"3. Eliminar cancion por titulo."<<'\n'<<"4. Eliminar cancion por cantante."<<'\n'<<"5. Eliminar cancion por duracion."<<'\n'<<"6. Salir"<<endl;	
		cin >> opc;
		
		if(opc>6 || opc<1)
			cout<<"\n\tValor incorrecto, intenta nuevamente\n";
			
			
		switch(opc){
			case 1:
				li->pedirDatos();
				li->insertar();
				break;
			case 2:
				li->mostrar();
				break;
			case 3:
				cin.ignore();
				cout<<"Titulo a eliminar: ";
				getline (cin, busqueda);
				li->eliminarCancionTitulo(busqueda);
				break;
			case 4: 
				cin.ignore();
				cout<<"Cantante a eliminar: ";
				getline (cin, busqueda);
				li->eliminarCancionCantante(busqueda);
				break;
			case 5: 
				cout<<"Duracion a eliminar: ";
				cin>>busquedaInt;
				li->eliminarCancionDuracion(busquedaInt);
				break;
		}
		cout<<endl<<endl;
			
			
	}	
}

int jerarquiaInsert(){
	int opc;
	do{
		cout << "Como quieres ingresar y ordenar lo datos de las canciones: "<<endl;
		cout << "1. Por titulo."<<'\n'<<"2. Por cantante."<<'\n'<<"3. Por duracion."<<endl;
		cin >> opc;
	}while(opc<1 || opc>3);
	return opc;
}

void cancionesIniciales(ListaReproduccion* li){
	int cant;
	do{
		cout << "Con cuantas canciones quieres comenzar: "<<endl;
		cin >> cant;
		if(cant<0)
			cout<<"\nError, debes ingresar un numero mayor o igual a 0.\n\n";
			
	}while(cant<0);
	
	int j = 1;
	for(int i = 0 ; i < cant ; i++){
		cout <<"<---"<< " Cancion "<<j<<" --->"<<endl;
		li->pedirDatos();
		li->insertar();
		j = j+1;
	}
}

int main(){
	int prio = jerarquiaInsert();
	ListaReproduccion* li = new ListaReproduccion(prio);
	cancionesIniciales(li);
	menu(li);
	
	return 0;
}
