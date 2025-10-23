#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> dat_;
  int m_;
  PComparator c_;
  void heapify(size_t indx);


};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t indx){
  size_t bIndx =indx;
  size_t leftChild = m_ * indx +1; //2 * indx +1 first child

  // will give the best index, which will also ensure that the values are in order from least to greatest 
  for (int i=0; i<m_ ; ++i){
    size_t childIndx = leftChild + i;
    //updates to the best index
    if (childIndx < dat_.size() && c_(dat_[childIndx], dat_[bIndx])){
      bIndx = childIndx; 
    }
  }
  
  // if the child should be before the current value they will be swapped and continue to heapify 
  if (bIndx != indx){
    std::swap(dat_[indx], dat_[bIndx]);
    heapify(bIndx);
  }

}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error ("emtpy heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return dat_[0];;



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error ("emtpy heap");

  }

  dat_[0] = dat_.back();
  dat_.pop_back();

  if(!empty()){
    heapify(0);
  }


}

template <typename T, typename PComparator>
Heap <T, PComparator>::Heap(int m, PComparator c): m_(m), c_(c){

  if (m_ < 2){
    throw std::invalid_argument("Wrong");
  }

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  dat_.push_back(item);
  trickleUp(dat_.size() -1);

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return dat_.empty();

}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return dat_.size();

}




#endif

