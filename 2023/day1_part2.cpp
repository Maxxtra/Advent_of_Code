/*
Your calculation isn't quite right. It looks like some of the digits are
actually spelled out with letters: one, two, three, four, five, six, seven,
eight, and nine also count as valid "digits".

Equipped with this new information, you now need to find the real first and last
digit on each line. For example:

two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76.
Adding these together produces 281.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream cin("day1.txt");
  ofstream fout("day1.out");


  string digits[] = {"zero", "one", "two",   "three", "four", "five",
                     "six", "seven", "eight", "nine"};
  int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  string x;
  vector<int> v;

  while (cin >> x) {
    int first_digit = 0, second_digit = 0;
	unordered_map<string, vector<int>> occurences;
	unordered_map<int, vector<int>> occurences_numbers;

    for (auto digit : digits) {
      size_t pos = x.find(digit);

      while (pos != std::string::npos) {
        // Salvează poziția în vector
        occurences[digit].push_back(pos);

        // Găsește următoarea apariție
        pos = x.find(digit, pos + 1);
      }
    }
	
	for (auto number : numbers) {
          size_t pos = x.find(std::to_string(number));

          while (pos != std::string::npos) {
            // Salvează poziția în vector
            occurences_numbers[number].push_back(pos);

            // Găsește următoarea apariție
            pos = x.find(std::to_string(number), pos + 1);
          }
        }

	for (const auto& pair : occurences) {
	  cout << pair.first << ": ";
	  for (auto x : pair.second) {
		cout << x << ' ';
	  }
	  cout << '\n';
	}

	for (const auto& pair : occurences_numbers) {
	  cout << pair.first << ": ";
	  for (auto x : pair.second) {
		cout << x << ' ';
	  }
	  cout << '\n';
	}

	int minVal_string =  numeric_limits<int>::max(), minVal_numbers = numeric_limits<int>::max();
    string digit = "";
    int number = 0;

    // Iterate through the map
    for (const auto& pair : occurences) {
      int minim_pos = 100;
		for (auto x : pair.second) {
			if (x < minim_pos) {
				minim_pos = x;
			}
		}

      if (minim_pos < minVal_string) {
        // Update the minimum value and its associated key
        minVal_string = minim_pos;
        digit = pair.first;
      }
    }

    for (const auto& pair : occurences_numbers) {
      int minim_pos = 100;
      for (auto x : pair.second) {
        if (x < minim_pos) {
          minim_pos = x;
        }
      }

      if (minim_pos < minVal_numbers) {
        // Update the minimum value and its associated key
        minVal_numbers = minim_pos;
        number = pair.first;
      }
    }

    if (minVal_numbers < minVal_string) {
      first_digit = number;
	} else {
		if (digit == "zero") {
			first_digit = 0;
		} else if (digit == "one") {
			first_digit = 1;
		} else if (digit == "two") {
			first_digit = 2;
		} else if (digit == "three") {
			first_digit = 3;
		} else if (digit == "four") {
			first_digit = 4;
		} else if (digit == "five") {
			first_digit = 5;
		} else if (digit == "six") {
			first_digit = 6;
		} else if (digit == "seven") {
			first_digit = 7;
		} else if (digit == "eight") {
			first_digit = 8;
		} else if (digit == "nine") {
			first_digit = 9;
		}
	}
    
	int maxVal_string =  numeric_limits<int>::min(), maxVal_numbers = numeric_limits<int>::min();
    digit = "";
    number = 0;

    // Iterate through the map
    for (const auto& pair : occurences) {
      int maxim_pos = -1;
	  for (auto x : pair.second) {
		if (x > maxim_pos) {
		  maxim_pos = x;
		}
	  }

      if (maxim_pos > maxVal_string) {
        // Update the minimum value and its associated key
        maxVal_string = maxim_pos;
        digit = pair.first;
      }
    }

    for (const auto& pair : occurences_numbers) {
      int maxim_pos = -1;
      for (auto x : pair.second) {
        if (x > maxim_pos) {
          maxim_pos = x;
        }
      }

      if (maxim_pos > maxVal_numbers) {
        // Update the minimum value and its associated key
        maxVal_numbers = maxim_pos;
        number = pair.first;
      }
    }

	if (maxVal_numbers > maxVal_string) {
	  second_digit = number;
	} else {
		if (digit == "zero") {
		second_digit = 0;
		} else if (digit == "one") {
		second_digit = 1;
		} else if (digit == "two") {
		second_digit = 2;
		} else if (digit == "three") {
		second_digit = 3;
		} else if (digit == "four") {
		second_digit = 4;
		} else if (digit == "five") {
		second_digit = 5;
		} else if (digit == "six") {
		second_digit = 6;
		} else if (digit == "seven") {
		second_digit = 7;
		} else if (digit == "eight") {
		second_digit = 8;
		} else if (digit == "nine") {
		second_digit = 9;
		}
	}

    v.push_back(first_digit * 10 + second_digit);
  }

  for (auto x : v) {
	fout << x << '\n';
  }

  cout << accumulate(v.begin(), v.end(), 0) << '\n';
}