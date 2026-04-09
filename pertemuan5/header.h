#ifndef HEADER_H
#define HEADER_H

// start header.h
#include<iostream>
using namespace std;

    class Mhs{
        private:    // atribute
        string nim, nama;
        float ipk;

        public: // behavior
        void input();
        void cetak();
        string getNim();    // karena atribut bersifat private
        string getNama();   // maka perlu fungsi getter
        float getIpk();     // agar bisa mengakses atribut nya
        void setIpk(float iipk);
        // karena atribut bersifat private, maka perlu prosedur setter untuk mengisi nilai pada atribut
    };

    void sortingIpkDesc(Mhs m[], int n);
    void cetakSemuaMhs(Mhs m[], int n);
    bool searchNim(string k, int n, Mhs m[]);
    float cariIpkDariNama(string k, int n, Mhs m[]);
    void analisaMhs(Mhs m[], int n);

#endif