#pragma once

template <class T>
class BinaryTree
{
private:
	struct Node {
		Node* right = nullptr;
		Node* left = nullptr;
		Node* parent = nullptr;
		T key = T(0);
	};
	Node* tree = nullptr;
	int size = 0;

	Node* search(const T key) {
		Node* node = this->tree;
		while (node != nullptr) {
			if (key < node->key) {
				node = node->left;
			}
			else if (key > node->key) {
				node = node->right;
			}
			else return node;
		}
		return nullptr;
	}		

	void show(Node* node) {
		if (node == nullptr) return;
		if (node->left != nullptr) {
			show(node->left);
			std::cout << "\nleft: " << node->left->key << " <- parent " << node->left->parent->key;
		}
		if (node->right != nullptr) {
			show(node->right);
			std::cout << "\nright: " << node->right->key << " <- parent " << node->right->parent->key;;
		}
	}


	void Erase(Node* node) {
		Node* delet = search(node->key);


		if (delet->right == nullptr && delet->left == nullptr) {
			if (delet == this->tree) {
				delete delet;
				this->tree = nullptr;
			}
			else {
				if (delet->parent->right == delet)
					delet->parent->right = nullptr;
				else delet->parent->left = nullptr;
				delete delet;
			}
		}
		else if (delet->right == nullptr && delet->left != nullptr)
		{
			if (delet == this->tree) {
				delet->left->parent = nullptr;
				this->tree = delet->left;
			}
			else {
				if (delet->parent->left == delet) delet->parent->left = delet->left;
				else delet->parent->right = delet->left;
				delet->left->parent = delet->parent;

			}
			delete delet;
		}
		else if (delet->right != nullptr && delet->left == nullptr) {
			if (delet == this->tree) {
				delet->right->parent = nullptr;
				this->tree = delet->right;
			}
			else {
				if (delet->parent->left == delet) delet->parent->left = delet->right;
				else delet->parent->right = delet->right;
				delet->right->parent = delet->parent;
			}
			delete delet;
		}
		else if (delet->right != nullptr && delet->left != nullptr) {
			Node* node_ = delet;
			if (node_->right != nullptr) {
				node_ = node_->right;
				while (node_->left != nullptr) {
					node_ = node_->left;
				}
			}
			else if (node_->parent->left == node_) {
				node_ = node_->parent;
			}
			else node_ = nullptr;

			T tmp = delet->key;
			delet->key = node_->key;
			node_->key = tmp;
			this->Erase(node_);
			}
		else if (delet == nullptr) return;
	}


	void destructor(Node* node_ptr)
	{
		if (node_ptr == nullptr) return;

		if (node_ptr->left != nullptr)
		{
			destructor(node_ptr->left);
			delete node_ptr->left;
		}
		if (node_ptr->right != nullptr)
		{
			destructor(node_ptr->right);
			delete node_ptr->right;
		}
	}
public:
	BinaryTree(const T key) {
		this->tree = new Node;
		this->tree->key = key;
		this->size = 1;
	}

	T min() {
		if (this->tree == nullptr) return T(0);
		Node* node = this->tree;
		while (node->left != nullptr) {
			node = node->left;
		}
		return node->key;
	}
	T max() {
		Node* node = this->tree;
		if (this->tree == nullptr) {
			return T(0);
		}
		while (node->right != nullptr) {
			node = node->right;
		}
		return node->key;
	}

	int getSize() { return this->size; }

	void add(T key) {
		Node* node = this->tree;
		this->size++;
		if (this->tree == nullptr) {
			this->tree = new Node;
			this->tree->key = key;
			return;
		}
		while (node != nullptr) {
			if (key < node->key) {
				if (node->left != nullptr) {
					node = node->left;
				}
				else {
					node->left = new Node;
					node->left->key = key;
					node->left->parent = node;
					break;
				}
			}
			else {
				if (node->right != nullptr) {
					node = node->right;
				}
				else {
					node->right = new Node;
					node->right->key = key;
					node->right->parent = node;
					break;
				}
			}
		}
	}
	void erase(T key) {
		Node* delet = search(key);
		if (delet == nullptr) return;
		Erase(delet);
		this->size--;
	}
	void show()
	{
		if (this->tree == nullptr)  return; 
		show(this->tree);
	}
	

	bool exist(T elem) {
		if (search(elem) != nullptr) {
			return true;
		}
		else return false;
	}
	~BinaryTree() {
		destructor(this->tree);
		this->size = 0;
		delete this->tree;
	}
};
