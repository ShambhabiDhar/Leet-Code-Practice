/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr, unordered_map<Node*, Node*> &mpp){
        vector<Node*> neighbour;
        Node* clone = new Node(curr->val);
        mpp[curr]=clone;
        for(auto it:curr->neighbors){
            if(mpp.find(it)!=mpp.end()){
                neighbour.push_back(mpp[it]);
            }
            else{
                neighbour.push_back(dfs(it,mpp));
            }
        }
        clone->neighbors=neighbour;
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mpp;
        if(node==nullptr){
            return nullptr;
        }
        if(node->neighbors.size()==0){ //only one node, no neighbours
            Node* clone = new Node(node->val);
            return clone;
        } 
        return dfs(node,mpp);
    }
};