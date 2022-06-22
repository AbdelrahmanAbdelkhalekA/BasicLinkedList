# BasicLinkedList

### Namespace:
The `List` class is declared within namespace `ECE275Lib::containers`

### Datatype/Composition:
- The `List` class is constructable with an arbitrary C++ datatype. Hint: The `List` class will be declared as `List<T> l` where `T` is an arbitrary data type. This may be accomplished through a template!!
- The `List` class is comprised of a user-defined type `Node` where the `Node` may similarly be constructed given an arbitrary data type, i.e., `Node<T>`. The `Node` class/struct is point to the next node in the list 
  (Hint: declare as `Node<T>* next`, i.e., `Node<T>::next` should be of type `Node<T>*` and should hold the memory location of the next `Node` in the list). The `Node` type return the "next" node given a member function `Node<T>* get_next(void)`. 
- The `List` is null-terminated, i.e., the last `Node` will set it's "next" to `nullptr`


### Construction:
- The `List` class is constructable with a default constructor. This is set the head of the list to `nullptr` and the list's size to 0.
- The `List` class is constructable with a parameterized constructor accepting an `unsigned int` type which denotes the length of the list. 
  This is construct N `Node`s in the list where N is the input parameter. The last `Node` in the `List` is always point to `nullptr` (the list is *always* NULL-terminated).

### Access:
- The `List` class provide access to the memory location of the head, i.e., the first node in the linked list, through a member function `List<T>::front()`
- The `List` class provide access to the memory location of the tail, i.e., the last node in the linked list, through a member function `List<T>::back()`
- The `List` class provide access to the i<sup>th</sup> element through a member function `List<T>::at(i)` which returns type `T` where `i` is of type `unsigned int` and the return value is the value stored in the *i* <sup>th</sup> node
- The `List` class provide a setting function to the i <sup>th</sup> element through a member function `List<T>::assign(i, d)` which returns type `void` where `i` is of type `unsigned int` and `d` is of type `T`. 
  The function shall assign the data stored in the  i<sup>th</sup> element of the list to be the value `d`. 
- The `List` return the length of the list as an unsigned integer through a member function `List<T>::size()` which accepts no input.

### Mutation:
- The `List` class remove one node in the list through a member function `List<T>::remove(unsigned int i`) where `i` denotes the index of the `Node` to remove. 
  The list's size must be updated accordingly. 
- The `List` class remove multiple nodes in the list through a member function `List<T>::remove(unsigned int s, unsigned int e`) where `s` denotes the starting index of the `Node` to remove and `e` denotes the ending index of the `Node` to remove. 
  The list's size must be updated accordingly. 
- The `List` insert an element at index `i` through a member function `List<T>::insert(unsigned int i, T d)` where `i` is the index of the new element to be inserted, e.g., the list before insertion may look like `[HEAD] (index 0) A --> (index 1) B --> (index 2) C --> nullptr` and the list after `List<T>::insert(1, N)` where `N` represents the data stored in the new `Node` will look like `[HEAD] (index 0) A --> (index 1) N --> (index 2) B --> (index 3) C --> nullptr`
- The `List` insert a separate `List` starting at index `i` through a member function `List<T>::insert(unsigned int i, List<T>& other)` (note the necessity to pass by reference!!). 
  E.g., the list before insertion of another list may look like `[HEAD] (index 0) A --> (index 1) B --> (index 2) C --> nullptr` and the list after `List<T>::insert(1, other)` where `other` may look like `[HEAD] (index 0) Z --> (index 1) Y --> nullptr` will look like `[HEAD] (index 0) A --> (index 1) Z --> (index 2) Y --> (index 3) B --> (index 4) C --> nullptr` 

```c
Steps I used to approach this:
1. Draw with pen and paper the layout of the linked list so that you have a concrete reference.
2. Draw an actual picture for the `List` operations. It is useful to draw each operation and label using the variable names you intend to use in your code. 
3. Leverage member helper functions. Hint: The solution file includes a private helper function `List<T>::traverse(unsigned int i)` which returns a pointer to the i <sup>th</sup> `Node<T>` in the list. 
   Operations which are common between 2 or more functions are usually a good candidate to be placed into a helper function. 
4. Design a flowchart for each operation. This may help identify good candidates for a helper function. 
5. Run, test, and re-test *locally* so that you can leverage your local debugger!! It's so much easier to track down errors locally then to leverage the tester. 
   You are encouraged to write your own "tests" which might test your `List` class against the `std::list` (or any other sequence container) to ensure that the described operations will most likely not experience a segmentation fault in the tester. 
```

