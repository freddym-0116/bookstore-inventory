/*
Name: Frederic Mantilla
CWID: 826125924
Email: fmantilla@csu.fullerton.edu
*/

#ifndef MY_DOUBLY_LINKED_LIST_HPP
#define MY_DOUBLY_LINKED_LIST_HPP


/**
 * TODO: Implement DoublyLinkedList, its Node, and its Iterator!
 * 
 * I've left some methods filled out for you,
 * 	and stubbed out some structure, to reduce difficulty.
 * 
 * You may add helper methods as you see fit,
 * 	as long as you can still pass all unit tests.
 * 
 * Notice we're inside a namespace here.
 * The DLL is inside a namespace called DoublyLinkedList,
 * 	which is itself inside a namespace called CPSC131
 * This means, if you'd like to play around with your class later,
 * 	you'll need to access it like so:
 * ::CPSC131::DoublyLinkedList::DoublyLinkedList<int> list;
 * 
 * Look into main.cpp and CPP_Tests.cpp for examples of using
 * 	the DLL and your BookStore. But don't worry too much, as you
 * 	only need to implement these classes
 * (main and tests are already done for you)
 */


//
#include <iostream>
#include <stdlib.h>
#include <stdexcept>


/**
 * Namespace for our classroom and DLL !
 */
namespace CPSC131::DoublyLinkedList
{
	/**
	 * Implement our DoublyLinkedList class !
	 */
	template <class T>
	class DoublyLinkedList
	{
		public:
			
			/**
			 * Node class, representing a single item in our linked list
			 */
			// TODO: Complete all class methods
			class Node
			{
				public:
					
					/// CTORS
					/// Member initialization lists?
					Node() {
					prev_ = nullptr;
					next_ = nullptr;
					}
					Node(T element) {
					element_ = element;
					prev_ = nullptr;
					next_ = nullptr;
					}
					Node(T element, Node* prev, Node* next) {
					element_ = element;
					prev_ = prev;
					next_ = next;
					}
					
					/// Set the pointer to the previous element
					void setPrevious(Node* prev) {
					prev_ = prev;
					}
					
					/// Set the pointer to the previous element
					void setPrev(Node* prev) {
					prev_ = prev;
					}
					
					/// Get a pointer to the previous element
					Node* getPrevious() {
					return prev_;
					}
					
					/// Get a pointer to the previous element
					Node* getPrev() {
					return prev_;
					}
					
					/// Set the pointer to the next node
					void setNext(Node* next) {
					next_ = next;
					}
					
					/// Get a pointer to the next node
					Node* getNext() {
					return next_;
					}
					
					/// Set the element this node holds
					void setElement(T element) {
					element_ = element;
					}
					
					/// Get the element this node holds
					///	YOUR WELCOME
					T& getElement() { return this->element_; }
					
					/// Return a reference to the element
					///	YOUR WELCOME
					T& operator*() { return this->element_; }
					
				private:
					T element_;
					Node* prev_;
					Node* next_;
			};
			
			/**
			 * Nested Iterator class.
			 * This allows user code to refer to the Iterator's type as:
			 * 
			 * CPSC131::DoublyLinkedList::DoublyLinkedList<int>::Iterator
			 * 
			 * (as opposed to specifying the template argument two times)
			 */
			class Iterator
			{
				public:
					
					///	Constructor that does nothing; YOUR WELCOME
					Iterator()
					{
						/// yw
					}
					
					///	Constructor taking a head and tail pointer; YOUR WELCOME
					Iterator(Node* head, Node* tail) : head_(head), tail_(tail)
					{
						this->cursor_ = this->end();	/// yw
					}
					
					///	Constructor taking a head, tail, and cursor pointer; YOUR WELCOME
					Iterator(Node* head, Node* tail, Node* cursor) : head_(head), tail_(tail), cursor_(cursor) {}
					
					///	Get a pointer to the head node, or end() if this list is empty
					Node* begin()
					{
						if (head_ == nullptr){
						 return end();
						 }
						 return head_;
					}
						
					///	Get a node pointer representing "end" (aka "depleted"). Probably want to just use nullptr.
					Node* end()
					{
						return nullptr;
					}
					
					///	Get the node to which this iterator is currently pointing
					Node* getCursor()
					{
						return cursor_;
					}
					
