#include"bt1.h"
#include "bt2.h"
int main() {
	/*cout << "***********************";
	cout << "1.BT1\n";
	cout << "2.BT2\n";
	cout << "0.ket thuc";
	cout << "Nhap bai tap muon xem: ";*/
	BinaryTree tree;
	for (int i = 0; i < 5; i++) {
		int a; cin >> a;
		tree.them_ds(tree.root,a);
	}
	cout << "Nhap gia tri can tim: "; int x; cin >> x; cout << endl;
	cout << tree.Xoa(tree.root, x);
	system("pause");
	return 0;
}
