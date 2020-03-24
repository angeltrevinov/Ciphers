// Angel Odiel Treviño Villanueva
// A01336559

#include <iostream>
#include <map>
#include <string>

using namespace std;

// --------------------------------------------------
void fillMap(
  std::map<char, int> &temp_map,
  string              str
) {
  for(int i = 0; i < str.length(); i++) {
    temp_map[str[i]] = i+1;
  }
}

// -------------------------------------------------
void fillMapBackwords(
  std::map<char, int, greater <char> > &temp_map,
  string              str
) {
  for(int i = str.length()-1, x=1; i >= 0; i--, x++) {
    temp_map[str[i]] = x;
  }
}

// -------------------------------------------------
string shiftToRight(
  // this shift is for maps that dont need their order modified
  std::map<char, int> &temp_map,
  string              str,
  int                 intKey
) {
  std::map<char,int>::iterator it;
  string result;

  for(int i = 0; i < str.length(); i++) {

    it = temp_map.find(str[i]);
    if(
      //check if we found our char
      it != temp_map.end()
    ) {
      int pos = it->second;
      if(
        // check if we havent pass the size of the map
        it->second + intKey < temp_map.size()
      ) {
        while(it != temp_map.end()){
          if(
            it->second == pos+intKey
          ) {
            result += it->first;
            break;
          }
          it++;
        }
      } else {
        int intPos = (intKey + it->second) % temp_map.size();
        if(intPos == 0) {
          intPos += temp_map.size();
        }
        it = temp_map.begin();
        while(it != temp_map.end()) {
          if(
            it->second == intPos
          ) {
            result += it->first;
            break;
          }
          it++;
        }
      }
    } else {
      result += str[i];
    }
  }

  return result;
}

// -------------------------------------------------
string shiftToRightBackwords(
  // this shift is for maps that come with descending order,
  //basically does the same but due to how maps work need to do another function
  std::map<char, int, greater <char> > &temp_map,
  string              str,
  int                 intKey
) {
  std::map<char,int>::iterator it;
  string result;

  for(int i = 0; i < str.length(); i++) {

    it = temp_map.find(str[i]);
    if(
      //check if we found our char
      it != temp_map.end()
    ) {
      int pos = it->second;
      if(
        // check if we havent pass the size of the map
        it->second + intKey < temp_map.size()
      ) {
        while(it != temp_map.end()){
          if(
            it->second == pos+intKey
          ) {
            result += it->first;
            break;
          }
          it++;
        }
      } else {
        int intPos = (intKey + it->second) % temp_map.size();
        if(intPos == 0) {
          intPos += temp_map.size();
        }
        it = temp_map.begin();
        while(it != temp_map.end()) {
          if(
            it->second == intPos
          ) {
            result += it->first;
            break;
          }
          it++;
        }
      }
    } else {
      result += str[i];
    }
  }

  return result;
}

// --------------------------------------------------
string encryptShiftCipher(
  string strAlphabet,
  string strKeyword,
  int    intKey
) {
  std::map<char,int> Alphabet;
  string             strEncrypt;

  fillMap(Alphabet, strAlphabet);
  strEncrypt = shiftToRight(
    Alphabet,
    strKeyword,
    intKey
  );
  return strEncrypt;
}

// --------------------------------------------------
string decryptShiftCipher(
  string strAlphabet,
  string strKeyword,
  int intKey
){
  std::map<char, int, greater <char> > Alphabet;
  string              strDecrypt;
  fillMapBackwords(Alphabet, strAlphabet);
  strDecrypt = shiftToRightBackwords(
    Alphabet,
    strKeyword,
    intKey
  );
  return strDecrypt;
}

// --------------------------------------------------
int main() {
  string strAlphabet;
  string strKeyword;
  string result;
  int    intKey;
  int    intOption;

  cout << "What do you want to do?" << endl;
  cout << "1. Encrypt Shift Cipher" << endl;
  cout << "2. Decrypt Shift Cipher" << endl;
  cin >> intOption;
  cin.ignore();
  cout << "Enter your Alphabet" << endl;
  getline(cin, strAlphabet);
  cout << "Enter your Keyword" << endl;
  getline(cin, strKeyword);
  cout << "Enter the Key" << endl;
  cin  >> intKey;

  if(intOption == 1) {
    result = encryptShiftCipher(strAlphabet, strKeyword, intKey);
  } else if (intOption == 2) {
    result = decryptShiftCipher(strAlphabet, strKeyword, intKey);
  }

  cout << result << endl;

  return 0;
}
