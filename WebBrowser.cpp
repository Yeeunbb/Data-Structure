<<<<<<< HEAD
#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

class Web_browser{
   string addrList[MAX_SIZE];
   string addrHome;
   string addrHistory[MAX_SIZE];
   int current;
   int length;
   int historyCurrent;
   int historyLength;

public:
   Web_browser();
   void go(string addr);
   void forward();
   void backward();
   void home();
   void set_home(string addr);
   void history();
   void quit();
};

int main()
{
   Web_browser wb;
   string command;
   string addr;
   string EXITCMD = "exit";

   while(cin>>command){
      if(command == EXITCMD){
         wb.quit();
      }
      else if(command == "go"){
         cin>>addr;
         wb.go(addr);
      }
      else if(command == "forward"){
         wb.forward();
      }
      else if(command == "backward"){
         wb.backward();
      }
      else if(command == "home"){
         wb.home();
      }
      else if(command == "set_home"){
         cin>>addr;
         wb.set_home(addr);
      }
      else if(command == "history"){
         wb.history();
      }
   }
   return 0;
}

Web_browser::Web_browser(){
   current =0;
   historyCurrent=0;
   addrHome="http://ces.hufs.ac.kr";
   length=1;
   historyLength=1;
   cout<<addrHome<<endl;
}
void Web_browser::go(string addr){
   if(current<=MAX_SIZE-1){ //current <= MAX_SIZE - 1
      current++;
      addrList[current]=addr;
      length=current+1;
      cout<<addrList[current]<<endl;
   }
   historyLength++;
   historyCurrent++;
   addrHistory[historyCurrent]=addr;
}
void Web_browser::forward(){
   if(current<length-1){
      current++;
   }
   cout<<addrList[current]<<endl;
}
void Web_browser::backward(){
   if(current != 0){
      current--;
   }
   cout<<addrList[current]<<endl;
}
void Web_browser::home(){
   if(current<MAX_SIZE-1){
      current++;
      addrList[current]=addrHome;
      length=current+1;
   }
   historyCurrent++;
   historyLength++;
   addrHistory[historyCurrent]=addrHome;
   cout<<addrList[current]<<endl;
}
void Web_browser::set_home(string addr){
   addrHome=addr;
}
void Web_browser::history(){
   if(historyLength<=10){
      cout<<addrHome<<endl;
      for(int i=1; i<length; i++){
         cout<<addrHistory[i]<<endl;
      }
   }
   else{ //historyLength>10
      for(int i=historyLength-10; i<historyLength; i++){
         cout<<addrHistory[i]<<endl;
      }
   }
}
void Web_browser::quit(){
   exit(0);
}


=======
#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

class Web_browser{
   string addrList[MAX_SIZE];
   string addrHome;
   string addrHistory[MAX_SIZE];
   int current;
   int length;
   int historyCurrent;
   int historyLength;

public:
   Web_browser();
   void go(string addr);
   void forward();
   void backward();
   void home();
   void set_home(string addr);
   void history();
   void quit();
};

int main()
{
   Web_browser wb;
   string command;
   string addr;
   string EXITCMD = "exit";

   while(cin>>command){
      if(command == EXITCMD){
         wb.quit();
      }
      else if(command == "go"){
         cin>>addr;
         wb.go(addr);
      }
      else if(command == "forward"){
         wb.forward();
      }
      else if(command == "backward"){
         wb.backward();
      }
      else if(command == "home"){
         wb.home();
      }
      else if(command == "set_home"){
         cin>>addr;
         wb.set_home(addr);
      }
      else if(command == "history"){
         wb.history();
      }
   }
   return 0;
}

Web_browser::Web_browser(){
   current =0;
   historyCurrent=0;
   addrHome="http://ces.hufs.ac.kr";
   length=1;
   historyLength=1;
   cout<<addrHome<<endl;
}
void Web_browser::go(string addr){
   if(current<=MAX_SIZE-1){ //current <= MAX_SIZE - 1
      current++;
      addrList[current]=addr;
      length=current+1;
      cout<<addrList[current]<<endl;
   }
   historyLength++;
   historyCurrent++;
   addrHistory[historyCurrent]=addr;
}
void Web_browser::forward(){
   if(current<length-1){
      current++;
   }
   cout<<addrList[current]<<endl;
}
void Web_browser::backward(){
   if(current != 0){
      current--;
   }
   cout<<addrList[current]<<endl;
}
void Web_browser::home(){
   if(current<MAX_SIZE-1){
      current++;
      addrList[current]=addrHome;
      length=current+1;
   }
   historyCurrent++;
   historyLength++;
   addrHistory[historyCurrent]=addrHome;
   cout<<addrList[current]<<endl;
}
void Web_browser::set_home(string addr){
   addrHome=addr;
}
void Web_browser::history(){
   if(historyLength<=10){
      cout<<addrHome<<endl;
      for(int i=1; i<length; i++){
         cout<<addrHistory[i]<<endl;
      }
   }
   else{ //historyLength>10
      for(int i=historyLength-10; i<historyLength; i++){
         cout<<addrHistory[i]<<endl;
      }
   }
}
void Web_browser::quit(){
   exit(0);
}


>>>>>>> 703c4cd30b5df7fc525d0c1e7238cdd23ea21d06
