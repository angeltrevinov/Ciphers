// Angel Odiel Treviño Villanueva
// A01336559

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// =============== STRUCTURESFILLER ========================
// ---------------------------------------------------------
void fillMap(
  std::map<char, int> &temp_map,
  string              str
) {
  for(int i = 0; i < str.length(); i++) {
    temp_map[str[i]] = i+1;
  }
}
// ---------------------------------------------------------
void fillMapAlphabetValues(
  std::map<int, char> &temp_map,
  string              str
) {
  for(int i = 0; i < str.length(); i++) {
    temp_map[i] = str[i];
  }
}
// ---------------------------------------------------------
void fillMapBackwords(
  //for alphabets that are coming backwords
  std::map<char, int, greater <char> > &temp_map,
  string              str
) {
  for(int i = str.length()-1, x=1; i >= 0; i--, x++) {
    temp_map[str[i]] = x;
  }
}
// ---------------------------------------------------------
void fillMapValues(
  std::map<char, char> &temp_map,
  string strKeys,
  string strValues
) {
  for (int i = 0; i < strKeys.length(); i++) {
    temp_map[strKeys[i]] = strValues[i];
  }
}
// ---------------------------------------------------------
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
// ---------------------------------------------------------
void fillKeywordVectorMapBackwords(
  std::map<char, int, greater <char> > &temp_map,
  vector<int> &vectorKey,
  string strKey
) {
  for(int i = 0; i < strKey.length(); i++) {
    vectorKey.push_back(temp_map[strKey[i]]);
  }
}
// ---------------------------------------------------------
void fillVectorKeyValue(
  vector<int> &vectorKey,
  string strKey
) {
  int intAux;
  string strAux;
  for(int i = 0; i < strKey.length(); i++) {
    if(strKey[i] == '-') {
      intAux = stoi(strAux);
      vectorKey.push_back(intAux);
      strAux = "";
    } else {
      strAux += strKey[i];
    }
  }
  intAux = stoi(strAux);
  vectorKey.push_back(intAux);
}
// ---------------------------------------------------------
void fillVectorString(
  vector<char> &vector,
  string str
) {
  for(int i = 0; i < str.length(); i++) {
    vector.push_back(str[i]);
  }
}
// ---------------------------------------------------------
void fillMatrix(
  vector<vector<int> > &Matrix,
  int intRow,
  int intCol,
  string str
) {
  int intCont = 0;
  for(int i = 0; i < intRow; i++) {
    for(int j = 0; j < intCol; j++) {
      Matrix[i][j] = str[intCont];
      intCont++;
    }
  }
}
// ---------------------------------------------------------
string generateRandomString(int size) {
  string result = "";
  char   alphabet[] = "01";
  srand(time(0));
  for(int i = 0; i < size; i++) {
    result += alphabet[rand() %(sizeof(alphabet) - 1)];
  }
  return result;
}
// ---------------------------------------------------------
string generateKeyPermutation(int size) {
  string result = "";
  vector<int> storage;
  int aux;
  srand(time(0));
  for(int i = 1; i <= size; i++) {
    storage.push_back(i);
  }

  // loop to create new number
  for(int i = 0; i < size; i++) {
    aux = rand() % storage.size();
    result += std::to_string(storage[aux]);
    if (i < size-1) {
      result += '-';
    }
    storage.erase(storage.begin() + aux);
  }
  return result;
}
//----------------------------------------------------------
void fillFile(
  vector<string> &collection,
  string strName
) {
  ofstream myfile;
  string aux = "";
  myfile.open(strName);
  for(int i = 0; i < collection.size(); i++) {
    aux = collection[i];
    for(int j = 0; j < aux.length(); j++) {
      myfile << aux[j];
      if (j < aux.length()-1) {
        myfile << ",";
      }
    }
    myfile << "\n";
  }
  myfile.close();
}

