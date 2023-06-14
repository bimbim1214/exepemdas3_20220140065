#include <iostream>
#include <vector>
using namespace std;

class pengarang;
class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) :nama(pNama) {
		cout << "penerbit \"" << nama << "\" ada\n";
	}
	~penerbit() {
		cout << "penerbit \"" << nama << "\" tidak ada\n";
	}
	void tambahpengarang(pengarang*);
	void cetakpengarang();
	

};

class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	
	pengarang(string pNama) :nama(pNama) {
		cout << "pengarang \"" << nama << "\" ada\n";
	}
	~pengarang() {
		cout << "pengarang \"" << nama << "\" tidak ada\n";
	}
	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
};

void penerbit::tambahpengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}
void penerbit::cetakpengarang() {
	cout << "daftar pengarang yang menaungi penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void pengarang::tambahpenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->tambahpengarang(this);
}

void pengarang::cetakpenerbit() {
	cout << "daftar penerbit yang dikuti pengarang \"" << this->nama << "\":";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;

}

class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	buku(string pNama) :nama(pNama) {
		cout << "pengarang \"" << nama << "\" ada\n";
	}
	~buku() {
		cout << "pengarang \"" << nama << "\" tidak ada\n";
	}
	void tambahpengarang(pengarang*);
	void cetakpengarang();
}
void buku::tambahpengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
	pPengarang->tambahbuku(this->nama);

};

int main() {
	pengarang* verpengarang = new pengarang("joko");
	pengarang* verpengarang = new pengarang("lia");
	pengarang* verpengarang = new pengarang("giga");
	pengarang* verpengarang = new pengarang("asroni");
	pengarang* verpengarang = new pengarang("giga");
	penerbit* verpenerbit1 = new penerbit("Gama Press");
	penerbit* verpenerbit2 = new penerbit("Intan Pariwara");

	varpengarang->tambahpenerbit(varpenerbit1);

}