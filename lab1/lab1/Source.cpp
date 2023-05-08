/*#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>

using namespace std;
char v[100][100];

int main()
{
    char s[100];
    int j = 0;
    cin.getline(s, 100);
    char* p = strtok(s, " ");
    while (p!=nullptr) {
        strcpy(v[j], p);
        j++;
        p = strtok(NULL, " ");
    }
    for (int i = 0; i <j-1; i++)
        for(int k=i+1;k<j;k++)
          {
            if (strlen(v[i]) < strlen(v[k]))
            {
                char aux[100];
                strcpy(aux, v[i]);
                strcpy(v[i], v[k]);
                strcpy(v[k], aux);
            }
        else
            if (strlen(v[i]) == strlen(v[k]))
                if (v[i][0] > v[k][0])
                {
                    char aux[100];
                    strcpy(aux, v[i]);
                    strcpy(v[i], v[k]);
                    strcpy(v[k], aux);
                }
    }

    for (int i = 0; i < j; i++)
        cout << v[i] << endl;

    return 0;
}
*/



#include <iostream>

using namespace std;



bool isPrime(int n)

{

    for (int tr = 2; tr < n /2; tr++)

        if ((n % tr) == 0)

            return false;

    return true;

}

int main()

{

    int n;

    std::cout << "Enter a number:";

    std::cin >> n;

    if (isPrime(n))

        std::cout << n << " is prime !";

    else

        std::cout << n << " is NOT prime !";

    return 0;

}