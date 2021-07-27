#include <iostream>
#include <iomanip>

/*forward declaration*/
template <class T>
class Queue;

template <class T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data,Node* lt=nullptr,Node* rt=nullptr){
			data_=data;
			left_=lt;
			right_=rt;
		}
	};
	Node* root_;

	void printPreOrder(Node* subroot)const{
		if(subroot){
			std::cout << subroot->data_ << " ";		
			printPreOrder(subroot->left_);
			printPreOrder(subroot->right_);
		}
	}
	void printInOrder(Node* subroot)const{
		if(subroot){
			printInOrder(subroot->left_);
			std::cout << subroot->data_ << " ";
			printInOrder(subroot->right_);
		}
	}
	void destroy(Node* subroot){
		if(subroot){
			destroy(subroot->left_);
			destroy(subroot->right_);
			delete subroot;
		}
	}
	
	bool isSame(const Node* left, const Node* right) const;

	/*used by print() to print all nodes at same level*/
	void printLine(Node* data[],int numNodes,int width) const{
		int half=width/2;
		int firsthalf=width%2?half+1:half;

		if(numNodes > 1){
			for(int i=0;i<numNodes;i++){
				if(i%2==0){
					if(data[i]){
						std::cout << std::right <<std::setfill(' ') << std::setw(firsthalf)<< "-";
						std::cout << std::left << std::setfill('-') << std::setw(half) << "-";
					}
					else{
						std::cout << std::right <<std::setfill(' ') << std::setw(firsthalf)<< " ";
						std::cout << std::left << std::setfill(' ') << std::setw(half) << " ";
					}
				}
				else{
					if(data[i]){
						std::cout << std::right << std::setfill('-') << std::setw(firsthalf) << "-";
						std::cout << std::left <<std::setfill(' ') << std::setw(half)<<"-";
					}
					else{
						std::cout << std::right << std::setfill(' ') << std::setw(firsthalf) << " ";
						std::cout << std::left <<std::setfill(' ') << std::setw(half)<<" ";
					}
				}
			}
			std::cout << std::endl;
		}
		for(int i=0;i<numNodes;i++){
			if(data[i]){
				if(i%2==0){
					std::cout << std::right << std::setw(firsthalf) << "|";
					std::cout << std::left <<std::setfill(' ') << std::setw(half)<<" ";
				}
				else{
					std::cout << std::right << std::setfill(' ') << std::setw(firsthalf) << " ";
					std::cout << std::left <<std::setfill(' ') << std::setw(half)<< "|";				
				}
			}
			else{
				std::cout << std::left <<std::setfill(' ') << std::setw(width)<<" ";			
			}
		}
		std::cout << std::endl;		
		for(int i=0;i<numNodes;i++){
			if(data[i]){
				if(i%2==0){
					std::cout << std::right << std::setw(firsthalf) << data[i]->data_;
					std::cout << std::left <<std::setfill(' ') << std::setw(half)<<" ";
				}
				else{
					std::cout << std::right << std::setfill(' ') << std::setw(firsthalf) << " ";
					std::cout << std::left <<std::setfill(' ') << std::setw(half)<< data[i]->data_;				
				}
			}
			else{
				std::cout << std::left <<std::setfill(' ') << std::setw(width)<<" ";			
			}
		}
		std::cout << std::endl;

	}


public:
	BST(){
		root_=nullptr;
	}
	BST(const BST& rhs){
		  root_=NULL;
          copy(rhs.root_);
   }
   void copy(Node * N)
{
     if(N)
     {
         insert(N->data_);
         copy(N->left_);
         copy(N->right_);
     }
}

// void remove(const T& data){

// 		Node* curr=root_;
// 			bool found = false;
// 			if(root_->data_ == data){
			
// 				Node *temp = curr;
//         		curr = curr->left_ ? curr->left_ : curr->right_;
//         		delete temp;
// 				root_ = nullptr;
// 			}else{
// 				while (curr && !found)
// 				{
// 				if(data==curr->data_){
				
//                 found=true;
// 				Node *temp = curr;
// 				if(curr == root_){
// 				if(curr->left_ != nullptr){

// 				if(curr == root_){
// 					root_ = curr->left_;
// 				}


