#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

int olahOperasi(int a, int b, int i) {
    int ans = 9999;
    switch(i) {
        case 0:
            ans = a + b;
            break;
        case 1:
            ans = a - b;
            break;
        case 2:
            ans = a * b;
            break;
        case 3:
            if (b!=0) {
                ans = a/b;
            }
            break;
    }
    return ans;
}

char charOperator(int i) {
    switch(i) {
        case 0:
            return '+';
            break;
        case 1:
            return '-';
            break;
        case 2:
            return '*';
            break;
        case 3:
            return '/';
            break;
        default:
            return 'i';
    }
}

// bentuk solusi

// bentuk ((a op b) op c) op d
void sol0(int listAngka[4], int* n, string* txt) {
    int A, B, C;
    for (int i=0; i<4; i++) {
        A = olahOperasi(listAngka[0], listAngka[1], i);
        for (int j=0; j<4; j++) {
            B = olahOperasi(A, listAngka[2], j);
            for (int k=0; k<4; k++) {
                C = olahOperasi(B, listAngka[3], k);
                if (C == 24) {
                    (*n)++;
                    (*txt) = (*txt) + "((" + to_string(listAngka[0]) + charOperator(i) + to_string(listAngka[1]) + ")" 
                    + charOperator(j) + to_string(listAngka[2]) + ")" + charOperator(k) + to_string(listAngka[3]) + "\n";
                }
            }
        }
    }
} 

// bentuk (a op (b op c)) op d
void sol1(int listAngka[4], int* n, string* txt) {
    int A, B, C;
    for (int i=0; i<4; i++) {
        A = olahOperasi(listAngka[1], listAngka[2], i);
        for (int j=0; j<4; j++) {
            B = olahOperasi(listAngka[0], A, j);
            for (int k=0; k<4; k++) {
                C = olahOperasi(B, listAngka[3], k);
                if (C == 24) {
                    (*n)++;
                    (*txt) = (*txt) + "(" + to_string(listAngka[0]) + charOperator(j) + "(" + to_string(listAngka[1])
                    + charOperator(i) + to_string(listAngka[2]) + "))" + charOperator(k) + to_string(listAngka[3]) + "\n";
                }
            }
        }
    }
}

// bentuk (a op b) op (c op d)
void sol2(int listAngka[4], int* n, string* txt) {
    int A, B, C;
    for (int i=0; i<4; i++) {
        A = olahOperasi(listAngka[0], listAngka[1], i);
        for (int j=0; j<4; j++) {
            B = olahOperasi(listAngka[2], listAngka[3], j);
            for (int k=0; k<4; k++) {
                C = olahOperasi(A, B, k);
                if (C == 24) {
                    (*n)++;
                    (*txt) = (*txt) + "(" + to_string(listAngka[0]) + charOperator(i) + to_string(listAngka[1]) + ")" 
                    + charOperator(k) + "(" +  to_string(listAngka[2])  + charOperator(j) + to_string(listAngka[3]) + ")" + "\n";
                }
            }
        }
    }
}

// bentuk a op ((b op c) op d)
void sol3(int listAngka[4], int* n, string* txt) {
    int A, B, C;
    for (int i=0; i<4; i++) {
        A = olahOperasi(listAngka[1], listAngka[2], i);
        for (int j=0; j<4; j++) {
            B = olahOperasi(A, listAngka[3], j);
            for (int k=0; k<4; k++) {
                C = olahOperasi(listAngka[0], B, k);
                if (C == 24) {
                    (*n)++;
                    (*txt) = (*txt) + "(" + to_string(listAngka[0]) + charOperator(k) + "((" + to_string(listAngka[1])
                    + charOperator(i) +  to_string(listAngka[2])  + ")" + charOperator(j) + to_string(listAngka[3]) + ")" + "\n";
                }
            }
        }
    }
}

void solusi24(int listAngka[4], int* n, string* txt) {
    sol0(listAngka, n, txt);
    sol1(listAngka, n, txt);
    sol2(listAngka, n, txt);
    sol3(listAngka, n, txt);
}

void replaceList(int listAngka[4], int a, int b, int c, int d) {
    listAngka[0] = a;
    listAngka[1] = b;
    listAngka[2] = c;
    listAngka[3] = d;
}

void userInputList(int listAngka[4]) {
    string input;
    int iNum;
    bool flag = true;
    while (flag) {
        flag = false;
        for(int i=0; i<4; i++) {
            cin >> input;
            if (input == "A") {
                listAngka[i] = 1;
            } else if (input == "J") {
                listAngka[i] = 11;
            } else if (input == "Q") {
                listAngka[i] = 12;
            } else if (input == "K") {
                listAngka[i] = 13;
            } else if (stoi(input) >= 2 && stoi(input) <= 10) {
                listAngka[i] = stoi(input);
            } else {
                printf("Masukan tidak sesuai, silakan masukkan kembali.\n");
                flag = true;
                break;
            }
    }
    
    }
}

void printList(int listAngka[4]) {
    for (int i=0; i<4; i++) {
        printf("%d ", listAngka[i]);
    } printf("\n");
}

void randomizer(int listAngka[4]) {
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        int a = rand() % 13 + 1;
        listAngka[i] = a;
    }
    printf("Berhasil mengacak dengan hasil:\n");
    printList(listAngka);
}

