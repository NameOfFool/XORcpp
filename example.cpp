#include <iostream>
#include <string>
#include <vector>
// #include <windows.h>

using namespace std;

vector<int> encryption(wstring message = L"БЕГЕМОТ", wstring key = L"КОТ", wstring alphabet = L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХчЦцЧчШшЩщЪъЫыЬьЭэЮюЯя ")
{ 
  vector<int> result;
  for(int i = 0; i < message.length(); i++)
  {
    int n = (alphabet.find(message[i]) ^ alphabet.find(key[i % key.length()]));
    result.push_back(n);
  }
  return result;
}
vector<int> encryption(vector<int> message, wstring key = L"КОТ", wstring alphabet = L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХчЦцЧчШшЩщЪъЫыЬьЭэЮюЯя ")
{ 
  vector<int> result;
  for(int i = 0; i < message.size(); i++)
  {
    int n = (message[i] ^ alphabet.find(key[i % key.length()]));
    result.push_back(n);
  }
  return result;
}
wstring output(vector<int> salt, wstring alphabet = L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХчЦцЧчШшЩщЪъЫыЬьЭэЮюЯя ")
{

  vector<wchar_t> result;
  for(int i = 0; i < salt.size(); i++)
  {
    result.push_back(alphabet[salt[i] % alphabet.length()]);
  }
  return wstring(result.begin(), result.end());
}

int main(){
  #if defined(__linux__)
    setlocale(LC_ALL, "ru_RU.UTF-8");
  #elif _WIN32
      setlocale(LC_ALL, "Russian");
  #endif
  // SetConsoleOutputCP(1251);
  // SetConsoleCP(1251);
  wstring message;
  wstring key;
  wcout << L"Введите сообщение:";
  getline(wcin, message);
  wcout << L"Введите ключ:";
  wcin >> key;
  vector<int> e = encryption(message, key);
  vector<int> d = encryption(e, key);
  wcout << L"Шифр:" << output(e) <<endl;
  wcout << L"Расшифровка:" << output(d) << endl;
  // system("pause");
  return 0;
}
