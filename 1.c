#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char states[][3] = {
        "AP", "AR", "AS", "BR", "CG", "GA", "GJ",
        "HR", "HP", "JH", "KA", "KL", "MP", "MH",
        "MN", "ML", "MZ", "NL", "OD", "PB", "RJ",
        "SK", "TN", "TS", "TR", "UP", "UK", "WB",
        "AN", "CH", "DD", "DL", "JK", "LA", "LD", "PY"
    };

    char vehicle[20];
    int i, len, found = 0, valid = 1;

    printf("Enter vehicle number: ");
    scanf("%19s", vehicle);

    for (i = 0; vehicle[i] != '\0'; i++)
        vehicle[i] = toupper((unsigned char)vehicle[i]);

    len = strlen(vehicle);

    if (len < 9 || len > 10) {
        printf("Invalid length\n");
        return 0;
    }

       for (i = 0; i < 36; i++) {
        if (vehicle[0] == states[i][0] &&
            vehicle[1] == states[i][1]) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid state code\n");
        return 0;
    }

   
    if (!isdigit((unsigned char)vehicle[2]) ||
        !isdigit((unsigned char)vehicle[3])) {
        printf("Invalid RTO code\n");
        return 0;
    }

    
    for (i = 4; i < len - 4; i++) {
        if (!isalpha((unsigned char)vehicle[i])) {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("Invalid series code\n");
        return 0;
    }

    
    for (i = len - 4; i < len; i++) {
        if (!isdigit((unsigned char)vehicle[i])) {
            valid = 0;
            break;
        }
    }

    if (valid)
        printf("Valid vehicle number\n");
    else
        printf("Invalid registration number\n");

    return 0;
}
 