#pragma once

#include "../templates/type.hpp"
#include "../templates/templates.hpp"

namespace ft {
  template <class Key, class T, class Compare, typename Node, bool B>
  class map_iterator
  {
  	public:
  		typedef Key                                             key_type;
  		typedef Compare                                         key_compare;
  		typedef T                                               mapped_type;
  		typedef ft::pair<const key_type, mapped_type>           value_type;
  		typedef long int                                        difference_type;
  		typedef size_t                                          size_type;
  		typedef std::bidirectional_iterator_tag                                     iterator_category;
  		typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
  		typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
  		typedef Node*                                                               nodePtr;

  	private:
  		nodePtr         _node;
  		nodePtr         _lastElem;
  		key_compare     _comp;

  	public:
  		map_iterator(nodePtr node = 0, nodePtr lastElem = 0,
  								const key_compare& comp = key_compare()) :
  				_node(node), _lastElem(lastElem), _comp(comp) {}

  		map_iterator(const map_iterator<Key, T, Compare, Node, false>& copy) {
  			this->_node = copy.getNode();
  			this->_lastElem = copy.getLastElem();
  			this->_comp = copy.getCompare();
  		}

  		~map_iterator() {}
  		map_iterator& operator=(const map_iterator& assign) {
  			if (this != &assign) {
  					this->_node = assign._node;
  					this->_lastElem = assign._lastElem;
  					this->_comp = assign._comp;
  			}
  			return (*this);
  		}

  		nodePtr getNode() const             { return this->_node; }
  		nodePtr getLastElem() const         { return this->_lastElem; }
  		key_compare getCompare() const      { return this->_comp; }
  		reference operator*() const         { return (this->_node->content); }
  		pointer operator->() const          { return (&this->_node->content); }

  		map_iterator& operator++() {
  			nodePtr previousNode = this->_node;
  			if (this->_node == this->_lastElem) {
  				this->_node = this->_lastElem->smaller;
  				return (*this);
  			}
  			while (this->_node != this->_lastElem && !this->_comp(previousNode->content.first, this->_node->content.first)) {
  				if (this->_node->smaller && (this->_node->smaller == this->_lastElem ||
  								this->_comp(previousNode->content.first, this->_node->smaller->content.first))) {
  					this->_node = this->_node->smaller;
  					Node* tmp = 0;
  					if (this->_node != this->_lastElem && (tmp = this->searchMinNode(this->_node)))
  						this->_node = tmp;
  				}
  				else
  					this->_node = this->_node->parent;
  			}
  			return (*this);
  		}

  		map_iterator operator++(int) {
  			map_iterator res(*this);
  			if (this->_node == this->_lastElem) {
  				this->_node = this->_lastElem->smaller;
  				return (res);
  			}
  			while (this->_node != this->_lastElem && !this->_comp(res->first, this->_node->content.first)) {
  				// std::cout << "content =  " << this->_node->content.first << " " << this->_node->content.second << std::endl;
  				if (this->_node->smaller && (this->_node->smaller == this->_lastElem ||
  						this->_comp(res->first, this->_node->smaller->content.first))) {
  					this->_node = this->_node->smaller;
  					Node* tmp = this->searchMinNode(this->_node);
  					if (this->_node != this->_lastElem && tmp)
  						this->_node = tmp;
  				}
  				else
  					this->_node = this->_node->parent;
  			}
  			return (res);
  		}

  		map_iterator& operator--() {
  			nodePtr previousNode = this->_node;
  			if (this->_node == this->_lastElem) {
  					this->_node = this->_lastElem->bigger;
  					return (*this);
  			}
  			while (this->_node != _lastElem && !this->_comp(this->_node->content.first, previousNode->content.first)) {
  				if (_node->bigger && (_node->bigger == this->_lastElem ||
  						this->_comp(_node->bigger->content.first, previousNode->content.first))) {
  					this->_node = _node->bigger;
  					Node* tmp = 0;
  					if (this->_node != this->_lastElem && (tmp = this->searchMaxNode(this->_node)))
  						this->_node = tmp;
  				}
  				else
  					this->_node = this->_node->parent;
  			}
  			return (*this);
  		}

  		map_iterator operator--(int) {
  			map_iterator res(*this);
  			if (this->_node == this->_lastElem) {
  					this->_node = this->_lastElem->bigger;
  					return (res);
  			}
  			while (this->_node != this->_lastElem && !this->_comp(this->_node->content.first, res->first)) {
  				if (this->_node->bigger && (this->_node->bigger == this->_lastElem ||
  						this->_comp(this->_node->bigger->content.first, res->first))) {
  					this->_node = this->_node->bigger;
  					Node* tmp = 0;
  					if (this->_node != this->_lastElem && (tmp = this->searchMaxNode(this->_node)))
  							this->_node = tmp;
  				}
  				else
  					this->_node = this->_node->parent;
  			}
  			return (res);
  		}

  		bool operator==(const map_iterator& it) const   { return (it._node == this->_node); }
  		bool operator!=(const map_iterator& it) const   { return (it._node != this->_node); }

  	private:
  		Node* searchMaxNode(Node *root) {
  			while (root && root != this->_lastElem && root->smaller && root->smaller != this->_lastElem)
  				root = root->smaller;
  			return root;
  		}
  		Node* searchMinNode(Node *root) {
  			while (root && root != this->_lastElem && root->bigger && root->bigger != this->_lastElem)
  				root = root->bigger;
  			return root;
  		}
  };
}