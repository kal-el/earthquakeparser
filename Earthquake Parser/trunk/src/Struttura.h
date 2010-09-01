#ifndef _Struttura_H_
#define _Struttura_H_

#include "Constants.h"
#include "Exceptions.h"
#include <list>

using namespace std;

namespace example {

typedef struct {
	short int type;
	int x1;
	int x2;
	int y1;
	int y2;
} token_;


/**
* Class definitions
*	Get and Set methods shouldn't be used, they are provided for debugging purpose
**/



/**
* Class representing the "Apertura" non terminal:
*	APERTURE 	-> APERTURA
*	APERTURA 	-> apertura <isAbove, Height(0.1,0.2),isCentered,isLarger(0.15,0.3)> architrave
**/
class Apertura {

private:

	token_ *apertura;
	token_ *architrave;

	/**
	* this method checks if the condition of the objects "apertura" and "architrave"
	* are respected
	* Property to check: 
	*		apertura <isAbove, Height(0.1,0.2),isCentered,isLarger(0.15,0.3)> architrave
	* @throws PropertyViolationException if the properties aren't satisfied
	**/
	void checkProperties() throw(PropertyViolationException);

public:


	Apertura(token_ *ap, token_ *ar) throw(PropertyViolationException, IllegalArgumentException) {
		
		if( (!ap || !ar) || ap->type != APERTURA_ || ar->type != ARCHITRAVE_)
			throw new IllegalArgumentException(string("bad arguments"));

		apertura = ap;
		architrave = ar;

		checkProperties();
	}


	~Apertura() {
		delete apertura;
		delete architrave;
	}


	void setApertura(token_ *ap);

	void setArchitrave(token_ *ar);

	token_ *getApertura();

	token_ *getArchitrave();
};


/**
* Class representing the "Interpiani" grammar non terminal
*	INTERPIANI 	-> linea_piano <isUnder, Height(0.2,0.4)> CORDOLO
*	INTERPIANI 	-> linea_piano
**/
class Interpiano {

private:

	token_ *linea_piano;
	token_ *cordolo;

	/**
	* this method checks if the condition of the objects "linea_piano" and "cordolo"
	* are respected
	* Property to check: 
	*		linea_piano <isUnder, Height(0.2,0.4)> CORDOLO
	*		linea_piano (if cordolo is Null)
	* @throws PropertyViolationException if the properties aren't satisfied
	**/
	void checkProperties() throw(PropertyViolationException);

public:

	//no null-pointer is allowed: in the grammar an "interpiano" must always have those tokens
	Interpiano(token_ *lp, token_ *c) throw(IllegalArgumentException, PropertyViolationException) {
		if((!c || !lp) || (c->type != CORDOLO_ || lp->type != LINEA_PIANO_))
			throw(new IllegalArgumentException(string("wrong token type")));

		linea_piano = lp;
		cordolo = c;

		checkProperties();
	}

	//to create the object with only linea_piano
	Interpiano(token_ *lp) {
		Interpiano(lp, 0);
	}


	~Interpiano() {
		delete linea_piano;
		delete cordolo;
	}


	token_ *getLineaPiano();

	token_ *getCorridoio();

	void setLineaPiano(token_ *lp) throw(IllegalArgumentException);

	void setCordolo(token_ *c) throw(IllegalArgumentException);

};


/**
* Class representing the "piani" non terminal in the grammar
*	PIANI 		-> PIANI’  <contains> INTERPIANI
*	PIANI 		-> parete
**/
class Piani {

private:
	
	list<Interpiano> interpiani;
	token_ *parete;

	/**
	* this method checks if the condition of the objects "interpiani" and "parete"
	* are respected
	* Property to check: 
	*		PIANI’  <contains> INTERPIANI
	*		parete (if interpiani is empty)
	* @throws PropertyViolationException if the properties aren't satisfied
	**/
	void checkProperties() throw(PropertyViolationException);

public:

	Piani(list<Interpiano> i, token_ *p=0) throw(IllegalArgumentException, PropertyViolationException) : interpiani(i) {
		if(p && p->type != PARETE_)
			throw new IllegalArgumentException(string("wrong token type"));
		
		checkProperties();

		parete = p;
	}

	//to create the object without the interpiano list
	Piani(token_ *p) {
		list<Interpiano> l;
		Piani(l, p);
	}

	~Piani() {
		interpiani.~list();
		delete parete;
	}

	token_ *getParete();

	list<Interpiano> getInterpiani();

	void setParete(token_ *p) throw(IllegalArgumentException) ;

	void setInterpiani(list<Interpiano> i);
};





/**
* Class that represents the start simbol of the grammar
*	STRUTTURA 	-> PIANI <contains, not_intersect> APERTURE
**/
class Struttura {

private:
	Piani p;
	list<Apertura> a;

	/**
	* this method checks if the condition of the objects "piani" and "aperture"
	* are respected
	* Property to check: 
	*		PIANI <contains, not_intersect> APERTURE
	* @throws PropertyViolationException if the properties aren't satisfied
	**/
	void checkProperties() throw(PropertyViolationException);

public:

	Struttura(Piani listaPiani, list<Apertura> listaAperture) : p(listaPiani), a(listaAperture) {
	}

	~Struttura() {
		p.~Piani();
		a.~list();
	}


	Piani getPiani();

	list<Apertura> getAperture();

	void setPiani(Piani &piani);

	void setAperture(list<Apertura> a);

	/**
	* returns the list of Maschi calculated using "a" and "p"
	**/
	list<token_*> calcolaMaschi(); 

	/**
	* throws an exception if one or more Maschi doesn't respect their properties
	**/
	void verificaProprietaMaschio(list<token_*> l) throw(PropertyViolationException);

};

}

#endif