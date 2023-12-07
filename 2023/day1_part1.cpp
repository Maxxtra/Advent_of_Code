/*
The newly-improved calibration document consists of lines of text; each line
originally contained a specific calibration value that the Elves now need to
recover. On each line, the calibration value can be found by combining the first
digit and the last digit (in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
In this example, the calibration values of these four lines are 12, 38, 15,
and 77. Adding these together produces 142.
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v;
  string x;

  while (cin >> x) {
    int poz_first_digit = 0, first_digit = 0, second_digit = 0,
        poz_second_digit = x.size() - 1;

    for (poz_first_digit = 0; poz_first_digit < x.size(); poz_first_digit++) {
      if (isdigit(x[poz_first_digit])) {
        first_digit = x[poz_first_digit] - '0';
        break;
      }
    }

    for (poz_second_digit = x.size() - 1; poz_second_digit >= 0;
         poz_second_digit--) {
      if (isdigit(x[poz_second_digit])) {
        second_digit = x[poz_second_digit] - '0';
        break;
      }
    }

    v.push_back(first_digit * 10 + second_digit);
  }

  // sum of all elements of v
  int sum = accumulate(v.begin(), v.end(), 0);

  cout << sum << '\n';
}