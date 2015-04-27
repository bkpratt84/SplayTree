template <class Record>
class SplayTree : public Search_tree<Record> {

public:
	Error_code insert(const Record &new_data);
	Error_code remove(const Record &old_data);
	Error_code search(const Record &data);
protected:
	//  Auxiliary functions
	Error_code ST_insert(Binary_node<Record>* &sub_root, const Record &new_data);
	Error_code ST_delete(Binary_node<Record>* &sub_root, const Record &old_data);
	Error_code ST_search(Binary_node<Record>* &sub_root, const Record &data);
	Error_code ST_splay(Binary_node<Record>* &sub_root, const Record &data);

	void rotate_left(Binary_node<Record>* &sub_root);
	void rotate_right(Binary_node<Record>* &sub_root);
};

template <class Record>
Error_code SplayTree<Record>::insert(const Record &new_data) {
	return ST_insert(this->root, new_data);
}

template <class Record>
Error_code SplayTree<Record>::remove(const Record &old_data) {
	return ST_delete(this->root, old_data);
}

template <class Record>
Error_code SplayTree<Record>::search(const Record &data) {
	return ST_search(this->root, data);
}

template <class Record>
Error_code SplayTree<Record>::ST_insert(Binary_node<Record>* &sub_root, const Record &new_data)
{
	Error_code result = success;

	if (sub_root == NULL) {
		sub_root = new SplayTree_node<Record>(new_data);
	} else if (new_data < sub_root->data) {
		result = ST_insert(sub_root->left, new_data);
	} else if (new_data > sub_root->data) {
		result = ST_insert(sub_root->right, new_data);
	}

	if (result == success) {
		result = ST_splay(sub_root, new_data);


		Binary_node<Record> *p_node = NULL;

		if (new_data < sub_root->data) {
			p_node->left = sub_root->left;
			p_node->right = sub_root;
			sub_root->left = NULL;
			sub_root = p_node;
		} else if (new_data > sub_root->data) {
			p_node->right = sub_root->right;
			p_node->left = sub_root;
			sub_root->right = NULL;
			sub_root = p_node;
		}

		p_node = NULL;
	}

	return result;
}

template <class Record>
Error_code SplayTree<Record>::ST_delete(Binary_node<Record>* &sub_root, const Record &data) {
	Error_code result = success;
	Binary_node<Record> *newTree;

	result = ST_splay(sub_root, data);
	if (sub_root == NULL)
		result = tree_empty;
	else if (sub_root->data != data)
		result = not_present;
	else {
		if (sub_root->left == NULL)
			newTree = sub_root->right;
		else {
			newTree = sub_root->left;
			result = ST_splay(newTree, data);
			newTree->right = sub_root->right;
		}

		delete sub_root;
		sub_root = newTree;
	}
	return result;
}

template <class Record>
Error_code SplayTree<Record>::ST_search(Binary_node<Record>* &sub_root, const Record &data) {
	Error_code result;

	result = ST_splay(sub_root, data);

	return result;
}

template <class Record>
Error_code SplayTree<Record>::ST_splay(Binary_node<Record>* &sub_root, const Record &data) {
	Error_code result = success;

	if (sub_root == NULL)
		result = tree_empty;
	else {
		Binary_node<Record> header;

		header.left = header.right = NULL;

		Binary_node<Record> *left_tree = &header;
		Binary_node<Record> *right_tree = &header;

		while (true) {
			if (data < sub_root->data) {
				if (sub_root->left == NULL)
					break;
				if (data < sub_root->left->data) {
					rotate_right(sub_root);

					if (sub_root->left == NULL)
						break;
				}

				right_tree->left = sub_root;
				right_tree = right_tree->left;
				sub_root = sub_root->left;
				right_tree->left = NULL;
			}
			else if (data > sub_root->data) {
				if (sub_root->right == NULL)
					break;
				if (data > sub_root->right->data) {
					rotate_left(sub_root);

					if (sub_root->right == NULL)
						break;
				}

				left_tree->right = sub_root;
				left_tree = left_tree->right;
				sub_root = sub_root->right;
				left_tree->right = NULL;
			} else
				break;
		}

		left_tree->right = sub_root->left;
		right_tree->left = sub_root->right;
		sub_root->left = header.right;
		sub_root->right = header.left;
	}

	return result;
}

template <class Record>
void SplayTree<Record>::rotate_left(Binary_node<Record>* &sub_root) {
	Binary_node<Record> *right_tree = sub_root->right;
	sub_root->right = right_tree->left;
	right_tree->left = sub_root;
	sub_root = right_tree;
}

template <class Record>
void SplayTree<Record>::rotate_right(Binary_node<Record>* &sub_root) {
	Binary_node<Record> *left_tree = sub_root->left;
	sub_root->left = left_tree->right;
	left_tree->right = sub_root;
	sub_root = left_tree;
}