					///	Return true if this iterator has hit its end; false otherwise
					/// YOUR WELCOME
					bool isAtEnd()
					{
						return this->cursor_ == nullptr;
					}
					
					/**
					 * Assignment operator
					 * Return a copy of this Iterator, after modification
					 */
					Iterator& operator=(const Iterator& other)
					{
						head_ = other.head_;
						tail_ = other.tail_;
						cursor_ = other.cursor_;
						return *this;
					}
					
					///	Comparison operator
					bool operator==(const Iterator& other)
					{
						return cursor_ == other.cursor_;
					}
					///	Inequality comparison operator
					bool operator!=(const Iterator& other)
					{
						return cursor_ != other.cursor_;
					}
					
					/**
					 * Addition operator
					 */
					Iterator operator +(size_t add)
					{
						   Iterator temp = *this;
						   temp += add;
						   return temp;
					}
					
					/**
					 * Subtraction operator
					 */
					Iterator operator -(size_t subtract)
					{
						   Iterator temp = *this;
						   temp -= subtract;
						   return temp;
					}
					
					/**
					 * Prefix increment operator
					 * Return a reference to this Iterator, after modification
					 */
					Iterator& operator++()
					{
						if (cursor_ != nullptr) {
						cursor_ = cursor_->getNext();
					}
					return *this;
					
					}
					
					/**
					 * Postfix increment
					 * Return a copy of this Iterator, BEFORE it was modified
					 */
					Iterator operator++(int)
					{
						Iterator temp = *this;
						if (cursor_ != nullptr) {
						cursor_ = cursor_->getNext();
					}
					return temp;
					}
					
					/**
					 * Prefix decrement operator
					 * Return a reference to this Iterator, after modification
					 */
					Iterator& operator--()
					{
						if (cursor_ == nullptr) {
						cursor_ = tail_;
					} else {
					  cursor_ = cursor_->getPrev();
					  }
					  return *this;
					  }
					
					/**
					 * Postfix decrement operator
					 * Return a copy of this Iterator BEFORE it was modified
					 */
					Iterator operator--(int)
					{
						Iterator temp =*this;
						if (cursor_ == nullptr) {
						 cursor_ = tail_;
					} else {
					   cursor_ = cursor_->getPrev();
					   }
					   return temp;
					   }
					
					/**
					 * AdditionAssignment operator
					 * Return a copy of the current iterator, after modification
					*/
					Iterator operator +=(size_t add)
					{
						for (size_t i = 0; i < add; i++) {
						 if (cursor_ != nullptr) {
						    cursor_ = cursor_->getNext();
						 }
						}
						return *this;
						}
					/**
					 * SubtractionAssignment operator
					 * Return a copy of the current iterator, after modification
					 */
					Iterator operator -=(size_t sub)
					{
						 for (size_t i = 0; i < sub; i++) {
						  if (cursor_ == nullptr) {
						     cursor_ = tail_;
						} else {
						  cursor_ = cursor_->getPrev();
					        }
					     }
					     return *this;
					   }
					
					
					/**
					 * AdditionAssignment operator, supporting positive or negative ints
					 */
					Iterator operator +=(int add)
					{
						if (add >= 0) {
						  for (int i = 0; i < add; i++) {
						    if (cursor_ != nullptr) {
						       cursor_ = cursor_->getNext();
						   }
						 }
					       } else {
					          for (int i = 0; i < -add; i++) {
					             if (cursor_ == nullptr) {
					                 cursor_ = tail_;
					             } else {
					             	cursor_ = cursor_->getPrev();
					             }
					           }
					        }
					        return *this;
					        }
					
					/**
					 * SubtractionAssignment operator, supporting positive or negative ints
					 */
					Iterator operator -=(int subtract)
					{
						 if (subtract >= 0) {
						     for (int i = 0; i < subtract; i++) {
						        if (cursor_ == nullptr) {
						           cursor_ = tail_;
						        } else {
						            cursor_ = cursor_->getPrev();
						        }
						   }
						   } else {
						   	for (int i = 0; i < -subtract; i++) {
						   	  if (cursor_ != nullptr) {
						   	       cursor_ = cursor_->getNext();
						   	  }
						   	}
						   }
						   return *this;
					  }
					
