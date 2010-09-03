#ifndef _PROPERTYVIOLATIONEXCEPTION_H_
#define _PROPERTYVIOLATIONEXCEPTION_H_

#include <string>

using namespace std;


class PropertyViolationException : public exception {

private:
   string m_err;
public:
	 
	 PropertyViolationException(string &err) : m_err(err) {}
	 ~PropertyViolationException() throw() {}
    const char* what() { return m_err.c_str(); }

};


class IllegalArgumentException : public exception {

private:
   string m_err;
public:
	 
   IllegalArgumentException(string err) : m_err(err) {}
   ~IllegalArgumentException() throw() {}
    const char* what() { return m_err.c_str(); }
};

#endif
