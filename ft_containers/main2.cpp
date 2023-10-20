#include "srcs/vector/vector.hpp"
#include "srcs/stack/stack.hpp"
#include "srcs/map/map.hpp"

using namespace std;

template<typename T>
void	displayVect(ft::vector<T> vect, string name) {
	cout << name << " = ";
	for (size_t i = 0; i < vect.size(); i++) {
		cout << vect[i] << ' ';
	}
	cout << endl;
}

int	main(void) {
	ft::vector<int> test;
	cout << "test capacity = " << test.capacity() << endl;
	ft::vector<int> test1(5, 3);
	cout << "test1 capacity = " << test1.capacity() << endl;
	displayVect(test1, "test1");
	ft::vector<int> test2(test1);
	cout << "test2 capacity = " << test2.capacity() << endl;
	displayVect(test2, "test2");
	test = test1;
	displayVect(test, "test");
	cout << "test capacity after =op = " << test.capacity() << endl;
	ft::vector<int>::iterator it = test.begin();
	cout << "it value = " << *it << endl;
	ft::vector<int>::iterator ite = test.end();
	cout << "ite value = " << *ite << endl;
	ft::vector<int>::reverse_iterator rit = test.rbegin();
	cout << "rit value = " << *rit << endl;
	ft::vector<int>::reverse_iterator rite = test.rend();
	cout << "rite value = " << *rite << endl;
	cout << "test2 size = " << test2.size() << endl;
	cout << "test1 size = " << test1.size() << endl;
	cout << "test size = " << test.size() << endl;
	cout << "test2 max_size = " << test2.max_size() << endl;
	cout << "test1 max_size = " << test1.max_size() << endl;
	cout << "test max_size = " << test.max_size() << endl;
	test1.resize(50);
	cout << "test1 capacity = " << test1.capacity() << endl;
	cout << "test1 size = " << test1.size() << endl;
	test1.resize(1);
	cout << "test1 capacity = " << test1.capacity() << endl;
	cout << "test1 size = " << test1.size() << endl;
	test1.resize(0);
	cout << "test1 capacity = " << test1.capacity() << endl;
	cout << "test1 size = " << test1.size() << endl;
	cout << "test1 empty = " << test1.empty() << endl;
	test1.resize(1);
	cout << "test1 capacity = " << test1.capacity() << endl;
	cout << "test1 size = " << test1.size() << endl;
	test1.resize(1);
	cout << "test1 capacity = " << test1.capacity() << endl;
	cout << "test1 size = " << test1.size() << endl;
	test1.reserve(10);
	cout << "test1 capacity = " << test1.capacity() << endl;
	cout << "test1 size = " << test1.size() << endl;
	displayVect(test1, "test1");
	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);
	test1.push_back(4);
	cout << "test1 at(3) = " << test1.at(3) << endl;
	cout << "test1 front = " << test1.front() << endl;
	cout << "test1 back = " << test1.back() << endl;
	displayVect(test1, "test1");
	test1.assign(10, 5);
	displayVect(test1, "test1");
	test1.clear();
	displayVect(test1, "test1");
	test1.push_back(30);
	test1.push_back(40);
	test1.push_back(50);
	test1.push_back(60);
	it = test1.begin();
	it++;
	cout << "it = " << *it << endl;
	test1.insert(it, 2);
	it = test1.begin();
	it++;
	cout << "it = " << *it << endl;
	displayVect(test1, "test1");
	test1.erase(it);
	displayVect(test1, "test1");
	displayVect(test2, "test2");
	swap(test1, test2);
	displayVect(test1, "test1");
	displayVect(test2, "test2");
	test2.clear();
	displayVect(test2, "test2");

	/////////////////////

	ft::vector<string> test3;
	cout << "test3 capacity = " << test3.capacity() << endl;
	ft::vector<string> test4(5, "test");
	cout << "test4 capacity = " << test4.capacity() << endl;
	displayVect(test4, "test4");
	cout << test4.capacity() << endl;
	ft::vector<string> test5(test4);
	cout << "test5 capacity = " << test5.capacity() << endl;
	displayVect(test5, "test5");
	test3 = test4;
	displayVect(test3, "test3");
	cout << "test3 capacity after =op = " << test3.capacity() << endl;
	ft::vector<string>::iterator it1 = test3.begin();
	cout << "it1 value = " << *it1 << endl;
  	ft::vector<string>::iterator ite1 = test3.end();
	cout << "it1 value = " << *ite1 << endl;
	ft::vector<string>::reverse_iterator rit1 = test3.rbegin();
	cout << "rit1 value = " << *rit1 << endl;
  cout << "it1 == ite1 = " << (it1 == ite1) << endl;
	cout << "test5 size = " << test5.size() << endl;
	cout << "test4 size = " << test4.size() << endl;
	cout << "test3 size = " << test3.size() << endl;
	cout << "test5 max_size = " << test5.max_size() << endl;
	cout << "test4 max_size = " << test4.max_size() << endl;
	cout << "test3 max_size = " << test3.max_size() << endl;
	test4.resize(50);
	cout << "test4 capacity = " << test4.capacity() << endl;
	cout << "test4 size = " << test4.size() << endl;
	test4.resize(1);
	cout << "test4 capacity = " << test4.capacity() << endl;
	cout << "test4 size = " << test4.size() << endl;
	test4.resize(0);
	cout << "test4 capacity = " << test4.capacity() << endl;
	cout << "test4 size = " << test4.size() << endl;
	cout << "test4 empty = " << test4.empty() << endl;
	test4.resize(1);
	cout << "test4 capacity = " << test4.capacity() << endl;
	cout << "test4 size = " << test4.size() << endl;
	test4.resize(1);
	cout << "test4 capacity = " << test4.capacity() << endl;
	cout << "test4 size = " << test4.size() << endl;
	test4.reserve(10);
	cout << "test4 capacity = " << test4.capacity() << endl;
	cout << "test4 size = " << test4.size() << endl;
	displayVect(test4, "test4");
	test4.push_back("test1");
	test4.push_back("test2");
	test4.push_back("test3");
	test4.push_back("test4");
	cout << "test4 at(3) = " << test4.at(3) << endl;
	cout << "test4 front = " << test4.front() << endl;
	cout << "test4 back = " << test4.back() << endl;
	displayVect(test4, "test4");
	test4.assign(10, "blabla");
	displayVect(test4, "test4");
	test4.clear();
	displayVect(test4, "test4");
	test4.push_back("30");
	test4.push_back("40");
	test4.push_back("50");
	test4.push_back("60");
	it1 = test4.begin();
	it1++;
	cout << "it1 = " << *it1 << endl;
	test4.insert(it1, "insertion");
	it1 = test4.begin();
	it1++;
	cout << "it1 = " << *it1 << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	displayVect(test4, "test4");
	test4.erase(it1);
	displayVect(test4, "test4");
	displayVect(test5, "test5");
	swap(test4, test5);
	displayVect(test4, "test4");
	displayVect(test5, "test5");
	test5.clear();
	displayVect(test5, "test5");

	////////////////////////////////////////////

	ft::stack<int> s1;
	cout << "s1 empty = " << s1.empty() << endl;
	s1.push(5);
	s1.push(4);
	s1.push(46);
	s1.push(57);
	cout << "s1 empty = " << s1.empty() << endl;
	cout << "s1 top = " << s1.top() << endl;
	cout << "s1 size = " << s1.size() << endl;
	ft::stack<int> s2(s1);
	cout << "s2 empty = " << s2.empty() << endl;
	cout << "s2 top = " << s2.top() << endl;
	cout << "s2 size = " << s2.size() << endl;
	cout << "s1 == s2 = " << (s1 == s2) << endl;
	for (size_t i = 0; i < s1.size(); i++) {
		cout << ' ' << s1.top();
		s1.pop();
	}
	cout << "s1 == s2 = " << (s1 == s2) << endl;

	ft::stack<string> s3;
	cout << "s1 empty = " << s3.empty() << endl;
	s3.push("5");
	s3.push("4");
	s3.push("46");
	s3.push("57");
	cout << "s3 empty = " << s3.empty() << endl;
	cout << "s3 top = " << s3.top() << endl;
	cout << "s3 size = " << s3.size() << endl;
	ft::stack<string> s4(s3);
	cout << "s4 empty = " << s4.empty() << endl;
	cout << "s4 top = " << s4.top() << endl;
	cout << "s4 size = " << s4.size() << endl;
	cout << "s3 == s4 = " << (s3 == s4) << endl;
	for (size_t i = 0; i < s3.size(); i++) {
		cout << ' ' << s3.top();
		s3.pop();
	}
	cout << "s3 == s4 = " << (s3 == s4) << endl;

	///////////////////////////////////////////////

	ft::map<char, int> m1;
	m1['a'] =  1;
	cout << "size = " << m1.size() << std::endl;
	m1['b'] =  2;
	cout << "size = " << m1.size() << std::endl;
	m1['c'] =  3;
	cout << "size = " << m1.size() << std::endl;
	m1['d'] =  4;
	m1['e'] =  5;
	m1['f'] =  6;
	m1['f'] =  7;
	cout << "size = " << m1.size() << std::endl;
	m1.insert(ft::pair<char, int>('z', 134));
	cout << "size = " << m1.size() << std::endl;

	ft::map<char, int> m2(m1);
	cout << "m1 size = " << m1.size() << endl;
	cout << "m1[a] = " << m1['a'] << endl;
	cout << "m1[g] = " << m1['g'] << endl;
	ft::map<char, int>::iterator itm = m1.begin();
	itm++;
	cout << "m1 it = " << itm->first << " " << itm->second << endl;
	m1.erase(itm->first);
	cout << "m1[b] = " << m1['b'] << endl;
	ft::map<char, int> m3;
	swap(m1, m2);
	cout << "m1 size = " << m1.size() << endl;
	cout << "m1[a] = " << m1['a'] << endl;
	cout << "m1[b] = " << m1['b'] << endl;
	ft::map<char, int>::iterator itm2 = m1.find('f');
	cout << "itm2 = " << itm2->first << itm2->second << endl;
	cout << "m1 count = " << m1.count('g') << endl;
	ft::map<char, int>::iterator itm3 = m1.lower_bound('f');
	ft::map<char, int>::iterator itm4 = m1.upper_bound('a');
	cout << "itm3 = " << itm3->first << itm3->second << endl;
	cout << "itm4 = " << itm4->first << itm4->second << endl;
	m3 = m2;

	ft::map<string, string> m4;

	m4["a"] = "1";
	m4["b"] = "2";
	m4["c"] = "3";
	m4["d"] = "4";
	m4["e"] = "5";
	m4["f"] = "6";
	m4["f"] = "7";

	ft::map<string, string> m5(m4);
	cout << "m4 size = " << m4.size() << endl;
	cout << "m4[a] = " << m4["a"] << endl;
	cout << "m4[a] = " << m4["g"] << endl;
  ft::map<string, string>::iterator itm44 = m4.begin();
	ft::map<string, string>::reverse_iterator itmr44 = m4.rbegin();
  ft::map<string, string>::reverse_iterator itmr45 = m4.rend();
	cout << "m4 it = " << itm44->first << " " << itm4->second << endl;
	itm44++;
	itm44++;
	itm44++;
	itm44++;
	itm44--;
	itm44--;
	cout << "m4 it = " << itm44->first << " " << itm4->second << endl;
	itmr44++;
	itmr44++;
	itmr44++;
	itmr44--;
	itmr44--;
	cout << "mr4 it = " << itmr44->first << " " << itmr44->second << endl;
	m4.erase(itm44->first);
	cout << "m4[b] = " << m4["b"] << endl;
	ft::map<string, string> m6;
	swap(m4, m5);
	ft::map<string, string>::iterator itm22 = m4.find("f");
	cout << "itm2 = " << itm22->first << itm2->second << endl;
	cout << "m4 count = " << m4.count("f") << endl;
	ft::map<string, string>::iterator itm33 = m4.lower_bound("f");
	ft::map<string, string>::iterator itm45 = m4.upper_bound("a");
	cout << "itm3 = " << itm33->first << itm33->second << endl;
	cout << "itm4 = " << itm45->first << itm45->second << endl;
	m6 = m5;

	return (0);
}