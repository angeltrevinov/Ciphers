// Angel Odiel Treviño Villanueva
// A01336559

#include <iostream>
#include <map>
#include <string>

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
  int    intKey
){

  std::map<char, int, greater <char> > Alphabet;
  string                               strDecrypt;

  fillMapBackwords(Alphabet, strAlphabet);
  strDecrypt = shiftToRightBackwords(
    Alphabet,
    strKeyword,
    intKey
  );
  return strDecrypt;
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

// ==================== MAIN =======================
// --------------------------------------------------
int main() {
  string result;
  int    intOption;

  cout << "=================================" << endl;
  cout << "What Cypher do you want to do?"    << endl;
  cout << "1. Shift Cipher"                   << endl;
  cout << "2. Substitution Cipher"            << endl;
  cin  >> intOption;
  cin.ignore();

  if(intOption == 1) {
    result = useShiftCipher();
  } else if (intOption == 2) {
    result = useSubstitutionCipher();
  }
  cout << "================================="  << endl;
  cout << result                               << endl;

  return 0;
}