					/**
					 * Dereference operator returns a reference to the ELEMENT contained with the current node
					 */
					 T& operator*()
					{
						 if (cursor_ == nullptr) {
						    throw std::out_of_range("Cannot dereference end iterator");
						 }
						 return cursor_->getElement();
					}
				
				private:
					
					/// Pointer to the head node
					Node* head_ = nullptr;
					
					/// Pointer to the tail node
					Node* tail_ = nullptr;
					
					/**
					 * Pointer to the cursor node.
					 */
					Node* cursor_ = nullptr;
				
				friend class DoublyLinkedList;
			};
			
			/// Default constructor
			DoublyLinkedList()
			{
				head_ = nullptr;
				tail_ = nullptr;
				size_ = 0;
			}
			
			///	Copy Constructor
			DoublyLinkedList(const DoublyLinkedList& other)
			{
				head_ = nullptr;
				tail_ = nullptr;
				size_ = 0;
				Node* current = other.head_;
				while (current != nullptr) {
				 push_back(current->getElement());
				 current = current->getNext();
				} 
			}
			
			/// DTOR
			~DoublyLinkedList()
			{
				clear();
			}
			
			/**
			 * Clear the list and assign the same value, count times.
			 * 
			 * Example:
			 *   T is an int
			 *   count is 5
			 *   value = 3
			 * 
			 * Our list would become:
			 *   {3, 3, 3, 3, 3}
			 */
			void assign(size_t count, const T& value)
			{
				 clear();
				  for (size_t i = 0; i < count; i++) {
				    push_back(value);
				 }
			}
			
			/**
			 * Clear the list and assign values from another list.
			 * The 'first' iterator points to the first item copied from the other list.
			 * The 'last' iterator points to the last item copied from the other list.
			 * 
			 * Example:
			 * 	Suppose we have a source list like {8, 4, 3, 2, 7, 1}
			 * 	Suppose first points to the 4 node
			 *	Suppose last points to the 7 node
			 * 	We should end up with our list becoming: {4, 3, 2, 7}
			 *
			 * If the user code sends out-of-order iterators,
			 * 	just copy from 'first' to the end of the source list
			 * 
			 * Example:
			 *  If we have the same source list {8, 4, 3, 2, 7, 1},
			 *  and first points to the 7 node,
			 *  and last points to the 4 node,
			 *  we would end up with: {7, 1}
			 */
			void assign(Iterator first, Iterator last)
			{
				 clear();
				   Node* current = first.getCursor();
				   Node* lastNode = last.getCursor();
				   while (current != nullptr) {
				      push_back(current->getElement());
				       if (current == lastNode) {
				         break;
				       }
				       current = current->getNext();
				    }
  			 }
			
			/// Return a pointer to the head node, if any
			Node* head() const
			{
				return head_;
			}
			
			/// Return a pointer to the tail node, if any
			Node* tail() const
			{
				return tail_;
			}
			
			/**
			 * Return an iterator that points to the head of our list
			 */
			Iterator begin() const
			{
				return Iterator(head_, tail_, head_);
			}
			
			/**
			 * Return an iterator that points to the last element (tail) of our list
			 */
			Iterator last() const
			{
				 return Iterator(head_, tail_, tail_);
			}
			
			/**
			 * Should return an iterator that represents being past the end of our nodes,
			 * or just that we are finished.
			 * 
			 * You can make this a nullptr or use some other scheme of your choosing,
			 * 	as long as it works with the logic of the rest of your implementations.
			 */
			Iterator end() const
			{
				return Iterator(head_, tail_, nullptr);
			}
			
			/**
			 * Returns true if our list is empty
			 */
			bool empty() const
			{
				  return head_ == nullptr;
			}
			
			/**
			 * Returns the current size of the list
			 * 
			 * Should finish in constant time!
			 * (keep track of the size elsewhere)
			 */
			size_t size() const
			{
				   return size_;
			}
			
