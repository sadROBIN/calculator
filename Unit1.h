//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#define PI 3.14159265
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TButton *Button21;
	TButton *Button22;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------



std::stack<int> stack;
struct Pair {
	int first, second;
};
std::vector<Pair> pairs(std::string A) {
    std::vector<Pair> V;
	for(int i = 0; i < A.size(); ++i) {
        if(A[i] == '(') {
            stack.push(i);
        }
        if(A[i] == ')') {
            Pair P;
            P.first = stack.top();
            stack.pop();
            P.second = i;
            V.push_back(P);
        }
    }
    return V;
};
float calculate(std::string A) {
    using namespace std;
    string B;
    int a = 0, b = 1, c, d = 0, f = 0, g;
    while (A[a]) {                                                                        // ���������� ���������� �����/������ �� ������� (1)
        if (A[a] == '+' || A[a] == '-' || A[a] == '*' || A[a] == '/' || A[a] == '^') {    // b - ���������� �����, b-1 - ���������� ������
            b++;
        }
        a++;
	}

    float M[b];               // ���������� ������� �� ����� ������� (2)
    for (c = 0; c < b; c++) {
        while (A[d] && A[d] != '+' && A[d] != '-' && A[d] != '*' && A[d] != '/' && A[d] != '^') {
            B[f] = A[d];
            d++;
            f++;
        }
        M[c] = atof(B.c_str());
        for (g = 0; g < f; g++) { B[g] = 0; }
        d++;
        f = 0;
    }
    c = 0;
	while (c < b) {
        c++;
	}

    string C;         // ���������� ������ string �� ������ ������� (3)
    int l = 0, m = 0;
    while (A[l]) {
        if (A[l] == '+' || A[l] == '-' || A[l] == '*' || A[l] == '/' || A[l] == '^') {
            C[m] = A[l];
            m++;
        }
        l++;
    }
    m = 0;
	while (m < b - 1) {
        m++;
	}

    int z1 = 0, x1;           // ���� ����, ���������� �� ���������� ������ � ������ ���������� ������
    while (C[z1]) {
        if (C[z1] == '^') {
            M[z1] = pow(M[z1], M[z1 + 1]);
            for (x1 = z1; x1 < b - 1; x1++) { C[x1] = C[x1 + 1]; }
            for (x1 = z1 + 1; x1 < b; x1++) { M[x1] = M[x1 + 1]; }
            z1 = 0;
            b = b - 1;
        } else { z1++; }
    }
    z1 = 0;
    while (C[z1]) {
        if (C[z1] == '*' || C[z1] == '/') {
            switch (C[z1]) {
                case '*': {
                    M[z1] = M[z1] * M[z1 + 1];
                    for (x1 = z1; x1 < b - 1; x1++) { C[x1] = C[x1 + 1]; }
                    for (x1 = z1 + 1; x1 < b; x1++) { M[x1] = M[x1 + 1]; }
                    z1 = 0;
                    b = b - 1;
                    break;
                }
				case '/': {
						M[z1] = M[z1] / M[z1 + 1];
                        for (x1 = z1; x1 < b - 1; x1++) { C[x1] = C[x1 + 1]; }
                        for (x1 = z1 + 1; x1 < b; x1++) { M[x1] = M[x1 + 1]; }
                        z1 = 0;
						b = b - 1;
                }
            }
        } else { z1++; }
    }
    z1 = 0;
    while (C[z1]) {
        if (C[z1] == '-' || C[z1] == '+') {
            switch (C[z1]) {
                case '-': {
                    M[z1] = M[z1] - M[z1 + 1];
                    for (x1 = z1; x1 < b - 1; x1++) { C[x1] = C[x1 + 1]; }
                    for (x1 = z1 + 1; x1 < b; x1++) { M[x1] = M[x1 + 1]; }
                    z1 = 0;
                    b = b - 1;
                    break;
                }
                case '+': {
                    M[z1] = M[z1] + M[z1 + 1];
                    for (x1 = z1; x1 < b - 1; x1++) { C[x1] = C[x1 + 1]; }
                    for (x1 = z1 + 1; x1 < b; x1++) { M[x1] = M[x1 + 1]; }
                    z1 = 0;
                    b = b - 1;
                    break;
                }
            }
        } else { z1++; }
	}
    return M[0];
};

double ShowAnswer(AnsiString S){
	std::string A;
	A = S.c_str();
	std::vector<Pair> V, V1;
	V = pairs(A);
	V1 = V;
	for (int i = 0; i < V.size(); ++i) {
		std::string SubS = A.substr(V1[0].first + 1,V1[0].second - V1[0].first - 1);
		float z = calculate(SubS);
		A = A.replace(V1[0].first, V1[0].second - V1[0].first + 1, std::to_string(z));
		V1 = pairs(A);
	}
	return round(calculate(A)*10000)/10000;
}

AnsiString Min(AnsiString S) {
	std::string A;
	A = S.c_str();
	std::string X,Y;
	int index = A.find('M');
	if (index != -1) {
		std::vector V = pairs(A);
		Pair pairmin;
		for(int i = 0; i < V.size(); ++i) {
			if(V[i].first == index + 3) {
				pairmin = V[i];
			}
		}

		std::string timed = A.substr(pairmin.first + 1, pairmin.second - pairmin.first - 1);

		int index_of_zapataya = timed.find(',');
		for(int i = 0; i < index_of_zapataya; ++i) {
			X += timed[i];
		}

		for(int i = index_of_zapataya + 1; i < timed.size(); ++i) {
			Y += timed[i];
		}

		float xX, yY;
		xX = calculate(X);
		yY = calculate(Y);

		if(xX > yY) {
			xX = yY;
		}

		A = A.replace(index, pairmin.second - index + 1, std::to_string(xX));
		return A.c_str();
	} else return A.c_str();
}

#endif
