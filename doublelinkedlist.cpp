#include <iostream>
using namespace std;

struct Mahasiswa {
  string nama, jurusan, nrp;
  Mahasiswa *prev;
  Mahasiswa *next;
};

Mahasiswa *head, *tail, *now, *newNode, *del, *nextNode;

void buatList(string data[3]) {
  head = new Mahasiswa();
  head->nama = data[0];
  head->jurusan = data[1];
  head->nrp = data[2];
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int hitungList() {
  if(head == NULL) {
    cout << "Bikin list dulu ya!";
  } else {
    now = head;
    int jumlah = 0;
    while(now != NULL) {
      jumlah++;      
      // lanjut
      now = now->next;
    }
    return jumlah;
  }
}

void tambahAwal(string data[3]) {
  if(head == NULL) {
    cout << "Bikin list dulu ya!";
  } else {
    newNode = new Mahasiswa();
    newNode->nama = data[0];
    newNode->jurusan = data[1];
    newNode->nrp = data[2];
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void tambahAkhir(string data[3]) {
  if(head == NULL) {
    cout << "Bikin list dulu ya!";
  } else {
    newNode = new Mahasiswa();
    newNode->nama = data[0];
    newNode->jurusan = data[1];
    newNode->nrp = data[2];
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}

void tambahTengah(string data[3], int posisi) {
  if(head == NULL) {
    cout << "Bikin list dulu ya!";
  } else {
    if( posisi == 1 ) {
      cout << "Invalid" << endl;
    } else if(posisi < 1 || posisi > hitungList()) {
      cout << "Invalid" << endl;
    } else {
      newNode = new Mahasiswa();
      newNode->nama = data[0];
      newNode->jurusan = data[1];
      newNode->nrp = data[2];

      // tranversing
      now = head;
      int nomor = 1;
      while(nomor <  posisi - 1) {
        now = now->next;
        nomor++;
      }
      nextNode = now->next;
      newNode->prev = now;
      newNode->next = nextNode;
      now->next = newNode;
      nextNode->prev = newNode;
    }
  }
}

void hapusAwal() {
  if(head == NULL) {
    cout << "Bikin list dulu ya!";
  } else {
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }
}

void hapusAkhir() {
  if(head == NULL) {
    cout << "Bikin list dulu ya!";
  } else {
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }
}

void hapusTengah(int posisi) {
  if(head == NULL) {
    cout << "Bikin list dulu ya!";
  } else {
    if(posisi == 1 || posisi == hitungList()) {
      cout << "Invalid" << endl;
    } else if (posisi < 1 || posisi > hitungList()) {
      cout << "Invalid" << endl;
    } else {
      int nomor = 1;
      now = head;
      while(nomor < posisi - 1) {
        now = now->next;
        nomor++;
      }
      del = now->next;
      nextNode = del->next;
      now->next = nextNode;
      nextNode->prev = now;
      delete del;
    }
  }
}

void Print() {
  if(head == NULL) {
    cout << "Bikin list dulu ya!";
  } else {
    cout << "\n\n" << "Jumlah Data : " << hitungList() << endl;
    cout << "Isi Data : " << endl;
    now = head;
    while(now != NULL ) {
      // print
      cout << "==========" << endl;
      cout << "Nama : " << now->nama << endl;
      cout << "Jurusan : " << now->jurusan << endl;
      cout << "NRP : " << now->nrp << endl;
      // lanjut
      now = now->next;
    }
  }
}

int main() {

  string data1[3] = {"Ilhan", "Teknologi Informasi", "040"};
  buatList(data1);
  Print();

  string data2[3] = {"Joko", "Teknologi Informasi", "050"};
  tambahAwal(data2);
  Print();

  string data3[3] = {"Anwar", "Teknologi Informasi", "060"};
  tambahAkhir(data3);
  Print();

  string data4[3] = {"Rafi", "Teknologi Informasi", "070"};
  tambahTengah(data4, 2);
  Print();

  hapusTengah(3);
  Print();


}
