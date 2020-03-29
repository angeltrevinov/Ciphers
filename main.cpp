// Angel Odiel Treviño Villanueva
// A01336559

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// ===================== MAPS =======================
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
  //for alphabets that are coming backwords
  std::map<char, int, greater <char> > &temp_map,
  string              str
) {
  for(int i = str.length()-1, x=1; i >= 0; i--, x++) {
    temp_map[str[i]] = x;
  }
}
// -------------------------------------------------
void fillMapValues(
  std::map<char, char> &temp_map,
  string strKeys,
  string strValues
) {
  for (int i = 0; i < strKeys.length(); i++) {
    temp_map[strKeys[i]] = strValues[i];
  }
}
// -------------------------------------------------
void fillKeywordVector(
  // for keys that need to store their value in the position
  // of a certain alphabet
  std::map<char, int> &AlphabetMap,
  vector<int> &vectorKey,
  string strKey
) {
  for (int i = 0; i < strKey.length(); i++) {
    vectorKey.push_back(AlphabetMap[strKey[i]]);
  }
}
// --------------------------------------------------
void fillKeywordVectorMapBackwords(
  std::map<char, int, greater <char> > &temp_map,
  vector<int> &vectorKey,
  string strKey
) {
  for(int i = 0; i < strKey.length(); i++) {
    vectorKey.push_back(temp_map[strKey[i]]);
  }
}

// ================ HELPERCIPHERS ==================
// -------------------------------------------------
string shiftToRight(
  // this shift is for maps that dont need their order modified
  std::map<char, int> &temp_map,
  string              str,
  int                 intKey
) {
  std::map<char,int>::iterator it;
  string                       result;

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
      // keep the char as it was if not included in the alphabet
      result += str[i];
    }
  }

  return result;
}
// -------------------------------------------------
string shiftToRightBackwords(
  // this shift is for maps that come with descending order, basically does the
  // same but due to how maps work needs to be another function
  std::map<char, int, greater <char> > &temp_map,
  string                               str,
  int                                  intKey
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
      // keep the char as it was if not included in the alphabet
      result += str[i];
    }
  }

  return result;
}

// ================== CIPHERS =======================
// --------------------------------------------------
string encryptShiftCipher(
  string strAlphabet,
  string strKeyword,
  int    intKey
) {

  std::map<char, int> Alphabet;

  fillMap(Alphabet, strAlphabet);
  return shiftToRight(
    Alphabet,
    strKeyword,
    intKey
  );
}

// --------------------------------------------------
string decryptShiftCipher(
  string strAlphabet,
  string strKeyword,
  int    intKey
){

  std::map<char, int, greater <char> > Alphabet;

  fillMapBackwords(Alphabet, strAlphabet);
  return shiftToRightBackwords(
    Alphabet,
    strKeyword,
    intKey
  );
}
// --------------------------------------------------
string SubstitutionCipher(
  // do to Substitution Cipher changing the values then we just reverse who is
  // key and who is value inside our map
  string strAlphabetKey,
  string strAlphabetValue,
  string strKeyword
) {
  std::map<char, char>:: iterator it;
  std::map<char, char>            Alphabet;
  string                          result = "";

  fillMapValues(Alphabet, strAlphabetKey, strAlphabetValue);

  for(int i = 0; i < strKeyword.length(); i++) {

    it = Alphabet.find(strKeyword[i]);

    if(
      // check if we found our char
      it != Alphabet.end()
    ) {
      result += it->second;
    } else {
      result += strKeyword[i];
    }
  }
  return result;
}

// --------------------------------------------------
string encryptVigenereCipher(
  string strAlphabet,
  string strKey,
  string strKeyword
) {
  std::map<char, int> Alphabet;
  vector<int>         Key;
  string              result = "";
  string              send;
  int                 posVector;

  fillMap(Alphabet, strAlphabet);
  fillKeywordVector(Alphabet, Key, strKey);
  posVector = 0;
  for(int i = 0; i < strKeyword.length(); i++) {
    send = "";
    send.push_back(strKeyword[i]);
    result += shiftToRight(Alphabet, send, Key[posVector]-1);

    if (posVector < Key.size()-1) {
      posVector++;
    } else {
      posVector = 0;
    }
  }

  return result;
}
// --------------------------------------------------
string decryptVigenereCipher(
  string strAlphabet,
  string strKey,
  string strKeyword
) {
  std::map<char, int, greater <char> > Alphabet;
  vector<int>                         Key;
  string                              result = "";
  string                              send;
  int                                 posVector;

  fillMapBackwords(Alphabet, strAlphabet);
  fillKeywordVectorMapBackwords(Alphabet, Key, strKey);
  posVector = 0;
  for(int i = 0; i < strKeyword.length(); i++) {
    send = "";
    send.push_back(strKeyword[i]);
    result += shiftToRightBackwords(
      Alphabet,
      send,
      // we do this substraction because our alphabet is backwords
      strAlphabet.length() - Key[posVector]
    );

    if(posVector < Key.size()-1) {
      posVector++;
    } else {
      posVector = 0;
    }
  }
  return result;
}