// ================ HELPERCIPHERS ==========================
// ---------------------------------------------------------
string shiftToRight(
  // this shift is for maps that dont need their order
  // modified
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
// --------------------------------------------------------
string shiftToRightBackwords(
  // this shift is for maps that come with descending order,
  // basically does the same but due to how maps work needs
  // to be another function
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

// ================== CIPHERS ==============================
// ---------------------------------------------------------
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
// ---------------------------------------------------------
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
// ---------------------------------------------------------
string SubstitutionCipher(
  // do to Substitution Cipher changing the values then we
  // just reverse who is key and who is value inside our map
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
// ---------------------------------------------------------
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
// ---------------------------------------------------------
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
  // -------------------------------------------------
  string encryptPermutationCipher(
    string strKey,
    string strKeyword
  ) {
    vector<int>  Key;
    vector<char> Letters;
    string       strAux;
    string       result;
    int          intPos;
    fillVectorKeyValue(Key, strKey);
    if(
      Key.size() > strKey.length()
    ) {
      return "A number inside the key is bigger than the size of the key";
    } else {

      intPos = 0;
      while (intPos < strKeyword.length()) {
        Letters.clear();
        strAux = strKeyword.substr(intPos, strKey.length());
        fillVectorString(Letters, strAux);

        if(
          Letters.size() < Key.size()
        ) {
          for (int i = Letters.size(); i <= strAux.length(); i++) {
            Letters.push_back('A');
          }
        }
        for (int i = 0; i < Letters.size(); i++) {
          result+= Letters[Key[i]-1];
        }
        intPos+= strKey.length();
      }
      return result;
    }
  }
// ---------------------------------------------------------
string decryptPermutationCipher(
  string strKey,
  string strKeyword
) {
  vector<int>  Key;
  vector<char> Letters;
  vector<char> Result;
  string       strAux;
  string       result = "";
  int          intPos;
  fillVectorKeyValue(Key, strKey);
  if(
    Key.size() > strKey.length()
  ) {
    return "A number inside the key is bigger than the size of the key";
  } else {
    int intPos = 0;
    while(intPos < strKeyword.length()) {
      Letters.clear();
      Result.clear();
      for(int i = 0; i < strKey.length(); i++) {
        Result.push_back(' ');
      }

      strAux = strKeyword.substr(intPos, strKey.length());
      fillVectorString(Letters, strAux);

      for (int i = 0; i < Letters.size(); i++) {
        Result[Key[i]-1] = Letters[i];
      }
      for (int i = 0; i < Result.size(); i++) {
        result += Result[i];
      }
      intPos+= strKey.length();
    }
    return result;
  }
}
// ---------------------------------------------------------
string TranspositionCipher(
  // Option help us determine how to fill out matrix
  string strKeyword,
  int intKey,
  int intOption
) {
  string strResult = "";
  int    intRow;
  int    intCol;

  if (
    // we are encrypting
    intOption == 0
  ) {
    intRow = strKeyword.length() / intKey;
    intCol = intKey;
    if (
      strKeyword.length() % intKey > 0
    ){
      intRow++;
    }
  } else {
    intCol = strKeyword.length() / intKey;
    intRow = intKey;
    if (
      strKeyword.length() % intKey > 0
    ){
      intCol++;
    }
  }

  vector<vector<int> > Matrix(intRow, vector<int>(intCol));

  fillMatrix(Matrix, intRow, intCol, strKeyword);

  for(int i = 0; i < intCol; i++) {
    for(int j = 0; j < intRow; j++) {
      strResult += Matrix[j][i];
    }
  }

  return strResult;

}
// ---------------------------------------------------------
string encryptMultiplicationCipher() {
  std::map<char, int>::iterator it;
  std::map<char, int> Alphabet;
  std::map<int, char> AlphabetValue;
  string strKey;
  string strAlphabet;
  string strKeyword;
  string strResult = "";
  int intKey;
  int Pos;

  cout << "================================="  << endl;
  cout << "Enter your Alphabet"                << endl;
  getline(cin, strAlphabet);
  cout << "Enter your Keyword"                 << endl;
  getline(cin, strKeyword);
  cout << "Enter your Key"                     << endl;
  cin >> intKey;

  fillMap(Alphabet, strAlphabet);
  fillMapAlphabetValues(AlphabetValue, strAlphabet);

  for(int i = 0; i < strKeyword.length(); i++) {
    it = Alphabet.find(strKeyword[i]);
    if(
      it != Alphabet.end()
    ){
      Pos = ((it->second-1) * intKey)%26;
      strResult += AlphabetValue[Pos];
    } else {
      strResult += strKeyword[i];
    }
  }
  return strResult;
}

// ================ INPUTCIPHERS ===========================
// ---------------------------------------------------------
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
// ---------------------------------------------------------
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
// ---------------------------------------------------------
string useVigenereCipher(
  // basically is Shift Cipher but the key changes depending
  // on the value of the character of our key on the alphabet
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
// ---------------------------------------------------------
string usePermutationCipher() {
  string strOption;
  string strKey;
  string strKeyword;
  cout << "================================="  << endl;
  cout << "Enter your Key, enter divided by -" << endl;
  getline(cin, strKey);
  cout << "Enter your keyword"                 << endl;
  getline(cin, strKeyword);
  cout << "Do you want to Encrypt or Decrypt"  << endl;
  cin >> strOption;
  cin.ignore();

  if(
    strOption.compare("Encrypt") == 0
  ) {
    return encryptPermutationCipher(strKey, strKeyword);
  } else if (
    strOption.compare("Decrypt") == 0
  ) {
    return decryptPermutationCipher(strKey, strKeyword);
  } else {
    return "Could not understand " + strOption;
  }
}
// ---------------------------------------------------------
string useTranspositionCipher() {
  string strOption;
  string strKeyword;
  int    intKey;
  cout << "================================="  << endl;
  cout << "Enter your Key"                     << endl;
  cin  >> intKey;
  cin.ignore();
  cout << "Enter your Keyword"  << endl;
  getline(cin, strKeyword);
  cout << "Do you want to Encrypt or Decrypt?" << endl;
  cin >> strOption;
  cin.ignore();

  if (
    strOption.compare("Encrypt") == 0
  ) {
    return TranspositionCipher(strKeyword, intKey, 0);
  } else if (
    strOption.compare("Decrypt") == 0
  ) {
    return TranspositionCipher(strKeyword, intKey, 1);
  } else {
    return "Could not understand " + strOption;
  }
}
// ---------------------------------------------------------
void fillBunchPermutation() {
  vector<string> plainText;
  vector<string> cipherText;
  int            intMany;
  int            intOption;
  string         aux;
  string         key;
  string         firstFile;
  string         secondFile;
  cout << "=================================" << endl;
  cout << "How many do you need?"             << endl;
  cin  >> intMany;
  cout << "Name to store your plain strings?" << endl;
  cin  >> firstFile;
  cout << "Name to store your cipher strings?" << endl;
  cin >> secondFile;
  cout << "Do you want a 1.random key or 2.your own?" << endl;
  cin >> intOption;

  // generate our plain strings
  for (int i = 0; i < intMany; i++) {
    aux = generateRandomString(25);
    if(
      // check if its not 0
      aux.compare("0000000000000000000000000") == 0
    ) {
      i--;
    } else {
      plainText.push_back(aux);
    }
  }
  if (intOption == 1) {
    key = generateKeyPermutation(25);
  } else if (intOption == 2) {
    cout << "Enter Key, numbers divided by -" << endl;
    cin >> key;
  }
  cout << "Key= " << key << endl;
  cout << "=================================" << endl;
  aux = "";
  // generate cipher text
  for(int i = 0; i < intMany; i++) {
    aux = encryptPermutationCipher(key, plainText[i]);
    cipherText.push_back(aux);
  }

  fillFile(plainText, firstFile);
  fillFile(cipherText, secondFile);

}

// ==================== MAIN ===============================
// ---------------------------------------------------------
int main() {
  string result;
  int    intOption;

  cout << "=================================" << endl;
  cout << "What Cypher do you want to do?"    << endl;
  cout << "1. Shift Cipher"                   << endl;
  cout << "2. Substitution Cipher"            << endl;
  cout << "3. Vigenere Cipher"                << endl;
  cout << "4. Permutation Cipher"             << endl;
  cout << "5. Transposition Cipher"           << endl;
  cout << "6. Encrypt Multiplication Cipher"  << endl;
  cout << "7. generate a ton of permutation"  << endl;
  cin  >> intOption;
  cin.ignore();

  if(intOption == 1) {
    result = useShiftCipher();
  } else if (intOption == 2) {
    result = useSubstitutionCipher();
  } else if (intOption == 3) {
    result = useVigenereCipher();
  } else if (intOption == 4) {
    result = usePermutationCipher();
  } else if (intOption == 5) {
    result = useTranspositionCipher();
  } else if (intOption == 6) {
    result = encryptMultiplicationCipher();
  } else if (intOption == 7) {
    fillBunchPermutation();
    result = "done";
  }
  cout << "================================="  << endl;
  cout << result                               << endl;

  return 0;
}
