#ifndef G_H
#define G_H
#include <iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	node<T>* next;
};

template<class T>
class stack
{
public:
	stack();
	stack(const stack<T>& st);
	~stack();

	void push(T data);
	T pop();
	int size() const;
	void clear();

	stack<T>& operator=(const stack<T>& st);

	template<class T>
	friend ostream& operator<<(ostream& out, const stack<T>& st);

	
private:
	int m_size;
	node<T>* m_head;
	void copy(const stack<T>& st);
	void copy(node<T>* p);
};

template<class T>
stack<T>::stack()
{
	m_head = nullptr;
	m_size = 0;
}

template<class T>
stack<T>::stack(const stack<T>& st)
{
	copy(st);
}

template<class T>
stack<T>::~stack()
{
	clear();
}

template<class T>
void stack<T>::push(T data)
{
	node<T>* p = new node<T>();
	p->data = data;
	p->next = nullptr;

	p->next = m_head;
	m_head = p;
	m_size++;
}

template<class T>
T stack<T>::pop()
{
	if (m_size == 0) {
		throw exception("stack is empty");
	}
	T data = m_head->data;
	node<T>* temp = m_head;
	m_head = m_head->next;
	delete temp;
	m_size--;

	return data;
}

template<class T>
int stack<T>::size() const
{
	return m_size;
}

template<class T>
void stack<T>::clear()
{
	node<T>* p = m_head;
	node<T>* t;
	while (p != nullptr)
	{
		t = p->next;
		delete p;
		p = t;
	}

	m_head = nullptr;
	m_size = 0;
}

template<class T>
stack<T>& stack<T>::operator=(const stack<T>& st)
{
	if (this != &st) {
		clear();
		copy(st);
	}

	return *this;
}

template<class T>
void stack<T>::copy(const stack<T>& st)
{
	m_size = st.m_size;
	copy(st.m_head);
}

template<class T>
void stack<T>::copy(node<T>* p)
{
	if (p == nullptr)
		return;

	copy(p->next);
	push(p->data);
}

template<class T>
ostream& operator<<(ostream& out, const stack<T>& st)
{
	node<T>* p = st.m_head;
	while (p != nullptr)
	{
		out << p->data << " ";
		p = p->next;
	}
	out << endl;
	return out;
}

#endif
