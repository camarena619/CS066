#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

void converter();
void list();
void decimalConversion(int choice);
void binaryConversion(int choice);
void octalConversion(int choice);
void hexConvesion(int choice);
void twoConversion(int choice);


std::string decTo2sComp(int n);

int hexToDecimal(std::string hex);

template <class T>
int toDecimal(int choice, T n);

template <class T>
void toBinary(int choice, T n);

template <class T>
void toOctal(int choice, T n);

template <class T>
void toHex(int choice, T n);

#endif //CONVERSIONS_H_