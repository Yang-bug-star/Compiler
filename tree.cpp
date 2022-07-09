#include "tree.h"


TreeNode::TreeNode(string name):name(name),row(yyrow),col(yycol){}

TreeNode::TreeNode(string name, string val):TreeNode(name){
    this->val = val;
}

TreeNode::TreeNode(string name,int num,...):TreeNode(name){
    va_list valist;

    va_start(valist,num);

    if(num > 0){
        TreeNode *temp = va_arg(valist, TreeNode*);
        this->first_child = temp;
        this->val = "";
        if(num > 1){
            while(--num){
                TreeNode *next = va_arg(valist,TreeNode*);
                temp->right_neighbor = next;
                temp = next;
            }
        }
        this->col = first_child->col;
        this->row = first_child->row;
    }
}

void TreeNode::save_json(string path){
    ofstream fout;
    fout.open(path);
    traverse(this, fout);
    fout.close();
}


void TreeNode::traverse(TreeNode *node, ofstream &fout){
    fout << "{";
    fout << "\"name\":\"" << node->name << "\",";
    fout << "\"val\":\"" << node->val << "\",";
    fout << "\"row\":" << to_string(node->row) << ",";
    fout << "\"col\":" << to_string(node->col) << ",";
    fout << "\"children\":[";
    if(node->first_child){
        traverse(node->first_child, fout);
    }
    fout << "]";
    fout << "}";
    if(node->right_neighbor){
        fout << ",";
        traverse(node->right_neighbor, fout);
    }
}

