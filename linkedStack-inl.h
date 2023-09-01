#include "linkedStack.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedStack<T>::LinkedStack() {
}

template <typename T> void LinkedStack<T>::push(T element) {
  this->actualList.insertFirst(element);
}

template <typename T> T LinkedStack<T>::pop() {
  return this->actualList.removeFirst();
}

template <typename T> void LinkedStack<T>::insert(T element) {
  // To "insert" into a stack is to push onto it.  So when we are told to
  // insert, we will push.
  this->push(element);
}

template <typename T> T LinkedStack<T>::remove() {
  return this->pop();
}

template <typename T> int LinkedStack<T>::getSize() {
  return this->actualList.getSize();
}

template <typename T> bool LinkedStack<T>::isEmpty() {
  return this->actualList.isEmpty();
}

template <typename T> T LinkedStack<T>::peek() {
  return this->actualList.getFirst();
}
