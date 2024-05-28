#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

void capitalizeFirstLetters(wchar_t str[]) {
    int i = 0;
    int capitalize = 1;

    while (str[i] != L'\0') {
        if (iswspace(str[i])) {
            capitalize = 1;  // Set
        } else if (capitalize && iswalpha(str[i])) {
            str[i] = towupper(str[i]);
            capitalize = 0;  // Reset
        }
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "");

    wchar_t str[1000];

    wprintf(L"Enter text: ");
    fgetws(str, sizeof(str)/sizeof(str[0]), stdin);

    capitalizeFirstLetters(str);

    wprintf(L"Modified text: %ls", str);

    return 0;
}
