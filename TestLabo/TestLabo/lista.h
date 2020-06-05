#pragma once
#include <iostream>
using namespace std;

template<class T>
class lista {
	T** vector;
public:
	void Agregar(T* elem) {
		//bla bla 
	}
};

class Suceso {

};

class Persona {

};

class Sucesos : protected lista<Suceso> {
public:
	static Sucesos ListaSucesos;
	void Registrar(Persona* s,string QuePaso) {
		Agregar(new Suceso(Datetime.today, s.nombre + ": " + QuePaso));
	}
};

void main() {
	Sucesos::ListaSucesos.Registrar()
}



/*
class p{
  llamarAzafata(az* a){
	Sucesos::ListaSucesos.Registrar(this,"LLamo azafata");
	try{
	a->atenderPasajero(this);
	//algo o lo manejan en atender pasajero
	}
	catch(exception& e){
	//Manejo como quiera
	//Busco otra azafata (No recomendado)
	//o un return
		Sucesos::ListaSucesos.Registrar(az,"azafata ocupada");
		return;
		throw e; //Si quiero que lo maneje alguien mas arriba
	}
  }

}

class az{
	atenderPasajero(p* pasaj){
		if(!disponible)
			throw exception("az no disponible");
		Sucesos::ListaSucesos.Registrar(this,"Atendio pasajero azafata");
		//hacer algo con el pasajero
	}


}

*/
