//
//  main.cpp
//  DataStructuresProject4ArrayBST
//
//  Created by Grant Higgins on 4/8/17.
//  Copyright © 2017 Grant Higgins. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstdlib>

using namespace::std;

template <class DT>
class ArrayBTNode
{
    friend ostream& operator<<(ostream& os, const ArrayBTNode<DT>& abt);//ostream operator
public:
    ArrayBTNode();//default constructor
    ArrayBTNode(const DT& info, const int& left, const int& right);//non-default constructor - starts with at least 3 nodes
    ArrayBTNode(const DT& info);//non-defualt constructor - starts with one node
    DT& getInfo();//returns info
    int getLeft();//returns left
    int getRight();//returns right
    void setInfo(const DT& info);//sets info
    void setLeft(const int& left);//sets left
    void setRight(const int& right);//sets right
    bool infoIsNull();//returns true if info is null
    void makeNull();//makes the node a null node
    bool operator>(const ArrayBTNode<DT>& abt);//greater than operator
    bool operator<(const ArrayBTNode<DT>& abt);//less than operator
    bool operator>=(const ArrayBTNode<DT>& abt);//greater than or equal to operator
    bool operator<=(const ArrayBTNode<DT>& abt);//less than or equal to operator
    bool operator==(const ArrayBTNode<DT>& abt);//equal to operator
    bool operator!=(const ArrayBTNode<DT>& abt);//not equal to operator
    void operator=(const ArrayBTNode<DT>& abt);//overloaded assignment operator
    virtual ~ArrayBTNode();//destructor
protected:
    DT* _info; //value within the node
    int _left; //index position where the left ArrayBTNode will be available
    int _right; //index position where the right ArrayBTNode will be available
};
template<class DT>
void ArrayBTNode<DT>::makeNull()
{
    _right = -1;
    _left = -1;
    _info = NULL;
}

template<class DT>
bool ArrayBTNode<DT>::infoIsNull()
{
    return (_info == NULL);
}

template<class DT>
ostream& operator<<(ostream& os, const ArrayBTNode<DT>& abt)
{
    cout << "Info: " << abt.getInfo() << endl << "Left: " << abt.getLeft() << endl << "Right: " << abt.getRight() << endl << endl;
    return os;
}

template<class DT>
void ArrayBTNode<DT>::operator=(const ArrayBTNode<DT>& abt)
{
    //deals with shallow copying
    this->_info = new DT(*abt._info);
    _left = abt._left;
    _right = abt._right;
}

template<class DT>
ArrayBTNode<DT>::ArrayBTNode()
{
    //set all values to null or equivilant
    _info = NULL;
    _left = -1;
    _right = -1;
}

template<class DT>
ArrayBTNode<DT>::ArrayBTNode(const DT& info, const int& left, const int& right)
{
    //set all values to values inputted
    _info = new DT(info);
    _left = left;
    _right = right;
}

template<class DT>
ArrayBTNode<DT>::ArrayBTNode(const DT& info)
{
    //set info to input and right and left inputs to -1
    _info = new DT(info);
    _left = -1;
    _right = -1;

}

template<class DT>
bool ArrayBTNode<DT>::operator!=(const ArrayBTNode<DT> &abt)
{
    return (*_info != abt._info);
}

template<class DT>
bool ArrayBTNode<DT>::operator==(const ArrayBTNode<DT> &abt)
{
    return (*_info == *(abt._info));
}

template<class DT>
bool ArrayBTNode<DT>::operator<=(const ArrayBTNode<DT> &abt)
{
    return (*_info <= *abt._info);
}

template<class DT>
bool ArrayBTNode<DT>::operator>=(const ArrayBTNode<DT> &abt)
{
    return (*_info >= *abt._info);
}

template<class DT>
bool ArrayBTNode<DT>::operator<(const ArrayBTNode<DT> &abt)
{
    return (*_info < *(abt._info));
}

template<class DT>
bool ArrayBTNode<DT>::operator>(const ArrayBTNode<DT> &abt)
{
    return (*_info > *(abt._info));
}

template<class DT>
DT& ArrayBTNode<DT>::getInfo()
{
    return *_info;
}

template<class DT>
int ArrayBTNode<DT>::getLeft()
{
    return _left;
}

template<class DT>
int ArrayBTNode<DT>::getRight()
{
    return _right;
}

template<class DT>
void ArrayBTNode<DT>::setInfo(const DT& info)
{
    _info = new DT(info);
}

template<class DT>
void ArrayBTNode<DT>::setLeft(const int &left)
{
    _left = left;
}

template<class DT>
void ArrayBTNode<DT>::setRight(const int &right)
{
    _right = right;
}

