#include <iostream>
#include <string>
#include <list>
 
using namespace std;
 
//����״̬����״̬���ֱ��Ӧ���ֺͷ���
//����ip��ַ��ʼλ�ñ�Ϊ���֣��ʿ���ֱ������NUMΪ��ʼ״̬
enum STATE {NUM, SIGN};
 
typedef struct IP
{
	unsigned ip = 0;
	int len = 32;
}IP;
 
//���벢����ip��ַ�ַ���
IP read(string s)
{
	IP a;
	bool flag = false; //��¼�Ƿ��Ѿ���б�߷��Ž����˴���
	STATE state = NUM;
	unsigned buf = 0; //����ÿ�����ݴ���Ľ��
	unsigned rule = 0x01000000; //�ڴ洢���ݵ���Ӧ�ֽ�ʱ����λ�����õı���
	for(int i = 0; i < s.size(); i++)
	{
		switch(state)
		{
		case NUM: //��������
			if(isdigit(s[i])) buf = s[i] - '0' + buf * 10; //�����־����뻺��
			else //����Ҫ��ָ�����һ��ת��״̬��SIGN
			{
				i--; state = SIGN;
			}
			break;
		case SIGN: //�������
			if(isdigit(s[i]))
			{
				i--; state = NUM; break;
			}
			a.ip += buf * rule; //�����������ƶ�����ȷλ�ò����뵽ip��
			rule >>= 8; //��һ������Ӧλ�Ƶ�λ��
			buf = 0; //�������
			flag = (s[i] == '/') ? true : false;
			break;
		}
		if(i == s.size() - 1) //�ַ����ڱ�����β��ʱ��Ҫ�������⴦��
		{
			if(flag) //�������⣬����Ѿ������б����˵����ip��ַ�Ǳ�׼�ͻ��׺ʡ����
			{
				a.len = buf; //��ʱbuf��ŵıض���ǰ׺����
			}
			else //�����ip��ַΪ����ʡ���ͣ���ʱbuf��ŵ�����ip��ַ���ݣ�ǰ׺������Ҫ�Լ�����
			{
				a.ip += buf * rule;
				rule >>= 8;
				while(rule)
				{
					a.len -= 8;
					rule >>= 8;
				}
			}
		}
	}
	return a;
}
 
//��������b��ƥ�伯Ϊa��ƥ�伯���Ӽ��ȼ���
//a��ǰ׺���Ȳ�����b����a��b��ip��ַ��ǰa.lenλ��ȫ��ͬ
bool isChildCollection(IP &a, IP &b)
{
	if(a.len > b.len) return false;
	if((a.ip ^ b.ip) >> (32 - a.len)) return false;
	return true;
}
 
void merge1(list<IP> &ipl)
{
	auto i = ipl.begin(), j = ipl.begin();
	j++;
	while(j != ipl.end())
	{
		if(isChildCollection(*i, *j)) j = ipl.erase(j);
		else { i++; j++; }
	}
}
 
//��������a��bΪa`���Ժϲ��ȼ���
//a��bǰ׺������ͬ�Ҷ��ߵ�ǰlenλ��ֻ�����һλ����ͬ
bool unionCollection(IP &a, IP &b)
{
	if(a.len != b.len) return false;
	return ((a.ip ^ b.ip) >> (32 - a.len)) == 1u;
}
 
void merge2(list<IP> &ipl)
{
	auto i = ipl.begin(), j = ipl.begin();
	j++;
	while(j != ipl.end())
	{
		if(unionCollection(*i, *j))
		{
			j = ipl.erase(j);
			((*i).len)--;
			if(i != ipl.begin())
			{
				i--; j--;
			}
		}
		else { i++; j++; }
	}
}
 
int main()
{
	int n;
	cin >> n;
	list<IP> ipl;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		ipl.push_back(read(s));
	}
	ipl.sort([](const IP &a, const IP &b){
		if(a.ip != b.ip) return a.ip < b.ip;
		return a.len < b.len;
	});
	merge1(ipl);
	merge2(ipl);
	for(auto &e : ipl)
	{
		unsigned a = 0xff000000, b = 0x00ff0000, c = 0x0000ff00, d = 0x000000ff;
		cout << ((e.ip&a) >> 24) << '.' << ((e.ip&b) >> 16) << '.' << ((e.ip&c) >> 8) << '.' << ((e.ip&d)) << '/' << e.len << endl;
	}
	return 0;
}
