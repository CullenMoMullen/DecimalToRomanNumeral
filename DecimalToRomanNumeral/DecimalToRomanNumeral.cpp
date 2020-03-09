/*

This program will convert a decimal number into a Roman Numeral

*/

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

void setupMap();
void convertToRoman(uint32_t& num, int multiplier);

map<int, wstring> DecToRomMap;

int main()
{
    
    setupMap();
    
    uint32_t decNum;
    wcout << L"Enter a number under 4,000,000: ";
    wcin >> decNum;
    wcin.ignore(numeric_limits<streamsize>::max(), L'\n');

    wcout << L"You entered: " << decNum << endl;
    
    
    cout << "A roman might write that like the below:" << endl << endl; 
    convertToRoman(decNum, 1);

}

void convertToRoman(uint32_t& num, int multiplier) {
    if (num < 10) {
        if (DecToRomMap.end() != DecToRomMap.find(num * multiplier)) {
            wcout << DecToRomMap[num * multiplier];
        }
        num = 0;
        return;
    }
    else if (DecToRomMap.end() != DecToRomMap.find(num * multiplier)) {
        wcout << DecToRomMap[num * multiplier];
        return;
    }
    else {
        int rem = num % 10;
        num /= 10;
        convertToRoman(num, multiplier*10);
        wcout << DecToRomMap[rem * multiplier];
    }
}


void setupMap() {
    DecToRomMap[1] = L"I";
    DecToRomMap[2] = L"II";
    DecToRomMap[3] = L"III";
    DecToRomMap[4] = L"IV";
    DecToRomMap[5] = L"V";
    DecToRomMap[6] = L"VI";
    DecToRomMap[7] = L"VII";
    DecToRomMap[8] = L"VIII";
    DecToRomMap[9] = L"IX";
    DecToRomMap[10] = L"X";
    DecToRomMap[20] = L"XX";
    DecToRomMap[30] = L"XXX";
    DecToRomMap[40] = L"XL";
    DecToRomMap[50] = L"L";
    DecToRomMap[60] = L"LX";
    DecToRomMap[70] = L"LXX";
    DecToRomMap[80] = L"LXXX";
    DecToRomMap[90] = L"XC";
    DecToRomMap[100] = L"C";
    DecToRomMap[200] = L"CC";
    DecToRomMap[300] = L"CCC";
    DecToRomMap[400] = L"CD";
    DecToRomMap[500] = L"D";
    DecToRomMap[600] = L"DC";
    DecToRomMap[700] = L"DCC";
    DecToRomMap[800] = L"DCCC";
    DecToRomMap[900] = L"CM";
    DecToRomMap[1000] = L"M";
    DecToRomMap[2000] = L"MM";
    DecToRomMap[3000] = L"MMM";
    DecToRomMap[4000] = L"M|V|";
    DecToRomMap[5000] = L"|V|";
    DecToRomMap[6000] = L"|V|M";
    DecToRomMap[7000] = L"|V|MM";
    DecToRomMap[8000] = L"|V|MMM";
    DecToRomMap[9000] = L"M|X|";
    DecToRomMap[10000] = L"|X|";
    DecToRomMap[20000] = L"|X||X|";
    DecToRomMap[30000] = L"|X||X||X|";
    DecToRomMap[40000] = L"|X||L|";
    DecToRomMap[50000] = L"|L|";
    DecToRomMap[60000] = L"|L||X|";
    DecToRomMap[70000] = L"|L||X||X|";
    DecToRomMap[80000] = L"|L||X||X||X|";
    DecToRomMap[90000] = L"|X||C|";
    DecToRomMap[100000] = L"|C|";
    DecToRomMap[200000] = L"|C||C|";
    DecToRomMap[300000] = L"|C||C||C|";
    DecToRomMap[400000] = L"|C||D|";
    DecToRomMap[500000] = L"|D|";
    DecToRomMap[600000] = L"|D||C|";
    DecToRomMap[700000] = L"|D||C||C|";
    DecToRomMap[800000] = L"|D||C||C||C|";
    DecToRomMap[900000] = L"|C||M|";
    DecToRomMap[1000000] = L"|M|";
    DecToRomMap[2000000] = L"|M||M|";
    DecToRomMap[3000000] = L"|M||M||M|";
}
//C̄D̄M̄X̄V̄ L̄
