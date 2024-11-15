The process of deletion of a node from binary tree involves the searching of the nodein the binary tree and deleting it. The search process is handled by a function search(); which receives the address of the root node the number to be searched, address of parent node and the address of the node to be deleted . If the no. to be deleted is found the address of the node to be deleted and its parent nodes address is returned beck The function also retums 1/0 indicating the status of found/ not found of the node to be deleted is not found into 3 Parts:
deletion process. If the node to be deleted terminated is found then the process of deletion is divided into 3 parts:

    1)Delete a node with 2 child.
    2)Delete a node with 0 child.
    3)Delete a node with 1 child.
