#pragma once 

#include <functional>
#include <cmath>

#include "../templates/templates.hpp"

#include "./map_iterators.hpp"
#include "./reverse_map_iterator.hpp"
namespace ft {
  template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > > 
  class map {
    private:        
      struct Node
      {
          ft::pair<const Key, T>  		content;
          Node*                   		parent;
          Node*                   		bigger;
          Node*                   		smaller;
      };

    public:
      typedef Key                                             						key_type;
      typedef Compare                                         						key_compare;
      typedef Alloc                                           						allocator_type;
      typedef T                                               						mapped_type;
      typedef ft::pair<const key_type, mapped_type>           						value_type;
      typedef long int                                        						difference_type;
      typedef size_t                                          						size_type;
      typedef typename allocator_type::reference                          reference;
      typedef typename allocator_type::const_reference            				const_reference;
      typedef typename allocator_type::pointer                            pointer;
      typedef typename allocator_type::const_pointer         							const_pointer;
      typedef map_iterator<Key, T, Compare, Node, false>     							iterator;
      typedef map_iterator<Key, T, Compare, Node, true>      							const_iterator;
      typedef reverse_map_iterator<Key, T, Compare, Node, false>					reverse_iterator;
      typedef reverse_map_iterator<Key, T, Compare, Node, true> 					const_reverse_iterator;

      class value_compare {
        friend class map;
      	protected:
      	  key_compare comp;
      	  value_compare(Compare c) : comp(c) {}
      	public:
      	  typedef bool        result_type;
          typedef value_type  first_argument_type;
    	    typedef value_type  second_argument_type;
    	    bool operator()(const value_type& first, const value_type& second) const { return comp(first.first, second.first); }
     };

    private:
      Node*                   _root;
      Node*                   _lastElem;
      size_type               _size;
      allocator_type          _allocPair;
      key_compare             _comp;
      std::allocator<Node>    _allocNode;

    public:
      explicit map(const key_compare& comp = key_compare(),
                  const allocator_type& alloc = allocator_type()) {
  			this->_size = 0;
  			this->_allocPair = alloc;
  			this->_comp = comp;
        this->_lastElem = createNode(ft::pair<const key_type, mapped_type>());
        this->_root = _lastElem;
        this->_lastElem->bigger = this->_lastElem;
        this->_lastElem->smaller = this->_lastElem;
      }

      template <class InputIterator>
      map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type(), 
                typename ft::enable_if<ft::is_integral<InputIterator>::value >::type* = 0) {
  			this->_size = 0;
  			this->_allocPair = alloc;
  			this->_comp = comp;
      	this->_lastElem = createNode(ft::pair<const key_type, mapped_type>());
        this->_root = _lastElem;
        this->_lastElem->bigger = this->_lastElem;
        this->_lastElem->smaller = this->_lastElem;
  			while (first != last) {
  				first++;
  				insert(*first);
  			}
      }

      map(const map& cpy) {
  			this->_size = 0;
  			this->_allocPair = cpy._allocPair;
  			this->_comp = cpy._comp;
  			this->_allocNode = cpy._allocNode;
        this->_lastElem = createNode(ft::pair<const key_type, mapped_type>());
        this->_root = this->_lastElem;
        this->_lastElem->bigger = this->_lastElem;
        this->_lastElem->smaller = this->_lastElem;
        for (const_iterator it = cpy.begin(); it != cpy.end(); ++it)
          insert(*it);
      }

      ~map() {
        clear();
        deallocateNode(this->_lastElem);
      }

      map& operator=(const map& other) {
  			if (&other == this)
  				return (*this);
  			this->clear();
  			this->insert(other.begin(), other.end());
  			return (*this);
      }

      iterator begin()                        { return (iterator(this->_lastElem->smaller, this->_lastElem, this->_comp)); }
      const_iterator begin() const            { return (const_iterator(this->_lastElem->smaller, this->_lastElem, this->_comp)); }
      iterator end()                          { return (iterator(this->_lastElem, this->_lastElem, this->_comp)); }
      const_iterator end() const              { return (const_iterator(this->_lastElem, this->_lastElem, this->_comp)); }
      reverse_iterator rbegin()               { return (reverse_iterator(this->_lastElem->bigger, this->_lastElem, this->_comp)); }
      const_reverse_iterator rbegin() const   { return (const_reverse_iterator(this->_lastElem->bigger, this->_lastElem, this->_comp)); }
      reverse_iterator rend()                 { return (reverse_iterator(this->_lastElem, this->_lastElem, this->_comp)); }
      const_reverse_iterator rend() const     { return (const_reverse_iterator(this->_lastElem, this->_lastElem, this->_comp)); }
      bool empty() const              				{ return (this->_size == 0); }
      size_type size() const          				{ return (this->_size); }
  		size_type	max_size() const 							{ return (this->_allocNode.max_size()); }

