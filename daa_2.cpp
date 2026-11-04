#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int f;
    char c;
    Node *l, *r;

    Node(char ch, int fr): c(ch), f(fr) {};
    Node(char ch, int fr, Node* left, Node* right): c(ch), f(fr), l(left), r(right) {};
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

priority_queue<Node*, vector<Node*>, Compare> pq;

void build_tree()
{
    while (pq.size() > 1)
    {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();

        pq.push(new Node('?', (l->f + r->f), l, r));
    }

}

void disp_tree(Node* root, string code)
{
    if (root == NULL) return;

    if (root->l || root->r) {
        disp_tree(root->l, code + "0");
        disp_tree(root->r, code + "1");
    } else {
        cout << root->c << " : " << code << "\n";
    }
}

int main()
{
    int n = 0;

    cout << "Enter No. of characters: ";
    cin >> n;

    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        char c;
        int f;

        cin >> c >> f;
        pq.push(new Node(c, f));
    }

    build_tree();
    disp_tree(pq.top(), " ");

    return 0;
}

/*
Enter No. of characters: 5
Enter characters and their frequencies:
a 5
b 9
c 12
d 13
e 16
c :  00
d :  01
a :  100
b :  101
e :  11
*/