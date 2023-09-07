/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        ostringstream out;
        encode(root, out);
        return out.str();
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        istringstream in(data);
        return decode(in);
        
    }
    
private:
    
    void encode( TreeNode* node, ostringstream& out ) {
        
        if ( !node ) {
            out << "N ";
            return;
        }
        
        out << node->val << " ";
        
        encode( node->left, out );
        encode( node->right, out );
        
    }
    
    TreeNode* decode( istringstream& in ) {
        
        string s = "";
        in >> s;
        
        if ( s == "N" ) return nullptr;
        
        TreeNode* ret = new TreeNode( stoi( s ) );
        
        ret->left = decode( in );
        ret->right = decode( in );
        
        return ret;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));