template<class DT>
ArrayBTNode<DT>::~ArrayBTNode()
{
    //just have to delete dynamically allocated members
    delete _info;
}

template <class DT>
class ArrayBT
{
    friend ostream& operator<<(ostream& os, const ArrayBT<DT>& abt);//ostream operator
public:
    ArrayBT();//default constructor for ArrayBT
    ArrayBT(int size);//constructor for ArrayBT with size
    int getRoot();//returns root's index position
    int getNumberOfNodes();//get number of nodes in binary tree
    int getSize();//get max size of the vector
    void setRoot(const int& root);//set index position of the root of the binary tree
    void setNumberOfNodes(const int& noNodes);//set the number of nodes
    bool isEmpty();//returns true if empty
    ArrayBTNode<DT>& getNode(int index);//gets node at index
    virtual ~ArrayBT();//destructor
protected:
    vector<ArrayBTNode<DT>*>* myBinaryTree; //array representing the binary tree
    int _root; //index position of the root
    int _noNodes; //the number of nodes in the binary tree
    int _size; //the maximum size of the vector
    stack<int> freeLocations; //stack of locations available for insertion
};

template<class DT>
ArrayBTNode<DT>& ArrayBT<DT>::getNode(int index)
{
    return *(myBinaryTree->at(index));
}

template<class DT>
ArrayBT<DT>::ArrayBT()
{
    //sets all parametrs to defualts
    _root = -1;
    _noNodes = 0;
    _size = 0;
}

template<class DT>
ArrayBT<DT>::ArrayBT(int size)
{
    _size = size;
    _root = -1;
    _noNodes = 0;
    myBinaryTree = new vector<ArrayBTNode<DT>*> (size);
    freeLocations = stack<int>();
    for (int i = 0; i < size; i++)
    {
        freeLocations.push(i);
        myBinaryTree->at(i) = new ArrayBTNode<DT>();
    }
}

template<class DT>
bool ArrayBT<DT>::isEmpty()
{
    //if root == null then there hasnt been a node added
    return (_root == NULL);
}

template<class DT>
int ArrayBT<DT>::getRoot()
{
    return _root;
}

template<class DT>
int ArrayBT<DT>::getNumberOfNodes()
{
    return _noNodes;
}

template<class DT>
int ArrayBT<DT>::getSize()
{
    return _size;
}

template<class DT>
void ArrayBT<DT>::setRoot(const int& root)
{
    _root = root;
}

template<class DT>
void ArrayBT<DT>::setNumberOfNodes(const int &noNodes)
{
    _noNodes = noNodes;
}

template<class DT>
ArrayBT<DT>::~ArrayBT()
{
    myBinaryTree->clear();
    delete myBinaryTree;
    stack<int> ().swap(freeLocations);//swaps free locations with empty stack effectively deallocating mem
}

template<class DT>
class ArrayBST : virtual public ArrayBT<DT>
{
    friend ostream& operator<<(ostream& s, const ArrayBST<DT>& abst);
public:
    ArrayBST();//default constructor for ArrayBST
    ArrayBST(int size);//constructor for arraybst with specific size
    void displayRaw();//prints raw info of arraybst
    int find(int value);//returns index locaiton of value or -1 if it ant be found
    void insert(int toAdd);//adds a node to the tree
    void remove(int toRemove);//removes a node from the tree
    void inorderTraversal();//prints an inorder traversal
    void preorderTraversal();//prints a preorder traversal
    virtual ~ArrayBST();//destructor
    void inorderTraversal(int rootIndex);//recursive inorder
    int findForInsert(int value);//a find method to help me allocate from stack effectively in insert
};

template<class DT>
ostream& operator<<(ostream& s, const ArrayBST<DT>& abst)
{
    abst.inorderTraversal();
    abst.preorderTraversal();
    return s;
}

template<class DT>
ArrayBST<DT>::ArrayBST()
: ArrayBT<DT>()
{
    //no new elements here so no statements needed
}

template<class DT>
ArrayBST<DT>::ArrayBST(int size)
: ArrayBT<DT>(size)
{
    //no new elements so no statements needed
}

