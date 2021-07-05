#ifndef __ED_SList_HPP__
#define __ED_SList_HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

/** @brief a single link node.*/
template <class T>
class SNode
{
public:

    /** @brief Define a shared reference to a SNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< SNode<T> > Ref;

    /** @name Life cicle.*/
    /** @{*/

    /** @brief Create a node.
     * @post !has_next()
     */
    SNode (T const& it)
    {
        //TODO
        data_=it;
        siguiente_=nullptr;

        assert(!has_next());
    }

    /** @brief Create an empty Stack.*/
    SNode (T const& it, SNode<T>::Ref& next)
    {
        //TODO
        data_=it;
        siguiente_=next;
    }

    /**
     * @brief Create a SNode using dynamic memory.
     * @param it the value save in the node.
     * @param next link to the next node.
     * @return a shared referente to the new node.
     */
    static typename SNode<T>::Ref create(T const& it, SNode<T>::Ref next=nullptr)
    {
        return std::make_shared<SNode<T>> (it, next);
    }

    /** @brief Destroy a SNode.**/
    ~SNode()
    {
        //TODO: think if it is needed.
    }
    /** @}*/

    /** @name Observers.*/
    /** @{*/

    /** @brief Get the data item.*/
    const T& item() const
    {
        //TODO
        return data_;
    }

    /**
     * @brief Has it a next node?.
     * @return true if it has a next node.
    */
    bool has_next() const
    {
        //TODO
        if(siguiente_==nullptr){
            return false;
        }

        return true;
    }

    /** @brief Get the link to next element.*/
    SNode<T>::Ref next() const
    {
        //TODO
        return siguiente_;
        //return nullptr;
    }

    /** @}*/

    /** @name Modifiers.*/
    /** @{*/

    /** @brief Set the data item.*/
    void set_item(const T& new_it)
    {
        //TODO
        data_=new_it;
    }

    /** @brief Set the link to the next node.*/
    void set_next(SNode<T>::Ref next)
    {
        //TODO
        siguiente_=next;
    }

protected:

    //TODO
    T data_;
    Ref siguiente_;
};

/**
 * @brief ADT SList.
 * Models a Single linked list[T].
 */
template<class T>
class SList
{
  public:

    /** @brief Define a shared reference to a SNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< SList<T> > Ref;

  /** @name Life cicle.*/
  /** @{*/

  /** @brief Create an empty Stack.
   * @post is_empty()
   */
  SList ()
  {
      //TODO
      head_=nullptr;

      assert(is_empty());
  }

  /** @brief Destroy a Stack.**/
  ~SList()
  {}

  /**
   * @brief Create a SList using dynamic memory.
   * @return a shared referente to the new slist.
   */
  static typename SList<T>::Ref create()
  {
      return std::make_shared<SList<T>> ();
  }

  /**
   * @brief Create a SList unfoldig from an input stream.
   *
   * The input format will be "[]" for the empty list
   * or "[" item1 item2 ... item_n "]" where item1 is the head.
   *
   * @param in is the input stream.
   * @warning if the input format is not correct a std::runtime_error with
   * what message "Wrong input format." will be reaised.
   * @return A shared referente to the new slist.
   */
  static typename SList<T>::Ref create(std::istream& in) noexcept(false)
  {      
      typename SList<T>::Ref lista=SList<T>::create();
      //TODO
      //Hint: use std::istringstream to convert a token into generic T type.
      typename SList<T>::Ref aux_lista=SList<T>::create();
      std::string read;
      in>>read;
      T new_data;

      if(read=="[]"){
        return lista;
      }

      else if(read!="["){
        throw std::runtime_error("Wrong input format.");
      }

      while(in>>read){
          if(read=="]"){
            break;
          }

          std::istringstream str(read);
          str>>new_data;
          if(aux_lista->is_empty()){
              aux_lista->push_front(new_data);
          } 

          else{
              aux_lista->push_front(new_data);
          }
      }

      while(!aux_lista->is_empty()){
          lista->push_front(aux_lista->front());
          aux_lista->pop_front();
      }

      if(read!="]"){
        throw std::runtime_error("Wrong input format.");
      }

      return lista;
  }

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const
  {
      //TODO
      if(head_==nullptr){
        return true;
      }

      return false;
  }

  /**
   * @brief Get the head's item of the list.
   * @return the item at the head.
   */
  const T& front() const
  {
      assert(!is_empty());
      //TODO
      return head_->item();
      //return T();
  }

  /** @brief get the current item.
   * @pre not is_empty()
   */
  const T& current() const
  {
      assert(! is_empty());
      //TODO
      return current_->item();
      //return T();
  }

  /**
   * @brief Is there a next item?
   * @return true if there is.
   * @pre !is_empty()
   */
  bool has_next() const
  {
      assert(!is_empty());
      //TODO
      return current_->has_next();
  }

  /**
   * @brief Get the next item.
   * @return the next item data.
   * @pre has_next()
   */
  T const& next() const
  {
      assert(has_next());
      //TODO
      return current_->next()->item();
      //return T();
  }


    /**
     * @brief Has it the item data?
     * @param[in] it is the item to find.
     * @return true if the item is into the list.
     */
    bool has(T const& it) const
    {
        //TODO
        if(is_empty()){
            return false;
        }

        typename SNode<T>::Ref cursor=head_;

        if(cursor->item()==it){
            return true;
        }

        while(cursor->has_next()){
            cursor=cursor->next();

            if(cursor->item()==it){
                return true;
            }
        }

        return false;
    }

