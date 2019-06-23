#include "BasicTree.h"
#include <queue>
#include <cstdio>
using namespace std;

class val_not_found{};

BasicTree::BasicTree() : root{nullptr} {}
BasicTree::BasicTree(int i) : root{new Node(i)} {}

BasicTree::~BasicTree()
{
    destructorRecursive(root);
}

void BasicTree::insert(int val)
{
    
    if(root == nullptr)
    {
        //cout << "HELLO" << endl;
        root = new Node(val);
    }

    else
    {
        //cout << "HEY" << endl;
        Node *curr = root;
        Node *parent = nullptr;

        while(curr != nullptr)
        {
            parent = curr;

            if(val < curr->data) 
                curr = curr->left;
            else
                curr = curr->right;
        }

        if(val < parent->data)
        {
            parent->left = new Node(val);
            curr = parent->left;
            curr->parent = parent;
        }

        else
        {
            parent->right = new Node(val);
            curr = parent->right;
            curr->parent = parent;
        }
    }
}

ostream& BasicTree::in_order(Node *n, ostream &os)
{
    // 1. Traverse the left subtree by visiting node to the left of the current node.
    
    if (n->left != nullptr) 
        in_order(n->left, os);

    // 2. Visit the current node; insert its value to the stream.

    os << n->data << " ";

    // 3. Traverse the right subtree by visiting node to the right of the current node.

    if (n->right != nullptr) 
        in_order(n->right, os);

    // 4. Return the stream
    
    return os;

}

ostream& BasicTree::post_order(Node *n, ostream &os)
{
    // 1. Traverse the left subtree by visiting node to the left of the current node.

    if (n->left != nullptr)
        post_order(n->left, os);

    // 2. Traverse the right subtree by visiting the node to the right of the current node.

    if (n->right != nullptr)
        post_order(n->right, os);

    // 3. Visit the current node; insert its value to the stream.

    os << n->data << " ";

    // 4. Return the stream

    return os;

}

ostream& BasicTree::pre_order(Node *n, ostream &os)
{
    // 1. Visit the current node; insert its value to the stream.

    os << n->data << " ";

    // 2. Traverse the left subtree by visiting node to the left of the current node.

    if (n->left != nullptr)
        pre_order(n->left, os);

    // 3. Traverse the right subtree by visiting the node to the right of the current node.

    if (n->right != nullptr)
        pre_order(n->right, os);

    // 4. Return the stream

    return os;

}

int const& BasicTree::find(int val) {

    Node* curr = root;

    while(curr != nullptr)
    {
        if(curr->data == val)
            return curr->data;
        else if(curr->data > val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    throw val_not_found();
}

void BasicTree::destructorRecursive(Node* n)
{
    if(n)
    {
        destructorRecursive(n->left);
        destructorRecursive(n->right);
        delete n;
    }
}

///////////////////////////////////////////////////////////////////////////////
// operator<< support
///////////////////////////////////////////////////////////////////////////////
stringstream& BasicTree::to_sstream(Node *n, int depth, string s, stringstream& os) const
{
    if (n==nullptr) {
        os << "Empty" << endl;
        return os;
    }
    os << "("<<n->data<<") Address: " << n << " Parent: " << n->parent << "\n";
    os << s << " `--[L]";
    s += " |  ";
    if (n->left)
        to_sstream(n->left, depth + 1, s, os);
    else
        os <<"nullptr\n";
    s.erase(s.end() - 4, s.end());

    os << s << " `--[R]";
    s += "    ";
    if (n->right)
        to_sstream(n->right, depth + 1, s, os);
    else
        os <<"nullptr\n";
    s.erase(s.end() - 4, s.end());
    return os;
}

ostream& operator<<(ostream& os, BasicTree const& bt)
{
    os << bt.to_str();
    return os;
}