template<class DT>
void ArrayBST<DT>::displayRaw()
{
    vector<ArrayBTNode<DT>*>* bt = ArrayBT<DT>::myBinaryTree;
    int currentIndex = ArrayBT<DT>::_root;
    //checks that the array isnt empty
    if (ArrayBT<DT>::_root == -1 || bt->at(ArrayBT<DT>::_root)->infoIsNull())
    {
        cout << "No nodes to print" << endl << endl;
        return;
    }
    stack<int> preorder;
    preorder.push(ArrayBT<DT>::_root);//stack is to loop through all existing nodes
    //print position, info, left, right in array for rows with content
    while (!preorder.empty())
    {

        ArrayBTNode<DT>* node = bt->at(preorder.top());
        currentIndex = preorder.top();
        cout << "Position: " << currentIndex << " Info: " << bt->at(currentIndex)->getInfo() << " Left: " << bt->at(currentIndex)->getLeft() << " Right: " << bt->at(currentIndex)->getRight() << endl;
        preorder.pop();
        if (node->getRight() != -1 && !(bt->at(node->getRight())->infoIsNull()))
        {
            preorder.push(node->getRight());
        }
        if (node->getLeft() != -1 && !(bt->at(node->getLeft())->infoIsNull()))
        {
            preorder.push(node->getLeft());
        }

    }

    //print content of stack
    cout << "Contents of free locations stack: " << endl << endl;
    stack<int> s;
    while (!ArrayBT<DT>::freeLocations.empty())
    {
        int i = ArrayBT<DT>::freeLocations.top();
        cout << i << endl;
        s.push(i);
        ArrayBT<DT>::freeLocations.pop();
    }
    ArrayBT<DT>::freeLocations = s;
}

//to help me fix problem with allocating left and right from stack
template<class DT>
int ArrayBST<DT>::findForInsert(int value)
{
    int currentIndex = ArrayBT<DT>::getRoot();
    int prevIndex = currentIndex;
    while (true)
    {
        if (currentIndex == -1)
        {
            return prevIndex;
        }
        if (ArrayBT<DT>::myBinaryTree->at(currentIndex)->infoIsNull())
        {
            return prevIndex;
        }
        else if (*(ArrayBT<DT>::myBinaryTree->at(currentIndex)) < value)
        {
            prevIndex = currentIndex;
            currentIndex = ArrayBT<DT>::myBinaryTree->at(currentIndex)->getRight();
        }
        else if (*(ArrayBT<DT>::myBinaryTree->at(currentIndex)) > value)
        {
            prevIndex = currentIndex;
            currentIndex = ArrayBT<DT>::myBinaryTree->at(currentIndex)->getLeft();
        }
        else
        {
            return currentIndex;
        }
    }
}

template<class DT>
int ArrayBST<DT>::find(int value)
{
    int currentIndex = ArrayBT<DT>::getRoot();
    while (true)
    {
        if (currentIndex == -1)
        {
            return -1;
        }
        if (ArrayBT<DT>::myBinaryTree->at(currentIndex)->infoIsNull())
        {
            return currentIndex;
        }
        else if (*(ArrayBT<DT>::myBinaryTree->at(currentIndex)) < value)
        {
            currentIndex = ArrayBT<DT>::myBinaryTree->at(currentIndex)->getRight();
        }
        else if (*(ArrayBT<DT>::myBinaryTree->at(currentIndex)) > value)
        {
            currentIndex = ArrayBT<DT>::myBinaryTree->at(currentIndex)->getLeft();
        }
        else
        {
            return currentIndex;
        }
    }
}

template<class DT>
void ArrayBST<DT>::insert(int toAdd)
{
    //get index from find and add to it or
    //replace current value if it already exists
    if (ArrayBT<DT>::_noNodes == ArrayBT<DT>::_size)
    {
        cout << "array is full" << endl;
        return;
    }
    if (ArrayBT<DT>::_noNodes == 0)
    {
        //if there are no arrays assign root left and right from stack of locs
        ArrayBT<DT>::_root = ArrayBT<DT>::freeLocations.top();
        ArrayBT<DT>::freeLocations.pop();
        ArrayBT<DT>::myBinaryTree->at(ArrayBT<DT>::_root) = new ArrayBTNode<DT>(toAdd);
        ArrayBT<DT>::_noNodes++;
        return;
    }
    int bstIndex = find(toAdd);
    int prevIndex = findForInsert(toAdd);
    if (prevIndex == -1)
    {
        cout << "couldn't add to tree while keeping logic" << endl;
        return;
    }
    if (bstIndex == -1 || ArrayBT<DT>::myBinaryTree->at(bstIndex)->infoIsNull())
    {
        if (ArrayBT<DT>::freeLocations.empty())
        {
            cout << "no empty locations remaining" << endl;
            return;
        }
        if (ArrayBT<DT>::myBinaryTree->at(prevIndex)->getInfo() > toAdd)
        {
            int left = ArrayBT<DT>::freeLocations.top();
            //add node to left of prevIndex
            ArrayBT<DT>::myBinaryTree->at(prevIndex)->setLeft(left);
            ArrayBT<DT>::freeLocations.pop();
            ArrayBT<DT>::myBinaryTree->at(left) = new ArrayBTNode<DT>(toAdd);
        }
        else if (ArrayBT<DT>::myBinaryTree->at(prevIndex)->getInfo() < toAdd)
        {
            int right = ArrayBT<DT>::freeLocations.top();
            //add node to right of prevIndex
            ArrayBT<DT>::myBinaryTree->at(prevIndex)->setRight(right);
            ArrayBT<DT>::freeLocations.pop();
            ArrayBT<DT>::myBinaryTree->at(right) = new ArrayBTNode<DT>(toAdd);
        }
    }
    else
    {
        int right = ArrayBT<DT>::myBinaryTree->at(bstIndex)->getRight();
        int left = ArrayBT<DT>::myBinaryTree->at(bstIndex)->getLeft();
        delete ArrayBT<DT>::myBinaryTree->at(bstIndex);
        ArrayBT<DT>::myBinaryTree->at(bstIndex) = new ArrayBTNode<DT>(toAdd, left, right);
    }
    ArrayBT<DT>::_noNodes++;
}

