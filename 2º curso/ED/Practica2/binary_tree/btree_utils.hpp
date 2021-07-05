#ifndef __ED_BTree_Utils_HPP__
#define __ED_BTree_Utils_HPP__

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
#include "btree.hpp"
#include <queue>

/**
 * @brief Compute the height of a tree.
 * The tree's height is the longitude of the longest branch connecting the root
 * node with a leaf node, or -1 if the tree was empty.
 *
 * @param t is the tree.
 * @return the tree's height or -1 if it is a empty tree.
 * @pre t->is_empty() == false
 */
template<class T>
int compute_height (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    int ret_val = -1;

    //TODO
    if(not t->is_empty()){
    	auto left = t->left();
    	auto maxleft_subtree = -1;

    	if(left->is_empty()==false){
    		maxleft_subtree = compute_height<T>(left);
        }

    	auto right = t->right();

    	auto maxright_subtree = -1;

    	if(right->is_empty()==false){
    		maxright_subtree = compute_height<T>(right);
        }

    	if(maxleft_subtree>maxright_subtree){
    		ret_val = maxleft_subtree + 1;
        }
    	else{
    		ret_val = maxright_subtree + 1;
        }

    }

    return ret_val;
}

/**
 * @brief Compute the number of nodes in the tree.
 *
 * @param t is the tree.
 * @return the number of nodes in the tree.
 * @pre t->is_empty() == false
 * @post t->is_empty() and ret_val==0
 * @post !t->is_empty() and ret_val>0
 */
template<class T>
size_t compute_size (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    size_t ret_val = 0;


    //TODO

    if(t->is_empty()==false){
  		ret_val += 1;
  		auto left = t->left();

  		if(left->is_empty()==false){
      		ret_val += compute_size<T>(t->left());
  		}

      	auto right = t->right();

      	if(right->is_empty()==false){
  			ret_val += compute_size<T>(t->right());
      	}
  	}

    assert(!t->is_empty() || ret_val==0);
    assert(t->is_empty() || ret_val>0);
    return ret_val;
}

/**
 * @brief Prefix processing of a binary tree
 * The template class Processor must have an closure interface:
 *
 * bool Processor::operator()(T const& item).
 *
 * that makes something with item and returning true when the processing must
 * continue or false to stop it.
 *
 * A lambda expression can be used too.
 *
 * @return true if all nodes were processed.
 * @pre tree->is_empty() == false
 */
template <class T>
struct Processor
{
	bool operator()(T const& value)
	{
		std::cout << value << " ";
		return true;
	}
};
template <class T, typename Processor>
bool
prefix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;

    //TODO
    if(tree->is_empty()==false){
    	retVal = p(tree->item());

    	auto left = tree->left();

	    if(left->is_empty()==false){
	    	retVal = retVal && prefix_process<T>(left,p);
        }

	   	auto right = tree->right();

	    if(right->is_empty()==false){
	    	retVal = retVal && prefix_process<T>(right,p);
        }
    }



    return retVal;
}

/**
 * @brief Infix processing of a binary tree.
 * The template class Processor must have an apply interface:
 *
 * bool Processor::operator()(T const& item).
 *
 * that makes something with item and returning true when the processing must
 * continue or false to stop it.
 *
 * A lambda expression can be used too.
 *
 * @return true if all nodes were processed.
 * @pre tree->is_empty() == false
 */
template <class T, class Processor>
bool
infix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;

    //TODO
    if(tree->is_empty()==false){
    	auto left = tree->left();

	    if(left->is_empty()==false){
	    	retVal = infix_process<T>(left,p);
        }

	    retVal = retVal && p(tree->item());

	   	auto right = tree->right();

	    if(right->is_empty()==false){
	    	retVal = retVal && infix_process<T>(right,p);
        }
    }

    return retVal;
}

/**
 * @brief Postfix processing of a binary tree.
 * The template class Processor must have an apply interface:
 *
 * bool Processor::operator()(T const& item).
 *
 * that makes something with item and returning true when the processing must
 * continue or false to stop it.
 *
 * A lambda expression can be used too.
 *
 * @return true if all nodes were processed.
 * @pre tree->is_empty() == false
 */
template <class T, class Processor>
bool
postfix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;

    //TODO
    if(tree->is_empty()==false){
    	auto left = tree->left();

	    if(left->is_empty()==false){
	    	retVal = postfix_process<T>(left,p);
        }

	   	auto right = tree->right();

	    if(right->is_empty()==false){
	    	retVal = retVal && postfix_process<T>(right,p);
        }

	    retVal = retVal && p(tree->item());
    }

    return retVal;
}


