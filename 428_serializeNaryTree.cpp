/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        stringstream ss;
        serializeAux(root, ss);
        string ret = move(ss.str());
        return ret;
    }
    
    void serializeAux(Node* node, stringstream& ss) {
        ss << node->val << ',';
        for (auto child : node->children) {
            serializeAux(child, ss);
        }
        ss << "null" << ',';
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        string buffer;
        stringstream ss(data);
        getline(ss, buffer, ',');
        
        if (ss.fail()) {
            return nullptr;
        }
        int val = stol(buffer);
        Node* ret = deserializeAux(val, ss);
        return ret;
    }
    
    Node* deserializeAux(int val, stringstream& ss) {
        Node* node = new Node;
        node->val = val;
        
        string buffer;
        getline(ss, buffer, ',');
        while (!ss.fail() && isdigit(buffer[0])) {
            int child_val = stol(buffer);
            Node* child = deserializeAux(child_val, ss);
            node->children.push_back(child);
            getline(ss, buffer, ',');
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
