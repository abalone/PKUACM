#include <iostream>
#include <string>

using namespace std;

int n;//�ܹ����ֵĲ�ͬ��ĸ������ĸ���A��ʼ
string s1,s2,s3;//�ֱ�Ϊ����1������2����
int v[27];//ÿ����ĸ��ȡֵ
int digits[10];//��ĸ�Ƿ�ʹ��
int ok;//�ɹ�ƥ��
int i;


//�ַ���ת����
int tovalue(string s)
{
	int l= s.length();
	int vv = 0;
	for(int i=0;i<l;i++){
		vv=vv*10+v[s[i]-'A'];
	}
	return vv;
}

//��������������Сû����֦
void dfs(int r)
{
	if(r==n){
		if(tovalue(s1)+tovalue(s2)==tovalue(s3)){
			ok=1;
		}
		return;
	}
	for(int i=0;i<10;i++){
		if(digits[i]==0){
			v[r]=i;
			digits[i]=1;
			dfs(r+1);
			if(ok)
				return;
			digits[i]=0;
		}
	}
}

int main()
{
	cin >> n;
	cin >> s1 >> s2 >> s3;
	ok=0;
	dfs(0);
	if(ok){
		cout << "SOLUTION:" << endl;
		for(i=0;i<n;i++){
			cout << char(i+'A') << ":" << v[i] << endl;
		}
	}
	else{
		cout << "NO SOLUTIONS!" << endl;
	}
}