			/**
			 * Clears our entire list, making it empty
			 */
			void clear()
			{
				Node* current = head_;
				while (current != nullptr) {
				  Node* next = current->getNext();
				  delete current;
				  current = next;
				}
				 head_ = nullptr;
				 tail_ = nullptr;
				 size_ = 0;
			}
			/**
			 * Insert an element after the node pointed to by the pos Iterator
			 * 
			 * If the list is currently empty,
			 * 	ignore the iterator and just make the new node at the head/tail (list of length 1).
			 * 
			 * If the incoming iterator is this->end(),
			 *   insert the element as the new tail
			 * 
			 * Should return an iterator that points to the newly added node
			 */
			Iterator insert_after(Iterator pos, const T& value)
			{
				Node* current = pos.getCursor();
				 if (current == nullptr) {
				   return push_back(value);
				}
				 Node* nextNode = current->getNext();
				 Node* newNode = new Node(value, current, nextNode);
				  current->setNext(newNode);
				 if (nextNode != nullptr) {
				       nextNode->setPrev(newNode);
				   } else {
				   	tail_ = newNode;
				   }
				   size_++;
				   return Iterator(head_, tail_, newNode);
			}
			
			/**
			 * Insert a new element after the index pos.
			 * Should work with an empty list.
			 * 
			 * If the user attempts to insert to an index
			 * that is out of range (e.g., size=5 but index=13),
			 * just add to the end of the list.
			 * 
			 * Should return an iterator pointing to the newly created node
			*/
			Iterator insert_after(size_t pos, const T& value)
			{
				if (empty()) {
				  return push_back(value);
				}
				 if (pos >= size_ - 1) {
				   return push_back(value);
				 }
				  Node* current = head_;
				  for (size_t i = 0; i < pos; i++) {
				     current = current->getNext();
				   }
				    Iterator itr(head_, tail_, current);
				    return insert_after(itr, value);
		        }
			
			/**
			 * Erase the node pointed to by the Iterator's cursor.
			 * 
			 * If the 'pos' iterator does not point to a valid node,
			 * 	throw an std::range_error
			 * 
			 * Return an iterator to the node AFTER the one we erased,
			 * 	or this->end() if we just erased the tail
			 */
			Iterator erase(Iterator pos)
			{
				Node* current = pos.getCursor();
				 if (current == nullptr) {
      				   throw std::range_error("Cannot erase end iterator");
   				 }
				 Node* nextNode = current->getNext();
   				 Node* prevNode = current->getPrev();
				  if (prevNode != nullptr) {
     				     prevNode->setNext(nextNode);
   				  } else {
       				    head_ = nextNode;
				  }
   				  if (nextNode != nullptr) {
     				     nextNode->setPrev(prevNode);
   				  } else {
      				    tail_ = prevNode;
   				  }
				   delete current;
   				   size_--;

   				 return Iterator(head_, tail_, nextNode);
			}
			
			/**
			 * Add an element just after the one pointed to by the 'pos' iterator
			 * 
			 * Should return an iterator pointing to the newly created node
			 */
			Iterator push_after(Iterator pos, const T& value)
			{
				Node* current = pos.getCursor();
				if (current == nullptr) {
       				  return push_back(value);
   				}
				 Node* nextNode = current->getNext();
   				 Node* newNode = new Node(value, current, nextNode);
				  current->setNext(newNode);
				 if (nextNode != nullptr) {
       				    nextNode->setPrev(newNode);
    				 } else {
     			           tail_ = newNode;
    			         }
  			         size_++;
   				 return Iterator(head_, tail_, newNode);
			}
			
			/**
			 * Add a new element to the front of our list.
			 */
			void push_front(const T& value)
			{
				Node* newNode = new Node(value, nullptr, head_);
				if (empty()) {
					head_ = newNode;
					tail_ = newNode;
				} else {
				   head_->setPrev(newNode);
				   head_ = newNode;
				}
				size_++;
			}
			
			/**
			 * Add an element to the end of this list.
			 * 
			 * Should return an iterator pointing to the newly created node.
			 */
			Iterator push_back(const T& value)
			{
				Node* newNode = new Node(value, tail_, nullptr);
				if (empty()) {
				 head_ = newNode;
				 tail_ = newNode;
				} else {
				  tail_->setNext(newNode);
				  tail_ = newNode;
				}
				size_++;
				return Iterator(head_, tail_, newNode);
			}
			
			
			/**
			 * Remove the node at the front of our list
			 * 
			 * Should throw an exception if our list is empty
			 */
			void pop_front()
			{
				if (empty()) {
				 throw std::range_error("Cannot pop_front from an empty list");
				}
				Node* oldHead = head_;
				 if (head_ == tail_) {
				 head_ = nullptr;
				 tail_ = nullptr;
				} else {
				   head_ = head_->getNext();
				   head_->setPrev(nullptr);
				 }
				 delete oldHead;
				 size_--;
			}
			
