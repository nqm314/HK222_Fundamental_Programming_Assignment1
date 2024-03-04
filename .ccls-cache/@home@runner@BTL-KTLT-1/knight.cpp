#include "knight.h"
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown,
             int rescue) {
  cout << "HP=" << HP << ", level=" << level << ", remedy=" << remedy
       << ", maidenkiss=" << maidenkiss << ", phoenixdown=" << phoenixdown
       << ", rescue=" << rescue << endl;
}

int levelO(int i) {
  int b = i % 10;
  int levelO = i > 6 ? (b > 5 ? b : 5) : b;
  return levelO;
}

// Calculate s1
int s1(int n) {
  if (n <= 0)
    return 0;
  int res = 0, m = 99;
  while (n--) {
    res += m;
    m -= 2;
  }
  return res;
}

bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int findPrimeNum(int n) {
  // Nhập vào số nguyên n và trả về số nguyên tố > n và gần n nhất
  int p = n + 1;
  while (!isPrime(p)) {
    p++;
  }
  return p;
}

int fibNum(int n) {
  int a[10001];
  a[0] = 0;
  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  return a[n];
}
int findFibNum(int n) {
  // nhận tham số đầu vào là số nguyên n và trả về số Fibonacci nhỏ hơn và gần n
  // nhất
  if (n == 1) return 1;
  int res;
  for (int i = 1; i <= 10000; i++) {
    if (fibNum(i) >= n) {
      res = fibNum(i - 1);
      break;
    }
  }
  return res;
}

int secondMaxNum(int a[], int n2) {
  if (n2 < 2)
    return -1;
  int maxNum = -10e7;
  for (int i = 0; i < 3; i++) {
    if (a[i] > maxNum) {
      maxNum = a[i];
    }
  }
  int minDiff = 10e7, secondMaxNum = -10e7;
  for (int i = 0; i < 3; i++) {
    if ((maxNum - a[i]) != 0 && (maxNum - a[i]) < minDiff) {
      minDiff = maxNum - a[i];
      secondMaxNum = a[i];
    }
  }
  return secondMaxNum;
}

int merlin_support(string a) {
  string s = "Merlin";
  string s1 = "merlin";
  int count = 0;
  int res = 0;
  if ((a.find('m') != -1 || a.find('M') != -1) &&
      (a.find('e') != -1 || a.find('E') != -1) &&
      (a.find('r') != -1 || a.find('R') != -1) &&
      (a.find('l') != -1 || a.find('L') != -1) &&
      (a.find('i') != -1 || a.find('I') != -1) &&
      (a.find('n') != -1 || a.find('N') != -1)) {
    if (a.find(s) != -1 || a.find(s1) != -1) {
      res = 3;
    } else {
      res = 2;
    }
  }
  return res;
}