void splash() { cout
<<" .----------------.  .----------------.   .----------------.  .----------------.  .----------------.  .----------------.  \n"
<<"| .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. | \n"
<<"| |    _____     | || |   _    _     | | | |    ______    | || |      __      | || | ____    ____ | || |  _________   | | \n"
<<"| |   / ___ `.   | || |  | |  | |    | | | |  .' ___  |   | || |     /  \\     | || ||_   \\  /   _|| || | |_   ___  |  | | \n"
<<"| |  |_/___) |   | || |  | |__| |_   | | | | / .'   \\_|   | || |    / /\\ \\    | || |  |   \\/   |  | || |   | |_  \\_|  | | \n"
<<"| |   .'____.'   | || |  |____   _|  | | | | | |    ____  | || |   / ____ \\   | || |  | |\\  /| |  | || |   |  _|  _   | | \n"
<<"| |  / /____     | || |      _| |_   | | | | \\ `.___]  _| | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || |  _| |___/ |  | | \n"
<<"| |  |_______|   | || |     |_____|  | | | |  `._____.'   | || ||____|  |____|| || ||_____||_____|| || | |_________|  | | \n"
<<"| |              | || |              | | | |              | || |              | || |              | || |              | | \n"
<<"| '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' | \n"
<<" '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------'  \n\n";
}

void menuUtama() {
    printf("Pilih input yang Anda inginkan:\n");
    printf("1. Input sendiri\n");
    printf("2. Diinputin (random)\n");
}

void menuInputSendiri() {
    printf("Silakan masukkan 4 kartu Anda\n");
    printf("Input yang avaiable: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A\n");
}

void menuOutput() {
    printf("Apakah Anda ingin menyimpan solusi dalam file?\n");
    printf("1. Ya\n");
    printf("2. Tidak\n");
}

void exit() {
    printf("Terima kasih telah menggunakan program\n");
    printf("Masukkan input sembarang untuk keluar.\n");
    string ex;
    cin >> ex;
}


int main() {
    splash();
    menuUtama();
    int inp;
    bool flag = true;
    int listAngka[4];
    int n = 0;
    string output;

    while(flag) {
        flag = false;
        cin >> inp;
        if (inp == 1) {
            menuInputSendiri();
            userInputList(listAngka);
        } else if (inp == 2) {
            randomizer(listAngka);
        } else {
            flag = true;
        }
    }

    clock_t start = clock();

    int a = listAngka[0];
    int b = listAngka[1];
    int c = listAngka[2];
    int d = listAngka[3];

    int list[4] = {a,b,c,d};
    replaceList(list, a,b,c,d);solusi24(list, &n, &output);
    replaceList(list, a,b,d,c);solusi24(list, &n, &output);
    replaceList(list, a,c,b,d);solusi24(list, &n, &output);
    replaceList(list, a,c,d,b);solusi24(list, &n, &output);
    replaceList(list, a,d,b,c);solusi24(list, &n, &output);
    replaceList(list, a,d,c,b);solusi24(list, &n, &output);
    replaceList(list, b,a,c,d);solusi24(list, &n, &output);
    replaceList(list, b,a,d,c);solusi24(list, &n, &output);
    replaceList(list, b,c,a,d);solusi24(list, &n, &output);
    replaceList(list, b,c,d,a);solusi24(list, &n, &output);
    replaceList(list, b,d,a,c);solusi24(list, &n, &output);
    replaceList(list, b,d,c,a);solusi24(list, &n, &output);
    replaceList(list, c,a,b,d);solusi24(list, &n, &output);
    replaceList(list, c,a,d,b);solusi24(list, &n, &output);
    replaceList(list, c,b,a,d);solusi24(list, &n, &output);
    replaceList(list, c,b,d,a);solusi24(list, &n, &output);
    replaceList(list, c,d,a,b);solusi24(list, &n, &output);
    replaceList(list, c,d,b,a);solusi24(list, &n, &output);
    replaceList(list, d,a,b,c);solusi24(list, &n, &output);
    replaceList(list, d,a,c,b);solusi24(list, &n, &output);
    replaceList(list, d,b,a,c);solusi24(list, &n, &output);
    replaceList(list, d,b,c,a);solusi24(list, &n, &output);
    replaceList(list, d,c,a,b);solusi24(list, &n, &output);
    replaceList(list, d,c,b,a);solusi24(list, &n, &output);

    string nSol;
    if (n>0) {
        nSol = to_string(n) + " solutions found\n";
    } else {
        nSol = "Tidak ada solusi\n";
    }

    cout << nSol;
    cout << output;
    cout.precision(10);
    cout << "Execution time " << float(clock() - start)/CLOCKS_PER_SEC  << "s" << endl;
    menuOutput();

    flag =  true;
    while (flag) {
        flag = false;
        cin >> inp;
        if (inp == 1) {
            ofstream out("output.txt");
            out << n << " solutions found\n";
            out << output;
            out.close();
            printf("Berhasil menyimpan dengan nama file output.txt\n");
            exit();
        } else if (inp == 2) {
            exit();
        } else {
            flag = true;
        }
    }
}