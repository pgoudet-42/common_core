#pragma once

#include "../vector/vector.hpp"

namespace ft {
  template <class T, class Container = ft::vector<T> >
  class stack {
    public:
      typedef T           value_type;
      typedef Container   container_type;
      typedef size_t      size_type;

    private:
    	container_type  _stack;

    public:
      explicit stack (const container_type& ctnr = container_type()) : _stack(ctnr) {}
      stack(const stack& cpy) : _stack(cpy._stack) {}
      ~stack() {}

      stack& operator=(const stack& x) {
        stack tmp(x);
        swap(this->_stack, tmp._stack);
        return (*this);
      }

      bool empty() const                  												{ return (this->_stack.empty()); }
      size_type size() const              												{ return (this->_stack.size()); }
      value_type& top()                   												{ return (this->_stack.back()); }
      const value_type& top() const       												{ return (this->_stack.back()); }
      void push (const value_type& val)   												{ (this->_stack.push_back(val)); }
      void pop()                          												{ (this->_stack.pop_back()); }
      friend bool operator==(const stack& lhs, const stack& rhs)  { return (lhs._stack == rhs._stack); }
      friend bool operator!=(const stack& lhs, const stack& rhs)  { return (lhs._stack != rhs._stack); }
      friend bool operator<(const stack& lhs, const stack& rhs)   { return (lhs._stack < rhs._stack); }
      friend bool operator<=(const stack& lhs, const stack& rhs)  { return (lhs._stack <= rhs._stack); }
      friend bool operator>(const stack& lhs, const stack& rhs)   { return (lhs._stack > rhs._stack); }
      friend bool operator>=(const stack& lhs, const stack& rhs)  { return (lhs._stack >= rhs._stack); }

    private:
      template <typename U>
      void swap(U& a, U& b) {
        U tmp(a);
        a = b;
        b = tmp;
      }
  };
}
        