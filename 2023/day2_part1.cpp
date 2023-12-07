#include <bits/stdc++.h>
#define RED 12
#define GREEN 13
#define BLUE 14

using namespace std;

int main() {
  ifstream cin("day2.txt");
  vector<int> v;
  string command;

  regex gamePattern(R"(Game (\d+):)");
  regex redPattern(R"(\b(\d+) red\b)");
  regex greenPattern(R"(\b(\d+) green\b)");
  regex bluePattern(R"(\b(\d+) blue\b)");

  while (getline(cin, command)) {
    smatch match;
    int gameNumber = 0;
    // cout << command << '\n';
    if (std::regex_search(command, match, gamePattern)) {
      gameNumber = stoi(match[1].str());
    }
    // cout << gameNumber << '\n';
      bool invalid = 0;

      string x = command;
      while (regex_search(x, match, redPattern)) {
        int redCount = std::stoi(match[1].str());
        if (redCount > RED) {
          invalid = 1;
          break;
        }

        x = match.suffix().str();
      }

      // Extract green count
      x = command;
      while (regex_search(x, match, greenPattern)) {
        int greenCount = stoi(match[1].str());
        if (greenCount > GREEN) {
          invalid = 1;
          break;
        }

        x = match.suffix().str();
      }

      // Extract blue count
      x = command;
      while (regex_search(x, match, bluePattern)) {
        int blueCount = stoi(match[1].str());
        if (blueCount > BLUE) {
          invalid = 1;
          break;
        }

        x = match.suffix().str();
      }

      if (invalid == 0) {
        v.push_back(gameNumber);
    }
  }

    // for (int i = 0; i < v.size(); i++) {
    //   cout << v[i] << ' ';
    // }

  cout << accumulate(v.begin(), v.end(), 0) << '\n';
}