      mapped_type& operator[](const key_type& k) {
        Node* tmp = searchNode(this->_root, k);
        if (tmp)
            return (tmp->content.second);
        value_type val = make_pair<key_type, mapped_type>(k, mapped_type());
        return (insertNode(this->_root, val)->content.second);
      }

      ft::pair<iterator,bool> insert (const value_type& val) {
        Node* elemIsPresent = searchNode(this->_root, val.first);
        if (elemIsPresent)
            return (ft::pair<iterator, bool>(iterator(elemIsPresent, this->_lastElem, this->_comp), false));
        return (ft::pair<iterator, bool>(iterator(insertNode(this->_root, val), this->_lastElem, this->_comp), true));
      }

      iterator insert (iterator position, const value_type& val) {
        if (position->first > val.first) {
          iterator prev(position);
          --prev;
          while (prev != end() && prev->first >= val.first) {
            --position;
            --prev;
          }
        }
        else if (position->first < val.first) {
          iterator next(position);
          ++next;
          while (next != end() && next->first <= val.first) {
            ++position;
            ++next;
          }
        }
        if (position != end() && val.first == position->first)
          return (position);
        return (iterator(insertNode(position.getNode(), val), this->_lastElem, this->_comp));
      }

      template <class InputIterator>
      void insert (InputIterator first, InputIterator last,
                  typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
        while (first != last)
          insert(*first++);
      }

      void erase (iterator position) {
        deleteNode(position.getNode(), position->first);
        --this->_size;
      }

      size_type erase (const key_type& k) {
        size_type ret = deleteNode(this->_root, k);
        this->_size -= ret;
        return (ret);
      }

      void erase (iterator first, iterator last) {
        while (first != last) {
          iterator tmp(first);
          ++first;
          erase(tmp);
        }
      }

      void swap (map& other) {
        swap(this->_root, other._root);
        swap(this->_lastElem, other._lastElem);
        swap(this->_size, other._size);
        swap(this->_comp, other._comp);
        swap(this->_allocPair, other._allocPair);
        swap(this->_allocNode, other._allocNode);
      }

      void clear()        								{ erase(begin(), end()); }
      key_compare key_comp() const        { return (this->_comp); }
      value_compare value_comp() const    { return (value_compare(this->_comp)); }

      iterator find(const key_type& k) {
        Node* tmp = searchNode(this->_root, k);
        if (tmp)
          return (iterator(tmp, this->_lastElem, this->_comp));
        return (end());
      }

      const_iterator find(const key_type& k) const {
        Node* tmp = searchNode(this->_root, k);
        if (tmp)
          return (const_iterator(tmp, this->_lastElem, this->_comp));
        return (end());
      }

      size_type count (const key_type& k) const {
        Node* tmp = searchNode(this->_root, k);
        return (tmp ? true: false);
      }

      iterator lower_bound(const key_type& key) {
        iterator it = begin();
  			while (this->_comp(it->first, key) != 0 && it != this->end())
  				it++;
        return (it);  
      }

      const_iterator lower_bound(const key_type& key) const {
        const_iterator it = begin();
  			while (this->_comp(it->first, key) != 0 && it != this->end())
  				it++;
        return (it);  
      }

      iterator upper_bound(const key_type& key) {
        iterator it = begin();
  			while (this->_comp(key, it->first) != 1)
  				it++;
        return (it);  
      }

