#pragma once

#include "adts/queue.h"
#include "adts/stlList.h"

/**
 * The LinkedQueue is an implementation of the Queue interface using a
 * linked list.  
 * @tparam T The type of elements stored in the queue.
 */
template <typename T> class LinkedQueue : public Queue<T> {
  public:
    LinkedQueue();
    void enqueue(T element);
    T dequeue();
    void insert(T element);
    T remove();
    int getSize();
    bool isEmpty();
    T peek();

  private:
    STLList<T> actualList;

  private:
    // You can safely ignore the following code.  You can read more here:
    //   http://www.cplusplus.com/articles/y8hv0pDG/
    LinkedQueue(const LinkedQueue& other) = delete;
    LinkedQueue& operator=(const LinkedQueue& other) = delete;
};

#include "linkedQueue-inl.h"