// ================ INPUTCIPHERS ====================
// --------------------------------------------------
string useShiftCipher() {
  string option;
  string strAlphabet;
  string strKeyword;
  int    intKey;

  cout << "================================="  << endl;
  cout << "Enter your Alphabet"                << endl;
  getline(cin, strAlphabet);
  cout << "Enter your Keyword"                 << endl;
  getline(cin, strKeyword);
  cout << "Enter the Key"                      << endl;
  cin  >> intKey;
  cout << "================================="  << endl;
  cout << "Do you want to Encrypt or Decrypt?" << endl;
  cin  >> option;
  cin.ignore();

  if(
    option.compare("Encrypt") == 0
  ) {
    return encryptShiftCipher(strAlphabet, strKeyword, intKey);
  } else if(
    option.compare("Decrypt") == 0
  ) {
    return decryptShiftCipher(strAlphabet, strKeyword, intKey);
  } else {
    return "Could not understand " + option;
  }
}
// --------------------------------------------------
string useSubstitutionCipher() {
  string option;
  string strAlphabet;
  string strCipherAlphabet;
  string strKeyword;

  cout << "================================="  << endl;
  cout << "Enter your Alphabet"                << endl;
  getline(cin, strAlphabet);
  cout << "Enter your Cipher Alphabet"         << endl;
  getline(cin, strCipherAlphabet);
  cout << "Enter your Keyword"                 << endl;
  getline(cin, strKeyword);
  cout << "Do you want to Encrypt or Decrypt?" << endl;
  cin >> option;
  cin.ignore();

  if(
    strAlphabet.length() != strCipherAlphabet.length()
  ) {
    return "Alphabet's size don't match ";
  } else if(
    option.compare("Encrypt") == 0
  ) {
    return SubstitutionCipher(strAlphabet, strCipherAlphabet, strKeyword);
  } else if (
    option.compare("Decrypt") == 0
  ) {
    return SubstitutionCipher(strCipherAlphabet, strAlphabet, strKeyword);
  } else {
    return "Could not understand " + option;
  }
}
// -------------------------------------------------
string useVigenereCipher(
  // basically is Shift Cipher but the key changes depending on the value
  // of the character of our key on the alphabet
) {
  string strOption;
  string strAlphabet;
  string strKey;
  string strKeyword;
  cout << "================================="  << endl;
  cout << "Enter your Alphabet"                << endl;
  getline(cin, strAlphabet);
  cout << "Enter your Key"                     << endl;
  getline(cin, strKey);
  cout << "Enter your Keyword"                 << endl;
  getline(cin, strKeyword);
  cout << "Do you want to Encrypt or Decrypt?" << endl;
  cin >> strOption;
  cin.ignore();

  if(
    strOption.compare("Encrypt") == 0
  ) {
    return encryptVigenereCipher(strAlphabet, strKey, strKeyword);
  } else if (
    strOption.compare("Decrypt") == 0
  ) {
    return decryptVigenereCipher(strAlphabet, strKey, strKeyword);
  } else {
    return "Could not understand " + strOption;
  }
}

// ==================== MAIN =======================
// --------------------------------------------------
int main() {
  string result;
  int    intOption;

  cout << "=================================" << endl;
  cout << "What Cypher do you want to do?"    << endl;
  cout << "1. Shift Cipher"                   << endl;
  cout << "2. Substitution Cipher"            << endl;
  cout << "3. Vigenere Cipher"                << endl;
  cin  >> intOption;
  cin.ignore();

  if(intOption == 1) {
    result = useShiftCipher();
  } else if (intOption == 2) {
    result = useSubstitutionCipher();
  } else if (intOption == 3) {
    result = useVigenereCipher();
  }
  cout << "================================="  << endl;
  cout << result                               << endl;

  return 0;
}