			/**
			 * Remove the node at the end of our list
			 * 
			 * Should throw an exception if our list is empty
			 */
			void pop_back()
			{
				if (empty()) {
			       throw std::range_error("Cannot pop_back from an empty list");
				}
				Node* oldTail = tail_;
				if (head_ == tail_) {
				head_ = nullptr;
				tail_ = nullptr;
			     } else {
			     	tail_ = tail_->getPrev();
			     	tail_->setNext(nullptr);
			     }
			     delete oldTail;
			     size_--;	
			}     
			    
			/**
			 * Return a reference to the element at the front.
			 * 
			 * Throw an exception if the list is empty
			 */
			T& front()
			{
				  if (empty()) {
				   throw std::range_error("List is empty");
				   }
				    return head_->getElement();
			}
			
			/**
			 * Return a reference to the element at the back.
			 * 
			 * Throw an exception if the list is empty
			 */
			T& back()
			{
				    if (empty()) {
        			    throw std::range_error("List is empty");
    				     }
   				    return tail_->getElement();
			}
			
			/**
			 * Return the element at an index
			 * 
			 * Should throw a range_error is out of bounds
			 */
			T& at(size_t index)
			{
			    if (index >= size_) {
      		              throw std::range_error("Index out of bounds");
   			     }
			    Node* curr = head_;

  		            for (size_t i = 0; i < index; i++) {
   			      curr = curr->getNext();
   			    }
			    return curr->getElement();
			}
			
			/**
			 * Reverse the current list
			 */
			void reverse()
			{
   				    if (empty() || size_ == 1) {
   				     return;
				    }
				    DoublyLinkedList<T> tempList;
				     Node* current = tail_;
				     while (current != nullptr) {
				        tempList.push_back(current->getElement());
				        current = current->getPrev();
				      }
				      *this = tempList;
			}
				    
			
			/**
			 * I bet you're happy I'm not making you do this.
			 * No tests will be run against this function,
			 * 	but feel free to try it out, as a challenge!
			 * 
			 * If I were doing this and didn't care too much for efficiency,
			 * 	I would probably create an extra helper function to swap two
			 * 	positions in the current list.
			 * Then I would simply sweep through the list and perform
			 *  the bubble-sort algorithm. Perhaps selection sort.
			 * 
			 * If you want a huge challenge, try implementing quicksort.
			 * 
			 * (but again, don't worry about this method; it will not be tested)
			 */
			void sort()
			{
				//	TODO: Your code here
			}
			
			/**
			 * Assignment operator
			 * 
			 * Clear this list and fill it with the others' values
			 * (by value, not by reference)
			 * 
			 * Return a reference to this list
			 */
			DoublyLinkedList<T>& operator =(const DoublyLinkedList<T>& other)
			{
				 if (this == &other) {
				    return *this;
				 }
				 clear();
				 Node* current = other.head_;
				  while (current != nullptr) {
				    push_back(current->getElement());
				    current = current->getNext();
				  }
				  return *this;
			}
				    
			
			/**
			 * Return true if the lists are "equal"
			 * 
			 * "Equal" here is defined as:
			 * - Same size
			 * - Elements at the same indexes would return true for their own comparison operators
			 * 
			 * In other words: "They contain all the same values"
			 * (no need for their pointers or addresses to be the same)
			 */
			bool operator ==(DoublyLinkedList<T>& other)
			{
				if (size_ != other.size_) {
				  return false;
				}
				 Node* curr1 = head_;
				 Node* curr2 = other.head_;
				    while (curr1 != nullptr && curr2 != nullptr) {
				      if (curr1->getElement() != curr2->getElement()) {
				      	return false;
				      }
				       curr1 = curr1->getNext();
				       curr2 = curr2->getNext();
				      }
				      return true;
			}

			
			/**
			 * Return true if the lists are "not equal"
			 * 
			 * See the operator== stub for definition of "equal"
			 */
			bool operator !=(DoublyLinkedList<T>& other)
			{
				  return !(*this == other);
			}
			
		private:
			
			Node* head_ = nullptr;
			Node* tail_ = nullptr;
			size_t size_ = 0;
	};
}

#endif
