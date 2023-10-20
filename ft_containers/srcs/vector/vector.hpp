#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>

#include "./random_iterators.hpp"
#include "./reverse_iterators.hpp"
#include "../templates/templates.hpp"

#include <cstdio>

namespace ft {
  template <typename T, class Alloc = std::allocator<T> >
  class vector {
    public:   
      typedef T                                           value_type;
      typedef Alloc                                       allocator_type;
      typedef long int                                    difference_type;
      typedef size_t                                      size_type;
      typedef T&                                          reference;
      typedef const T&                                    const_reference;
      typedef T*                                          pointer;
      typedef const T*                                    const_pointer;
      typedef random_access_iterator<T>	                  const_iterator;
  		typedef random_access_iterator<T>							      iterator;
  		typedef reverse_iterator<const_iterator>						const_reverse_iterator;
  		typedef reverse_iterator<iterator>									reverse_iterator;

      private:    
      	Alloc               _allocator;
        pointer             _array;
        size_type           _size;
        size_type           _capacity;
      public:

        explicit vector(const allocator_type& alloc = allocator_type()) {
  				this->_allocator = alloc;
  				this->_size = 0;
  				this->_capacity = 0;
          this->_array = _allocator.allocate(this->_capacity);
        };

        explicit vector(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type()) {
  				this->_allocator = alloc;
  				this->_size = n;
  				this->_capacity = n;
          this->_array = _allocator.allocate(this->_capacity);
          for (size_type i = 0; i < this->_size; ++i)
            _allocator.construct(&this->_array[i], val);
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
  				this->_allocator = alloc;
  				this->_size = last - first;
          this->_capacity = this->_size;
          this->_array = _allocator.allocate(this->_capacity);
          for (int i = 0; first != last; ++first, ++i)
              _allocator.construct(&this->_array[i], *first);
        }

        vector(const vector& cpy) {
  				this->_allocator = cpy._allocator;
  				this->_size = cpy._size;
          this->_capacity = cpy._capacity;
          this->_array = this->_allocator.allocate(this->_capacity);
          for (size_type i = 0; i < this->_size; i++)
          	this->_allocator.construct(&this->_array[i], cpy[i]);
        }

        ~vector() {
          for (iterator it = begin(); it != end(); ++it)
              this->_allocator.destroy(&(*it));
          this->_allocator.deallocate(this->_array, this->_capacity);
        }

        vector& operator= (const vector& x) {
          vector tmp(x);
          swap(tmp);
          return *this;
        }

        iterator	begin() { return (iterator(this->_array)); }
        const_iterator	begin() const	{ return (const_iterator(this->_array)); }
        iterator	end()	{ return (iterator(this->_array + this->_size)); }
        const_iterator	end() const	{ return (const_iterator(this->_array + this->_size)); }
        reverse_iterator rbegin()	{ return (reverse_iterator(this->_array + this->_size - 1)); }
        const_reverse_iterator rbegin() const	{ return (const_reverse_iterator(this->_array + this->_size - 1)); }
        reverse_iterator rend()	{ return (reverse_iterator(this->_array - 1)); }
        const_reverse_iterator rend() const	{ return (const_reverse_iterator(this->_array - 1)); }
        size_type	size() const	{ return (this->_size); }
        size_type	max_size() const	{ return (this->_allocator.max_size()); }

        void resize (size_type n, value_type val = value_type()) {
          if (n > this->_capacity) {
  					pointer tmp = this->_allocator.allocate(n);
          	for (size_type i = 0; i < this->_size; ++i)
              this->_allocator.construct(&tmp[i], _array[i]);
          	this->~vector();
          	this->_capacity = n;
          	this->_array = tmp;
  				}
          while (n > this->_size)
              push_back(val);
          while (n < this->_size)
              pop_back();
        }

        size_type	capacity() const	{ return this->_capacity; }
        bool	empty() const	{ return (this->_size == 0 ? true : false); }

        void	reserve (size_type n) {
          if (n > this->max_size())
            throw std::length_error("index out of range");
          if (n > this->_capacity) {
  					pointer tmp = this->_allocator.allocate(n);
          	for (size_type i = 0; i < this->_size; ++i)
          	    this->_allocator.construct(&tmp[i], this->_array[i]);
          	this->~vector();
          	this->_capacity = n;
          	this->_array = tmp;
  				}
        }

        reference operator[] (size_type n)	{ return this->_array[n]; }
        const_reference operator[] (size_type n) const  { return this->_array[n]; }

        reference at(size_type n) {
          if (!(n < this->_size))
              throw std::out_of_range("index out of range");
          return this->_array[n];
        }

        const_reference at(size_type n) const {
          if (!(n < this->_size))
              throw std::out_of_range("index out of range");
          return this->_array[n];
        }

        reference front()	{ return this->_array[0]; }
        const_reference front() const { return this->_array[0]; }
        reference back()	{ return this->_array[_size - 1]; }
        const_reference back() const	{ return this->_array[_size - 1]; }

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
          clear();
          size_type n = static_cast<size_type>(last - first);
          if (n > this->_capacity) {
              this->_allocator.deallocate(this->_array, this->_capacity);
              this->_array = _allocator.allocate(n);
          }
          size_type i = 0;
          for (; first != last; ++i, ++first)
              this->_allocator.construct(&_array[i], *first);
          this->_size = i;
  			}

