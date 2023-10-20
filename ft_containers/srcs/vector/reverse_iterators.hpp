#pragma once

#include <iostream>
namespace ft {
  template <class Iterator>
  class reverse_iterator {
  	private:
  		typedef typename Iterator::pointer						pointer;
  		typedef typename Iterator::reference					reference;
  		typedef typename Iterator::difference_type		difference_type;
  		typedef	typename Iterator::iterator_category	iterator_category;
  		typedef Iterator															iterator_type;

  	protected:
  		Iterator	it;

  	public:
  		reverse_iterator() { this->it = NULL; }
  		explicit reverse_iterator (iterator_type itCpy) { it = itCpy; }
  		template <class Iter>
    	reverse_iterator (const reverse_iterator<Iter>& cpy) { this->it = cpy.it; }



  		iterator_type base() const { return (this->it); }
  		reference operator*() const { return (*it); }
  		pointer operator->() const { return (&(operator*())); }
  		reverse_iterator operator+ (difference_type n) const { return (this->current - n);}
  		reverse_iterator& operator++() { return (*this->current - 1); }
  		reverse_iterator  operator++(int) { reverse_iterator tmp(*this); this->_ptr = this->_ptr - 1; return (tmp); }
  		reverse_iterator& operator+= (difference_type n) { return (*this->current - n); }
  		reverse_iterator operator- (difference_type n) const { return (this->current + n);}
  		reverse_iterator& operator--() { return (*this->current + 1); }
  		reverse_iterator  operator--(int) { reverse_iterator tmp(*this); this->_ptr = this->_ptr + 1; return (tmp); }
  		reverse_iterator& operator-= (difference_type n) { return (*this->current + n); }
  		reference operator[] (difference_type n) const {
  			return (*(this->it - n - 1));
  		}
  };
}

template <class Iterator>
  bool operator== (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs) {
	return (*lhs == *rhs ? true : false);
}
template <class Iterator>
  bool operator!= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs) {
	return (*lhs != *rhs ? true : false);
}
template <class Iterator>
  bool operator<  (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs) {
	return (*lhs > *rhs ? true : false);
}
template <class Iterator>
  bool operator<= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs) {
	return (*lhs >= *rhs ? true : false);
}
template <class Iterator>
  bool operator>  (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs) {
	return (*lhs <= *rhs ? true : false);
}
template <class Iterator>
  bool operator>= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs) {
	return (*lhs <= *rhs ? true : false);
}

template <class Iterator>
  ft::reverse_iterator<Iterator> operator+ (
             typename ft::reverse_iterator<Iterator>::difference_type n,
             const ft::reverse_iterator<Iterator>& rev_it) {
	return (rev_it.base() + n);
}

template <class Iterator>
  typename ft::reverse_iterator<Iterator>::difference_type operator- (
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
			return (lhs.base() - rhs.base());
}