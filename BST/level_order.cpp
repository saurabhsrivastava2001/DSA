#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node * left;
        node * right;

       node(int d){
        this-> data=d;
        this->left=NULL;
        this->right=NULL;
       } 
};
node * build_tree(node * root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    if (data==-1){
        return NULL;
    }
    root=new node (data);
    cout<<"enter the data for left of " <<data<<endl;
    root->left=build_tree(root->left);
    cout<<"enter the data for right of " <<data<<endl;
    root->right=build_tree(root->right);
    return root;

}
vector<vector<int>> level_order(node * root){
    vector<vector <int >> ans;
    queue <node *> q;
    if (root==NULL){
        return ans;
    }
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector <int > level;
        for (int i=0;i<size;i++){ 
            node * curr=q.front();
            q.pop();
            if (curr->left)q.push(curr->left); 
            if (curr->right)q.push(curr->right);
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    return ans;

}
void print(vector <vector<int>> v){
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    node * root=NULL;
    //1 2 -1 3 -1 -1 4 5 -1 6 -1 -1 -1 
    root=build_tree(root);
    vector<vector<int>> v =level_order(root);
    print(v);
}