template<class DT>
void ArrayBST<DT>::remove(int toRemove)
{
    //check whether the value you are trying to remove exists
    int indexToRemove = find(toRemove);
    if (ArrayBT<DT>::_noNodes == 0)
    {
        cout << "There are no nodes to remove" << endl;
        return;
    }
    if (indexToRemove == -1)
    {
        cout << "cannot find value you are attempting to remove" << endl;
        return;
    }
    vector<ArrayBTNode<DT>*>* bt = ArrayBT<DT>::myBinaryTree;
    //if the node exists - deal with the 3 seperate scenarios
    int left = bt->at(indexToRemove)->getLeft();
    int right = bt->at(indexToRemove)->getRight();
    if (left == -1 || bt->at(left)->infoIsNull())
    {
        //if left doesnt exist
        if (right == -1)
        {
            //right node doesnt exist
            bt->at(indexToRemove)->makeNull();
            ArrayBT<DT>::_noNodes--;
            return;
        }
        ArrayBTNode<DT>* rightNode = bt->at(right);
        ArrayBT<DT>::freeLocations.push(right);
        ArrayBT<DT>::freeLocations.push(left);
        *bt->at(indexToRemove) = *rightNode;
        bt->at(right)->makeNull();
    }
    else if (right == -1 || bt->at(right)->infoIsNull())
    {
        //if right doesnt exist
        ArrayBTNode<DT>* leftNode = bt->at(left);
        if (right != -1)
        {
            ArrayBT<DT>::freeLocations.push(right);
        }
        ArrayBT<DT>::freeLocations.push(left);
        *bt->at(indexToRemove) = *leftNode;
        bt->at(left)->makeNull();
    }
    else
    {
        //both trees non empty
        ArrayBTNode<DT>* workingNode = bt->at(right);
        int leftWorking = workingNode->getLeft();
        while (!(leftWorking == -1 || bt->at(leftWorking)->infoIsNull()))
        {
            leftWorking = workingNode->getLeft();
            workingNode = bt->at(leftWorking);
        }
        bt->at(indexToRemove)->setInfo(workingNode->getInfo());
        int rightWorking = workingNode->getRight();
        if (rightWorking == -1 || bt->at(rightWorking)->infoIsNull())
        {
            workingNode->makeNull();
        }
        else
        {
            ArrayBTNode<DT>* veryTempNode = bt->at(rightWorking);
            *workingNode = *veryTempNode;
            veryTempNode->makeNull();
        }

    }
    ArrayBT<DT>::_noNodes--;

}

//seems to be the working class
template<class DT>
void ArrayBST<DT>::inorderTraversal(int rootIndex)
{
    if(rootIndex != -1 && !ArrayBT<DT>::myBinaryTree->at(rootIndex)->infoIsNull())
    {
        inorderTraversal(ArrayBT<DT>::myBinaryTree->at(rootIndex)->getLeft());
        cout << "Info: " << ArrayBT<DT>::myBinaryTree->at(rootIndex)->getInfo() << endl << "Left: " << ArrayBT<DT>::myBinaryTree->at(rootIndex)->getLeft() << endl << "Right: " << ArrayBT<DT>::myBinaryTree->at(rootIndex)->getRight() << endl << endl;
        inorderTraversal(ArrayBT<DT>::myBinaryTree->at(rootIndex)->getRight());
    }
}

