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

class Solution
{
public:
    map<Node *, Node *> cloneMap;
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        if (cloneMap.find(node) == cloneMap.end())
        { // check if we created clone starting from given node
            cloneMap[node] = new Node(node->val, {});

            for (Node *adj : node->neighbors)
            {
                Node *neighborClone = cloneGraph(adj);
                cloneMap[node]->neighbors.push_back(neighborClone);
            }
        }

        return cloneMap[node];
    }
};