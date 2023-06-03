#include<algorithm>
#include<iterator>
#include<list>
#include<iostream>
using namespace std;

int main()
{
    list<int> coll;

    for (int i = 1; i <= 6; ++i)
    {
        coll.push_back(i);
        coll.push_front(i);
    }

    cout << "pre:    ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //remove all elements with value 3
    list<int>::iterator new_end = remove(coll.begin(), coll.end(), 3);

    //cend,size�ޱ仯��ֻ��ɾ��ֵ������Ԫ�ظ��ǵ�
    cout << "post:   ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "number of removed elements: "
        << distance(new_end, coll.end()) << endl;

    //��ӡɾ����3���߼�����
    cout << "�߼��ϣ� post: ";
    copy(coll.begin(), new_end, ostream_iterator<int>(cout, " "));
    cout << endl;

    //��ʵɾ����removed��Ԫ��
    cout << "ִ����ʵɾ��..." << endl;
    coll.erase(new_end, coll.end());

    //��ӡɾ����3���߼�����
    cout << "ʵ��ɾ��removedԪ�غ� post new: ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;


    system("pause");
    return EXIT_SUCCESS;
}