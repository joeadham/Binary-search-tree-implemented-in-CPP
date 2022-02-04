#include <iostream>
#include "my_tree.h"

using namespace std;

int main(int argc, char** argv){


    int elementsNum,opNum;
    cin >> elementsNum >> opNum;

    vector<int> elements;

    for (int i = 0; i < elementsNum; ++i) {
        int x;
        cin>>x;
        elements.push_back(x);
    }
    MyTree<int> tree(elements);



    while(opNum--)
    {
        int opType;
        cin>>opType;
        if(opType == 1)
        {
            int element;
            cin>>element;
            tree.insert(element);
        }
        else if(opType == 2)
        {
            int element;
            cin>>element;
            cout << (tree.search(element) ? "1 " : "0") << endl;
        }
        else if(opType == 3)
        {
            int secondOperation;
            cin>>secondOperation;
            if(secondOperation == 1) tree.inorder_rec();
            else tree.inorder_it();
            cout <<endl;
        }
        else if(opType == 4)
        {
            int secondOperation;
            cin>>secondOperation;
            if(secondOperation == 1) tree.preorder_rec();
            else tree.preorder_it();
            cout <<endl;

        }
        else if(opType == 5)
        {
            int secondOperation;
            cin>>secondOperation;
            if(secondOperation == 1) tree.postorder_rec();
            else tree.postorder_it();
            cout <<endl;

        }
        else if (opType == 6)
        {
            tree.breadth_traversal();
            cout <<endl;

        }
        else
        {
            cout << tree.size() << ' ' << '\n';

        }
    }



//


//7 8
//6 7 3 4 2 1 5
//3 1
//3 2
//4 1
//4 1
//5 1
//5 3
//6
//7

//3 3
//2 3 1
//1 4
//7
//3 1


}