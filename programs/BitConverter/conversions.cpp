#include <iostream>
#include <string>
#include "conversions.h"


void converter(){
    
    int choice;

    list();
    std::cout << "\nEnter # for type of conversion: ";
    std::cin >> choice;


    while(choice >= 1 && choice <=5){

        switch (choice) {
            case 1:
                decimalConversion(choice);
                break;

            case 2: 
                binaryConversion(choice);
                break;

            case 3: 
                octalConversion(choice);
                break;

            case 4:
                hexConvesion(choice);
                break;
            
            case 5:
                list();
                break;
        }

        std::cout << "\nEnter # for type of conversion (5 for list): ";
        std::cin >> choice;
    }

    
}

// List of conversion types
void list(){
    std::cout << "\n\nConversions\n";
    std::cout << "-------------------\n";
    std::cout << "1. Decimal\n";
    std::cout << "2. Binary\n";
    std::cout << "3. Octal\n";
    std::cout << "4. Hex\n";
    std::cout << "5. List\n";
    std::cout << "To exit, enter any other number\n";
}

void decimalConversion(int choice){
    int n;

    std::cout << "Enter decimal #: ";
    std::cin >> n;
    std::cout <<"\n---------------------------------\n";

    std::cout << "Binary: "; toBinary(choice, n);
    std::cout << "Octal : "; toOctal(choice, n);
    std::cout << "Hex   : "; toHex(choice, n); 
    std::cout << "2's   : " << decTo2sComp(n) << std::endl; 
    std::cout <<"---------------------------------";

}
void binaryConversion(int choice){
    long n;

    std::cout << "Enter binary #: ";
    std::cin >> n;
    std::cout <<"\n---------------------------------\n";

    std::cout << "Decimal: " << toDecimal(choice, n) << std::endl;
    std::cout << "Octal  : "; toOctal(choice, n);
    std::cout << "Hex    : "; toHex(choice, n); 
    std::cout << "2's    : " << decTo2sComp(toDecimal(choice, n)) << std::endl; 
    std::cout <<"---------------------------------";

}
void octalConversion(int choice){
    long n;

    std::cout << "Enter Octal #: ";
    std::cin >> n;
    std::cout <<"\n---------------------------------\n";

    std::cout << "Decimal : " << toDecimal(choice, n) << std::endl;
    std::cout << "Binary  : "; toBinary(choice, n);
    std::cout << "Hex     : "; toHex(choice, n); 
    std::cout << "2's     : " << decTo2sComp(toDecimal(choice, n)) << std::endl; 
    std::cout <<"---------------------------------";
}
void hexConvesion(int choice){
    std::string hex = "";
    
    std::cout << "Enter Hex #: ";
    std::cin >> hex;

    std::cout <<"\n---------------------------------\n";

    std::cout << "Decimal : " << hexToDecimal(hex) << std::endl;
    std::cout << "Binary  : "; toBinary(choice, hexToDecimal(hex));
    std::cout << "Octal   : "; toOctal(choice, hexToDecimal(hex)); 
    std::cout << "2's     : " << decTo2sComp(hexToDecimal(hex)) << std::endl; 
    std::cout <<"---------------------------------";
}
void twoConversion(int choice){
    std::string hex = "";
    
    std::cout << "Enter Hex #: ";
    std::cin >> hex;

    std::cout <<"\n---------------------------------\n";

    std::cout << "Decimal : " << hexToDecimal(hex) << std::endl;
    std::cout << "Binary  : "; toBinary(choice, hexToDecimal(hex));
    std::cout << "Octal   : "; toOctal(choice, hexToDecimal(hex)); 
    std::cout << "2's     : " << decTo2sComp(hexToDecimal(hex)) << std::endl; 
    std::cout <<"---------------------------------";
}


std::string decTo2sComp(int n){

	// if (n < -32768 || n>32767)
	// 	return "";
    
	std::string result;

	for (int bit = 0; bit < sizeof(int) * 4; ++bit){
		int validation = 1 & n;
		result = (validation ? "1" : "0") + result;
		n = n >> 1;
	}
	return result;
}

int hexToDecimal(std::string hex){

    // Convert string to upper case
    for(int i = 0; i < hex.length(); i++){
        hex[i] = toupper(hex[i]);
    }

    int len = hex.length();
    int base = 1;
    int decimal = 0;

    for (int i = len - 1; i >= 0; i--)
    {

        if (hex[i] >= '0' && hex[i] <= '9'){
            decimal += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F'){
            decimal += (hex[i] - 55) * base;
            base = base * 16;
        }
    }
    return decimal;
}

template <class T>
int toDecimal(int choice, T n){

    // Converts binary to decimal
    if(choice == 2 || choice == 4){

        int decNum = 0;
        int base = 1;
        int temp = n;

        while (temp)
        {
            int lastDigit = temp % 10;
            temp = temp / 10;

            decNum += lastDigit * base;

            base = base * 2;
        }

        return decNum;
    }
    // Converts octal to decimal
    else if(choice == 3) {

        int decimal = 0;
        int base = 1;
        int temp = n;

        while (temp) {
    
            // Extracting last digit
            int lastDigit = temp % 10;
            temp = temp / 10;
    
            decimal += lastDigit * base;
    
            base = base * 8;
        }
    
        return decimal;
    }
    
    return 0;
}

// Converts to binary
template <class T>
void toBinary(int choice, T n){

    // Converts decimal to binary
    if(choice == 1 || choice == 4){
            // array to store octal number
            int binNum[100];
        
            // counter for octal number array
            int i = 0;
            while (n != 0) {
        
                // storing remainder in octal array
                binNum[i] = n % 2;
                n = n / 2;
                i++;
            }
        
            // printing octal number array in reverse order
            for (int j = i - 1; j >= 0; j--)
                std::cout << binNum[j];
        }

    // Converts octal to binary
    else if(choice == 3){
        int decimal = toDecimal(choice, n);
        toBinary(1, decimal);
    }

    std::cout<<"\n";
}

// Converts to octal
template <class T>
void toOctal(int choice, T n){

    // Converts deciaml to octal
    if(choice == 1 || choice == 4){
            // array to store octal number
            int octalNum[100];
        
            // counter for octal number array
            int i = 0;
            while (n != 0) {
        
                // storing remainder in octal array
                octalNum[i] = n % 8;
                n = n / 8;
                i++;
            }
        
            // printing octal number array in reverse order
            for (int j = i - 1; j >= 0; j--)
                std::cout << octalNum[j];

            std::cout<<"\n";
        }

    // Converts binary to octal
    else if(choice == 2){
    int decimal = toDecimal(choice, n);
    toOctal(1,decimal);
    }

}

// Converts to hex
template <class T>
void toHex(int choice, T n){

    if(choice == 1){
        // char array to store hexadecimal number
        char hexNum[100];
 
        // counter for hexadecimal number array
        int i = 0;
        while (n != 0) {
            // temporary variable to store remainder
            int temp = 0;
    
            // storing remainder in temp variable.
            temp = n % 16;
    
            // check if temp < 10
            if (temp < 10) {
                hexNum[i] = temp + 48;
                i++;
            }
            else {
                hexNum[i] = temp + 55;
                i++;
            }
    
            n = n / 16;
        }
    
        // printing hexadecimal number array in reverse order
        for (int j = i - 1; j >= 0; j--)
            std::cout << hexNum[j];

         std::cout<<"\n";
    }
   
    else if(choice == 2 || choice == 3){
        int decimal = toDecimal(choice, n);
        toHex(1,decimal);
    }

}