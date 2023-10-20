#pragma once

#include <iostream>

namespace ft {
  template < class T >
  class random_access_iterator {
  	private:
  		T* _ptr;
  	public:

  		typedef	ft::random_access_iterator<T> 				templateType;
  		typedef T*																pointer;
  		typedef T																	value_type;
  		typedef T&																reference;
  		typedef size_t														size_type;
  		typedef std::ptrdiff_t										difference_type;
  		typedef	std::random_access_iterator_tag		iterator_category;
  		typedef std::ptrdiff_t										distance;

  		random_access_iterator() { this->_ptr = NULL; }
  		random_access_iterator(const pointer elem) : _ptr(elem) {}
  		random_access_iterator(const random_access_iterator &cpy) { *this = cpy; }
  		random_access_iterator& operator=(const random_access_iterator &cpy) { this->_ptr = cpy._ptr; return (*this); }
  		~random_access_iterator() {}

  		T& operator*() const { return (*(this->_ptr)); }
  		T* operator->() const { return (&(this->operator*())); }

  		random_access_iterator operator++(int) { templateType tmp(*this); this->_ptr = this->_ptr + 1; return (tmp);}

  		random_access_iterator& operator++() { ++this->_ptr; return (*this); }

  		random_access_iterator operator--(int) { templateType tmp(*this); this->_ptr = this->_ptr - 1; return (tmp); }

  		random_access_iterator& operator--() { --this->_ptr; return (*this); }

  		random_access_iterator operator+(int n) { this->_ptr = this->_ptr + n; return (*this); }

  		size_t operator-(random_access_iterator const &other) { return (this->_ptr - other._ptr); }

  		random_access_iterator operator-(int n) { this->_ptr = this->_ptr - n; return (*this); }

  		random_access_iterator& operator+=(int n) { this->_ptr += n; return (*this); }

  		random_access_iterator& operator-=(int n) { return (this->_ptr - n); }

  		T&	operator[](int n) const {
  			return (*(this->_ptr + n));
  		}



  		bool operator==(const random_access_iterator& it) const    { return (it._ptr == _ptr); }
    	bool operator!=(const random_access_iterator& it) const    { return (it._ptr != _ptr); }
    	bool operator<(const random_access_iterator& it) const     { return (it._ptr > this->_ptr); }
    	bool operator>(const random_access_iterator& it) const     { return (it._ptr < this->_ptr); }
    	bool operator<=(const random_access_iterator& it) const    { return (it._ptr >= this->_ptr); }
    	bool operator>=(const random_access_iterator& it) const    { return (it._ptr <= this->_ptr); }


  };
}

template < class T >
bool operator==(const ft::random_access_iterator<T> &lhs, \
								const ft::random_access_iterator<T> &rhs) {
		return (*lhs == *rhs ? true : false);
}

template < class T >
bool operator!=(const ft::random_access_iterator<T> &lhs, \
								const ft::random_access_iterator<T> &rhs) {
	return (*lhs != *rhs ? true : false);
}

template < class T >
bool operator<(const ft::random_access_iterator<T> &lhs, \
								const ft::random_access_iterator<T> &rhs) {
	return (*lhs < *rhs ? true : false);
}

template < class T >
bool operator>(const ft::random_access_iterator<T> &lhs, \
								const ft::random_access_iterator<T> &rhs) {
	return (*lhs > *rhs ? true : false);
}

template < class T >
bool operator<=(const ft::random_access_iterator<T> &lhs, \
								const ft::random_access_iterator<T> &rhs) {
	return (*lhs <= *rhs ? false : true);
}

template < class T >
bool operator>=(const ft::random_access_iterator<T> &lhs, \
								const ft::random_access_iterator<T> &rhs) 	{
	return (*lhs >= *rhs ? true : false);
}