// 				Node *temp1 = curr->left_;}
// 				if(curr->right_ != nullptr){
// 				if(curr == root_){
// 					root_ = curr->left_;
// 				}
// 				Node *temp2 = curr->right_;
// 				}
//         		curr = curr->right_ ? curr->right_ : curr->left_;
//         		delete temp;
// 				}
				
				
				
				
// 				else{
// 					if(curr->left_ != nullptr){

// 				if(curr == root_){
// 					root_ = curr->left_;
// 				}
// 				Node *temp1 = curr->left_;}
// 				if(curr->right_ != nullptr){
// 				if(curr == root_){
// 					root_ = curr->left_;
// 				}
// 				Node *temp2 = curr->right_;
// 				}
//         		curr = curr->right_ ? curr->right_ : curr->left_;
//         		delete temp;
// 				}
//             		}
//             		else if(data < curr->data_){
//                		 curr=curr->left_;
//             		}
//             		else{
//                		 curr=curr->right_;
//             		}
// 				}
// 			}
// 	}
Node *parent = NULL;
	Node *current;

	void remove(const T &data)
	 {
	// 	Delete(root_, data);
	deleteNode(root_,data);
	}





void searchKey(Node* &curr, int key, Node* &parent)
{
    while (curr != nullptr && curr->data_ != key)
    {
        parent = curr;
        if (key < curr->data_) {
            curr = curr->left_;
        }
        else {
            curr = curr->right_;
        }
    }
}




void deleteNode(Node*& root, const T &key)
{
    Node* parent = nullptr;
    Node* curr = root;
    searchKey(curr, key, parent);
    if (curr == nullptr) {
        return;
    }
    if (curr->left_ == nullptr && curr->right_ == nullptr)
    {
        if (curr != root)
        {
            if (parent->left_ == curr) {
                parent->left_ = nullptr;
            }
            else {
                parent->right_ = nullptr;
            }
        }
        else {
            root = nullptr;
        }
        delete curr;
    }
    else if (curr->left_ && curr->right_)
    {
        // find its inorder successor node
        Node* successor = getMinimumKey(curr->right_);
        int val = successor->data_;
        deleteNode(root, successor->data_);
        curr->data_ = val;
    }
    else {
        Node* child = (curr->left_)? curr->left_: curr->right_;
        if (curr != root)
        {
            if (curr == parent->left_) {
                parent->left_ = child;
            }
            else {
                parent->right_ = child;
            }
        }
        else {
            root = child;
        }
        delete curr;
    }
}

Node* getMinimumKey(Node* curr)
{
    while (curr->left_ != nullptr) {
        curr = curr->left_;
    }
    return curr;
}



