      const_iterator upper_bound(const key_type& key) const {
        const_iterator it = begin();
  			while (this->_comp(key, it->first) != 1)
  				it++;
        return (it);  

      }
      ft::pair<iterator,iterator> equal_range(const key_type& k) {
        iterator it = upper_bound(k);
        if (it != begin()) {
          --it;
          if (this->_comp(it->first, k) || this->_comp(k, it->first))
            ++it;
        }
        iterator next(it);
        if (it != end())
          ++next;
        return (make_pair<iterator, iterator>(it, next));
      }

      ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
        const_iterator it = upper_bound(k);
        if (it != begin()) {
          --it;
          if (this->_comp(it->first, k) || this->_comp(k, it->first))
            ++it;
  			}
        const_iterator next(it);
        if (it != end())
          ++next;
        return (make_pair<const_iterator, const_iterator>(it, next));
      }

    private:
      template <typename U>
      void swap(U& a, U& b) {
        U tmp = a;
        a = b;
        b = tmp;
      }
  
      template <class T1,class T2>
      ft::pair<T1,T2> make_pair(T1 x, T2 y) const { return ft::pair<T1,T2>(x,y); }
      Node* createNode(const value_type& pair) {
        Node* newNode = this->_allocNode.allocate(1);
        this->_allocPair.construct(&newNode->content, pair);
        newNode->parent = 0;
        newNode->bigger = 0;
        newNode->smaller = 0;
        return (newNode);
      }

      void deallocateNode(Node* del) {
        this->_allocPair.destroy(&del->content);
        this->_allocNode.deallocate(del, 1);
      }

      int treeSize(Node *root, int height) {
        if (!root || root == this->_lastElem)
          return (height - 1);
        int biggerHeight = treeSize(root->bigger, height + 1);
        int smallerHeight = treeSize(root->smaller, height + 1);
        return (biggerHeight > smallerHeight ? biggerHeight : smallerHeight);
      }
  
      Node* searchNode(Node* root, key_type key) const {
        if (!root || root == this->_lastElem)
          return (0);
        if (!this->_comp(root->content.first, key) && !this->_comp(key, root->content.first))
          return (root);
        if (root->content.first > key && root->bigger && root->bigger != this->_lastElem)
          return (searchNode(root->bigger, key));
        else if (root->content.first < key && root->smaller && root->smaller != this->_lastElem)
          return (searchNode(root->smaller, key));
        return (0);
      }
  
      Node* searchMaxNode(Node *root) const {
  			while (root && root != this->_lastElem && root->smaller && root->smaller != this->_lastElem)
  				root = root->smaller;
        return (root);
      }
  
      Node* searchMinNode(Node *root) const {
  			while (root && root != this->_lastElem && root->bigger && root->bigger != this->_lastElem)
  				root = root->bigger;
        return (root);
      }
  
      Node* insertNode(Node* insertPos, const value_type& pair) {
        if (this->_root == this->_lastElem) {
          this->_root = createNode(pair);
          this->_root->bigger = this->_lastElem;
          this->_root->smaller = this->_lastElem;
          this->_lastElem->bigger = this->_root;
          this->_lastElem->smaller = this->_root;
  				this->_size++;
          return (this->_root);
        }
        if (insertPos->content.first == pair.first)
          return (0);
        if (insertPos->content.first > pair.first && 
            insertPos->bigger && insertPos->bigger != this->_lastElem)
          return (insertNode(insertPos->bigger, pair));
        else if (insertPos->content.first < pair.first && 
                insertPos->smaller && insertPos->smaller != this->_lastElem)
          return (insertNode(insertPos->smaller, pair));
        Node *newNode = createNode(pair);
        if (insertPos->content.first > newNode->content.first && !insertPos->bigger)
          insertPos->bigger = newNode;
        else if (insertPos->content.first < newNode->content.first && !insertPos->smaller)
          insertPos->smaller = newNode;
        else if (insertPos->bigger && insertPos->content.first > newNode->content.first) {
          newNode->bigger = this->_lastElem;
          this->_lastElem->smaller = newNode;
          insertPos->bigger = newNode;
        }
        else if (insertPos->smaller && insertPos->content.first < newNode->content.first) {
      		newNode->smaller = this->_lastElem;
          this->_lastElem->bigger = newNode;
          insertPos->smaller = newNode;
        }
        newNode->parent = insertPos;
        balanceTheTree(&this->_root, newNode);
  			this->_size++;
        return (newNode);
      }

      bool deleteNode(Node* deletePos, key_type key) {
        Node* balanceNode = 0;
        Node* del = searchNode(deletePos, key);
        if (!del)
          return (false);
        if (!del->parent) {
          if (del->bigger == this->_lastElem && del->smaller == this->_lastElem) {
            this->_root = _lastElem;
            this->_lastElem->bigger = this->_lastElem;
            this->_lastElem->smaller = this->_lastElem;
          }
          else if (del->bigger && del->smaller == this->_lastElem) {
            balanceNode = del->parent;
            this->_root = del->bigger;
            del->bigger->parent = 0;
            this->_lastElem->bigger = del->bigger;
             del->bigger->smaller = this->_lastElem;
          }
          else if (del->bigger == this->_lastElem && del->smaller) {
            balanceNode = del->parent;
            this->_root = del->smaller;
            del->smaller->parent = 0;
            this->_lastElem->smaller = del->smaller;
            del->smaller->bigger = this->_lastElem;
          }
          else {
            Node* maxNode = searchMaxNode(del->bigger);
            this->_allocPair.destroy(&del->content);
            this->_allocPair.construct(&del->content, maxNode->content);

            return (deleteNode(del->bigger, maxNode->content.first));
  				}
        }
        else if ((!del->bigger || del->bigger == this->_lastElem) && (!del->smaller || del->smaller == this->_lastElem)) {
          balanceNode = del->parent;
          Node* linkToParent = 0;
          if (del->bigger == this->_lastElem || del->smaller == this->_lastElem) {
            linkToParent = this->_lastElem;
            del->content.first <= del->parent->content.first ?
            this->_lastElem->smaller = del->parent : this->_lastElem->bigger = del->parent;
        	}

          del->content.first <= del->parent->content.first ?
          del->parent->bigger = linkToParent : del->parent->smaller = linkToParent;
        }
        else if ((del->bigger && del->bigger != this->_lastElem) && (!del->smaller || del->smaller == this->_lastElem)) {
          balanceNode = del->parent;
          del->content.first <= del->parent->content.first ?
            del->parent->bigger = del->bigger : del->parent->smaller = del->bigger;
          del->bigger->parent = del->parent;
          if (del->smaller == this->_lastElem) {
            this->_lastElem->bigger = del->bigger;
            del->bigger->smaller = this->_lastElem;
          }
        }
        else if ((!del->bigger || del->bigger == this->_lastElem) && del->smaller && del->smaller != this->_lastElem)
        {
          balanceNode = del->parent;
          del->content.first <= del->parent->content.first ?
             del->parent->bigger = del->smaller : del->parent->smaller = del->smaller;
          del->smaller->parent = del->parent;
          if (del->bigger == this->_lastElem) {
            this->_lastElem->smaller = del->smaller;
            del->smaller->bigger = this->_lastElem;
          }
        }
        else {
        	Node* maxNode = searchMaxNode(del->bigger);
          this->_allocPair.destroy(&del->content);
          this->_allocPair.construct(&del->content, maxNode->content);
          return (deleteNode(del->bigger, maxNode->content.first));
        }
        balanceTheTree(&_root, balanceNode);
        deallocateNode(del);
        return (true);
      }

      int balanceOfSubtrees(Node* node) {
        if (!node)
          return (0);
        return (treeSize(node->bigger, 1) - treeSize(node->smaller, 1));
      }

      void rotateSmaller(Node** root, Node* nodeGoingDown) {
        Node* nodeGoingUp = nodeGoingDown->bigger;
        nodeGoingDown->bigger = nodeGoingUp->smaller;
        if (nodeGoingUp->smaller)
          nodeGoingUp->smaller->parent = nodeGoingDown;
        nodeGoingUp->smaller = nodeGoingDown;
        nodeGoingUp->parent = nodeGoingDown->parent;
        if (nodeGoingDown->parent && nodeGoingDown->parent->bigger == nodeGoingDown)
          nodeGoingDown->parent->bigger = nodeGoingUp;
        else if (nodeGoingDown->parent)
          nodeGoingDown->parent->smaller = nodeGoingUp;
        nodeGoingDown->parent = nodeGoingUp;
        if (!nodeGoingUp->parent)
          *root = nodeGoingUp;
      }

      void rotateBigger(Node** root, Node* nodeGoingDown) {
        Node* nodeGoingUp = nodeGoingDown->smaller;
        nodeGoingDown->smaller = nodeGoingUp->bigger;
        if (nodeGoingUp->bigger)
          nodeGoingUp->bigger->parent = nodeGoingDown;
        nodeGoingUp->bigger = nodeGoingDown;
        nodeGoingUp->parent = nodeGoingDown->parent;
        if (nodeGoingDown->parent && nodeGoingDown->parent->bigger == nodeGoingDown)
          nodeGoingDown->parent->bigger = nodeGoingUp;
        else if (nodeGoingDown->parent)
          nodeGoingDown->parent->smaller = nodeGoingUp;
        nodeGoingDown->parent = nodeGoingUp;
        if (!nodeGoingUp->parent)
          *root = nodeGoingUp;
      }

      void balanceTheTree(Node** root, Node* node) {        
        while (node) {
          int balance  = balanceOfSubtrees(node);
          if (balance < -1 && balanceOfSubtrees(node->smaller) < 0)
            rotateBigger(root, node);
          else if (balance < -1 && balanceOfSubtrees(node->smaller) >= 0) {
            rotateSmaller(root, node->smaller);
            rotateBigger(root, node);
          }
          else if (balance > 1 && balanceOfSubtrees(node->bigger) > 0)
            rotateSmaller(root, node);
          else if (balance > 1 && balanceOfSubtrees(node->bigger) <= 0) {
            rotateBigger(root, node->bigger);
            rotateSmaller(root, node);
          }
          node = node->parent;
        }
      }

  };
}