        void assign (size_type n, const value_type& val) {
          clear();
          if (n > this->_capacity)
          {
              this->_allocator.deallocate(this->_array, this->_capacity);
              this->_array = this->_allocator.allocate(n);
          }

          for (size_type i = 0; i < n; ++i)
              _allocator.construct(&this->_array[i], val);
          this->_size = n;
        }


        void push_back (const value_type& val) {
          if (this->_size + 1 > this->_capacity) {
  					pointer tmp = this->_allocator.allocate(this->_size + 1);
          	for (size_type i = 0; i < this->_size; ++i)
          	    this->_allocator.construct(&tmp[i], this->_array[i]);
          	this->~vector();
          	this->_capacity = this->_size + 1;
          	this->_array = tmp;
  				}
          this->_allocator.construct(&this->_array[this->_size++], val);
        }

        void pop_back() {
          if (this->_size)
            this->_allocator.destroy(&_array[this->_size-- - 1]);
        }

        iterator insert (iterator position, const value_type& val) {
          difference_type index = position - begin();
          insert(position, 1, val);
          return iterator(&_array[index]);
        }
        void insert (iterator position, size_type n, const value_type& val) {
  				const size_t pos = position - begin();
  				const size_t size = n + this->_size;
  				T* tmp;
  				if (n + this->_size > this->_capacity) {
  					tmp = this->_allocator.allocate(sizeof(value_type) * size);
  					this->_capacity = n + this->_size;
  				}
  				else
  					tmp = this->_allocator.allocate(sizeof(value_type) * this->_capacity);
  				for (size_t i = 0, j = 0; i < size; i++) {
  					if (i >= pos && i < pos + n)
  						this->_allocator.construct(&tmp[i], val);
  					else
  						this->_allocator.construct(&tmp[i],this->_array[j++]);
  				}
  				this->~vector();
  				this->_size = n + this->_size;
  				this->_array = tmp;
        }
  
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, 
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
  				vector tmp(position, end());
  				this->_size -= this->end() - position;
  				while (first != last) {
  					push_back(first);
  					++first;
  				}
  				iterator it = tmp.begin();
  				while (it != tmp.end()) {
  					push_back(*it);
  					++it;
  				}
        }
        iterator erase (iterator position) { return erase(position, position + 1); }

        iterator erase (iterator first, iterator last) {
  				if (first == end() || first == last)
        	  return first;
  				size_t index = first - begin();
  				T* tmp = this->_allocator.allocate(sizeof(value_type) * this->_capacity);
  				const size_t range = last - first;
  				for (size_t i = 0, j = 0; i < this->_size - range + 1; i++) {
  					if (i < index || i >= index + range) {
  						this->_allocator.construct(&tmp[j++], this->_array[i]);
  					}
  				}
  				this->~vector();
  				this->_array = tmp;
  				this->_size = this->_size - range;
  				return (&(this->_array[index]));
        }

        void swap (vector& other) {
          this->swap(this->_allocator, other._allocator);
          this->swap(this->_array, other._array);
          this->swap(this->_size, other._size);
          this->swap(this->_capacity, other._capacity);
        }

        void clear() {
          while (_size)
            pop_back();
        }

    private:
      template <typename U>
      void swap(U& a, U&b)
      {
          U tmp = a;
          a = b;
          b = tmp;
      }
  };

  template<typename T>
  std::ostream& operator<<(std::ostream& os, const vector<T>& vec) {
  	os << "vector: ";
  	for (int i = 0; i < vec.size(); i++) {
  		os << vec[i] << std::endl;
  	}
  	os << vec.size() << std::endl;
  	return (os);
  }

  template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
  	const vector<T> tmp = x;
  	x = y;
  	y = tmp;
  }

  template <class T, class Alloc>
  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  	if (lhs.size() != rhs.size())
  		return (false);
  	else {
  		for (size_t i = 0; i < lhs.size(); i++)
  			if (lhs[i] != rhs[i])
  				return (false);
  	}
  	return (true);
  }

  template <class T, class Alloc>
  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  	if (lhs.size() != rhs.size())
  		return (true);
  	else {
  		for (size_t i = 0; i < lhs.size(); i++)
  			if (lhs[i] != rhs[i])
  				return (true);
  	}
  	return (false);
  }

  template <class T, class Alloc>
  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  	const size_t sizel = lhs.size();
  	const size_t sizer = rhs.size();
  	for (size_t i = 0; i < sizel && i < sizer; i++)
  		if (lhs[i] < rhs[i])
  			return (true);
  	return (sizel < sizer);
  }

  template <class T, class Alloc>
  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  	const size_t sizel = lhs.size();
  	const size_t sizer = rhs.size();
  	for (size_t i = 0; i < sizel && i < sizer; i++)
  		if (lhs[i] <= rhs[i])
  			return (true);
  	return (sizel <= sizer);
  }

  template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  	const size_t sizel = lhs.size();
  	const size_t sizer = rhs.size();
  	for (size_t i = 0; i < sizel && i < sizer; i++)
  		if (lhs[i] > rhs[i])
  			return (true);
  	return (sizel > sizer);
  }

  template <class T, class Alloc>
  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  	const size_t sizel = lhs.size();
  	const size_t sizer = rhs.size();
  	for (size_t i = 0; i < sizel && i < sizer; i++)
  		if (lhs[i] >= rhs[i])
  			return (true);
  	return (sizel >= sizer);
  }
}
