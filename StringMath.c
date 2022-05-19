#include <string.h>

void test(){
    printf("test");
}

void AddStringToString(char* Str1, char* Str2, char* Dest){
    int Str1Length = strlen(Str1);
    int Str2Length = strlen(Str2);

    Str1 += Str1Length-1;
    Str2 += Str2Length-1;

    int MinLength = (Str1Length < Str2Length) ? Str1Length:Str2Length;

    int Carry = 0;

    for(int i = 0; i < MaxLength; i++){
        int Subtotal = (*Str1 - '0')+(*Str2 - '0') + Carry;
        Carry = Subtotal/10;
        *Dest = (Subtotal%10) + '0';
        Dest++;
        Str1--;
        Str2--;
    }
}