/**
 * @brief Bread-first processing of a btree.
 * The template class Processor must have an apply interface:
 *
 * bool Processor::operator()(T const& item).
 *
 * that makes something with item and returning true when the processing must
 * continue or false to stop it.
 *
 * A lambda expression can be used too.
 *
 * @return true if all nodes were processed.
 * @pre tree->is_empty() == false
 */
template <class T, class Processor>
bool
breadth_first_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool ret_val = true;

    //TODO
    //Hint: may be you need to use std::queue
    std::queue <typename BTree<T>::Ref> queu;

    queu.push(tree);

    while(not queu.empty() and ret_val){
    	auto subtree = queu.front();

    	if(subtree->is_empty()==false){
    		ret_val = ret_val && p(subtree->item());
   			queu.push(subtree->left());
   			queu.push(subtree->right());
    	}

    	queu.pop();
    }

    return ret_val;
}

/**
 * @brief Check is a binary tree is in order.
 * A binary tree is in order whether it is the empty tree or
 * when for each subtree, the root node is greater than all its proper left
 * descendants and less than all its proper right descendants.
 *
 * @param tree is the tree to be checked.
 * @return true if the input tree is in order.
 */
template<class T>
bool check_btree_in_order(typename BTree<T>::Ref const& tree)
{
    bool ret_val = true;

    //TODO
    if(tree->is_empty()==false){
        auto left_sub=tree->left();

        if(!left_sub->is_empty()){
            T max_value = tree->item();

            auto pp = [&max_value](T item){
                return item < max_value;
            };

            bool result = breadth_first_process<T>(left_sub,pp);

            if(result==false){
                return false;
            }

            ret_val = ret_val && check_btree_in_order<T>(left_sub);
        }

        auto right_sub=tree->right();

        if(!right_sub->is_empty()){
            T min_value = tree->item();

            auto p = [&min_value](T item){
                return item > min_value;
            };

            bool result = breadth_first_process<T>(right_sub,p);

            if(result==false){
                return false;
            }

            ret_val = ret_val && check_btree_in_order<T>(right_sub);
        }
    }
    

    return ret_val;
}

/**
 * @brief Search a item into the tree.
 *
 * The input tree must be in order, a optimized search process can be used.
 *
 * @param tree is a in order binary tree.
 * @param v is the value to be found.
 * @pre check_btree_in_order(tree)
 * @return true if the value is in the tree.
 */
template<class T>
bool has_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));
    bool ret_val = false;

    //TODO
    if(tree->is_empty()==false){
    	if(v<tree->item()){
    		auto l_subtree = tree->left();

    		if(l_subtree->is_empty()==false){
    			ret_val = has_in_order<T>(l_subtree,v);
            }
    	}

    	else if(v>tree->item()){
    		auto r_subtree = tree->right();

    		if(r_subtree->is_empty()==false){
    			ret_val = has_in_order<T>(r_subtree,v);
            }
    	}

    	else{
    		ret_val = true;
    	}
    }
    //
    return ret_val;
}

/**
 * @brief Insert in orde a value intro a binary tree.
 * @see check_btree_in_order to know what is mean this.
 * If the value is already in tree, nothing is inserted.
 *
 * @param tree is the tree where inserting.
 * @param v is the value to be inserted.
 *
 * @pre check_btree_in_order(tree)
 * @post has_in_order(tree, v)
 */
template <class T>
void insert_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));

    //std::cout << "insertando el " << v << std::endl;

    //TODO
    if(tree->is_empty()){
    	tree->create_root(v);
    }

    else if(v<tree->item()){
    	if(tree->left()->is_empty()){
    		auto left = BTree<T>::create();
    		left->create_root(v);
    		tree->set_left(left);	
    	}

    	else{
    		auto right = tree->left();
    		insert_in_order<T>(right,v);
    		tree->set_left(right);
    	}
    }

    else if(v>tree->item()){
    	if(tree->right()->is_empty())
    	{
    		auto right = BTree<T>::create();
    		right->create_root(v);
    		tree->set_right(right);	
    	}

    	else{
    		auto right = tree->right();
    		insert_in_order<T>(right,v);
    		tree->set_right(right);
    	}
    }
    //
   assert(has_in_order<T>(tree, v));
}



#endif
