#include <iostream>
#include "admin.h"
#include "user.h"
#include "commodity.h"
#include "order.h"
#include <cstring>
using namespace std;

#define INTERVAL 10*60

time_t string2time(const string & time_string)
{
    struct tm tm1;
    time_t time1;
    sscanf(time_string.c_str(), "%d-%d-%d %d:%d:%d" ,    
        &(tm1.tm_year), &(tm1.tm_mon), &(tm1.tm_mday),
        &(tm1.tm_hour), &(tm1.tm_min), &(tm1.tm_sec));
    tm1.tm_year -= 1900;
    tm1.tm_mon --;
    time1 = mktime(&tm1);
    return time1;
}

void finish_order(UArray& uarr, CArray& carr, OArray& oarr)
{
	time_t nowtime = time(NULL);
	struct tm* t= localtime(&nowtime);
	nowtime = mktime(t);
	for(int i = 0; i < carr.length(); ++i)
	{
		time_t time1 = string2time(carr[i].get_date());
		double dTime = difftime(nowtime, time1);
		if(dTime >= INTERVAL && carr[i].get_state() == "onAuction") //拍卖时间到
		{
			OArray tmparr; //暂时存放该商品的所有订单
			for(int j = 0; j < oarr.length(); ++j)
				if(oarr[j].get_cid() == carr[i].get_id() && oarr[j].get_state() == "unfinished")
					tmparr.push_back(oarr[j]);
			for(int x = 0; x < tmparr.length(); ++x) //根据出价和时间排序
				for(int y = 0; y < tmparr.length()-x-1; ++y)
				{
					if((tmparr[y].get_bid() < tmparr[y+1].get_bid()) || 
					(tmparr[y].get_bid() == tmparr[y+1].get_bid() && tmparr[y].get_date() > tmparr[y+1].get_date()))
					{
						Order temp = tmparr[y];
						tmparr[y] = tmparr[y+1];
						tmparr[y+1] = temp;
					}
				}
			int k;
			for(k = 0; k < tmparr.length() && carr[i].get_num() > 0; ++k) //卖出商品
			{
				string buyerid(tmparr[k].get_buyerid(), 1, 3);
				string sellerid(tmparr[k].get_sellerid(), 1, 3);
				int bindex = stoi(buyerid) - 1;
				int sindex = stoi(sellerid) - 1;
				float b_balance = uarr[bindex].get_balance();
				float s_balance = uarr[sindex].get_balance();
				if(b_balance >= tmparr[k].get_bid())
				{
					b_balance -= tmparr[k].get_bid();
					uarr[bindex].set_balance(b_balance);
					s_balance += tmparr[k].get_bid();
					uarr[sindex].set_balance(s_balance);
					string orderid(tmparr[k].get_oid(), 1, 3);
					int oindex = stoi(orderid) - 1;
					oarr[oindex].set_state("get");
					carr[i].set_num(carr[i].get_num() - 1);
				}
			}
			for(; k < tmparr.length(); ++k)
			{
				string orderid(tmparr[k].get_oid(), 1, 3);
				int oindex = stoi(orderid) - 1;
				oarr[oindex].set_state("finished");
			}
			carr[i].set_state("removed");
		}
	}
	uarr.array2file("user.txt");
	carr.array2file("commodity.txt");
	oarr.array2file("order.txt");
}

int main()
{
	Admin admin;
	UArray uarr;
	CArray carr;
	OArray oarr;
	uarr.file2array("user.txt");
	carr.file2array("commodity.txt");
	oarr.file2array("order.txt");
	int flag = 0;
	while(flag == 0)
	{
		finish_order(uarr, carr, oarr);
		cout << endl << endl << "Welcome commodity auction platform!" << endl <<
		"============================================================" << endl << 
		"1.User login  2.User register  3.Administrator login  4.Exit" << endl <<
		"============================================================" << endl <<
		"Please input your choice:";
		int n;
		cin >> n;
		while(!cin.good())
		{
			cout << "Invalid input!" << endl;
			cout << "Please input your choose:";
			cin.clear(); cin.ignore(1); cin >> n;
		}
		switch (n)
		{
		case 1: uarr.login(carr, oarr); break;
		case 2: uarr.enroll(); break;
		case 3: admin.login(uarr, carr, oarr); break;
		case 4: { cout << "Bye!" << endl; flag = 1; }break;
		default: cout << "Invalid input!" << endl; break;
		}
	}
	return 0;
}