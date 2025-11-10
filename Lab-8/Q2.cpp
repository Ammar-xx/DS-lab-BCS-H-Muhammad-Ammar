#include <iostream>
#include <string>
using namespace std;

struct Song {
    int playCount;
    string name;
    Song* left;
    Song* right;
    Song(int count, string n) : playCount(count), name(n), left(NULL), right(NULL) {}
};

Song* insert(Song* root, int count, string name) {
    if (!root) return new Song(count, name);
    if (count < root->playCount)
        root->left = insert(root->left, count, name);
    else if (count > root->playCount)
        root->right = insert(root->right, count, name);
    return root;
}

Song* search(Song* root, int count) {
    if (!root || root->playCount == count) return root;
    if (count < root->playCount) return search(root->left, count);
    return search(root->right, count);
}

void inorder(Song* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->name << " (" << root->playCount << " plays)" << endl;
    inorder(root->right);
}

void postorder(Song* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->name << " (" << root->playCount << " plays)" << endl;
}

Song* findMin(Song* root) {
    while (root && root->left) root = root->left;
    return root;
}

Song* deleteSong(Song* root, int count) {
    if (!root) return NULL;
    if (count < root->playCount)
        root->left = deleteSong(root->left, count);
    else if (count > root->playCount)
        root->right = deleteSong(root->right, count);
    else {
        if (!root->left && !root->right)
            return NULL;
        else if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        Song* temp = findMin(root->right);
        root->playCount = temp->playCount;
        root->name = temp->name;
        root->right = deleteSong(root->right, temp->playCount);
    }
    return root;
}

int main() {
    Song* root = NULL;
    root = insert(root, 50, "Song A");
    root = insert(root, 30, "Song B");
    root = insert(root, 70, "Song C");
    root = insert(root, 20, "Song D");
    root = insert(root, 40, "Song E");
    root = insert(root, 60, "Song F");
    root = insert(root, 80, "Song G");

    cout << "Inorder Traversal (Least to Most Played):\n";
    inorder(root);

    cout << "\nPostorder Traversal (Reverse Popularity Order):\n";
    postorder(root);

    int searchCount = 60;
    Song* found = search(root, searchCount);
    if (found)
        cout << "\nSong found: " << found->name << " (" << found->playCount << " plays)\n";
    else
        cout << "\nSong with " << searchCount << " plays not found.\n";

    cout << "\nDeleting Song with 30 plays...\n";
    root = deleteSong(root, 30);

    cout << "\nUpdated Inorder Traversal:\n";
    inorder(root);
}