void CheckTiny_Frog(int &tinyEvent, int &frogEvent, int &HP, int &maxHP,
                    int &level, int &old_level) {
  if (tinyEvent == 1 || tinyEvent == 2) {
    tinyEvent++;
  } else if (tinyEvent == 3) {
    tinyEvent = 0;
    HP = HP > 0 ? min(HP * 5, maxHP) : HP;
  }
  if (frogEvent == 1 || frogEvent == 2) {
    frogEvent++;
  } else if (frogEvent == 3) {
    frogEvent = 0;
    level = old_level;
  }
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy,
                      int &maidenkiss, int &phoenixdown, int &rescue) {
  int maxLevel = 10, maxRemedy = 99, maxMaidenkiss = 99, maxPhoenixdown = 99;
  int tinyEvent = 0, frogEvent = 0, old_level, old_HP, damage, eve18Cnt = 0,
      eve19Cnt = 0;
  double baseDamage;
  bool isAuthur = false, isLancelot = false, isBowser = false;
  ifstream input(file_input);
  string line;
  // read knight's information
  if (getline(input, line)) {
    stringstream info(line);
    info >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
  }
  if (HP == 999) {
    isAuthur = true;
  }
  if (isPrime(HP)) {
    isLancelot = true;
  }
  int maxHP = HP, eventNum = 0, code;
  // read event
  if (getline(input, line)) {
    stringstream event(line);
    while (event >> code) {
      eventNum++;
    }
  }
  int *eventCode = new int[eventNum + 1];
  eventCode[0] = -1;
  input.seekg(-(line.size() + 1), ios::cur);
  if (getline(input, line)) {
    stringstream event(line);
    int i = 1;
    while (event >> code) {
      eventCode[i] = code;
      i++;
    }
  }
  string mush_ghost, aclepius_pack, merlin_pack;
  // read gift
  getline(input, line);
  stringstream ss(line);
  int ind = 0;
  while (ss.good() && ind < 3) {
    string substr;
    getline(ss, substr, ',');
    if (ind == 0) mush_ghost = substr;
    if (ind == 1) aclepius_pack = substr;
    if (ind == 2) merlin_pack = substr;
    ind++;
  }
  for (int i = 1; i < eventNum + 1; i++) {

    // Xu li su kien 0
    if (eventCode[i] == 0) {
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      rescue = 1;
      break;
    }

    // Xu li su kien 1
    if (eventCode[i] == 1) {
      if (isAuthur) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isLancelot) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      baseDamage = 1;
      if (levelO(i) < level) {
        level = min(level + 1, maxLevel);
      } else if (levelO(i) == level) {
        level = level * 1;
      } else if (levelO(i) > level) {
        damage = baseDamage * levelO(i) * 10;
        HP = HP - damage;
      }
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (HP <= 0 && phoenixdown == 0) {
        rescue = 0;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i == eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = 1;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i != eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      } else if (HP > 0 && i == eventNum) {
        rescue = 1;
        break;
      } else if (HP > 0 && i != eventNum) {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 2
    if (eventCode[i] == 2) {
      if (isAuthur) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isLancelot) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      baseDamage = 1.5;
      if (levelO(i) < level) {
        // level = min(level + 1, maxLevel);
        level = min(level + 1, maxLevel);
      } else if (levelO(i) == level) {
        level = level * 1;
      } else if (levelO(i) > level) {
        damage = baseDamage * levelO(i) * 10;
        HP = HP - damage;
      }
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (HP <= 0 && phoenixdown == 0) {
        rescue = 0;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i == eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = 1;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i != eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      } else if (HP > 0 && i == eventNum) {
        rescue = 1;
        break;
      } else if (HP > 0 && i != eventNum) {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 3
    if (eventCode[i] == 3) {
      if (isAuthur) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isLancelot) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      baseDamage = 4.5;
      if (levelO(i) < level) {
        level = min(level + 1, maxLevel);
      } else if (levelO(i) == level) {
        level = level * 1;
      } else {
        damage = baseDamage * levelO(i) * 10;
        HP = HP - damage;
      }
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (HP <= 0 && phoenixdown == 0) {
        rescue = 0;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i == eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = 1;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i != eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      } else if (HP > 0 && i == eventNum) {
        rescue = 1;
        break;
      } else if (HP > 0 && i != eventNum) {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 4
    if (eventCode[i] == 4) {
      if (isAuthur) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isLancelot) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      baseDamage = 7.5;
      if (levelO(i) < level) {
        level = min(level + 1, maxLevel);
      } else if (levelO(i) == level) {
        level = level * 1;
      } else if (levelO(i) > level) {
        damage = baseDamage * levelO(i) * 10;
        HP = HP - damage;
      }
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (HP <= 0 && phoenixdown == 0) {
        rescue = 0;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i == eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = 1;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i != eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      } else if (HP > 0 && i == eventNum) {
        rescue = 1;
        break;
      } else if (HP > 0 && i != eventNum) {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 5
    if (eventCode[i] == 5) {
      if (isAuthur) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isLancelot) {
        level = min(level + 1, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      baseDamage = 9.5;
      if (levelO(i) < level) {
        level = min(level + 1, maxLevel);
      } else if (levelO(i) == level) {
        level = level * 1;
      } else if (levelO(i) > level) {
        damage = baseDamage * levelO(i) * 10;
        HP = HP - damage;
      }
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (HP <= 0 && phoenixdown == 0) {
        rescue = 0;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i == eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = 1;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i != eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      } else if (HP > 0 && i == eventNum) {
        rescue = 1;
        break;
      } else if (HP > 0 && i != eventNum) {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 6
    if (eventCode[i] == 6) {
      if (tinyEvent == 1 || tinyEvent == 2) {
        tinyEvent++;
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      } else if (tinyEvent == 3) {
        tinyEvent = 0;
        HP = min(HP * 5, maxHP);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (frogEvent == 1 || frogEvent == 2) {
        frogEvent++;
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      } else if (frogEvent == 3) {
        frogEvent = 0;
        level = old_level;
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isAuthur) {
        level = min(level + 2, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isLancelot) {
        level = min(level + 2, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (level > levelO(i)) {
        level = min(level + 2, maxLevel);
      } else if (level == levelO(i))
        level *= 1;
      else {
        if (remedy >= 1) {
          remedy--;
        } else {
          old_HP = HP;
          tinyEvent++;
          if (HP < 5) {
            HP = 1;
          } else
            HP /= 5;
        }
      }
      if (HP <= 0 && phoenixdown == 0) {
        rescue = 0;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i == eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = 1;
        break;
      } else if (HP <= 0 && phoenixdown > 0 && i != eventNum) {
        HP = maxHP;
        phoenixdown--;
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      } else if (HP > 0 && i == eventNum) {
        rescue = 1;
        break;
      } else if (HP > 0 && i != eventNum) {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    while (tinyEvent && HP <= 0) {
      if (phoenixdown) {
        phoenixdown--;
        tinyEvent = 0;
        HP = maxHP;
      }
    }

    while (tinyEvent && remedy) {
      remedy--;
      tinyEvent = 0;
      HP = old_HP;
    }

    while (frogEvent && maidenkiss) {
      maidenkiss--;
      frogEvent = 0;
      level = old_level;
    }

    // Xu li su kien 7
    if (eventCode[i] == 7) {
      if (tinyEvent == 1 || tinyEvent == 2) {
        tinyEvent++;
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      } else if (tinyEvent == 3) {
        tinyEvent = 0;
        HP = min(HP * 5, maxHP);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (frogEvent == 1 || frogEvent == 2) {
        frogEvent++;
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      } else if (frogEvent == 3) {
        frogEvent = 0;
        level = old_level;
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isAuthur) {
        level = min(level + 2, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (isLancelot) {
        level = min(level + 2, maxLevel);
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      if (level > levelO(i)) {
        level = min(level + 2, maxLevel);
      } else if (level == levelO(i))
        level *= 1;
      else {
        if (maidenkiss >= 1) {
          maidenkiss--;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
        frogEvent++;
        old_level = level;
        level = 1;
      }
      if (i == eventNum) {
        rescue = 1;
        break;
      } else {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 11
    if (eventCode[i] == 11) {
      int n1 = ((level + phoenixdown) % 5 + 1) * 3;
      HP += s1(n1) % 100;
      HP = min(findPrimeNum(HP), maxHP);
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (i == eventNum) {
        rescue = 1;
        break;
      } else {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        continue;
      }
    }

    // Xu li su kien 12
    if (eventCode[i] == 12) {
      if (HP == 1) {
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      HP = findFibNum(HP);
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (i == eventNum) {
        rescue = 1;
        break;
      } else {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        continue;
      }
    }

    // Xu li su kien 13
    string stringEvent = to_string(eventCode[i]);
    string specialEvent = stringEvent.substr(0, 2);
    if (specialEvent == "13") {
      string mushGhostNum = stringEvent.substr(2);
      ifstream infile_mush_ghost(mush_ghost);
      int n2;
      string line;
      infile_mush_ghost >> n2;
      getline(infile_mush_ghost, line);
      int *arr = new int[n2];
      getline(infile_mush_ghost, line);
      stringstream ss(line);
      int index = 0;
      while (ss.good() && index < n2) {
        string substr;
        getline(ss, substr, ',');
        arr[index] = atoi(substr.c_str());
        index++;
      }
      for (int j = 0; j < mushGhostNum.size(); j++) {
        // Xu li nam ma loai 1
        if (mushGhostNum[j] == '1') {
          int minNum = 10e7, maxNum = -10e7;
          int maxi = 0, mini = 0;
          for (int k = 0; k < n2; k++) {
            if (arr[k] >= maxNum) { // Neu max thi cap nhat 2 bien max va maxi
              maxNum = arr[k];
              maxi = k;
            }
            if (arr[k] <= minNum) {
              minNum = arr[k];
              mini = k;
            }
          }
          HP -= (maxi + mini);
          HP = min(HP, maxHP);
          if (HP <= 0 && phoenixdown == 0) {
            rescue = 0;
            break;
          } else if (HP <= 0 && phoenixdown > 0) {
            HP = maxHP;
            phoenixdown--;
          }
        }
        // Xu li nam ma loai 2
        if (mushGhostNum[j] == '2') {
          int mtx = -2, mti = -3;
          bool isMount = true;
          // tìm giá trị và vị trí đỉnh núi
          int aMax = arr[0], iMax = 0;
          for (int k = 1; k < n2; k++) {
            if (arr[k] > aMax) {
              aMax = arr[k];
              iMax = k;
            }
          }
          // kiem tra hinh dang nui
          for (int k = 1; k < iMax; k++) {
            if (arr[k] <= arr[k - 1]) {
              isMount = false;
              break;
            }
          }
          if (isMount) {
            for (int k = iMax + 1; k < n2; k++) {
              if (arr[k] >= arr[k - 1]) {
                isMount = false;
                break;
              }
            }
          }
          if (isMount) {
            mtx = aMax;
            mti = iMax;
          } else {
            mtx = -2;
            mti = -3;
          }
          HP -= (mtx + mti);
          HP = min(HP, maxHP);
          if (HP <= 0 && phoenixdown == 0) {
            rescue = 0;
            break;
          } else if (HP <= 0 && phoenixdown > 0) {
            HP = maxHP;
            phoenixdown--;
          }
        }
        // Xu li nam ma loai 3
        if (mushGhostNum[j] == '3') {
          int minNum = 10e7, maxNum = -10e7;
          int *b = new int[n2];
          for (int k = 0; k < n2; k++) {
            b[k] = (17 * abs(arr[k]) + 9) % 257;
          }
          for (int k = 0; k < n2; k++) {
            if (b[k] > maxNum)
              maxNum = b[k];
            if (b[k] < minNum)
              minNum = b[k];
          }
          int maxi2 = 0, mini2 = 0;
          for (int k = 0; k < n2; k++) {
            if (b[k] == maxNum) {
              maxi2 += k;
              break;
            }
          }
          for (int k = 0; k < n2; k++) {
            if (b[k] == minNum) {
              mini2 += k;
              break;
            }
          }
          HP -= (maxi2 + mini2);
          HP = min(HP, maxHP);
          delete[] b;
          if (HP <= 0 && phoenixdown == 0) {
            rescue = 0;
            break;
          } else if (HP <= 0 && phoenixdown > 0) {
            HP = maxHP;
            phoenixdown--;
          }
        }
        // Xu li nam ma loai 4
        if (mushGhostNum[j] == '4') {
          int b[3];
          for (int k = 0; k < 3; k++) {
            b[k] = (17 * abs(arr[k]) + 9) % 257;
          }
          int max2_3x = -5, max2_3i = -7;
          for (int k = 0; k < 3; k++) {
            if (b[k] == secondMaxNum(b, n2)) {
              max2_3x = b[k];
              max2_3i = k;
              break;
            }
          }
          HP -= (max2_3x + max2_3i);
          HP = min(HP, maxHP);
          if (HP <= 0 && phoenixdown == 0) {
            rescue = 0;
            break;
          } else if (HP <= 0 && phoenixdown > 0) {
            HP = maxHP;
            phoenixdown--;
          }
        }
      }
      delete[] arr;
      if (HP <= 0) {
        rescue = 0;
        break;
      } else if (HP > 0 && i == eventNum) {
        rescue = 1;
        break;
      } else if (HP > 0 && i != eventNum) {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        continue;
      }
    }

    // Xu li su kien 15
    if (eventCode[i] == 15) {
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      remedy = min(remedy + 1, 99);
      while (tinyEvent && remedy) {
        remedy--;
        tinyEvent = 0;
        HP = old_HP;
      }
      if (i == eventNum) {
        rescue = 1;
        break;
      } else {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 16
    if (eventCode[i] == 16) {
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      maidenkiss = min(maidenkiss + 1, 99);
      while (frogEvent && maidenkiss) {
        maidenkiss--;
        frogEvent = 0;
        level = old_level;
      }
      if (i == eventNum) {
        rescue = 1;
        break;
      } else {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 17
    if (eventCode[i] == 17) {
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      phoenixdown = min(phoenixdown + 1, 99);
      if (i == eventNum) {
        rescue = 1;
        break;
      } else {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 18
    if (eventCode[i] == 18) {
      ++eve18Cnt;
      if (eve18Cnt > 1) {
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      string line, gift;
      int n9;
      ifstream infile_merlin_pack(merlin_pack);
      if (getline(infile_merlin_pack, line)) {
        stringstream ss(line);
        ss >> n9;
      }
      for (int j = 0; j < n9; j++) {
        if (getline(infile_merlin_pack, line)) {
          stringstream ss(line);
          ss >> gift;
          HP = min(HP + merlin_support(gift), maxHP);
        }
      }
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (i == eventNum) {
        rescue = 1;
        break;
      } else {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 19
    if (eventCode[i] == 19) {
      ++eve19Cnt;
      if (eve19Cnt > 1) {
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
          continue;
        }
      }
      int r1, c1;
      string line;
      ifstream infile_aclepius_pack(aclepius_pack);
      infile_aclepius_pack >> r1;
      getline(infile_aclepius_pack, line);
      infile_aclepius_pack >> c1;
      getline(infile_aclepius_pack, line);
      for (int j = 0; j < r1; j++) {
        int drugNum = 0;
        int *c1_arr = new int[c1];
        for (int k = 0; k < c1; k++) {
          infile_aclepius_pack >> c1_arr[k];
        }
        getline(infile_aclepius_pack, line);
        for (int k = 0; k < c1; k++) {
          if (drugNum == 3)
            break;
          if (c1_arr[k] == 16) {
            remedy = min(remedy + 1, 99);
            drugNum++;
          } else if (c1_arr[k] == 17) {
            maidenkiss = min(maidenkiss + 1, 99);
            drugNum++;
          } else if (c1_arr[k] == 18) {
            phoenixdown = min(phoenixdown + 1, 99);
            drugNum++;
          }
        }
        delete[] c1_arr;
      }
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (i == eventNum) {
        rescue = 1;
        break;
      } else {
        rescue = -1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
      }
    }

    // Xu li su kien 99
    if (eventCode[i] == 99) {
      CheckTiny_Frog(tinyEvent, frogEvent, HP, maxHP, level, old_level);
      if (isAuthur || (isLancelot && level >= 8) ||
          (!isAuthur && !isLancelot && level == 10)) {
        level = 10;
        if (i == eventNum) {
          rescue = 1;
          break;
        } else {
          rescue = -1;
          display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }
      } else {
        rescue = 0;
        break;
      }
    }
  }
  display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
  delete[] eventCode;
}