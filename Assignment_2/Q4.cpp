#include <iostream>
using namespace std;

bool isVowel(char c) {
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
           c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

int main() {
    int ch;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Concatenate Strings\n";
        cout << "2. Reverse String\n";
        cout << "3. Delete Vowels\n";
        cout << "4. Sort Strings Alphabetically\n";
        cout << "5. Convert Uppercase to Lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        cin.ignore();

        if (ch == 1) {
            string s1, s2;
            cout << "Enter first string: ";
            getline(cin, s1);
            cout << "Enter second string: ";
            getline(cin, s2);
            cout << "Concatenated: " << s1 + s2 << endl;
        }

        else if (ch == 2) {
            string s;
            cout << "Enter string: ";
            getline(cin, s);
            for(int i = 0, j = s.length()-1; i < j; i++, j--)
                swap(s[i], s[j]);
            cout << "Reversed: " << s << endl;
        }

        else if (ch == 3) {
            string s, t="";
            cout << "Enter string: ";
            getline(cin, s);
            for(int i=0;i<s.length();i++)
                if(!isVowel(s[i])) t += s[i];
            cout << "Without vowels: " << t << endl;
        }

        else if (ch == 4) {
            int n;
            cout << "Enter number of strings: ";
            cin >> n;
            cin.ignore();
            string a[100];
            for(int i=0;i<n;i++) getline(cin, a[i]);

            for(int i=0;i<n-1;i++)
                for(int j=i+1;j<n;j++)
                    if(a[i] > a[j])
                        swap(a[i], a[j]);

            cout << "Sorted strings:\n";
            for(int i=0;i<n;i++) cout << a[i] << endl;
        }

        else if (ch == 5) {
            char c;
            cout << "Enter uppercase character: ";
            cin >> c;
            if(c >= 'A' && c <= 'Z') c = c + 32;
            cout << "Lowercase: " << c << endl;
        }

        else if (ch == 6) {
            cout << "Exiting...\n";
            break;
        }

        else cout << "Invalid choice!\n";
    }

    return 0;
}
