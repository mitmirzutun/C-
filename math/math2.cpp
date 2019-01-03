#include<iostream>
#include<string>

bool printHeader = true, runTests = true;
std::string Version = "0.0.0";

unsigned long long potenz(unsigned long long zahl, unsigned int n){
    if (n == 0) {
        return 1;
    }
    unsigned int n1;
    unsigned long long n2 = 1;
    for (n1 = 1; n1 <= n; n1++) {
        n2 *= zahl;
    }
    return n2;
}

unsigned long long ggt2(unsigned long long zahl1, unsigned long long zahl2) {
    unsigned long long zahl=1;
    unsigned int n = 3, n1=0, n2=0;
    while (zahl1%2 == 0) {
        n1 += 1;
        zahl1 /= 2;
    } while (zahl2%2 == 0) {
        n2 += 1;
        zahl2 /= 2;
    } if (n2>n1){
        zahl = potenz(2,n1);
    } else {
        zahl = potenz(2,n2);
    } while (zahl1 != 1 && zahl2 != 1) {
        n1 = 0;
        n2 = 0;
        while (zahl1%n == 0) {
            n1 += 1;
            zahl1 /= n;
        } while (zahl2%n == 0) {
            n2 += 1;
            zahl2 /= n;
        } if (n2>n1){
            zahl *= potenz(n,n1);
        } else {
            zahl *= potenz(n,n2);
        } n += 2;
    }
    return zahl;
}

unsigned long long kgv2(unsigned long long zahl1, unsigned long long zahl2) {
    return zahl1*zahl2/ggt2(zahl1,zahl2);
}

void test() {
    bool sucess = true;
    std::cout << "Starting Tests...Running" << std::endl;
    if (potenz(2,2) != 4) {
        sucess = false;
    } if (potenz(3,2) != 9) {
        sucess = false;
    } if (potenz(3,3) != 27) {
        sucess = false;
    } if (ggt2(2,3) != 1) {
        sucess = false;
    } if (ggt2(2,4) != 2) {
        sucess = false;
    } if (ggt2(6,3) != 3) {
        sucess = false;
    } if (kgv2(2,3) != 6) {
        sucess = false;
    } if (kgv2(2,4) != 4) {
        sucess = false;
    } if (kgv2(6,3) != 6) {
        sucess = false;
    }
    std::cout << "Tests ";
    if (sucess == false) {
        std::cout << "not ";
    }
    std::cout << "successful." << std::endl;
}

int main() {
    if (printHeader) {
        std::cout << "This is Math module Version " << Version << std::endl;
    } if (runTests) {
        test();
    }
}
