实现了二叉树的遍历，包括：

- **递归**实现前序遍历
- **递归**实现中序遍历
- **递归**实现后序遍历
- **非递归**实现前序遍历
- **非递归**实现中序遍历
- **非递归**实现后序遍历
- 层次遍历
- 每层分开的层次遍历

## 递归实现
其中递归实现的前、中、后序遍历比较简单。

以递归实现的后序遍历为例：

```c++
void post_order_traverse_recursive(Node* root) {
	if(root == nullptr)
		return;
	post_order_traverse_recursive(root->left);
	post_order_traverse_recursive(root->right);
	cout << root->val << " "; // visit
}
```

只有一点需要注意的是,别忘了递归终止的条件

## 非递归实现

非递归实现中，前序和中序比较简单，也非常类似。对于每个节点，都是先一直向左遍历入栈，直到遇到空指针，然后回溯到上个节点，对该节点右孩子重复执行这个操作。

```c++
void in_order_traverse_non_recursive(Node* root) {
	stack<Node*> s;
	Node* p = root;
	while(p || !s.empty()) {
		while(p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		cout << p->val << " ";
		p = p->right;
	}
}
```

非递归实现的后序遍历就稍微麻烦一点，需要从右孩子返回后再处理，此时需要记录上次访问的节点，判断上次访问节点是不是右孩子。

```c++
void post_order_traverse_non_recursive(Node* root) {
	stack<Node*> s;
	Node* p = root;
	Node* last_visit_node = root;
	while(p || !s.empty()) {
		while(p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		if(p->right == nullptr || p->right == last_visit_node) {
                        // 从右孩子返回（或者没有右孩子）时，访问该节点
			cout << p->val << " ";
                        // 访问后，记录访问，并出栈
			last_visit_node = p;
			p = nullptr;
			s.pop();
		} else {
			p = p->right;
		}
	}
}
```

## 层次遍历

层次遍历比较容易理解，不断将左右孩子加入队列，直到队列为空。

需要注意的是区分层次遍历中每一层的方式：利用队列的长度。

```c++
void level_traverse_seperate(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		int len = q.size();
		for(int i = 0;i < len;i++) {
			Node* p = q.front();
			q.pop();
			cout << p->val << " ";
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
		}
		cout << " | ";
	}
}
```
