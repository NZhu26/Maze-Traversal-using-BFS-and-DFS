#include "linkedQueue.h"
#include "adts/stlList.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedQueue<T>::LinkedQueue() {
}

template <typename T> int LinkedQueue<T>::getSize() {
  return this->actualList.getSize();
}

template <typename T> bool LinkedQueue<T>::isEmpty() {
  return this->actualList.isEmpty();
}

template <typename T> T LinkedQueue<T>::peek() {
  return this->actualList.getFirst();
}

template <typename T> void LinkedQueue<T>::enqueue(T element) {
  return this->actualList.insertLast(element);
}

template <typename T> T LinkedQueue<T>::dequeue() {
  return this->actualList.removeFirst();
}

template <typename T> void LinkedQueue<T>::insert(T element) {
  this->enqueue(element);
}

template <typename T> T LinkedQueue<T>::remove() {
  return this->dequeue();
}
