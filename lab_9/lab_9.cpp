#include <iostream>
using namespace std;

class Tree {
private:
	int value;
	Tree* left;
	Tree* middle;
	Tree* right;
	static int count_elements;

public:
	Tree(int value) {
		this->left = NULL;
		this->middle = NULL;
		this->right = NULL;
		this->value = value;
	}

	static int SetCountElements() {
		int number = 0;
		bool date_is_not_number = true;
		while (date_is_not_number)
		{
			cin >> number;
			date_is_not_number = cin.fail();
			if (date_is_not_number)
			{
				cout << "Entered is not a number.\n";
				cout << "Enter number again: ";
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else {
				cin.ignore(32767, '\n');
				return number;
			}
		}

	}

	static void SetNaturalCountElements() {
		cout << "Enter count of elements: ";
		int entered_count = 0;
		bool number_is_not_natural = true;
		while (number_is_not_natural) {
			entered_count = SetCountElements();
			number_is_not_natural = (entered_count < 1);
			if (number_is_not_natural) {
				cout << "Number is not natural\n";
				cout << "Enter number again: ";
			}
		}
		count_elements = entered_count;
	}

	Tree* MakeElements(Tree* middle1, int N = count_elements) {
		if (N == 0) {
			return NULL;
		}
		N--;
		middle1->middle = NULL;
		if (N == 0) {
			middle1->left = NULL;
			middle1->right = NULL;
		}
		else {
			Tree* left = middle1->left = new Tree(2);
			left->left = NULL;
			left->right = NULL;
			N--;
			if (N == 0) {
				left->middle = NULL;
				middle1->right = NULL;
			}
			else {
				Tree* right = middle1->right = new Tree(3);
				right->left = NULL;
				right->right = NULL;
				N--;
				if (N == 0) {
					right->middle = NULL;
				}
				else {
					Tree* middle2 = left->middle = right->middle = new Tree(1);
					middle2->MakeElements(middle2, N);
				}
			}
			return middle1;
		}
	}

	void Show(Tree* middle)
	{
		if (middle != NULL) {
			cout << "          " << middle->value << endl;

			if (middle->left != NULL) {
				Tree* left = middle->left;
				cout << "     " << left->value;
			}
			if (middle->right != NULL) {
				Tree* right = middle->right;
				cout << "         " << right->value << endl;
				if (right->middle != NULL) {
					Show(right->middle);
				}
			}
		}
	}

	void FreeMemory(Tree* middle) {
		if (middle != NULL) {
			if (middle->left != NULL) {
				if (middle->right != NULL) {
					Tree* right = middle->right;
					if (right->middle != NULL) {
						FreeMemory(right->middle);
					}
					delete middle->right;
				}
				delete middle->left;
			}
			delete middle;
		}
	}
};

int Tree::count_elements = 0;

int main()
{
	Tree::SetNaturalCountElements();
	Tree* root = new Tree(1);
	root->MakeElements(root);
	root->Show(root);
	root->FreeMemory(root);
	return 0;
}


