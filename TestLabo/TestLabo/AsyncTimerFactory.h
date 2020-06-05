#pragma once

#include "AsyncTimer.h"
#include "cLista.h"
#include <memory>
using namespace std;

template<typename T>
class AsyncTimerFactory {
	static unique_ptr<cLista<AsyncTimer<T>>> timerList;

public:
	/*Ejecuta el metodo del objeto context en intervalo tiempo
	Intervalo de tiempo para ejecutar el timer, puntero a objeto (En general this), puntero a metodo del objeto
	*/
	static void NewTimer(long interval, T* context, void(T::* func)()) {
		if (timerList == NULL)
			timerList = make_unique<cLista<AsyncTimer<T>>>();
		AsyncTimer<T>* timer = new AsyncTimer<T>(interval, context, func);
		timer->start();
		timerList->AgregarItem(timer);
	}

};

template<typename T>
unique_ptr<cLista<AsyncTimer<T>>> AsyncTimerFactory<T>::timerList = NULL;