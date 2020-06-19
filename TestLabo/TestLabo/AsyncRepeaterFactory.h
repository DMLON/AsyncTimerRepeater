#pragma once

#include "AsyncRepeater.h"
#include "cLista.h"
#include <memory>
using namespace std;

template<typename T>
class AsyncRepeaterFactory {
	static unique_ptr<cLista<AsyncRepeater<T>>> timerList;

public:
	/*Ejecuta el metodo del objeto context en intervalo tiempo
	Intervalo de tiempo para ejecutar el timer, puntero a objeto (En general this), puntero a metodo del objeto
	*/
	static void NewTimer(long interval, T* context, void(T::* func)()) {
		if (timerList == NULL)
			timerList = make_unique<cLista<AsyncRepeater<T>>>();
		AsyncRepeater<T>* timer = new AsyncRepeater<T>(interval, context, func);
		timer->start();
		timerList->AgregarItem(timer);
	}

	static void StopRepeater() {
		for (int i = 0; i < timerList->getCA(); ++i) {
			timerList->getItem(i)->stop();
		}
	}

};

template<typename T>
unique_ptr<cLista<AsyncRepeater<T>>> AsyncRepeaterFactory<T>::timerList = NULL;