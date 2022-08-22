// Interpreter design pattern is one of the behavioral design pattern. Interpreter pattern is used to defines a
// grammatical representation for a language and provides an interpreter to deal with this grammar.

#include <iostream>
#include "list"

class TreeNode{
public:
    virtual int interpret() = 0;
};

class Leaf : public TreeNode{
public:
    int num;
    Leaf(int num) : num(num){}
    int interpret() override{
        return num;
    }
};

class BinaryNode : public TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    BinaryNode(TreeNode* left, TreeNode* right): left(left), right(right){}
};

class AddNode : public BinaryNode {
public:
    AddNode(TreeNode *left, TreeNode *right) : BinaryNode(left, right) {}
    int interpret() override{
        return left->interpret() + right->interpret();
    }
};

class SubNode : public BinaryNode {
public:
    SubNode(TreeNode *left, TreeNode *right) : BinaryNode(left, right) {}
    int interpret() override{
        return left->interpret() - right->interpret();
    }
};

class MultNode : public BinaryNode {
public:
    MultNode(TreeNode *left, TreeNode *right) : BinaryNode(left, right) {}
    int interpret() override{
        return left->interpret() * right->interpret();
    }
};

class DivNode : public BinaryNode {
public:
    DivNode(TreeNode *left, TreeNode *right) : BinaryNode(left, right) {}
    int interpret() override{
        return left->interpret() / right->interpret();
    }
};

int main(){
    // (1+7) * (4/(3-1)) = 16
    TreeNode * treeNode = new MultNode(new AddNode(new Leaf(1), new Leaf(7)),
                                       new DivNode(new Leaf(4), new SubNode(new Leaf(3), new Leaf(1))));
    std::cout << treeNode->interpret() << std::endl;
    return 0;
}
