#include "Reply.h"
#include "Request.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <sys/time.h>
#include "TextAnalyzer.cpp"

// struct timeval {
// 	time_t tv_sec; /* segundos */
// 	suseconds_t tv_usec; /* microsegundos */
// };

typedef struct timeval TimeVal;

using namespace std;

FILE* f;

void isr(int sig){
	if(sig == SIGINT){
		if(f){
			fclose(f);
		}
		printf("Servidor cerrado.\n");
		exit(0);
	}
}

timeval add(TimeVal a, TimeVal b){
	int64_t ta = a.tv_sec*1000000 + a.tv_usec;
	int64_t tb = b.tv_sec*1000000 + b.tv_usec;
	int64_t tc = ta + tb;
	TimeVal ans;
	ans.tv_sec = tc/1000000;
	ans.tv_usec = tc%1000000;
	return ans;
}

timeval subtract(TimeVal a, TimeVal b){
	int64_t ta = a.tv_sec*1000000 + a.tv_usec;
	int64_t tb = b.tv_sec*1000000 + b.tv_usec;
	int64_t tc = ta - tb;
	TimeVal ans;
	ans.tv_sec = tc/1000000;
	ans.tv_usec = tc%1000000;
	return ans;
}

timeval divide(TimeVal a, int64_t k){
	int64_t ta = a.tv_sec*1000000 + a.tv_usec;
	ta /= k;
	TimeVal ans;
	ans.tv_sec = ta/1000000;
	ans.tv_usec = ta%1000000;
	return ans;
}
void log(string i)
{
	cout << "print log: ----> "+i << endl; 
}
int main(int argc, char *argv[]) {
	signal(SIGINT, isr);

	Dictionary dic;
	dic.loadDictionary();

	uint16_t puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
	Reply reply(puerto);
	cout << "Servidor iniciado<>...\n";
	
	TimeVal tv_client, tv_server, tv_after, tv_real;
	string current_word;
	int val;
	vector <char> buffer;
	while (1) {
		Message *msg = reply.getRequest();
		
		
		if(msg->operationId == Message::allowedOperations::readWords)
		{
			//cout << msg->length << endl;
			current_word = "";
			for(int k = 0; k < msg->length; k++)
				current_word.push_back(msg->arguments[k]);
			//cout << current_word << endl;
			
			int number = 0;
			number = !dic.isWordInDictionary(current_word);

			reply.sendReply((char*)&number, sizeof(number));
		}
		/**else if(msg->operationId == Message::allowedOperations::getDictSize)
		{
			int size = dic.getSize();
			reply.sendReply((char*)&size, sizeof(size));
		}**/
		//log("5");
		
		/**if (msg->operationId == Message::allowedOperations::registerVote) {
			string id = string(reg.celular) + string(reg.CURP) + string(reg.partido);
			if (!nbd.count(id)) {
				memset(&tv_client, 0, sizeof(TimeVal));
				memset(&tv_server, 0, sizeof(TimeVal));
				memset(&tv_after, 0, sizeof(TimeVal));
				memset(&tv_real, 0, sizeof(TimeVal));
				gettimeofday(&tv_client, NULL);//get time
				size_t len_reply;
				tv_server = *(TimeVal *)r.doOperation(ip_time, puerto_time,
                                   Message::allowedOperations::getTime,
                                   NULL, 0, len_reply);
				gettimeofday(&tv_after, NULL);
				tv_real = add(tv_server, divide(subtract(tv_after, tv_client), 2));
				nbd.insert(id);
				fprintf(f, "%s%s%s\n", reg.celular, reg.CURP, reg.partido);
				fflush(f);
				res = 1;
				fprintf(fsileTimes, "%d:%d\n", tv_real.tv_sec, tv_real.tv_usec);
				fflush(fileTimes);
			}
			reply.sendReply((char*)&tv_real, sizeof(tv_real));
		}**/
	}
	return 0;
}
