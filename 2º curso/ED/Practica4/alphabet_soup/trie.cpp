#include <cassert>
#include "trie.hpp"

#ifdef assert
//We undefined this macro to not shadow our implementation of assert.
#undef assert
#endif

/**
 * @brief Check an assertion.
 * In Debug mode, if the assertion is not met, a segfault is generated.
 * @param assertion
 */
inline void assert(bool assertion)
{
#ifndef NDEBUG
    (void)((assertion) || (__assert ("Assert violation!", __FILE__, __LINE__),0));
#endif
}


TrieNode::TrieNode ()
{
    //TODO
    //Hint: Do you need to do something?
    //No necesitamos hacer nada
};

TrieNode::Ref TrieNode::create()
{
    return std::make_shared<TrieNode>();
}

bool
TrieNode::has(char k) const
{
    bool ret_v = false;
    //TODO
    /*auto it=children_.find(k);
    if(it!=children_.end()){
        ret_v=true;
    }*/

    for(auto it=children_.begin(); it!=children_.end(); it++){
        if(it->first==k){
            ret_v=true;
        }
    }

    //
    return ret_v;
}

TrieNode::Ref
TrieNode::child(char k) const
{
    assert(has(k));
    TrieNode::Ref ret_v;
    //TODO
    auto aux=children_;
    ret_v=aux[k];

    //
    return ret_v;
}

std::string const&
TrieNode::value() const
{
    return value_;
}

const std::map<char, TrieNode::Ref> &TrieNode::children() const
{
    return children_;
}

void
TrieNode::set_value(std::string const& new_v)
{
    value_ = new_v;
}

void
TrieNode::insert(char k, Ref node)
{
    //TODO
    children_.insert(std::make_pair(k, node));
    //children_[k]=node;
    //children_.insert(std::pair<char, Ref>(k, node));

    //
}

Trie::Trie()
{
    //TODO
    //Hint: Do you need to do something?
    //No necesitamos hacer nada
}

Trie::Ref Trie::create()
{
    return std::make_shared<Trie>();
}

TrieNode::Ref Trie::root() const
{
    //TODO
    return root_;

    //return nullptr;
    //
}

bool
Trie::has(std::string const& k) const
{  //Importante
    bool found = false;
    //TODO
    //Remember: The Trie can have a prefix==k but does not store the key k.
    if(root_!=nullptr){
        auto node_auxiliar=find_node(k);
        found=(node_auxiliar!=nullptr) && (node_auxiliar->value().size()==k.size());
    }

    //
    return found;
}

std::vector<std::string>
Trie::keys(std::string const& pref) const
{  //Importante
    std::vector<std::string> keys;
    //TODO
    auto node=find_node(pref);
    if(node!=nullptr){
        preorder_traversal(node, keys);
    }

    //
    return keys;
}


void
Trie::insert(std::string const& k)
{  //Importante
    //TODO
    if(root_==nullptr){
        root_=TrieNode::create();
    }

    auto node=root_;
    for(unsigned int i = 0; i<k.size(); i++){
        if(node->has(k[i])){
            node=node->child(k[i]);
        }

        else{
            auto new_Node=TrieNode::create();
            node->insert(k[i], new_Node);
            node=new_Node;
        }
    }

    node->set_value(k);

    //
    assert(has(k));
}

TrieNode::Ref
Trie::find_node(std::string const& pref) const
{  //Importante
    TrieNode::Ref node;
    //TODO
    /*node=root_;
    for(unsigned int i = 0; i < pref.length(); i++){
        if(node->has(pref[i])){
            node=node->child(pref[i]);
        }

        else{
            return nullptr;
        }
    }*/
    node=root_;
    for (size_t i = 0; i < pref.length() && node->has(pref[i]); i++){
        node=node->child(pref[i]);
    }
    
    //
    return node;
}

void
Trie::preorder_traversal(TrieNode::Ref const& node,
                         std::vector<std::string> & keys) const
{
    //TODO
    if(node->value()!=""){
        keys.push_back(node->value());
    }

    for(auto it=node->children().begin(); it!=node->children().end(); it++){
        preorder_traversal(it->second, keys);
    }

    //
}
