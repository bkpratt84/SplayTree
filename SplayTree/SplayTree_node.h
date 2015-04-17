template <class Record>
struct SplayTree_node : public Binary_node<Record> {
	SplayTree_node();
	SplayTree_node(const Record &x);
};

template <class Record>
SplayTree_node<Record>::SplayTree_node() :Binary_node<Record>(){
	balance = equal_height; // The balance factor is initailized to be equal_height
}

template <class Record>
SplayTree_node<Record>::SplayTree_node(const Record &x) :Binary_node<Record>(x){
	balance = equal_height; // The balance factor is initailized to be equal_height
}