#include "BTTH2.h"
int main() {
	cout << "Danh sach lien ket" << endl;
	cout << "*******************" << endl;
	cout << "Nhap so phan tu muon tao: ";
	int n; cin >> n;
	/*List_SV list;
	for (int i = 0; i < n; i++) {
		cout << "Nhap ho ten: ";
		string a; cin.ignore(); getline(cin, a);
		cout << "Nhap mssv";
		string b; cin >> b;
		cout << "Nhap diem: ";
		double c; cin >> c;
		list.Add_to_head(a,b,c);
	}
	cout << "nhap mssv muon chen: ";
	string d; cin >> d;
	list.Add("tan", "123", 6, d);
	cout << "danh sach sinh vien" << endl;
	list.Xuat();*/
	ArrStack stack;
	stack.changeBinary(164);
	stack.xuatStack();
	system("pause");
	return 0;
}
