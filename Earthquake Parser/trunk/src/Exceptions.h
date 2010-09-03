#ifndef _PROPERTYVIOLATIONEXCEPTION_H_
#define _PROPERTYVIOLATIONEXCEPTION_H_

#include <string>

using namespace std;


class PropertyViolationException : public exception {

private:
   string m_err;
public:
	 
	 PropertyViolationException(string &err) : m_err(err) {}

    	const char* what() { return m_err.c_str(); }

	~PropertyViolationException() throw() {}
};


class IllegalArgumentException : public exception {

private:
   string m_err;
public:
	 
	 IllegalArgumentException(string &err) : m_err(err) {}

    	const char* what() { return m_err.c_str(); }

	~IllegalArgumentException() throw() {}
};

#endif
