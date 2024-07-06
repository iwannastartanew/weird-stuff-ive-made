class TreeNode(var data: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}
TreeNode* insert(TreeNode* root, int val) {
    return root == nullptr ? new TreeNode(val) :
           val < root->data ? (root->left = insert(root->left, val)) :
           val > root->data ? (root->right = insert(root->right, val)) :
           root;
}
fun inorderTraversal(root: TreeNode?) {
    if (root != null) {
        inorderTraversal(root.left)
        print("${root.data} ")
        inorderTraversal(root.right)
    }
}
fun main() {
    var root: TreeNode? = null
    var nodeCount = 0
    val scanner = java.util.Scanner(System.`in`)
    var choice: Int

    do {
        print("Do you want to input a node? [1 for yes, 0 for no]: ")
        choice = scanner.nextInt()

        if (choice == 1) {
            print("Enter node ${++nodeCount}: ")
            val value = scanner.nextInt()
            root = insert(root, value)
        }
    } while (choice != 0)

    println("Alright, you're done inputting.")
    print("Now, the inorder traversal of the tree is: ")
    inorderTraversal(root)
    println()
}


*/


class TreeNode(var data: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

fun insert(root: TreeNode?, value: Int): TreeNode {
    return if (root == null) {
        TreeNode(value)
    } else if (value < root.data) {
        root.left = insert(root.left, value)
        root
    } else if (value > root.data) {
        root.right = insert(root.right, value)
        root
    } else {
        root
    }
}

fun inorderTraversal(root: TreeNode?) {
    if (root != null) {
        inorderTraversal(root.left)
        print("${root.data} ")
        inorderTraversal(root.right)
    }
}

fun main() {
    var root: TreeNode? = null
    var nodeCount = 0
    val scanner = java.util.Scanner(System.`in`)
    var choice: Int

    do {
        print("Do you want to input a node? [1 for yes, 0 for no]: ")
        choice = scanner.nextInt()

        if (choice == 1) {
            print("Enter node ${++nodeCount}: ")
            val value = scanner.nextInt()
            root = insert(root, value)
        }
    } while (choice != 0)

    println("Alright, you're done inputting.")
    print("Now, the inorder traversal of the tree is: ")
    inorderTraversal(root)
    println()



*/
