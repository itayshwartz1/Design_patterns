#include <iostream>
#include "list"


class TreeNode{
public:
    virtual int interprete() = 0;
};

class Leaf : public TreeNode{
public:
    int num;
    Leaf(int num) : num(num){}
    int interprete() override{
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
    int interprete() override{
        return left->interprete() + right->interprete();
    }
};

class SubNode : public BinaryNode {
public:
    SubNode(TreeNode *left, TreeNode *right) : BinaryNode(left, right) {}
    int interprete() override{
        return left->interprete() - right->interprete();
    }
};

class MultNode : public BinaryNode {
public:
    MultNode(TreeNode *left, TreeNode *right) : BinaryNode(left, right) {}
    int interprete() override{
        return left->interprete() * right->interprete();
    }
};

class DivNode : public BinaryNode {
public:
    DivNode(TreeNode *left, TreeNode *right) : BinaryNode(left, right) {}
    int interprete() override{
        return left->interprete() / right->interprete();
    }
};

int main(){
    TreeNode * treeNode = new MultNode(new AddNode(new Leaf(1), new Leaf(7)),
                                       new DivNode(new Leaf(4), new SubNode(new Leaf(3), new Leaf(1))));
    std::cout << treeNode->interprete();
    return 0;
}

//(1+7) * (4/(3-1)) = 16

