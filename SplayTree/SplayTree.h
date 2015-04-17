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
Error_code ST_insert(Binary_node<Record>* &sub_root, const Record &new_data)
{
	Error_code result = success;

	return result;
}

template <class Record>
Error_code ST_delete(Binary_node<Record>* &sub_root, const Record &old_data)
{
	Error_code result = success;

	return result;
}

template <class Record>
Error_code ST_search(Binary_node<Record>* &sub_root, const Record &data)
{
	Error_code result = success;

	return result;
}

template <class Record>
Error_code ST_splay(Binary_node<Record>* &sub_root, const Record &data)
{
	Error_code result = success;

	return result;
}