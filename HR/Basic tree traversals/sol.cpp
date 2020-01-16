#include <bits/stdc++.h>
using namespace std;

void preOrder(int node, vector<char> &letters, vector<vector<int>> &tree) {
    cout<<letters[node]<<' ';
    if (tree[node][0]!=-1)
        preOrder(tree[node][0],letters,tree);
    if (tree[node][1]!=-1)
        preOrder(tree[node][1],letters,tree);
}

void inOrder(int node, vector<char> &letters, vector<vector<int>> &tree) {
    if (tree[node][0]!=-1)
        inOrder(tree[node][0],letters,tree);
    cout<<letters[node]<<' ';
    if (tree[node][1]!=-1)
        inOrder(tree[node][1],letters,tree);
}

void postOrder(int node, vector<char> &letters, vector<vector<int>> &tree) {
    if (tree[node][0]!=-1)
        postOrder(tree[node][0],letters,tree);
    if (tree[node][1]!=-1)
        postOrder(tree[node][1],letters,tree);
    cout<<letters[node]<<' ';
}

void levelOrder(int r, vector<char> &letters, vector<vector<int>> &tree) {
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        int node = q.front();
        cout<<letters[node]<<' ';
        if (tree[node][0]!=-1) q.push(tree[node][0]);
        if (tree[node][1]!=-1) q.push(tree[node][1]);
        q.pop();
    }
}

int main() {
    int t; cin>>t;
    while (t--) {
        int n,r; cin>>n>>r;
        vector<char> letters(n+1);
        vector<vector<int>> tree(n+1,vector<int>(2,-1));
        for (int i=1; i<n+1; i++)
            cin>>letters[i];
        for (int i=1; i<n+1; i++) {
            string left, right; cin>>left>>right;
            if (left!="-") {tree[i][0] = stoi(left);}
            if (right!="-") {tree[i][1] = stoi(right);}
        }

        preOrder(r,letters,tree);
        cout << endl;
        inOrder(r,letters,tree);
        cout << endl;
        postOrder(r,letters,tree);
        cout << endl;
        levelOrder(r,letters,tree);
        cout << endl;
    }

    return 0;
}
