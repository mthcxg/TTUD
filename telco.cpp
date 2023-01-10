//Mai  Thu Hien
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool checkPhone(string s)
{
	if(s.length() != 10) return false;
	for(int i = 0; i < s.length(); i++){
		if(!s[i] >='0' && !s[i] <= '9') return false;
	}
	return true;
}

int countTime (string fromTime, string endTime)
{
	int start = 3600*(10*(fromTime[0]-'0') + fromTime[1]-'0') + 60*(10*(fromTime[3]-'0') + fromTime[4]-'0') + (10*(fromTime[6]-'0') + fromTime[7]-'0');
	int end = 3600*(10*(endTime[0]-'0') + endTime[1]-'0') + 60*(10*(endTime[3]-'0') + endTime[4]-'0') + (10*(endTime[6]-'0') + endTime[7]-'0');
	int cTime = end - start;
	return cTime;
}

map <string,int> numberCalls, timeCall;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string type;
	int totalCalls = 0;
	int incorrectPhone = 0;
	do {
		cin >> type;
		if (type == "#") continue;
		++totalCalls;
		string fromNumber, toNumber, date, fromTime, endTime;
		cin >> fromNumber >> toNumber >> date >> fromTime >> endTime;
		if(!checkPhone(fromNumber) || !checkPhone(toNumber)) ++incorrectPhone;
		numberCalls[fromNumber]++;
		timeCall[fromNumber] += countTime(fromTime, endTime);
	} while (type != "#");
	
	do {
		cin >> type;
		if (type == "#") continue;
		if ( type == "?check_number") {
			if (incorrectPhone == 0) cout << 1 <<endl;
			else cout << 0 <<endl;
		}
		
		else if (type == "?number_total_calls") 
			cout << totalCalls <<endl;
		else if (type == "?count_time_calls_from") {
			string phone;
			cin >> phone;
			cout << timeCall[phone] << endl;
		}
	} while (type != "#");
	
	return 0;
	
}