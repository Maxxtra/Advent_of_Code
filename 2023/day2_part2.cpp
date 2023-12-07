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
    int max_red = 0, max_green = 0, max_blue = 0;


    string x = command;
    while (regex_search(x, match, redPattern)) {
      int redCount = std::stoi(match[1].str());
      if (redCount > max_red) {
        max_red = redCount;
      }

      x = match.suffix().str();
    }

    // Extract green count
    x = command;
    while (regex_search(x, match, greenPattern)) {
      int greenCount = stoi(match[1].str());
      if (greenCount > max_green) {
        max_green = greenCount;
      }

      x = match.suffix().str();
    }

    // Extract blue count
    x = command;
    while (regex_search(x, match, bluePattern)) {
      int blueCount = stoi(match[1].str());
      if (blueCount > max_blue) {
        max_blue = blueCount;
      }

      x = match.suffix().str();
    }

    cout << gameNumber << " " << max_red << ' ' << max_green << ' ' << max_blue << '\n';
    v.push_back(max_red * max_green * max_blue);
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
    cout << '\n';

  cout << accumulate(v.begin(), v.end(), 0) << '\n';
}