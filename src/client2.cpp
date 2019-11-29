#include "Request.h"
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <sys/time.h>

// struct timeval {
// 	time_t tv_sec; /* segundos */
// 	suseconds_t tv_usec; /* microsegundos */
// };

typedef struct timeval TimeVal;

using namespace std;

Request r;
const int num_servers = 1;
vector<thread> ths;
vector<string> book_words[num_servers];

int total_words = 0;

void sendWord(const string & ip, uint16_t puerto, string *reg) {
	size_t len_reply;
  try {
    //cout << "from sendWord: ";
    //cout << *reg << endl;
    //cout << ip << " " << puerto << '\n';
    vector <char> buffer;
    for(int i = 0; i < (*reg).length(); i++)
      buffer.push_back((*reg)[i]);
    int cont = *(int *)r.doOperation(ip, puerto,
                                   Message::allowedOperations::readWords,
                                   (char *)&buffer[0], buffer.size(), len_reply);
    total_words += cont;
  } catch (const char *msg) {
    throw msg;
  }
}

void handler(const string & ip, uint16_t puerto, int pos)
{
	for(int i = 0; i < book_words[pos].size(); ++i){
    try {
      cout <<"from handler: "<< book_words[pos][i] << '\n';
  		sendWord(ip, puerto, &book_words[pos][i]);
    } catch(const char *msg)
    {
      cerr << msg << "\n";
    }
	}
}

int main(int argc, char *argv[])
{
  string ip[num_servers];
  uint16_t puerto;
  cout << "Direcciones IPs de los servidores: ";
  for (int i = 0; i < num_servers; i++) cin >> ip[i];
  cout << "Puerto de los servidores: ";
  cin >> puerto;
  int n = atoi(argv[1]);

  FILE *f = fopen(argv[2], "rb");
  ifstream fin(string(argv[2]),ifstream::in);
  string reg;
  int last = 0;
  while (n-- && fin >> reg)
  {
          //int last = reg.celular[9] - '0';
          cout << reg << endl;
          book_words[last % num_servers].push_back(reg);
          cout << book_words[0].size() << '\n';
          last++;
  }
  cout << "--------" << endl;
  fclose(f);
  
	for(int i = 0; i < num_servers; ++i)
  {
		ths.emplace_back(handler, ip[i], puerto, i);
	}

	for(int i = 0; i < num_servers; ++i)
  {
	  ths[i].join();
	}
  cout << "percentaje: "<< total_words << endl;
  return 0;
}