  /**
   * @brief Fold to an output stream.
   *
   * The format will be "[]" for the empty list or  '[' item1 item2 item3 ... item_n ']'
   * where item1 is the head.
   *
   * @param out is the output stream.
   * @return the output stream.
   */

    void fold(std::ostream& out) const
    {
        //TODO
        out<<"[";
        typename SNode<T>::Ref cursor=head_;

        if(cursor!=nullptr){
            out<<" "<<head_->item();

            while(cursor->has_next()){
                cursor=cursor->next();
                out<<" "<<cursor->item();
            }

            out<<" ";
        }

        out<<"]";
    }

  /**@}*/

  /** @name Modifiers*/

  /** @{*/

  /**
   * @brief Set a new value for current.
   * @param new_v is the new value.
   * @pre !is_empty()
   * @post item()==new_v
   */
  void set_current(T const& new_v)
  {
      assert(!is_empty());
      //TODO
      current_->set_item(new_v);

      assert(current()==new_v);
  }


  /**
   * @brief insert an item as the new list's head.
   * @param new_itf is the item to insert.
   * @post head()==new_it
   */
  void push_front(T const& new_it)
  {
      //TODO
      //typename SNode<T>::Ref nodo = SNode<T>::create(new_it, head);
      //head = nodo;
      typename SNode<T>::Ref node=SNode<T>::create(new_it, head_);
        if(current_==head_){
            current_=node;
        }

        head_=node;

      assert(front()==new_it);
  }


  /**
   * @brief insert a new item after current.
   * @param new_it is the item to insert.
   * @post old.is_empty() implies item()==head()==new_it
   * @post !old.is_empty() implies item()==old.item() && has_next() && next()==new_it
   */
  void insert(T const& new_it)
  {  //Importante
#ifndef NDEBUG
      auto old_is_empty = is_empty();
      T old_item;
      if (!old_is_empty)
          old_item = current ();
#endif

      //TODO
      if(is_empty()){
          push_front(new_it);
          previous_=nullptr;
          current_=head_;
      }

      else{
          typename SNode<T>::Ref nodo=SNode<T>::create(new_it, current_->next());
          current_->set_next(nodo);
      }
    
    assert(!old_is_empty || (front()==new_it && current()==new_it));
    assert(old_is_empty || (old_item == current() && has_next() && next()==new_it));
  }

  /**
   * @brief Remove the head.
   * @prec !is_empty()
   * @post is_empty() || head() == "next of old.head()".
   */
  void pop_front()
  {
      assert(!is_empty());
      //TODO
      if(current_==head_){
          current_=head_->next();
      }

      head_=head_->next();
      
  }


  /**
   * @brief Remove current item.
   * @pre !is_empty()
   * @post old.has_next() implies current()==old.next()
   * @post !old.has_next() implies is_empty() || current()=="old previous_ item."
   */
  void remove()
  {  //Importante
      assert(!is_empty());
#ifndef NDEBUG
      bool old_has_next = has_next();
      T old_next;
      if (has_next())
          old_next=next();
#endif

      //TODO:
      //Study three cases: remove from head, remove from last and
      //remove from middle.
      if(current_==head_){
          pop_front();
          previous_=nullptr;
          current_=head_;
      }

      else{
          if(current_->has_next()){
            previous_->set_next(current_->next());
            current_=current_->next();
          }

          else{
              find(previous_->item());
              current_->set_next(nullptr);
          }
      }

      assert(!old_has_next || current()==old_next);
  }

  /**
   * @brief Move the cursor to the next list's item.
   * @pre has_next()
   * @post old.next()==current()
   */
  void goto_next()
  {
      assert(has_next());      
#ifndef NDEBUG
      auto old_next = next();
#endif

      //TODO
      previous_=current_;
      current_=current_->next();

      assert(current()==old_next);
  }

  /**
   * @brief Move the cursor to the list's head.
   * @pre !is_empty()
   * @post current()==front()
   */
  void goto_first()
  {
      assert(!is_empty());
      //TODO
      previous_=nullptr;
      current_=head_;

      assert(current()==front());
  }

  /**
   * @brief Move the cursor to the first occurrence of a value from the head of the list.
   * If the item is not found, the cursor will be at the end of the list.
   * @param it is the value to be found.
   * @return true if it is found.
   * @pre !is_empty()
   * @post !ret_val || item()==it
   * @post ret_value || !has_next()
   */
  bool find(T const& it)
  {
      assert(!is_empty());
      bool found = false;
      //TODO
      previous_=nullptr;
      current_=head_;

      if(current_->item()==it) {
          found=true;
      }

      if(!found){
        while(current_->has_next()){
            previous_=current_;
            current_=current_->next();
            
            if(current_->item()==it){
                found=true;
                break;
            }
        }
      }

      assert(!found || current()==it);
      assert(found || !has_next());
      return found;
  }

  /**
   * @brief Move the cursor to the next occurrence of a value from current.
   * If the item is not found, the cursor will be at the end of the list.
   * @param it is the value to be found.
   * @return true if it is found.
   * @pre has_next()
   * @post !ret_val || item()==it
   * @post ret_value || !has_next()
   */
  bool find_next(T const& it)
  {
      assert(has_next());
      bool found = false;
      //TODO
      while (current_->has_next()){
        previous_=current_;
        current_=current_->next();

        if(current_->item()==it){
            found=true;
            break;
        }
      }

      assert(!found || current()==it);
      assert(found || !has_next());
      return found;
  }

  /** @}*/


protected:

  //TODO
  typename SNode<T>::Ref head_;
  typename SNode<T>::Ref current_;
  typename SNode<T>::Ref previous_;
};

#endif //ED_SList