template<class DT>
void ArrayBST<DT>::inorderTraversal()
{
    cout << "Inorder Traversal" << endl << endl;
    //push root
    stack<int> s;
    vector<ArrayBTNode<DT>*>* bt = ArrayBT<DT>::myBinaryTree;
    //overloading keeps program safe from possible out of bounds exception
    if (ArrayBT<DT>::_root == -1 || bt->at(ArrayBT<DT>::_root)->infoIsNull())
    {
        cout << "There are no nodes in the tree" << endl << endl;
        return;
    }
    s.push(ArrayBT<DT>::_root);
    //push to bottom left
    ArrayBTNode<DT>* node = bt->at(s.top());
    while (node->getLeft() != -1 && !bt->at(node->getLeft())->infoIsNull())
    {
        s.push(node->getLeft());
        node = bt->at(node->getLeft());
    }
    bool skip = false;
    //while s has elements: pop and push, push right of popped, and push to bottom left of popped
    while (!s.empty())
    {
        node = bt->at(s.top());
        cout << "Info: " << node->getInfo() << endl << "Left: " << node->getLeft() << endl << "Right: " << node->getRight() << endl << endl;
        if (s.top() == ArrayBT<DT>::_root)
        {
            skip = true;
        }
        s.pop();
        if (node->getRight() != -1 && !(bt->at(node->getRight())->infoIsNull()))
            {
                s.push(node->getRight());
            }
        if (!skip)
        {
            while (node->getLeft() != -1 && !bt->at(node->getLeft())->infoIsNull())
            {
                s.push(node->getLeft());
                node = bt->at(node->getLeft());
            }
        }
        skip = false;

    }
}

template<class DT>
void ArrayBST<DT>::preorderTraversal()
{
    cout << "Preorder Traversal" << endl << endl;
    //push root
    stack<int> s;
    vector<ArrayBTNode<DT>*>* bt = ArrayBT<DT>::myBinaryTree;
    //overloading keeps program safe from possible out of bounds exception
    if (ArrayBT<DT>::_noNodes == 0)
    {
        cout << "There are no nodes in the tree" << endl << endl;
        return;
    }
    s.push(ArrayBT<DT>::_root);
    //while s has elements pop and print, check right then push, then check left then push
    while (!s.empty())
    {
        ArrayBTNode<DT>* node = bt->at(s.top());
        cout << "Info: " << node->getInfo() << endl << "Left: " << node->getLeft() << endl << "Right: " << node->getRight() << endl << endl;

        s.pop();
        if (node->getRight() != -1 && !(bt->at(node->getRight())->infoIsNull()))
        {
            s.push(node->getRight());
        }
        if (node->getLeft() != -1 && !(bt->at(node->getLeft())->infoIsNull()))
        {
            s.push(node->getLeft());
        }
    }
}

template<class DT>
ArrayBST<DT>::~ArrayBST()
{
    ArrayBT<DT>::myBinaryTree->clear();//deallocates mem for all objects in vector
    delete ArrayBT<DT>::myBinaryTree;//deletes vector
    stack<int> ().swap(ArrayBT<DT>::freeLocations);//swaps free locations with empty stack effectively deallocating mem

}

int main()
{
    int size;
    char command;
    int value;
    cin >> size;
    ArrayBST<int> abst = ArrayBST<int>(size);
    //input a list of commands and values - O gives you inorder and preoreder traversals,
    //a gives you a raw display of the data, r and a value removes a value, f and a value attempts
    //to find a value, andI and a value inserts a value
    while(!cin.eof())
    {
        cin >> command;
        if (command == 'O')
        {
            //print tree using ostream operator
            //xcode was giving me issues and saying that
            //i hadent defined the ostream operator
            //this code is essentially copy pasted from there and I
            //beg mercy for my workaround to a problem that I believe is not my problem
            cout << "Inorder Traversal" << endl << endl;
            abst.inorderTraversal(abst.getRoot());
            abst.preorderTraversal();
            cin.clear();
        }
        else if (command =='A')
        {
            //print tree using raw display
            abst.displayRaw();
            cin.clear();

        }
        else
        {
            cin >> value;
            if (command =='R')
            {
                //r for remove
                abst.remove(value);
                cin.clear();

            }
            if (command == 'F')
            {
                //f for find
                int index = abst.find(value);
                if (index == -1)
                {
                    cout << "value not found" << endl;
                }
                else if (abst.getNode(index).infoIsNull())
                {
                    cout << "value not found" << endl;
                }
                else
                {
                    cout << "Found " << value << " at index " << abst.find(value) << endl;
                }
                cin.clear();

            }
            if (command == 'I')
            {
                //i for insert
                abst.insert(value);
                cin.clear();

            }
        }
    }
}
