#include <iostream>
#include <conio.h>
#include <iomanip> //setw()
using namespace std;

struct node
{
	int data;
	// untuk menghubungkan dengan node lain,
	// tipe data dibuat sama seperi aturan penggunaan pointer.
	node* next;
};

node* head;
node* tail;
node* curr;
node* curr2;
node* curr3;
node* curr4;
node* entry;
node* del;
node* simpan_pos1;
node* simpan_pos2;
node* simpan_pos3;

void inisialisasi()
{
	head = NULL;
	tail = NULL;
}

void input(int dt)
{
	entry = (node* )malloc(sizeof(node)); //alokasi memori
	entry->data = dt;
	entry->next = NULL;
	if(head==NULL) {
		head = entry;
		tail = head;
	} else {
		tail->next = entry;
		tail = entry;
	}
}
void hapus()
{
	int simpan;
	if(head==NULL) {
		cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
	}
	else {
		simpan  = head ->data;
		cout<<"\ndata yang dihapus adalah "<<simpan<<endl;
		//hapus depan
		del = head;
		head = head->next;
		delete del;
	}
}
void cetak()
{
	curr = head;
	if(head == NULL)
		cout<<"\ntidak ada data dalam linked list"<<endl;
	else {
		cout<<"\nData yang ada dalam linked list adalah"<<endl;
		cout<<setw(6);
		while(curr!=NULL) {
			cout<<curr->data<<"->";
			curr = curr->next;
		}
		cout<<"NULL";
		cout<<endl;
	}
}

int hitung_node()
{
	int jumlah = 0;
	curr = head;
	while(curr!=NULL) {
		jumlah++;
		curr=curr->next;
	}
	return(jumlah);
}

void hapus_tengah()
{
	float posisi_tengah;

	//'jumlah' dibagi 2, kemudian dibulatkan ke bawah
	posisi_tengah = float(hitung_node()/2);

	int simpan, simpan2;

	if(head==NULL) {
		cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
	} else
{
		if(hitung_node()<=2){
			hapus();
		} else if(hitung_node()==3){
			curr2 = head;
			simpan_pos1 = curr2->next;
			//menyambungkan node awal dengan node akhir
			curr2->next = curr2->next->next;
			simpan2 = simpan_pos1->data;
			cout<<"\ndata yang dihapus adalah "<<simpan2<<endl;

			simpan_pos1->next = NULL;
			delete simpan_pos1;
		} else if(hitung_node()>3) {
			curr3 = head;
			//menempatkan pointer di posisi "sebelum" tengah
			for(float i = 0; i<posisi_tengah-1; i++){
				curr3 = curr3->next;
				simpan_pos2 = curr3;
			}
			curr4 = head;
			//menempatkan pointer di posisi tengah
			for(float i = 0; i<posisi_tengah; i++){
				curr4 = curr4->next;
				simpan_pos3 = curr4;
			}
			simpan = simpan_pos3->data;
			cout<<"\ndata yang dihapus adalah "<<simpan<<endl;
			//menyambungkan node sebelum 'node tengah' dengan node sesudah 'node tengah'
			simpan_pos2->next = simpan_pos3->next;
			//hapus node
			simpan_pos3->next = NULL; //memutus hubungan node sebelum dihapus
			del = simpan_pos3;
			delete del;
		}
	}
}

void menu()
{
	char pilih, ulang;
	int data;
	do {
		system("cls");
		cout<<"SINGLE LINKED LIST NON CIRCULAR"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<"Menu : "<<endl;
		cout<<"1. Input data"<<endl;
		cout<<"2. Hapus data"<<endl;
		cout<<"3. Cetak data"<<endl;
		cout<<"4. Hapus tengah"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Masukkan pilihan Anda : ";
		cin>>pilih;

		switch(pilih) {
			case '1' :
				cout<<"\nMasukkan data : ";
				cin>>data;
				input(data);
				break;
			case '2' :
				hapus();
				break;
			case '3' :
				cetak();
				break;
			case '4' :
				hapus_tengah();
				break;
			case '5' :
				exit(0);
				break;
			default :
				cout<<"\nPilih ulang"<<endl;
		}

		cout<<"\nKembali ke menu?(y/n)";
		cin>>ulang;

	} while(ulang=='y' || ulang=='Y');
}

int main()
{
	inisialisasi();
	menu();

	return EXIT_SUCCESS;
}
