/*	
 problem:
 clone a connected graph:
 1) given a ?  
*/
#include <stdio.h>

class Node {
    int value;
    Node* left;
    Node* right;
};

class ListNode{
    int value;
    Node* next;
};

class GraphNode{
    int value;
    vector<GraphNode*> links;
};


class Solution {
public:
  Node* copyBinaryTree(Node* root){
    if (root) {
        Node* node = new Node(root->value);
        node->left = copyBinaryTree(root->left);
        node->right = copyBinaryTree(root->right);   
        return node;
    }
    else return NULL;
  }

  ListNode* copyLinkedList(ListNode* head){
    if (root) {
        ListNode* node = new ListNode(head->value);
        node->next = copyLinkedList(root->next);
        return node;
    }
    else return NULL;
  }

  GraphNode* copyGraph(GraphNode* root){
    if (root) {
        GraphNode* node = new GraphNode(root->value);
        for (int i=0; i<links.size(); i++) {
            node->links->pushback(copyGraph(links[i]));
        }
        return node;
    }
    else return NULL;
  }
};

int main()
{

}

