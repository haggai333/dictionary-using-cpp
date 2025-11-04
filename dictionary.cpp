#include<iostream>

#include<vector>
#include<fstream>
#include<string>
#include<cctype>
#include <cstdlib> 
#include<ctime>
using namespace std;

void pronounce_with_festival(const std::string& text) {
    std::string command = "echo \"" + text + "\" | festival --tts";
    system(command.c_str());
}


#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

struct  words{
  string word;
  string definition;
  string synonym; 
   
};
string lowwers(string a){
string b;
for(int i=0;i<a.size();i++){
  b+=tolower(a[i]);
  
}
return b;
}
void clearScreen() {
    system(CLEAR_COMMAND);
}
void reads(const std::string& text) {
  std::string command = "echo \"" + text + "\" | festival --tts";
  system(command.c_str());
}
void spellingbee(vector<words>a){
  clearScreen();
  srand(time(0));
  string i,k;
  int index = rand() % a.size(),n=0;
  cout<<"===============spelling bee game================="<<endl<<endl;
  cout<<"you have 5 chances to spell the word correct  the length of the word is   "<<a[index].word.size()<<endl<<endl;
 
 reads(a[index].word);
while(n<5){
   cout<<"spell the word or if you want to listen again press 1  ";
   cout<<"you have "<<5-n<<"    tries left "<<endl<<"input";
   cin>>i;
   cout<<endl<<endl;

   if(lowwers(i)=="1"){
    reads(a[index].word);
    clearScreen();
     continue;
   }
   else{
    k+="  " +i;
     if(lowwers(i)==lowwers(a[index].word)){
      cout<<"congrats you spelled the word"<<endl<<endl;
      cout<<"definition :"<<a[index].definition<<endl;
      cout<<"press a key to continue ";

      cin.ignore();
      cin.get();
      clearScreen();
      return;
     }
     

   n++;}
  
   
}
cout<<"your trials were";
cout<<"your tries were"<<endl<<k<<endl;
 cout<<"the correct spelling is "<<a[index].word;
   cin.ignore();
   cin.get();
   clearScreen();
}


void loadSynonymsToStruct(vector<words>& entries, const string& synonymFile) {
  ifstream infile(synonymFile);
  string line;

  int index = 0;
  while (getline(infile, line) && index < entries.size()) {
      
      size_t firstSpacePos = line.find(' ');
      if (firstSpacePos != string::npos) {
          
          string synonyms = line.substr(firstSpacePos + 1);
          entries[index].synonym = synonyms;  
      }

      index++;
  }
}





void load(vector<words>& entries, const string& filename) {
  ifstream infile(filename);
  string line;
 

  while (std::getline(infile, line)) {
      if (line.empty()) continue;

      size_t colonPos = line.find(':');
      if (colonPos == string::npos) continue;

      string word = line.substr(0, colonPos);
      string definition = line.substr(colonPos + 1);

      
      definition.erase(0, definition.find_first_not_of(" \t"));

      entries.push_back({word, definition});
  }

 
}



void search(vector<words>&a,string tosearch,int sp,int c=-1){
  
  int left=0,right=sp-1,mid;
  int result=-1;
 

while(right>=left){
 mid=(left+right)/2;
 if(lowwers(a[mid].word)==lowwers(tosearch)){
  result=mid;
  break;
 }
 else if(lowwers(a[mid].word)<lowwers(tosearch)){
  left=mid+1;
 }
 else{
   right=mid-1; 
 }
 
}


if(c==1)
{
  c=mid;
}
if(result==-1){
cout<<"word not found";
cin.ignore();
cin.get();
clearScreen();
}
else if(result!=-1&&c==-1){
  clearScreen();
cout<<"word found"<<endl<<endl;
cout<<a[result].word<<endl<<"definition    "<<a[result].definition<<endl<<"press a key to continue";
cin.ignore();
cin.get();
clearScreen();
}
else if(c==-1){
  cout<<"word not found";
cin.ignore();
cin.get();
clearScreen();
}
else if(c!=-1){
  clearScreen();
cout<<"word found"<<endl<<endl;
cout<<a[result].word<<endl<<"synonyms are......    "<<a[result].synonym<<endl<<"press a key to continue";
cin.ignore();
cin.get();
clearScreen();

}
}
void getsynonym(vector<words>&a,int size){
  string c;
  cout<<"enter a word to be searched    ";
  cin>>c;
  search(a,c,size,1);


}
void quiz(const vector<words>& a) {
  srand(time(0));
  int randomIndex = rand() % a.size();
  clearScreen();
  cout<<"Guess the Word Quiz!" << endl;
  cout << "Definition: " << a[randomIndex].definition << endl;

  string guess;
  int attempts = 3;

  while (attempts > 0) {
      cout << "Guess the word (" << attempts << " tries left): ";
      cin >> guess;

      if (lowwers(guess) == lowwers(a[randomIndex].word)) {
          cout << "Correct!" << endl;
          cout << "The word was: " << a[randomIndex].word << endl;
          cout<<"press any key to continue";
          cin.ignore();
          cin.get();
          clearScreen();
          cout << "Thanks for playing!" << endl;
          return;
      } else {
          cout << "Wrong! Try again." << endl;
          attempts--;
      }
      if(attempts==1){
        cout<<"Hint: The first letter is: "<<a[randomIndex].word[0]<<endl<<endl<<"and its synonyms is   "<<a[randomIndex].synonym<<endl;
      }
  }

  
  cout << "Out of tries! The word was: " << a[randomIndex].word << endl;
  cout<<"press any key to continue";
  cin.ignore();
  cin.get();
  clearScreen();
}

  void getwordoftheday(vector<words>& a, int size) {
     srand(time(0));
     int randomIndex = rand() % size;
     clearScreen();
    cout << "Word of the Day:" << endl << endl;
    cout << "Word: " << a[randomIndex].word << endl;
    cout << "Definition: " << a[randomIndex].definition << endl;
    cout << "Synonyms: " << a[randomIndex].synonym << endl;
    cout << endl << "Press any key to continue...";
    cin.ignore();
    cin.get();
    clearScreen();
}


int main(){
    int c,size=89517;
    vector<words> a;
    load(a,"order.txt");
    loadSynonymsToStruct(a,"synons.txt");
      
 do {
      cout<<"Dictionary and word search"<<endl;
      cout<<"1.search a word"<<endl;
      cout<<"2.get synonym"<<endl;
      cout<<"3.get word of the day"<<endl;
      cout<<"4.play guess the word quiz"<<endl;
      cout<<"5.play spelling bee quiz"<<endl;
      cout<<"6.exit"<<endl<<endl;
      cout<<"enter a choice \t";
      cin>>c;
      if (cin.fail()) {
        clearScreen();
        cout << "Invalid input! Please enter a number between 1 and 6." << endl;
        cin.clear(); 
        cin.ignore(100, '\n'); 
        continue; 
    }
      cout<<endl;
      
      if(c==1){
        string c;
        cout<<"enter a word to be searched    ";
        cin>>c;
        search(a,c,size);
      }
      else if (c==2){
        
        getsynonym(a,size);


      }
      else if (c==3){
         getwordoftheday(a,size);
      }
      else if(c==4){
        cout<<"play guess the word quiz"<<endl;
        quiz(a);
      }
      else if (c==5){
        spellingbee(a);
      }
      else if (c==6){
        cout<<"exiting.......";
      }
      else  {
        cout<<"enter a valid choice"<<endl;
        
      }
    
   
    

    }
    
    while(c!=6);

    return 0;
  }