// 	Node* Delete(struct Node *root, int data) {
// 	if(root == NULL) return root; 
// 	else if(data < root->data_) root->left_ = Delete(root->left_,data);
// 	else if (data > root->data_) root->right_ = Delete(root->right_,data);
// 	// Wohoo... I found you, Get ready to be deleted	
// 	else {
// 		// Case 1:  No child
// 		if(root->left_ == NULL && root->right_ == NULL) { 
// 			delete root;
// 			root = NULL;
// 		}
// 		//Case 2: One child 
// 		else if(root->left_ == NULL) {
// 			 Node *temp = root;
// 			root = root->right_;
// 			delete temp;
// 		}
// 		else if(root->right_ == NULL) {
// 			 Node *temp = root;
// 			root = root->left_;
// 			delete temp;
// 		}
// 		// case 3: 2 children
// 		else { 
// 			Node *temp = FindMin(root->right_);
// 			root->data_ = temp->data_;
// 			root->right_ = Delete(root->right_,temp->data_);
// 		}
// 	}
// 	return root;
// }
Node* FindMin(Node* root)
{
	while(root->left_ != NULL) root = root->left_;
	return root;
}
		// Node *curr = root_;
		// if (search(data) == NULL)
		// {
		// 	return;
		// }
		// Node *toDelete = current;
		// if(parent == NULL){
		// 	root_ = toDelete;
		// }
		// else{
		// 	if (parent->right_ == toDelete){
		// 		parent->right_ = toDelete->right_;
		// 	}
		// 	else if(parent->left_ == toDelete){
		// 		parent->left_ = toDelete->right_;
		// 	}
		// }

		// if(toDelete->left_ == NULL){
		// 	return;
		// }

		// search(toDelete->left_->data_);
		// if(toDelete->left_->data_ < parent->data_){
		// 	parent->left_ = toDelete->left_;
		// }
		// else if(toDelete->left_->data_ > parent->data_){
		// 	parent->right_ = toDelete->left_;
		// }
	//}

	Node *search(const T &data)
	{
		parent = NULL;
		current = root_;
		while (current != NULL && current->data_ != data)
		{
			if (data < current->data_)
			{
				parent = current;
				current = current->left_;
			}
			else
			{
				parent = current;
				current = current->right_;
			}
		}
		return current;
	}


	int depth(const T& data){
		if(root_ == nullptr){
			return -1;
		}else{
			Node* curr=root_;
			bool found = false;
			int x =-1;
			if(root_->data_ == data){
				return 0;
			}else{
				while (curr && !found)
				{
				if(data==curr->data_){
					x++;
                found=true;
            }
            else if(data < curr->data_){
                curr=curr->left_;
				x++;
            }
            else{
                curr=curr->right_;
				x++;
            }
				}
				if(found == false)
				{return -1;}
			return x;

			}
		}
	}


	void printPreOrder() const{
		printPreOrder(root_);
		std::cout << std::endl;
	}
	void printInOrder() const{
		printInOrder(root_);
		std::cout << std::endl;
	}


	void insert(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{

			Node* curr=root_;
			while(curr != nullptr){
				if(data < curr->data_){
					//go left
					if(curr->left_){
						curr=curr->left_;
					}
					else{
						curr->left_=new Node(data);
						curr=nullptr;
					}
				}	
				else{
					//go right
					if(curr->right_){
						curr=curr->right_;
					}
					else{
						curr->right_=new Node(data);
						curr=nullptr;
					}
				}
			}

		}

	}

	bool operator==(const BST& rhs) const;
	void print() const{
		struct Output{
			Node* node_;
			int lvl_;
			int position_;
			Output(Node* n=nullptr,int l=0, int p=0){
				node_=n;
				lvl_=l;
				position_=p;
			}
			void set(Node* n=nullptr,int l=0, int p=0){
				node_=n;
				lvl_=l;
				position_=p;
			}
		};
		Queue<Output> theNodes;
		Node* line[16];
		if(root_){
			for(int i=0;i<16;i++){
				line[i]=nullptr;
			}
			theNodes.enqueue(Output(root_,0,0));
			int currline=0;
			int width=80;
			int numInLine=1;
			while(theNodes.isEmpty()==false){
				Output curr=theNodes.front();
				if(curr.node_->left_)
					theNodes.enqueue(Output(curr.node_->left_,curr.lvl_+1,curr.position_*2));
				if(curr.node_->right_)
					theNodes.enqueue(Output(curr.node_->right_,curr.lvl_+1,curr.position_*2+1));
				theNodes.dequeue();


				if(curr.lvl_>currline){
					printLine(line,numInLine,width);
					width=width/2;
					numInLine=numInLine*2;
					for(int i=0;i<16;i++){
						line[i]=nullptr;
					}
					currline++;

				}
				line[curr.position_]=curr.node_;
			}
			printLine(line,numInLine,width);
			std::cout << std::endl;

		}
		else{
			std::cout << "tree is empty" << std::endl;
		}
	}
	~BST(){
		destroy(root_);
	}
};

template <class T>
class Queue{
	T* theQueue_;
	int capacity_;
	int used_;
	int front_;
	int back_;
	void grow(){
		T* tmp=new T[capacity_*2];
		int j;
		for(int i=0,j=front_;i<used_;i++,j=(j+1)%capacity_){
			tmp[i]=theQueue_[j];
		}
		delete [] theQueue_;
		theQueue_=tmp;
		capacity_=capacity_*2;
		front_=0;
		back_=used_;
	}
public:
	Queue(){
		theQueue_=new T[50];
		capacity_=50;
		used_=0;
		front_=0;
		back_=0;
	}
	void enqueue(const T& data){
		if(used_==capacity_){
			grow();
		}
		theQueue_[back_]=data;
		back_=(back_+1)%capacity_;
		used_++;
	}
	void dequeue(){
		if(!isEmpty()){
			used_--;
			front_=(front_+1)%capacity_;
		}
	}
	T front() const{
		if(!isEmpty()){
			return theQueue_[front_];
		}
		return T{};

	}
	bool isEmpty() const{
		return used_==0;
	}
	~Queue(){
		delete [] theQueue_;
	}	
};
